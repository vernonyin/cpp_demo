//
// Created by yin on 2019-01-23.
//
#include "shm_statistics.h"
#include <fstream>
#include <sstream>

using namespace std;

namespace  CommonHelper{
    template <class T>
    static void ConvertFromString(T &value, const std::string &s)
    {
        std::stringstream ss(s);
        ss >> value;
    }
}

ShmStatistics *ShmStatistics::inst_ = nullptr;

ShmStatistics *ShmStatistics::Instance() {
    if (inst_ == nullptr) {
        inst_ = new ShmStatistics();
    }

    return inst_;
}

ShmStatistics::ShmStatistics() : start_shm(nullptr) {
    int shmid = shmget(SHM_KEY, sizeof(struct stat_data), 0666 | IPC_CREAT);

    assert(shmid != -1);
    void *shm = shmat(shmid, (void *) 0, 0);
    assert(shm != (void *) -1);

    start_shm = (struct stat_data *) shm;
    Reset();
}

void ShmStatistics::UpdateAPI(std::string api_name, int result, int cost_ms) {
    assert(start_shm != nullptr);
    for (int i = 0; i < API_CNT; ++i) {
        if (start_shm->apis[i].name == api_name || strlen(start_shm->apis[i].name) == 0) {
            strncpy(start_shm->apis[i].name, api_name.c_str(), 128);
            start_shm->apis[i].totalCount++;
            start_shm->apis[i].totalTime += cost_ms;
            if (result == 0) {
                start_shm->apis[i].succCount++;
            } else {
                start_shm->apis[i].failCount++;
            }
            break;
        }
    }
}


void ShmStatistics::updateHold(const FR::Hold& rsp) {
//    string account_id = rsp.acc.client_acc;
//    for (FR::Hold hold : rsp.holds) {
//        string symbol = hold.symbol;
//        map_hold_[account_id][symbol] = hold;
//    }
}
void ShmStatistics::updateFund(const FR::Query_fund_rsp& rsp){
    stAccount* ac = getAccount(rsp.acc.client_acc);
    for (FR::Fund fund : rsp.items) {
        mm::Currency currency = fund.ccy;

        double balance,frozen,usable;
        CommonHelper::ConvertFromString(balance, fund.balance);
        CommonHelper::ConvertFromString(frozen, fund.frozen);
        CommonHelper::ConvertFromString(usable, fund.usable);
        ac->funds[currency].currency = currency;
        ac->funds[currency].balance = balance;
        ac->funds[currency].frozen = frozen;
        ac->funds[currency].usable = usable;
    }
}

stAccount* ShmStatistics::getAccount(const string& account){
    for (int i = 0; i < ACCOUNT_CNT; ++i) {
        if (strcmp(start_shm->accounts[i].userName,account.c_str()) ==0){
            return &start_shm->accounts[i];
        }
        if(strlen(start_shm->accounts[i].userName) == 0){
            strcpy(start_shm->accounts[i].userName,account.c_str());
            return &start_shm->accounts[i];
        }
    }
    return &start_shm->accounts[0];
}

void ShmStatistics::updateTrade(const std::string account,int amount){
    stAccount* ac = getAccount(account);
    ac->tradeCount++;
    ac->tradeAmount += amount;
}


void ShmStatistics::Reset() {
    assert(start_shm != nullptr);
    time_t tt = time(NULL);
    tm* t= localtime(&tt);
    char buff[128];
    sprintf(buff,"%d-%02d-%02d", t->tm_year+1900, t->tm_mon+1, t->tm_mday);

    if (strcmp(start_shm->data,buff) == 0) {
        return ;
    }
    //换天了重置数据
    memset(start_shm,0,sizeof(struct stat_data));
    strcpy(start_shm->data,buff);
}

void ShmStatistics::Print() {
    assert(start_shm != nullptr);
    cout << "统计数据：" << start_shm->data << endl;

    for (int i = 0; i < ACCOUNT_CNT; ++i) {
        if (strlen(start_shm->accounts[i].userName) == 0) {
            break;
        }
        const stAccount &ac = start_shm->accounts[i];
        printf("账户:%s",ac.userName);
        for (int j=0;j<FUND_CNT;j++){
            const stFund& fund = ac.funds[j];
            if (fund.balance+fund.frozen+fund.usable > 0){
                printf("资金:%d,b:%f,f:%f,u:%f,",
                       fund.currency,fund.balance,fund.frozen,fund.usable);
            }
        }
        printf(" 交易次数:%d,手数:%d\n", ac.tradeCount, ac.tradeAmount);
    }

    for (int i = 0; i < API_CNT; ++i) {
        if (strlen(start_shm->apis[i].name) == 0) {
            break;
        }
        const stAPI &api = start_shm->apis[i];
        float f1 = float(api.failCount) / api.totalCount;
        float f2 = float(api.totalTime) / api.totalCount;
        printf("接口:%s,请求总数:%d,成功次数:%d,失败次数:%d,失败率:%.3f,平均耗时：%.3f ms\n",
               api.name, api.totalCount, api.succCount, api.failCount, f1,f2);
    }

}

//ipcrm -M 0x0000029a

int main(){
    string s("2340er232sdvasd");
    int i=stoi(s);
    return 0;
    ShmStatistics::Instance()->Print();

    ShmStatistics::Instance()->UpdateAPI("下单请求",0,10);
    ShmStatistics::Instance()->UpdateAPI("下单请求1",0,20);

    ShmStatistics::Instance()->updateTrade("accout1",2);
    ShmStatistics::Instance()->updateTrade("accout1",3);

    FR::Query_fund_rsp rsp;
    rsp.acc.client_acc = "accout1";
    FR::Fund f;
    f.ccy = mm::Currency_CNY;
    f.balance ="123.5";
    f.frozen ="666";
    f.usable ="888";
    rsp.items.push_back(f);

    ShmStatistics::Instance()->updateFund(rsp);


    ShmStatistics::Instance()->Print();
}

