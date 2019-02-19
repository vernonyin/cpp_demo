//
// Created by yin on 2019-01-23.
//
#ifndef CPP_FRAMEWORK_SHM_STATISTICS_H
#define CPP_FRAMEWORK_SHM_STATISTICS_H
#pragma once

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <iostream>
#include "fbs/mm_reader.h"

const key_t SHM_KEY = 666;
const int ACCOUNT_CNT = 40;
const int API_CNT = 40;
const int FUND_CNT = 40;

//struct stHold{
//    char account[128];
//
//};

struct stFund{
    mm::Currency currency;
    double balance;
    double frozen;
    double usable;
};

//账户数据统计
struct stAccount {
    // 用户名或者instrumentId
    char userName[100];
    // 可用资金
    stFund funds[FUND_CNT];
    // 当天交易次数
    int tradeCount;
    // 当天交易手数
    int tradeAmount;
};

//接口数据统计
struct stAPI {
    char name[128];//接口名称
    int totalCount;
    int succCount;
    int failCount;
    int totalTime;//总耗时
};


//共享内存的统计数据
struct stat_data {
    char data[128];//日期
    stAccount accounts[ACCOUNT_CNT];
    stAPI apis[API_CNT];
};

class ShmStatistics {
public:
    static ShmStatistics *Instance();

    //统计接口，result=0成功
    void UpdateAPI(std::string api_name, int result, int cost_ms);

    void updateHold(const FR::Hold& hold);
    void updateFund(const FR::Query_fund_rsp& rsp);
    void updateTrade(const std::string account,int amount);

    stAccount* getAccount(const std::string& account);

    void Reset();

    void Print();

private:
    ShmStatistics();
    ShmStatistics(const ShmStatistics& ss);
    ShmStatistics& operator=(const ShmStatistics& ss);

private:
    static ShmStatistics *inst_;
    struct stat_data *start_shm;
};


#endif //CPP_FRAMEWORK_SHM_STATISTICS_H
