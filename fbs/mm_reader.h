#pragma once
#include <sstream>
#include "mm_generated.h"


namespace FR
{

//#define uint unsigned int
 #define ulong unsigned long
#ifndef GX1
#	define GX1(x, y) (!x ? (y) : x)
#endif
#ifndef GX2
#define GX2(x1, x2, y) ((!x1 || !(x1->x2)) ? (y) : x1->x2)
#endif
#ifndef GX3
#define GX3(x1, x2, x3, y) (((!x1 || !(x1->x2) || !(x1->x2->x3)) ? (y) : x1->x2->x3))
#endif
#ifndef GX4
#define GX4(x1, x2, x3, x4, y) (((!x1 || !(x1->x2) || !(x1->x2->x3) || !(x1->x2->x3->x4))) ? (y) : x1->x2->x3->x4)
#endif
#ifndef GX5
#define GX5(x1, x2, x3, x4, x5, y) (((!x1 || !(x1->x2) || !(x1->x2->x3) || !(x1->x2->x3->x4) || !(x1->x2->x3->x4->x5))) ? (y) : x1->x2->x3->x4->x5)

#endif
#ifndef fs
#	define fs(str) str.empty() ? 0 : fb.CreateString(str)
#endif
#ifndef fb
#	define fv(vct) vct.empty() ? 0 : fb.CreateVector(vct)
#endif
#ifndef FBS_MAX_SIZE
#	define FBS_MAX_SIZE 10 * 1024 * 1024
#endif
#ifndef READ_FBS
#	define READ_FBS(obj, cls, data, len)\
	flatbuffers::FlatBufferBuilder builder_##obj;\
	builder_##obj.PushFlatBuffer((const uint8_t*)data, len);\
	auto obj = flatbuffers::GetRoot<cls>(builder_##obj.GetBufferPointer())
#endif
#ifndef BUILD_FBS
#	define BUILD_FBS(fb, fr)\
	flatbuffers::FlatBufferBuilder fb;\
	fb.Finish(fr.to_fbs(fb))
#endif

static std::stringstream& ss_cut_back_c(std::stringstream &ss)
{
	std::string str = ss.str(); 
	str = str.substr(0, str.size() - 1); 
	ss.str(""); 
	ss << str; 
	return ss; 
}

template <typename T>
static bool fbs_verify_table(const void* ptr_fbs, const size_t n_len)
{
	if (!ptr_fbs || 0 == n_len || FBS_MAX_SIZE < n_len) return false;
	READ_FBS(obj, T, ptr_fbs, n_len);
	auto verify = flatbuffers::Verifier((const uint8_t*)builder_obj.GetBufferPointer(), builder_obj.GetSize());
	return obj->Verify(verify);
}


// Verify
////////////////////
// reader && builder


template <typename Tc, typename Tf>
static std::vector<Tc> read_vct(const flatbuffers::Vector<flatbuffers::Offset<Tf>> *ptr_fbs)
{
	std::vector<Tc> data;
	for (int i = 0; i < (int)GX2(ptr_fbs, size(), 0); i++)
	{
		auto iter = ptr_fbs->Get(i);
		data.push_back(iter);
	}
	return data;
}
template <typename Tc, typename Tf>
static std::vector<Tc> read_vct_enum(const flatbuffers::Vector<Tf> *ptr_fbs)
{
	std::vector<Tc> data;
	for (int i = 0; i < (int)GX2(ptr_fbs, size(), 0); i++)
	{
		auto iter = ptr_fbs->Get(i);
		data.push_back((Tc)iter);
	}
	return data;
}
template <typename Tc, typename Tf>
static std::vector<Tc> read_vct_str(const flatbuffers::Vector<flatbuffers::Offset<Tf>> *ptr_fbs)
{
	std::vector<Tc> data;
	for (int i = 0; i < (int)GX2(ptr_fbs, size(), 0); i++)
	{
		auto iter = ptr_fbs->Get(i);
		data.push_back(GX2(iter, c_str(), ""));
	}
	return data;
}
template <typename Tc>
static std::string read_vct_2_json(const std::vector<Tc> &data)
{
	std::stringstream ss;
	ss << "[";
	for (auto i : data) ss << i << ",";
	ss_cut_back_c(ss);
	ss << "]";
	return ss.str();
}
template <typename Tc, typename Tf>
static flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Tf>>> build_vct(flatbuffers::FlatBufferBuilder &fb, const std::vector<Tc> vct_data)
{
	std::vector<flatbuffers::Offset<Tf>> vct_fbs;
	for (auto i : vct_data)
	{
		vct_fbs.push_back(i.to_fbs(fb));
	}
	return fv(vct_fbs);
}
template <typename Tc, typename Tf>
static flatbuffers::Offset<flatbuffers::Vector<Tf>> build_vct_enum(flatbuffers::FlatBufferBuilder &fb, const std::vector<Tc> vct_data)
{
	std::vector<Tf> vct_fbs;
	for (auto i : vct_data)
	{
		vct_fbs.push_back(i);
	}
	return fv(vct_fbs);
}
template <typename Tc, typename Tf>
static flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Tf>>> build_vct_str(flatbuffers::FlatBufferBuilder &fb, const std::vector<Tc> vct_data)
{
	std::vector<flatbuffers::Offset<Tf>> vct_fbs;
	for (auto i : vct_data)
	{
		vct_fbs.push_back(fs(i));
	}
	return fv(vct_fbs);
}



struct Pair;
struct Result;
struct Bank;
struct Banks;
struct Account;
struct Query_page;
struct Deal_summary;
struct Deal_detail;
struct Capital_detail;
struct Fee;
struct Entrust;
struct SpecialCond;
struct Login;
struct Login_rsp;
struct ChangePwd;
struct QueryConsign;
struct QueryConsign_rsp;
struct Query_hold;
struct Query_hold_rsp;
struct Query_fund;
struct Query_fund_rsp;
struct QueryBargain;
struct QueryBargain_rsp;
struct QueryCapital;
struct Query_capital_rsp;
struct FundTransfer;
struct Query_ftflow;
struct Query_ftflow_rsp;
struct QueryPosition;
struct Query_position_rsp;
struct Query_settlement;
struct Query_settlement_rsp;
struct Query_maxbuy;
struct Query_maxbuy_rsp;
struct Entrust_rsp;
struct EntrustAll;
struct Exrate;
struct Exrates;
struct Product;
struct Product_rsp;
struct Query_products;
struct Query_products_rsp;
struct MarginScalingClassDetail;
struct MarginScalingClass;
struct AccountInfo;
struct UserInfo;
struct Fund;
struct Hold;
struct PositionNotify;
struct Notify;
struct Margin;
struct Recovery;
struct VerifyCode_req;
struct VerifyCode_rsp;
struct exrates_req;
struct Query_order_oprecord;
struct Order_operation_record;
struct Query_order_oprecord_rsp;
struct ACCOUNT_INFO;


struct Pair
{
	std::string first;
	std::string second;

	Pair()
	{
	}
	Pair(const Pair &src)
	{
		first = src.first;
		second = src.second;
	}
	Pair(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Pair();
			return;
		}
		READ_FBS(fbs_obj, mm::Pair, ptr_data, n_len);
		*this = Pair(fbs_obj);
	}
	Pair(const mm::Pair *ptr_fbs)
	{
		if (!ptr_fbs) return;
		first = GX3(ptr_fbs, first(), c_str(), "");
		second = GX3(ptr_fbs, second(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Pair>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Pair> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreatePair(fb, fs(first), fs(second));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && first.size())) ss << "\"first\":" << "\"" << first << "\"" << ",";
		if (!b_simplify || (b_simplify && second.size())) ss << "\"second\":" << "\"" << second << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Pair &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Result
{
	std::string errcode;
	std::string errmsg;

	Result()
	{
	}
	Result(const Result &src)
	{
		errcode = src.errcode;
		errmsg = src.errmsg;
	}
	Result(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Result();
			return;
		}
		READ_FBS(fbs_obj, mm::Result, ptr_data, n_len);
		*this = Result(fbs_obj);
	}
	Result(const mm::Result *ptr_fbs)
	{
		if (!ptr_fbs) return;
		errcode = GX3(ptr_fbs, errcode(), c_str(), "");
		errmsg = GX3(ptr_fbs, errmsg(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Result>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Result> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateResult(fb, fs(errcode), fs(errmsg));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && errcode.size())) ss << "\"errcode\":" << "\"" << errcode << "\"" << ",";
		if (!b_simplify || (b_simplify && errmsg.size())) ss << "\"errmsg\":" << "\"" << errmsg << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Result &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Bank
{
	uint bankid;
	std::string eng_name;
	std::string cht_name;
	std::string chs_name;
	std::vector<Pair> extras;

	Bank()
	{
		bankid = 0;
	}
	Bank(const Bank &src)
	{
		bankid = src.bankid;
		eng_name = src.eng_name;
		cht_name = src.cht_name;
		chs_name = src.chs_name;
		extras = src.extras;
	}
	Bank(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Bank();
			return;
		}
		READ_FBS(fbs_obj, mm::Bank, ptr_data, n_len);
		*this = Bank(fbs_obj);
	}
	Bank(const mm::Bank *ptr_fbs)
	{
		if (!ptr_fbs) return;
		bankid = ptr_fbs->bankid();
		eng_name = GX3(ptr_fbs, eng_name(), c_str(), "");
		cht_name = GX3(ptr_fbs, cht_name(), c_str(), "");
		chs_name = GX3(ptr_fbs, chs_name(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Bank>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Bank> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateBank(fb, bankid, fs(eng_name), fs(cht_name), fs(chs_name), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"bankid\":" << (uint)bankid << ",";
		if (!b_simplify || (b_simplify && eng_name.size())) ss << "\"eng_name\":" << "\"" << eng_name << "\"" << ",";
		if (!b_simplify || (b_simplify && cht_name.size())) ss << "\"cht_name\":" << "\"" << cht_name << "\"" << ",";
		if (!b_simplify || (b_simplify && chs_name.size())) ss << "\"chs_name\":" << "\"" << chs_name << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Bank &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Banks
{
	std::vector<Bank> items;
	std::vector<Pair> extras;

	Banks()
	{
	}
	Banks(const Banks &src)
	{
		items = src.items;
		extras = src.extras;
	}
	Banks(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Banks();
			return;
		}
		READ_FBS(fbs_obj, mm::Banks, ptr_data, n_len);
		*this = Banks(fbs_obj);
	}
	Banks(const mm::Banks *ptr_fbs)
	{
		if (!ptr_fbs) return;
		items = read_vct<Bank, mm::Bank>(ptr_fbs->items());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Banks>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Banks> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateBanks(fb, build_vct<Bank, mm::Bank>(fb, items), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<Bank>(items) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Banks &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Account
{
	std::string user;
	std::string client_acc;
	std::string session;
	std::string uuid_3rd;
	std::string mobile;
	std::vector<Pair> extras;

	Account()
	{
	}
	Account(const Account &src)
	{
		user = src.user;
		client_acc = src.client_acc;
		session = src.session;
		uuid_3rd = src.uuid_3rd;
		mobile = src.mobile;
		extras = src.extras;
	}
	Account(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Account();
			return;
		}
		READ_FBS(fbs_obj, mm::Account, ptr_data, n_len);
		*this = Account(fbs_obj);
	}
	Account(const mm::Account *ptr_fbs)
	{
		if (!ptr_fbs) return;
		user = GX3(ptr_fbs, user(), c_str(), "");
		client_acc = GX3(ptr_fbs, client_acc(), c_str(), "");
		session = GX3(ptr_fbs, session(), c_str(), "");
		uuid_3rd = GX3(ptr_fbs, uuid_3rd(), c_str(), "");
		mobile = GX3(ptr_fbs, mobile(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Account>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Account> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateAccount(fb, fs(user), fs(client_acc), fs(session), fs(uuid_3rd), fs(mobile), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && user.size())) ss << "\"user\":" << "\"" << user << "\"" << ",";
		if (!b_simplify || (b_simplify && client_acc.size())) ss << "\"client_acc\":" << "\"" << client_acc << "\"" << ",";
		if (!b_simplify || (b_simplify && session.size())) ss << "\"session\":" << "\"" << session << "\"" << ",";
		if (!b_simplify || (b_simplify && uuid_3rd.size())) ss << "\"uuid_3rd\":" << "\"" << uuid_3rd << "\"" << ",";
		if (!b_simplify || (b_simplify && mobile.size())) ss << "\"mobile\":" << "\"" << mobile << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Account &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_page
{
	mm::Page_mode mode;
	uint idx;
	uint count;

	Query_page()
	{
		mode = mm::Page_mode_ALL;
		idx = 0;
		count = 0;
	}
	Query_page(const Query_page &src)
	{
		mode = src.mode;
		idx = src.idx;
		count = src.count;
	}
	Query_page(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_page();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_page, ptr_data, n_len);
		*this = Query_page(fbs_obj);
	}
	Query_page(const mm::Query_page *ptr_fbs)
	{
		if (!ptr_fbs) return;
		mode = ptr_fbs->mode();
		idx = ptr_fbs->idx();
		count = ptr_fbs->count();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_page>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_page> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_page(fb, mode, idx, count);
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"mode\":" << "\"" << EnumNamePage_mode(mode) << "\"" << ",";
		ss << "\"idx\":" << (uint)idx << ",";
		ss << "\"count\":" << (uint)count << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_page &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Deal_summary
{
	std::string deal_day;
	std::string entrust_no;
	std::string deal_qty;
	std::string queue_qty;
	std::string deal_price;
	std::string amount;
	mm::Entrust_status status;
	std::vector<Pair> extras;

	Deal_summary()
	{
		status = mm::Entrust_status_NONE;
	}
	Deal_summary(const Deal_summary &src)
	{
		deal_day = src.deal_day;
		entrust_no = src.entrust_no;
		deal_qty = src.deal_qty;
		queue_qty = src.queue_qty;
		deal_price = src.deal_price;
		amount = src.amount;
		status = src.status;
		extras = src.extras;
	}
	Deal_summary(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Deal_summary();
			return;
		}
		READ_FBS(fbs_obj, mm::Deal_summary, ptr_data, n_len);
		*this = Deal_summary(fbs_obj);
	}
	Deal_summary(const mm::Deal_summary *ptr_fbs)
	{
		if (!ptr_fbs) return;
		deal_day = GX3(ptr_fbs, deal_day(), c_str(), "");
		entrust_no = GX3(ptr_fbs, entrust_no(), c_str(), "");
		deal_qty = GX3(ptr_fbs, deal_qty(), c_str(), "");
		queue_qty = GX3(ptr_fbs, queue_qty(), c_str(), "");
		deal_price = GX3(ptr_fbs, deal_price(), c_str(), "");
		amount = GX3(ptr_fbs, amount(), c_str(), "");
		status = ptr_fbs->status();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Deal_summary>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Deal_summary> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateDeal_summary(fb, fs(deal_day), fs(entrust_no), fs(deal_qty), fs(queue_qty), fs(deal_price), fs(amount), status, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && deal_day.size())) ss << "\"deal_day\":" << "\"" << deal_day << "\"" << ",";
		if (!b_simplify || (b_simplify && entrust_no.size())) ss << "\"entrust_no\":" << "\"" << entrust_no << "\"" << ",";
		if (!b_simplify || (b_simplify && deal_qty.size())) ss << "\"deal_qty\":" << "\"" << deal_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && queue_qty.size())) ss << "\"queue_qty\":" << "\"" << queue_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && deal_price.size())) ss << "\"deal_price\":" << "\"" << deal_price << "\"" << ",";
		if (!b_simplify || (b_simplify && amount.size())) ss << "\"amount\":" << "\"" << amount << "\"" << ",";
		ss << "\"status\":" << "\"" << EnumNameEntrust_status(status) << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Deal_summary &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Deal_detail
{
	Account acc;
	std::string deal_time;
	std::string entrust_no;
	mm::Market market;
	std::string symbol;
	std::string bargain_no;
	mm::Entrust_mode direction;
	std::string price;
	std::string deal_qty;
	std::string queue_qty;
	std::string opponent_entrust_no;
	std::string commission;
	std::string charge;
	std::vector<Pair> extras;

	Deal_detail()
	{
		market = mm::Market_NONE;
		direction = mm::Entrust_mode_NONE;
	}
	Deal_detail(const Deal_detail &src)
	{
		acc = src.acc;
		deal_time = src.deal_time;
		entrust_no = src.entrust_no;
		market = src.market;
		symbol = src.symbol;
		bargain_no = src.bargain_no;
		direction = src.direction;
		price = src.price;
		deal_qty = src.deal_qty;
		queue_qty = src.queue_qty;
		opponent_entrust_no = src.opponent_entrust_no;
		commission = src.commission;
		charge = src.charge;
		extras = src.extras;
	}
	Deal_detail(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Deal_detail();
			return;
		}
		READ_FBS(fbs_obj, mm::Deal_detail, ptr_data, n_len);
		*this = Deal_detail(fbs_obj);
	}
	Deal_detail(const mm::Deal_detail *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		deal_time = GX3(ptr_fbs, deal_time(), c_str(), "");
		entrust_no = GX3(ptr_fbs, entrust_no(), c_str(), "");
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		bargain_no = GX3(ptr_fbs, bargain_no(), c_str(), "");
		direction = ptr_fbs->direction();
		price = GX3(ptr_fbs, price(), c_str(), "");
		deal_qty = GX3(ptr_fbs, deal_qty(), c_str(), "");
		queue_qty = GX3(ptr_fbs, queue_qty(), c_str(), "");
		opponent_entrust_no = GX3(ptr_fbs, opponent_entrust_no(), c_str(), "");
		commission = GX3(ptr_fbs, commission(), c_str(), "");
		charge = GX3(ptr_fbs, charge(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Deal_detail>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Deal_detail> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateDeal_detail(fb, acc.to_fbs(fb), fs(deal_time), fs(entrust_no), market, fs(symbol), fs(bargain_no), direction, fs(price), fs(deal_qty), fs(queue_qty), fs(opponent_entrust_no), fs(commission), fs(charge), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && deal_time.size())) ss << "\"deal_time\":" << "\"" << deal_time << "\"" << ",";
		if (!b_simplify || (b_simplify && entrust_no.size())) ss << "\"entrust_no\":" << "\"" << entrust_no << "\"" << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && bargain_no.size())) ss << "\"bargain_no\":" << "\"" << bargain_no << "\"" << ",";
		ss << "\"direction\":" << "\"" << EnumNameEntrust_mode(direction) << "\"" << ",";
		if (!b_simplify || (b_simplify && price.size())) ss << "\"price\":" << "\"" << price << "\"" << ",";
		if (!b_simplify || (b_simplify && deal_qty.size())) ss << "\"deal_qty\":" << "\"" << deal_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && queue_qty.size())) ss << "\"queue_qty\":" << "\"" << queue_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && opponent_entrust_no.size())) ss << "\"opponent_entrust_no\":" << "\"" << opponent_entrust_no << "\"" << ",";
		if (!b_simplify || (b_simplify && commission.size())) ss << "\"commission\":" << "\"" << commission << "\"" << ",";
		if (!b_simplify || (b_simplify && charge.size())) ss << "\"charge\":" << "\"" << charge << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Deal_detail &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Capital_detail
{
	Account acc;
	std::string time;
	std::string serialno;
	mm::CashIOType business_type;
	mm::CashMedia media_type;
	Bank bankid;
	std::string amount;
	mm::Currency ccy;
	std::vector<Pair> extras;

	Capital_detail()
	{
		business_type = mm::CashIOType_NONE;
		media_type = mm::CashMedia_NONE;
		ccy = mm::Currency_NONE;
	}
	Capital_detail(const Capital_detail &src)
	{
		acc = src.acc;
		time = src.time;
		serialno = src.serialno;
		business_type = src.business_type;
		media_type = src.media_type;
		bankid = src.bankid;
		amount = src.amount;
		ccy = src.ccy;
		extras = src.extras;
	}
	Capital_detail(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Capital_detail();
			return;
		}
		READ_FBS(fbs_obj, mm::Capital_detail, ptr_data, n_len);
		*this = Capital_detail(fbs_obj);
	}
	Capital_detail(const mm::Capital_detail *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		time = GX3(ptr_fbs, time(), c_str(), "");
		serialno = GX3(ptr_fbs, serialno(), c_str(), "");
		business_type = ptr_fbs->business_type();
		media_type = ptr_fbs->media_type();
		bankid = ptr_fbs->bankid();
		amount = GX3(ptr_fbs, amount(), c_str(), "");
		ccy = ptr_fbs->ccy();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Capital_detail>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Capital_detail> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateCapital_detail(fb, acc.to_fbs(fb), fs(time), fs(serialno), business_type, media_type, bankid.to_fbs(fb), fs(amount), ccy, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && time.size())) ss << "\"time\":" << "\"" << time << "\"" << ",";
		if (!b_simplify || (b_simplify && serialno.size())) ss << "\"serialno\":" << "\"" << serialno << "\"" << ",";
		ss << "\"business_type\":" << "\"" << EnumNameCashIOType(business_type) << "\"" << ",";
		ss << "\"media_type\":" << "\"" << EnumNameCashMedia(media_type) << "\"" << ",";
		ss << "\"bankid\":" << bankid.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && amount.size())) ss << "\"amount\":" << "\"" << amount << "\"" << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Capital_detail &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Fee
{
	std::string ccass;
	std::string commission;
	std::string stamp;
	std::string levy;
	std::string charge;
	std::string tradevalue;
	std::string other;
	std::string tariff;
	std::vector<Pair> extras;

	Fee()
	{
	}
	Fee(const Fee &src)
	{
		ccass = src.ccass;
		commission = src.commission;
		stamp = src.stamp;
		levy = src.levy;
		charge = src.charge;
		tradevalue = src.tradevalue;
		other = src.other;
		tariff = src.tariff;
		extras = src.extras;
	}
	Fee(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Fee();
			return;
		}
		READ_FBS(fbs_obj, mm::Fee, ptr_data, n_len);
		*this = Fee(fbs_obj);
	}
	Fee(const mm::Fee *ptr_fbs)
	{
		if (!ptr_fbs) return;
		ccass = GX3(ptr_fbs, ccass(), c_str(), "");
		commission = GX3(ptr_fbs, commission(), c_str(), "");
		stamp = GX3(ptr_fbs, stamp(), c_str(), "");
		levy = GX3(ptr_fbs, levy(), c_str(), "");
		charge = GX3(ptr_fbs, charge(), c_str(), "");
		tradevalue = GX3(ptr_fbs, tradevalue(), c_str(), "");
		other = GX3(ptr_fbs, other(), c_str(), "");
		tariff = GX3(ptr_fbs, tariff(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Fee>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Fee> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateFee(fb, fs(ccass), fs(commission), fs(stamp), fs(levy), fs(charge), fs(tradevalue), fs(other), fs(tariff), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && ccass.size())) ss << "\"ccass\":" << "\"" << ccass << "\"" << ",";
		if (!b_simplify || (b_simplify && commission.size())) ss << "\"commission\":" << "\"" << commission << "\"" << ",";
		if (!b_simplify || (b_simplify && stamp.size())) ss << "\"stamp\":" << "\"" << stamp << "\"" << ",";
		if (!b_simplify || (b_simplify && levy.size())) ss << "\"levy\":" << "\"" << levy << "\"" << ",";
		if (!b_simplify || (b_simplify && charge.size())) ss << "\"charge\":" << "\"" << charge << "\"" << ",";
		if (!b_simplify || (b_simplify && tradevalue.size())) ss << "\"tradevalue\":" << "\"" << tradevalue << "\"" << ",";
		if (!b_simplify || (b_simplify && other.size())) ss << "\"other\":" << "\"" << other << "\"" << ",";
		if (!b_simplify || (b_simplify && tariff.size())) ss << "\"tariff\":" << "\"" << tariff << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Fee &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct SpecialCond
{
	mm::SpecialType Spec_type;
	mm::Entrust_mode Spec_direction;
	std::string trigger_price;
	std::string stop_loss_price;
	std::string pursuit_price;
	std::string step;
	std::string target_profit_price;
	std::vector<Pair> extras;

	SpecialCond()
	{
		Spec_type = mm::SpecialType_NONE;
		Spec_direction = mm::Entrust_mode_NONE;
	}
	SpecialCond(const SpecialCond &src)
	{
		Spec_type = src.Spec_type;
		Spec_direction = src.Spec_direction;
		trigger_price = src.trigger_price;
		stop_loss_price = src.stop_loss_price;
		pursuit_price = src.pursuit_price;
		step = src.step;
		target_profit_price = src.target_profit_price;
		extras = src.extras;
	}
	SpecialCond(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = SpecialCond();
			return;
		}
		READ_FBS(fbs_obj, mm::SpecialCond, ptr_data, n_len);
		*this = SpecialCond(fbs_obj);
	}
	SpecialCond(const mm::SpecialCond *ptr_fbs)
	{
		if (!ptr_fbs) return;
		Spec_type = ptr_fbs->Spec_type();
		Spec_direction = ptr_fbs->Spec_direction();
		trigger_price = GX3(ptr_fbs, trigger_price(), c_str(), "");
		stop_loss_price = GX3(ptr_fbs, stop_loss_price(), c_str(), "");
		pursuit_price = GX3(ptr_fbs, pursuit_price(), c_str(), "");
		step = GX3(ptr_fbs, step(), c_str(), "");
		target_profit_price = GX3(ptr_fbs, target_profit_price(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::SpecialCond>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::SpecialCond> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateSpecialCond(fb, Spec_type, Spec_direction, fs(trigger_price), fs(stop_loss_price), fs(pursuit_price), fs(step), fs(target_profit_price), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"Spec_type\":" << "\"" << EnumNameSpecialType(Spec_type) << "\"" << ",";
		ss << "\"Spec_direction\":" << "\"" << EnumNameEntrust_mode(Spec_direction) << "\"" << ",";
		if (!b_simplify || (b_simplify && trigger_price.size())) ss << "\"trigger_price\":" << "\"" << trigger_price << "\"" << ",";
		if (!b_simplify || (b_simplify && stop_loss_price.size())) ss << "\"stop_loss_price\":" << "\"" << stop_loss_price << "\"" << ",";
		if (!b_simplify || (b_simplify && pursuit_price.size())) ss << "\"pursuit_price\":" << "\"" << pursuit_price << "\"" << ",";
		if (!b_simplify || (b_simplify && step.size())) ss << "\"step\":" << "\"" << step << "\"" << ",";
		if (!b_simplify || (b_simplify && target_profit_price.size())) ss << "\"target_profit_price\":" << "\"" << target_profit_price << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, SpecialCond &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Entrust
{
	Account acc;
	mm::Market market;
	std::string symbol;
	std::string order_time;
	mm::Currency ccy;
	mm::Entrust_mode direction;
	mm::Price_mode price_mode;
	mm::Deal_mode deal_mode;
	std::string price;
	std::string qty;
	std::string deal_qty;
	std::string os_qty;
	std::string entrust_no;
	std::string related_entrust_no;
	mm::Entrust_status status;
	uint16_t loan_ratio;
	mm::TerminalType input_channel;
	std::vector<Pair> extras;
	Deal_summary deal;
	Fee fee;
	SpecialCond spec_cond;
	std::string update_time;
	bool T_1;
	std::string sub_status;

	Entrust()
	{
		market = mm::Market_NONE;
		ccy = mm::Currency_NONE;
		direction = mm::Entrust_mode_NONE;
		price_mode = mm::Price_mode_NONE;
		deal_mode = mm::Deal_mode_NONE;
		status = mm::Entrust_status_NONE;
		loan_ratio = 0;
		input_channel = mm::TerminalType_NONE;
	}
	Entrust(const Entrust &src)
	{
		acc = src.acc;
		market = src.market;
		symbol = src.symbol;
		order_time = src.order_time;
		ccy = src.ccy;
		direction = src.direction;
		price_mode = src.price_mode;
		deal_mode = src.deal_mode;
		price = src.price;
		qty = src.qty;
		deal_qty = src.deal_qty;
		os_qty = src.os_qty;
		entrust_no = src.entrust_no;
		related_entrust_no = src.related_entrust_no;
		status = src.status;
		loan_ratio = src.loan_ratio;
		input_channel = src.input_channel;
		extras = src.extras;
		deal = src.deal;
		fee = src.fee;
		spec_cond = src.spec_cond;
		update_time = src.update_time;
		T_1 = src.T_1;
		sub_status = src.sub_status;
	}
	Entrust(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Entrust();
			return;
		}
		READ_FBS(fbs_obj, mm::Entrust, ptr_data, n_len);
		*this = Entrust(fbs_obj);
	}
	Entrust(const mm::Entrust *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		order_time = GX3(ptr_fbs, order_time(), c_str(), "");
		ccy = ptr_fbs->ccy();
		direction = ptr_fbs->direction();
		price_mode = ptr_fbs->price_mode();
		deal_mode = ptr_fbs->deal_mode();
		price = GX3(ptr_fbs, price(), c_str(), "");
		qty = GX3(ptr_fbs, qty(), c_str(), "");
		deal_qty = GX3(ptr_fbs, deal_qty(), c_str(), "");
		os_qty = GX3(ptr_fbs, os_qty(), c_str(), "");
		entrust_no = GX3(ptr_fbs, entrust_no(), c_str(), "");
		related_entrust_no = GX3(ptr_fbs, related_entrust_no(), c_str(), "");
		status = ptr_fbs->status();
		loan_ratio = ptr_fbs->loan_ratio();
		input_channel = ptr_fbs->input_channel();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		deal = ptr_fbs->deal();
		fee = ptr_fbs->fee();
		spec_cond = ptr_fbs->spec_cond();
		update_time = GX3(ptr_fbs, update_time(), c_str(), "");
		T_1 = ptr_fbs->T_1();
		sub_status = GX3(ptr_fbs, sub_status(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Entrust>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Entrust> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateEntrust(fb, acc.to_fbs(fb), market, fs(symbol), fs(order_time), ccy, direction, price_mode, deal_mode, fs(price), fs(qty), fs(deal_qty), fs(os_qty), fs(entrust_no), fs(related_entrust_no), status, loan_ratio, input_channel, build_vct<Pair, mm::Pair>(fb, extras), deal.to_fbs(fb), fee.to_fbs(fb), spec_cond.to_fbs(fb), fs(update_time), T_1, fs(sub_status));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && order_time.size())) ss << "\"order_time\":" << "\"" << order_time << "\"" << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		ss << "\"direction\":" << "\"" << EnumNameEntrust_mode(direction) << "\"" << ",";
		ss << "\"price_mode\":" << "\"" << EnumNamePrice_mode(price_mode) << "\"" << ",";
		ss << "\"deal_mode\":" << "\"" << EnumNameDeal_mode(deal_mode) << "\"" << ",";
		if (!b_simplify || (b_simplify && price.size())) ss << "\"price\":" << "\"" << price << "\"" << ",";
		if (!b_simplify || (b_simplify && qty.size())) ss << "\"qty\":" << "\"" << qty << "\"" << ",";
		if (!b_simplify || (b_simplify && deal_qty.size())) ss << "\"deal_qty\":" << "\"" << deal_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && os_qty.size())) ss << "\"os_qty\":" << "\"" << os_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && entrust_no.size())) ss << "\"entrust_no\":" << "\"" << entrust_no << "\"" << ",";
		if (!b_simplify || (b_simplify && related_entrust_no.size())) ss << "\"related_entrust_no\":" << "\"" << related_entrust_no << "\"" << ",";
		ss << "\"status\":" << "\"" << EnumNameEntrust_status(status) << "\"" << ",";
		ss << "\"loan_ratio\":" << (uint16_t)loan_ratio << ",";
		ss << "\"input_channel\":" << "\"" << EnumNameTerminalType(input_channel) << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss << "\"deal\":" << deal.to_json(b_simplify) << ",";
		ss << "\"fee\":" << fee.to_json(b_simplify) << ",";
		ss << "\"spec_cond\":" << spec_cond.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && update_time.size())) ss << "\"update_time\":" << "\"" << update_time << "\"" << ",";
		ss << "\"T_1\":" << "\"" << (bool)T_1 << "\"" << ",";
		if (!b_simplify || (b_simplify && sub_status.size())) ss << "\"sub_status\":" << "\"" << sub_status << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Entrust &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Login
{
	Account acc;
	std::string pwd;
	std::string device_code;
	std::string device_name;
	std::string otp;
	mm::Lang language;
	std::string ip;
	mm::TerminalType terminal;
	std::string encrypt_key;
	uint push_serialno;
	std::vector<Pair> extras;

	Login()
	{
		language = mm::Lang_ENG;
		terminal = mm::TerminalType_NONE;
		push_serialno = 0;
	}
	Login(const Login &src)
	{
		acc = src.acc;
		pwd = src.pwd;
		device_code = src.device_code;
		device_name = src.device_name;
		otp = src.otp;
		language = src.language;
		ip = src.ip;
		terminal = src.terminal;
		encrypt_key = src.encrypt_key;
		push_serialno = src.push_serialno;
		extras = src.extras;
	}
	Login(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Login();
			return;
		}
		READ_FBS(fbs_obj, mm::Login, ptr_data, n_len);
		*this = Login(fbs_obj);
	}
	Login(const mm::Login *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		pwd = GX3(ptr_fbs, pwd(), c_str(), "");
		device_code = GX3(ptr_fbs, device_code(), c_str(), "");
		device_name = GX3(ptr_fbs, device_name(), c_str(), "");
		otp = GX3(ptr_fbs, otp(), c_str(), "");
		language = ptr_fbs->language();
		ip = GX3(ptr_fbs, ip(), c_str(), "");
		terminal = ptr_fbs->terminal();
		encrypt_key = GX3(ptr_fbs, encrypt_key(), c_str(), "");
		push_serialno = ptr_fbs->push_serialno();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Login>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Login> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateLogin(fb, acc.to_fbs(fb), fs(pwd), fs(device_code), fs(device_name), fs(otp), language, fs(ip), terminal, fs(encrypt_key), push_serialno, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && pwd.size())) ss << "\"pwd\":" << "\"" << pwd << "\"" << ",";
		if (!b_simplify || (b_simplify && device_code.size())) ss << "\"device_code\":" << "\"" << device_code << "\"" << ",";
		if (!b_simplify || (b_simplify && device_name.size())) ss << "\"device_name\":" << "\"" << device_name << "\"" << ",";
		if (!b_simplify || (b_simplify && otp.size())) ss << "\"otp\":" << "\"" << otp << "\"" << ",";
		ss << "\"language\":" << "\"" << EnumNameLang(language) << "\"" << ",";
		if (!b_simplify || (b_simplify && ip.size())) ss << "\"ip\":" << "\"" << ip << "\"" << ",";
		ss << "\"terminal\":" << "\"" << EnumNameTerminalType(terminal) << "\"" << ",";
		if (!b_simplify || (b_simplify && encrypt_key.size())) ss << "\"encrypt_key\":" << "\"" << encrypt_key << "\"" << ",";
		ss << "\"push_serialno\":" << (uint)push_serialno << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Login &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Login_rsp
{
	Result rsp;
	Account acc;
	std::string name;
	mm::Status status;
	std::string last_login_time;
	std::string encrypt_key;
	std::string session;
	std::vector<Pair> extras;

	Login_rsp()
	{
		status = mm::Status_NONE;
	}
	Login_rsp(const Login_rsp &src)
	{
		rsp = src.rsp;
		acc = src.acc;
		name = src.name;
		status = src.status;
		last_login_time = src.last_login_time;
		encrypt_key = src.encrypt_key;
		session = src.session;
		extras = src.extras;
	}
	Login_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Login_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Login_rsp, ptr_data, n_len);
		*this = Login_rsp(fbs_obj);
	}
	Login_rsp(const mm::Login_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		rsp = ptr_fbs->rsp();
		acc = ptr_fbs->acc();
		name = GX3(ptr_fbs, name(), c_str(), "");
		status = ptr_fbs->status();
		last_login_time = GX3(ptr_fbs, last_login_time(), c_str(), "");
		encrypt_key = GX3(ptr_fbs, encrypt_key(), c_str(), "");
		session = GX3(ptr_fbs, session(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Login_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Login_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateLogin_rsp(fb, rsp.to_fbs(fb), acc.to_fbs(fb), fs(name), status, fs(last_login_time), fs(encrypt_key), fs(session), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"rsp\":" << rsp.to_json(b_simplify) << ",";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && name.size())) ss << "\"name\":" << "\"" << name << "\"" << ",";
		ss << "\"status\":" << "\"" << EnumNameStatus(status) << "\"" << ",";
		if (!b_simplify || (b_simplify && last_login_time.size())) ss << "\"last_login_time\":" << "\"" << last_login_time << "\"" << ",";
		if (!b_simplify || (b_simplify && encrypt_key.size())) ss << "\"encrypt_key\":" << "\"" << encrypt_key << "\"" << ",";
		if (!b_simplify || (b_simplify && session.size())) ss << "\"session\":" << "\"" << session << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Login_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct ChangePwd
{
	Account acc;
	std::string pwd;
	std::string newpwd;
	std::string otp;
	std::vector<Pair> extras;

	ChangePwd()
	{
	}
	ChangePwd(const ChangePwd &src)
	{
		acc = src.acc;
		pwd = src.pwd;
		newpwd = src.newpwd;
		otp = src.otp;
		extras = src.extras;
	}
	ChangePwd(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = ChangePwd();
			return;
		}
		READ_FBS(fbs_obj, mm::ChangePwd, ptr_data, n_len);
		*this = ChangePwd(fbs_obj);
	}
	ChangePwd(const mm::ChangePwd *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		pwd = GX3(ptr_fbs, pwd(), c_str(), "");
		newpwd = GX3(ptr_fbs, newpwd(), c_str(), "");
		otp = GX3(ptr_fbs, otp(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::ChangePwd>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::ChangePwd> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateChangePwd(fb, acc.to_fbs(fb), fs(pwd), fs(newpwd), fs(otp), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && pwd.size())) ss << "\"pwd\":" << "\"" << pwd << "\"" << ",";
		if (!b_simplify || (b_simplify && newpwd.size())) ss << "\"newpwd\":" << "\"" << newpwd << "\"" << ",";
		if (!b_simplify || (b_simplify && otp.size())) ss << "\"otp\":" << "\"" << otp << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, ChangePwd &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct QueryConsign
{
	Account acc;
	Query_page page;
	mm::Market market;
	std::string symbol;
	std::string begin_date;
	std::string end_date;
	std::vector<Pair> extras;

	QueryConsign()
	{
		market = mm::Market_NONE;
	}
	QueryConsign(const QueryConsign &src)
	{
		acc = src.acc;
		page = src.page;
		market = src.market;
		symbol = src.symbol;
		begin_date = src.begin_date;
		end_date = src.end_date;
		extras = src.extras;
	}
	QueryConsign(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = QueryConsign();
			return;
		}
		READ_FBS(fbs_obj, mm::QueryConsign, ptr_data, n_len);
		*this = QueryConsign(fbs_obj);
	}
	QueryConsign(const mm::QueryConsign *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		begin_date = GX3(ptr_fbs, begin_date(), c_str(), "");
		end_date = GX3(ptr_fbs, end_date(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::QueryConsign>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::QueryConsign> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQueryConsign(fb, acc.to_fbs(fb), page.to_fbs(fb), market, fs(symbol), fs(begin_date), fs(end_date), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && begin_date.size())) ss << "\"begin_date\":" << "\"" << begin_date << "\"" << ",";
		if (!b_simplify || (b_simplify && end_date.size())) ss << "\"end_date\":" << "\"" << end_date << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, QueryConsign &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct QueryConsign_rsp
{
	Result rsp;
	Query_page page;
	std::vector<Entrust> orders;
	std::vector<Pair> extras;
	Account acc;

	QueryConsign_rsp()
	{
	}
	QueryConsign_rsp(const QueryConsign_rsp &src)
	{
		rsp = src.rsp;
		page = src.page;
		orders = src.orders;
		extras = src.extras;
		acc = src.acc;
	}
	QueryConsign_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = QueryConsign_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::QueryConsign_rsp, ptr_data, n_len);
		*this = QueryConsign_rsp(fbs_obj);
	}
	QueryConsign_rsp(const mm::QueryConsign_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		rsp = ptr_fbs->rsp();
		page = ptr_fbs->page();
		orders = read_vct<Entrust, mm::Entrust>(ptr_fbs->orders());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		acc = ptr_fbs->acc();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::QueryConsign_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::QueryConsign_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQueryConsign_rsp(fb, rsp.to_fbs(fb), page.to_fbs(fb), build_vct<Entrust, mm::Entrust>(fb, orders), build_vct<Pair, mm::Pair>(fb, extras), acc.to_fbs(fb));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"rsp\":" << rsp.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && orders.size())) ss << "\"orders\":" << read_vct_2_json<Entrust>(orders) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, QueryConsign_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_hold
{
	Account acc;
	Query_page page;
	mm::Market market;
	std::vector<Pair> extras;

	Query_hold()
	{
		market = mm::Market_NONE;
	}
	Query_hold(const Query_hold &src)
	{
		acc = src.acc;
		page = src.page;
		market = src.market;
		extras = src.extras;
	}
	Query_hold(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_hold();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_hold, ptr_data, n_len);
		*this = Query_hold(fbs_obj);
	}
	Query_hold(const mm::Query_hold *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		market = ptr_fbs->market();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_hold>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_hold> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_hold(fb, acc.to_fbs(fb), page.to_fbs(fb), market, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_hold &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_hold_rsp
{
	Result res;
	Query_page page;
	std::vector<Hold> holds;
	std::vector<Pair> extras;
	Account acc;

	Query_hold_rsp()
	{
	}
	Query_hold_rsp(const Query_hold_rsp &src)
	{
		res = src.res;
		page = src.page;
		holds = src.holds;
		extras = src.extras;
		acc = src.acc;
	}
	Query_hold_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_hold_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_hold_rsp, ptr_data, n_len);
		*this = Query_hold_rsp(fbs_obj);
	}
	Query_hold_rsp(const mm::Query_hold_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		holds = read_vct<Hold, mm::Hold>(ptr_fbs->holds());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		acc = ptr_fbs->acc();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_hold_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_hold_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_hold_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct<Hold, mm::Hold>(fb, holds), build_vct<Pair, mm::Pair>(fb, extras), acc.to_fbs(fb));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && holds.size())) ss << "\"holds\":" << read_vct_2_json<Hold>(holds) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_hold_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_fund
{
	Account acc;
	mm::Currency ccy;
	std::vector<Pair> extras;

	Query_fund()
	{
		ccy = mm::Currency_NONE;
	}
	Query_fund(const Query_fund &src)
	{
		acc = src.acc;
		ccy = src.ccy;
		extras = src.extras;
	}
	Query_fund(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_fund();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_fund, ptr_data, n_len);
		*this = Query_fund(fbs_obj);
	}
	Query_fund(const mm::Query_fund *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		ccy = ptr_fbs->ccy();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_fund>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_fund> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_fund(fb, acc.to_fbs(fb), ccy, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_fund &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_fund_rsp
{
	Result res;
	std::vector<Fund> items;
	std::vector<Pair> extras;
	Account acc;

	Query_fund_rsp()
	{
	}
	Query_fund_rsp(const Query_fund_rsp &src)
	{
		res = src.res;
		items = src.items;
		extras = src.extras;
		acc = src.acc;
	}
	Query_fund_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_fund_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_fund_rsp, ptr_data, n_len);
		*this = Query_fund_rsp(fbs_obj);
	}
	Query_fund_rsp(const mm::Query_fund_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		items = read_vct<Fund, mm::Fund>(ptr_fbs->items());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		acc = ptr_fbs->acc();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_fund_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_fund_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_fund_rsp(fb, res.to_fbs(fb), build_vct<Fund, mm::Fund>(fb, items), build_vct<Pair, mm::Pair>(fb, extras), acc.to_fbs(fb));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<Fund>(items) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_fund_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct QueryBargain
{
	Account acc;
	Query_page page;
	mm::Market market;
	std::string symbol;
	std::string entrust_no;
	std::string begin_date;
	std::string end_date;
	std::vector<Pair> extras;

	QueryBargain()
	{
		market = mm::Market_NONE;
	}
	QueryBargain(const QueryBargain &src)
	{
		acc = src.acc;
		page = src.page;
		market = src.market;
		symbol = src.symbol;
		entrust_no = src.entrust_no;
		begin_date = src.begin_date;
		end_date = src.end_date;
		extras = src.extras;
	}
	QueryBargain(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = QueryBargain();
			return;
		}
		READ_FBS(fbs_obj, mm::QueryBargain, ptr_data, n_len);
		*this = QueryBargain(fbs_obj);
	}
	QueryBargain(const mm::QueryBargain *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		entrust_no = GX3(ptr_fbs, entrust_no(), c_str(), "");
		begin_date = GX3(ptr_fbs, begin_date(), c_str(), "");
		end_date = GX3(ptr_fbs, end_date(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::QueryBargain>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::QueryBargain> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQueryBargain(fb, acc.to_fbs(fb), page.to_fbs(fb), market, fs(symbol), fs(entrust_no), fs(begin_date), fs(end_date), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && entrust_no.size())) ss << "\"entrust_no\":" << "\"" << entrust_no << "\"" << ",";
		if (!b_simplify || (b_simplify && begin_date.size())) ss << "\"begin_date\":" << "\"" << begin_date << "\"" << ",";
		if (!b_simplify || (b_simplify && end_date.size())) ss << "\"end_date\":" << "\"" << end_date << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, QueryBargain &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct QueryBargain_rsp
{
	Result res;
	Query_page page;
	std::vector<Deal_detail> deals;
	std::vector<Pair> extras;
	Account acc;

	QueryBargain_rsp()
	{
	}
	QueryBargain_rsp(const QueryBargain_rsp &src)
	{
		res = src.res;
		page = src.page;
		deals = src.deals;
		extras = src.extras;
		acc = src.acc;
	}
	QueryBargain_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = QueryBargain_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::QueryBargain_rsp, ptr_data, n_len);
		*this = QueryBargain_rsp(fbs_obj);
	}
	QueryBargain_rsp(const mm::QueryBargain_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		deals = read_vct<Deal_detail, mm::Deal_detail>(ptr_fbs->deals());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		acc = ptr_fbs->acc();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::QueryBargain_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::QueryBargain_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQueryBargain_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct<Deal_detail, mm::Deal_detail>(fb, deals), build_vct<Pair, mm::Pair>(fb, extras), acc.to_fbs(fb));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && deals.size())) ss << "\"deals\":" << read_vct_2_json<Deal_detail>(deals) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, QueryBargain_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct QueryCapital
{
	Account acc;
	mm::Currency ccy;
	Query_page page;
	std::string date_from;
	std::string date_to;
	std::vector<Pair> extras;

	QueryCapital()
	{
		ccy = mm::Currency_NONE;
	}
	QueryCapital(const QueryCapital &src)
	{
		acc = src.acc;
		ccy = src.ccy;
		page = src.page;
		date_from = src.date_from;
		date_to = src.date_to;
		extras = src.extras;
	}
	QueryCapital(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = QueryCapital();
			return;
		}
		READ_FBS(fbs_obj, mm::QueryCapital, ptr_data, n_len);
		*this = QueryCapital(fbs_obj);
	}
	QueryCapital(const mm::QueryCapital *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		ccy = ptr_fbs->ccy();
		page = ptr_fbs->page();
		date_from = GX3(ptr_fbs, date_from(), c_str(), "");
		date_to = GX3(ptr_fbs, date_to(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::QueryCapital>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::QueryCapital> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQueryCapital(fb, acc.to_fbs(fb), ccy, page.to_fbs(fb), fs(date_from), fs(date_to), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && date_from.size())) ss << "\"date_from\":" << "\"" << date_from << "\"" << ",";
		if (!b_simplify || (b_simplify && date_to.size())) ss << "\"date_to\":" << "\"" << date_to << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, QueryCapital &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_capital_rsp
{
	Result res;
	Query_page page;
	std::vector<Capital_detail> items;
	std::vector<Pair> extras;

	Query_capital_rsp()
	{
	}
	Query_capital_rsp(const Query_capital_rsp &src)
	{
		res = src.res;
		page = src.page;
		items = src.items;
		extras = src.extras;
	}
	Query_capital_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_capital_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_capital_rsp, ptr_data, n_len);
		*this = Query_capital_rsp(fbs_obj);
	}
	Query_capital_rsp(const mm::Query_capital_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		items = read_vct<Capital_detail, mm::Capital_detail>(ptr_fbs->items());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_capital_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_capital_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_capital_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct<Capital_detail, mm::Capital_detail>(fb, items), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<Capital_detail>(items) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_capital_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct FundTransfer
{
	Account acc;
	mm::Currency ccy;
	Bank bankid;
	std::string sum;
	mm::CashMedia media_type;
	std::string time;
	std::string remark;
	std::vector<Pair> extras;

	FundTransfer()
	{
		ccy = mm::Currency_NONE;
		media_type = mm::CashMedia_NONE;
	}
	FundTransfer(const FundTransfer &src)
	{
		acc = src.acc;
		ccy = src.ccy;
		bankid = src.bankid;
		sum = src.sum;
		media_type = src.media_type;
		time = src.time;
		remark = src.remark;
		extras = src.extras;
	}
	FundTransfer(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = FundTransfer();
			return;
		}
		READ_FBS(fbs_obj, mm::FundTransfer, ptr_data, n_len);
		*this = FundTransfer(fbs_obj);
	}
	FundTransfer(const mm::FundTransfer *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		ccy = ptr_fbs->ccy();
		bankid = ptr_fbs->bankid();
		sum = GX3(ptr_fbs, sum(), c_str(), "");
		media_type = ptr_fbs->media_type();
		time = GX3(ptr_fbs, time(), c_str(), "");
		remark = GX3(ptr_fbs, remark(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::FundTransfer>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::FundTransfer> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateFundTransfer(fb, acc.to_fbs(fb), ccy, bankid.to_fbs(fb), fs(sum), media_type, fs(time), fs(remark), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		ss << "\"bankid\":" << bankid.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && sum.size())) ss << "\"sum\":" << "\"" << sum << "\"" << ",";
		ss << "\"media_type\":" << "\"" << EnumNameCashMedia(media_type) << "\"" << ",";
		if (!b_simplify || (b_simplify && time.size())) ss << "\"time\":" << "\"" << time << "\"" << ",";
		if (!b_simplify || (b_simplify && remark.size())) ss << "\"remark\":" << "\"" << remark << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, FundTransfer &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_ftflow
{
	Account acc;
	Query_page page;
	Bank bankid;
	std::string date_from;
	std::string date_to;
	std::vector<Pair> extras;

	Query_ftflow()
	{
	}
	Query_ftflow(const Query_ftflow &src)
	{
		acc = src.acc;
		page = src.page;
		bankid = src.bankid;
		date_from = src.date_from;
		date_to = src.date_to;
		extras = src.extras;
	}
	Query_ftflow(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_ftflow();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_ftflow, ptr_data, n_len);
		*this = Query_ftflow(fbs_obj);
	}
	Query_ftflow(const mm::Query_ftflow *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		bankid = ptr_fbs->bankid();
		date_from = GX3(ptr_fbs, date_from(), c_str(), "");
		date_to = GX3(ptr_fbs, date_to(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_ftflow>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_ftflow> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_ftflow(fb, acc.to_fbs(fb), page.to_fbs(fb), bankid.to_fbs(fb), fs(date_from), fs(date_to), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss << "\"bankid\":" << bankid.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && date_from.size())) ss << "\"date_from\":" << "\"" << date_from << "\"" << ",";
		if (!b_simplify || (b_simplify && date_to.size())) ss << "\"date_to\":" << "\"" << date_to << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_ftflow &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_ftflow_rsp
{
	Result res;
	Query_page page;
	std::vector<FundTransfer> items;
	std::vector<Pair> extras;

	Query_ftflow_rsp()
	{
	}
	Query_ftflow_rsp(const Query_ftflow_rsp &src)
	{
		res = src.res;
		page = src.page;
		items = src.items;
		extras = src.extras;
	}
	Query_ftflow_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_ftflow_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_ftflow_rsp, ptr_data, n_len);
		*this = Query_ftflow_rsp(fbs_obj);
	}
	Query_ftflow_rsp(const mm::Query_ftflow_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		items = read_vct<FundTransfer, mm::FundTransfer>(ptr_fbs->items());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_ftflow_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_ftflow_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_ftflow_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct<FundTransfer, mm::FundTransfer>(fb, items), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<FundTransfer>(items) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_ftflow_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct QueryPosition
{
	Account acc;
	Query_page page;
	mm::Market market;
	std::string symbol;
	std::string date_from;
	std::string date_to;
	std::vector<Pair> extras;

	QueryPosition()
	{
		market = mm::Market_NONE;
	}
	QueryPosition(const QueryPosition &src)
	{
		acc = src.acc;
		page = src.page;
		market = src.market;
		symbol = src.symbol;
		date_from = src.date_from;
		date_to = src.date_to;
		extras = src.extras;
	}
	QueryPosition(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = QueryPosition();
			return;
		}
		READ_FBS(fbs_obj, mm::QueryPosition, ptr_data, n_len);
		*this = QueryPosition(fbs_obj);
	}
	QueryPosition(const mm::QueryPosition *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		date_from = GX3(ptr_fbs, date_from(), c_str(), "");
		date_to = GX3(ptr_fbs, date_to(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::QueryPosition>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::QueryPosition> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQueryPosition(fb, acc.to_fbs(fb), page.to_fbs(fb), market, fs(symbol), fs(date_from), fs(date_to), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && date_from.size())) ss << "\"date_from\":" << "\"" << date_from << "\"" << ",";
		if (!b_simplify || (b_simplify && date_to.size())) ss << "\"date_to\":" << "\"" << date_to << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, QueryPosition &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_position_rsp
{
	Result res;
	Query_page page;
	std::vector<PositionNotify> items;
	std::vector<Pair> extras;

	Query_position_rsp()
	{
	}
	Query_position_rsp(const Query_position_rsp &src)
	{
		res = src.res;
		page = src.page;
		items = src.items;
		extras = src.extras;
	}
	Query_position_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_position_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_position_rsp, ptr_data, n_len);
		*this = Query_position_rsp(fbs_obj);
	}
	Query_position_rsp(const mm::Query_position_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		items = read_vct<PositionNotify, mm::PositionNotify>(ptr_fbs->items());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_position_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_position_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_position_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct<PositionNotify, mm::PositionNotify>(fb, items), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<PositionNotify>(items) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_position_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_settlement
{
	Account acc;
	Query_page page;
	mm::SettleType settlement_type;
	std::string date_from;
	std::string date_to;
	std::vector<Pair> extras;

	Query_settlement()
	{
		settlement_type = mm::SettleType_NONE;
	}
	Query_settlement(const Query_settlement &src)
	{
		acc = src.acc;
		page = src.page;
		settlement_type = src.settlement_type;
		date_from = src.date_from;
		date_to = src.date_to;
		extras = src.extras;
	}
	Query_settlement(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_settlement();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_settlement, ptr_data, n_len);
		*this = Query_settlement(fbs_obj);
	}
	Query_settlement(const mm::Query_settlement *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		settlement_type = ptr_fbs->settlement_type();
		date_from = GX3(ptr_fbs, date_from(), c_str(), "");
		date_to = GX3(ptr_fbs, date_to(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_settlement>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_settlement> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_settlement(fb, acc.to_fbs(fb), page.to_fbs(fb), settlement_type, fs(date_from), fs(date_to), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss << "\"settlement_type\":" << "\"" << EnumNameSettleType(settlement_type) << "\"" << ",";
		if (!b_simplify || (b_simplify && date_from.size())) ss << "\"date_from\":" << "\"" << date_from << "\"" << ",";
		if (!b_simplify || (b_simplify && date_to.size())) ss << "\"date_to\":" << "\"" << date_to << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_settlement &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_settlement_rsp
{
	Result res;
	Query_page page;
	std::vector<std::string> urls;
	std::vector<Pair> extras;

	Query_settlement_rsp()
	{
	}
	Query_settlement_rsp(const Query_settlement_rsp &src)
	{
		res = src.res;
		page = src.page;
		urls = src.urls;
		extras = src.extras;
	}
	Query_settlement_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_settlement_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_settlement_rsp, ptr_data, n_len);
		*this = Query_settlement_rsp(fbs_obj);
	}
	Query_settlement_rsp(const mm::Query_settlement_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		urls = read_vct_str<std::string, flatbuffers::String>(ptr_fbs->urls());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_settlement_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_settlement_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_settlement_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct_str<std::string, flatbuffers::String>(fb, urls), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && urls.size())) ss << "\"urls\":" << read_vct_2_json<std::string>(urls) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_settlement_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_maxbuy
{
	Account acc;
	mm::Market market;
	std::string symbol;
	std::string power;
	std::string price;
	std::vector<Pair> extras;

	Query_maxbuy()
	{
		market = mm::Market_NONE;
	}
	Query_maxbuy(const Query_maxbuy &src)
	{
		acc = src.acc;
		market = src.market;
		symbol = src.symbol;
		power = src.power;
		price = src.price;
		extras = src.extras;
	}
	Query_maxbuy(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_maxbuy();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_maxbuy, ptr_data, n_len);
		*this = Query_maxbuy(fbs_obj);
	}
	Query_maxbuy(const mm::Query_maxbuy *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		power = GX3(ptr_fbs, power(), c_str(), "");
		price = GX3(ptr_fbs, price(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_maxbuy>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_maxbuy> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_maxbuy(fb, acc.to_fbs(fb), market, fs(symbol), fs(power), fs(price), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && power.size())) ss << "\"power\":" << "\"" << power << "\"" << ",";
		if (!b_simplify || (b_simplify && price.size())) ss << "\"price\":" << "\"" << price << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_maxbuy &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_maxbuy_rsp
{
	Result res;
	std::string qty;
	std::vector<Pair> extras;

	Query_maxbuy_rsp()
	{
	}
	Query_maxbuy_rsp(const Query_maxbuy_rsp &src)
	{
		res = src.res;
		qty = src.qty;
		extras = src.extras;
	}
	Query_maxbuy_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_maxbuy_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_maxbuy_rsp, ptr_data, n_len);
		*this = Query_maxbuy_rsp(fbs_obj);
	}
	Query_maxbuy_rsp(const mm::Query_maxbuy_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		qty = GX3(ptr_fbs, qty(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_maxbuy_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_maxbuy_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_maxbuy_rsp(fb, res.to_fbs(fb), fs(qty), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && qty.size())) ss << "\"qty\":" << "\"" << qty << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_maxbuy_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Entrust_rsp
{
	Result res;
	Entrust entrust;
	std::vector<Pair> extras;

	Entrust_rsp()
	{
	}
	Entrust_rsp(const Entrust_rsp &src)
	{
		res = src.res;
		entrust = src.entrust;
		extras = src.extras;
	}
	Entrust_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Entrust_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Entrust_rsp, ptr_data, n_len);
		*this = Entrust_rsp(fbs_obj);
	}
	Entrust_rsp(const mm::Entrust_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		entrust = ptr_fbs->entrust();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Entrust_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Entrust_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateEntrust_rsp(fb, res.to_fbs(fb), entrust.to_fbs(fb), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"entrust\":" << entrust.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Entrust_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct EntrustAll
{
	Account acc;
	mm::Market market;

	EntrustAll()
	{
		market = mm::Market_NONE;
	}
	EntrustAll(const EntrustAll &src)
	{
		acc = src.acc;
		market = src.market;
	}
	EntrustAll(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = EntrustAll();
			return;
		}
		READ_FBS(fbs_obj, mm::EntrustAll, ptr_data, n_len);
		*this = EntrustAll(fbs_obj);
	}
	EntrustAll(const mm::EntrustAll *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		market = ptr_fbs->market();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::EntrustAll>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::EntrustAll> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateEntrustAll(fb, acc.to_fbs(fb), market);
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, EntrustAll &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Exrate
{
	mm::Currency ccy;
	std::string rate;

	Exrate()
	{
		ccy = mm::Currency_NONE;
	}
	Exrate(const Exrate &src)
	{
		ccy = src.ccy;
		rate = src.rate;
	}
	Exrate(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Exrate();
			return;
		}
		READ_FBS(fbs_obj, mm::Exrate, ptr_data, n_len);
		*this = Exrate(fbs_obj);
	}
	Exrate(const mm::Exrate *ptr_fbs)
	{
		if (!ptr_fbs) return;
		ccy = ptr_fbs->ccy();
		rate = GX3(ptr_fbs, rate(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Exrate>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Exrate> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateExrate(fb, ccy, fs(rate));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && rate.size())) ss << "\"rate\":" << "\"" << rate << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Exrate &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Exrates
{
	mm::Currency ccy;
	std::vector<Exrate> rates;

	Exrates()
	{
		ccy = mm::Currency_NONE;
	}
	Exrates(const Exrates &src)
	{
		ccy = src.ccy;
		rates = src.rates;
	}
	Exrates(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Exrates();
			return;
		}
		READ_FBS(fbs_obj, mm::Exrates, ptr_data, n_len);
		*this = Exrates(fbs_obj);
	}
	Exrates(const mm::Exrates *ptr_fbs)
	{
		if (!ptr_fbs) return;
		ccy = ptr_fbs->ccy();
		rates = read_vct<Exrate, mm::Exrate>(ptr_fbs->rates());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Exrates>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Exrates> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateExrates(fb, ccy, build_vct<Exrate, mm::Exrate>(fb, rates));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && rates.size())) ss << "\"rates\":" << read_vct_2_json<Exrate>(rates) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Exrates &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Product
{
	mm::Market market;
	std::string symbol;
	mm::ProductType product_type;
	mm::ProductSubType product_sub_type;
	std::string short_name;
	std::string name;
	mm::Status status;
	std::string lot_size;
	std::string ps_code;
	ulong contract_size;
	std::string product_group;
	std::string contract_month;
	std::string expire_date;
	std::string last_trading_date;
	mm::Currency ccy;
	std::string strike_price;
	ulong price_factor;
	ulong price_denominator;
	uint16_t loan_percent;
	uint8_t disallow_buy;
	uint8_t disallow_sell;
	uint8_t disallow_shortsell;
	std::vector<Pair> extras;
	ulong expire_notify_day;
	std::string im_ratio;
	std::string mm_ratio;
	std::string mmargin;
	mm::MarginMode margin_mode;

	Product()
	{
		market = mm::Market_NONE;
		product_type = mm::ProductType_NONE;
		product_sub_type = mm::ProductSubType_NONE;
		status = mm::Status_NONE;
		contract_size = 0;
		ccy = mm::Currency_NONE;
		price_factor = 0;
		price_denominator = 0;
		loan_percent = 0;
		disallow_buy = 0;
		disallow_sell = 0;
		disallow_shortsell = 0;
		expire_notify_day = 0;
		margin_mode = mm::MarginMode_SPAN;
	}
	Product(const Product &src)
	{
		market = src.market;
		symbol = src.symbol;
		product_type = src.product_type;
		product_sub_type = src.product_sub_type;
		short_name = src.short_name;
		name = src.name;
		status = src.status;
		lot_size = src.lot_size;
		ps_code = src.ps_code;
		contract_size = src.contract_size;
		product_group = src.product_group;
		contract_month = src.contract_month;
		expire_date = src.expire_date;
		last_trading_date = src.last_trading_date;
		ccy = src.ccy;
		strike_price = src.strike_price;
		price_factor = src.price_factor;
		price_denominator = src.price_denominator;
		loan_percent = src.loan_percent;
		disallow_buy = src.disallow_buy;
		disallow_sell = src.disallow_sell;
		disallow_shortsell = src.disallow_shortsell;
		extras = src.extras;
		expire_notify_day = src.expire_notify_day;
		im_ratio = src.im_ratio;
		mm_ratio = src.mm_ratio;
		mmargin = src.mmargin;
		margin_mode = src.margin_mode;
	}
	Product(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Product();
			return;
		}
		READ_FBS(fbs_obj, mm::Product, ptr_data, n_len);
		*this = Product(fbs_obj);
	}
	Product(const mm::Product *ptr_fbs)
	{
		if (!ptr_fbs) return;
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		product_type = ptr_fbs->product_type();
		product_sub_type = ptr_fbs->product_sub_type();
		short_name = GX3(ptr_fbs, short_name(), c_str(), "");
		name = GX3(ptr_fbs, name(), c_str(), "");
		status = ptr_fbs->status();
		lot_size = GX3(ptr_fbs, lot_size(), c_str(), "");
		ps_code = GX3(ptr_fbs, ps_code(), c_str(), "");
		contract_size = ptr_fbs->contract_size();
		product_group = GX3(ptr_fbs, product_group(), c_str(), "");
		contract_month = GX3(ptr_fbs, contract_month(), c_str(), "");
		expire_date = GX3(ptr_fbs, expire_date(), c_str(), "");
		last_trading_date = GX3(ptr_fbs, last_trading_date(), c_str(), "");
		ccy = ptr_fbs->ccy();
		strike_price = GX3(ptr_fbs, strike_price(), c_str(), "");
		price_factor = ptr_fbs->price_factor();
		price_denominator = ptr_fbs->price_denominator();
		loan_percent = ptr_fbs->loan_percent();
		disallow_buy = ptr_fbs->disallow_buy();
		disallow_sell = ptr_fbs->disallow_sell();
		disallow_shortsell = ptr_fbs->disallow_shortsell();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		expire_notify_day = ptr_fbs->expire_notify_day();
		im_ratio = GX3(ptr_fbs, im_ratio(), c_str(), "");
		mm_ratio = GX3(ptr_fbs, mm_ratio(), c_str(), "");
		mmargin = GX3(ptr_fbs, mmargin(), c_str(), "");
		margin_mode = ptr_fbs->margin_mode();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Product>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Product> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateProduct(fb, market, fs(symbol), product_type, product_sub_type, fs(short_name), fs(name), status, fs(lot_size), fs(ps_code), contract_size, fs(product_group), fs(contract_month), fs(expire_date), fs(last_trading_date), ccy, fs(strike_price), price_factor, price_denominator, loan_percent, disallow_buy, disallow_sell, disallow_shortsell, build_vct<Pair, mm::Pair>(fb, extras), expire_notify_day, fs(im_ratio), fs(mm_ratio), fs(mmargin), margin_mode);
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		ss << "\"product_type\":" << "\"" << EnumNameProductType(product_type) << "\"" << ",";
		ss << "\"product_sub_type\":" << "\"" << EnumNameProductSubType(product_sub_type) << "\"" << ",";
		if (!b_simplify || (b_simplify && short_name.size())) ss << "\"short_name\":" << "\"" << short_name << "\"" << ",";
		if (!b_simplify || (b_simplify && name.size())) ss << "\"name\":" << "\"" << name << "\"" << ",";
		ss << "\"status\":" << "\"" << EnumNameStatus(status) << "\"" << ",";
		if (!b_simplify || (b_simplify && lot_size.size())) ss << "\"lot_size\":" << "\"" << lot_size << "\"" << ",";
		if (!b_simplify || (b_simplify && ps_code.size())) ss << "\"ps_code\":" << "\"" << ps_code << "\"" << ",";
		ss << "\"contract_size\":" << (ulong)contract_size << ",";
		if (!b_simplify || (b_simplify && product_group.size())) ss << "\"product_group\":" << "\"" << product_group << "\"" << ",";
		if (!b_simplify || (b_simplify && contract_month.size())) ss << "\"contract_month\":" << "\"" << contract_month << "\"" << ",";
		if (!b_simplify || (b_simplify && expire_date.size())) ss << "\"expire_date\":" << "\"" << expire_date << "\"" << ",";
		if (!b_simplify || (b_simplify && last_trading_date.size())) ss << "\"last_trading_date\":" << "\"" << last_trading_date << "\"" << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && strike_price.size())) ss << "\"strike_price\":" << "\"" << strike_price << "\"" << ",";
		ss << "\"price_factor\":" << (ulong)price_factor << ",";
		ss << "\"price_denominator\":" << (ulong)price_denominator << ",";
		ss << "\"loan_percent\":" << (uint16_t)loan_percent << ",";
		ss << "\"disallow_buy\":" << (int)disallow_buy << ",";
		ss << "\"disallow_sell\":" << (int)disallow_sell << ",";
		ss << "\"disallow_shortsell\":" << (int)disallow_shortsell << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss << "\"expire_notify_day\":" << (ulong)expire_notify_day << ",";
		if (!b_simplify || (b_simplify && im_ratio.size())) ss << "\"im_ratio\":" << "\"" << im_ratio << "\"" << ",";
		if (!b_simplify || (b_simplify && mm_ratio.size())) ss << "\"mm_ratio\":" << "\"" << mm_ratio << "\"" << ",";
		if (!b_simplify || (b_simplify && mmargin.size())) ss << "\"mmargin\":" << "\"" << mmargin << "\"" << ",";
		ss << "\"margin_mode\":" << "\"" << EnumNameMarginMode(margin_mode) << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Product &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Product_rsp
{
	Result res;
	Product product;

	Product_rsp()
	{
	}
	Product_rsp(const Product_rsp &src)
	{
		res = src.res;
		product = src.product;
	}
	Product_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Product_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Product_rsp, ptr_data, n_len);
		*this = Product_rsp(fbs_obj);
	}
	Product_rsp(const mm::Product_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		product = ptr_fbs->product();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Product_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Product_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateProduct_rsp(fb, res.to_fbs(fb), product.to_fbs(fb));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"product\":" << product.to_json(b_simplify) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Product_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_products
{
	Account acc;
	Query_page page;

	Query_products()
	{
	}
	Query_products(const Query_products &src)
	{
		acc = src.acc;
		page = src.page;
	}
	Query_products(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_products();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_products, ptr_data, n_len);
		*this = Query_products(fbs_obj);
	}
	Query_products(const mm::Query_products *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_products>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_products> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_products(fb, acc.to_fbs(fb), page.to_fbs(fb));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_products &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_products_rsp
{
	Result rsp;
	Account acc;
	Query_page page;
	std::vector<Product> items;
	std::vector<Pair> extras;

	Query_products_rsp()
	{
	}
	Query_products_rsp(const Query_products_rsp &src)
	{
		rsp = src.rsp;
		acc = src.acc;
		page = src.page;
		items = src.items;
		extras = src.extras;
	}
	Query_products_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_products_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_products_rsp, ptr_data, n_len);
		*this = Query_products_rsp(fbs_obj);
	}
	Query_products_rsp(const mm::Query_products_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		rsp = ptr_fbs->rsp();
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		items = read_vct<Product, mm::Product>(ptr_fbs->items());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_products_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_products_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_products_rsp(fb, rsp.to_fbs(fb), acc.to_fbs(fb), page.to_fbs(fb), build_vct<Product, mm::Product>(fb, items), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"rsp\":" << rsp.to_json(b_simplify) << ",";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<Product>(items) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_products_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct MarginScalingClassDetail
{
	std::string time_interval;
	std::vector<std::string> product_groups;
	std::string scaling_ratio;

	MarginScalingClassDetail()
	{
	}
	MarginScalingClassDetail(const MarginScalingClassDetail &src)
	{
		time_interval = src.time_interval;
		product_groups = src.product_groups;
		scaling_ratio = src.scaling_ratio;
	}
	MarginScalingClassDetail(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = MarginScalingClassDetail();
			return;
		}
		READ_FBS(fbs_obj, mm::MarginScalingClassDetail, ptr_data, n_len);
		*this = MarginScalingClassDetail(fbs_obj);
	}
	MarginScalingClassDetail(const mm::MarginScalingClassDetail *ptr_fbs)
	{
		if (!ptr_fbs) return;
		time_interval = GX3(ptr_fbs, time_interval(), c_str(), "");
		product_groups = read_vct_str<std::string, flatbuffers::String>(ptr_fbs->product_groups());
		scaling_ratio = GX3(ptr_fbs, scaling_ratio(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::MarginScalingClassDetail>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::MarginScalingClassDetail> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateMarginScalingClassDetail(fb, fs(time_interval), build_vct_str<std::string, flatbuffers::String>(fb, product_groups), fs(scaling_ratio));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && time_interval.size())) ss << "\"time_interval\":" << "\"" << time_interval << "\"" << ",";
		if (!b_simplify || (b_simplify && product_groups.size())) ss << "\"product_groups\":" << read_vct_2_json<std::string>(product_groups) << ",";
		if (!b_simplify || (b_simplify && scaling_ratio.size())) ss << "\"scaling_ratio\":" << "\"" << scaling_ratio << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, MarginScalingClassDetail &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct MarginScalingClass
{
	std::string code;
	std::vector<MarginScalingClassDetail> details;

	MarginScalingClass()
	{
	}
	MarginScalingClass(const MarginScalingClass &src)
	{
		code = src.code;
		details = src.details;
	}
	MarginScalingClass(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = MarginScalingClass();
			return;
		}
		READ_FBS(fbs_obj, mm::MarginScalingClass, ptr_data, n_len);
		*this = MarginScalingClass(fbs_obj);
	}
	MarginScalingClass(const mm::MarginScalingClass *ptr_fbs)
	{
		if (!ptr_fbs) return;
		code = GX3(ptr_fbs, code(), c_str(), "");
		details = read_vct<MarginScalingClassDetail, mm::MarginScalingClassDetail>(ptr_fbs->details());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::MarginScalingClass>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::MarginScalingClass> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateMarginScalingClass(fb, fs(code), build_vct<MarginScalingClassDetail, mm::MarginScalingClassDetail>(fb, details));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && code.size())) ss << "\"code\":" << "\"" << code << "\"" << ",";
		if (!b_simplify || (b_simplify && details.size())) ss << "\"details\":" << read_vct_2_json<MarginScalingClassDetail>(details) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, MarginScalingClass &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct AccountInfo
{
	Account acc;
	std::vector<mm::Market> markets;
	std::string eng_name;
	std::string cht_name;
	std::string chs_name;
	std::string fax;
	std::string tel;
	std::string address;
	mm::Status status;
	std::string open_date;
	std::string extra_buying_power;
	std::vector<Bank> bankids;
	std::vector<Pair> extras;
	std::string credit_value;
	std::string margin_scale_code;

	AccountInfo()
	{
		status = mm::Status_NONE;
	}
	AccountInfo(const AccountInfo &src)
	{
		acc = src.acc;
		markets = src.markets;
		eng_name = src.eng_name;
		cht_name = src.cht_name;
		chs_name = src.chs_name;
		fax = src.fax;
		tel = src.tel;
		address = src.address;
		status = src.status;
		open_date = src.open_date;
		extra_buying_power = src.extra_buying_power;
		bankids = src.bankids;
		extras = src.extras;
		credit_value = src.credit_value;
		margin_scale_code = src.margin_scale_code;
	}
	AccountInfo(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = AccountInfo();
			return;
		}
		READ_FBS(fbs_obj, mm::AccountInfo, ptr_data, n_len);
		*this = AccountInfo(fbs_obj);
	}
	AccountInfo(const mm::AccountInfo *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		markets = read_vct_enum<mm::Market, uint8_t>(ptr_fbs->markets());
		eng_name = GX3(ptr_fbs, eng_name(), c_str(), "");
		cht_name = GX3(ptr_fbs, cht_name(), c_str(), "");
		chs_name = GX3(ptr_fbs, chs_name(), c_str(), "");
		fax = GX3(ptr_fbs, fax(), c_str(), "");
		tel = GX3(ptr_fbs, tel(), c_str(), "");
		address = GX3(ptr_fbs, address(), c_str(), "");
		status = ptr_fbs->status();
		open_date = GX3(ptr_fbs, open_date(), c_str(), "");
		extra_buying_power = GX3(ptr_fbs, extra_buying_power(), c_str(), "");
		bankids = read_vct<Bank, mm::Bank>(ptr_fbs->bankids());
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		credit_value = GX3(ptr_fbs, credit_value(), c_str(), "");
		margin_scale_code = GX3(ptr_fbs, margin_scale_code(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::AccountInfo>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::AccountInfo> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateAccountInfo(fb, acc.to_fbs(fb), build_vct_enum<mm::Market, uint8_t>(fb, markets), fs(eng_name), fs(cht_name), fs(chs_name), fs(fax), fs(tel), fs(address), status, fs(open_date), fs(extra_buying_power), build_vct<Bank, mm::Bank>(fb, bankids), build_vct<Pair, mm::Pair>(fb, extras), fs(credit_value), fs(margin_scale_code));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && markets.size())) ss << "\"markets\":" << read_vct_2_json<mm::Market>(markets) << ",";
		if (!b_simplify || (b_simplify && eng_name.size())) ss << "\"eng_name\":" << "\"" << eng_name << "\"" << ",";
		if (!b_simplify || (b_simplify && cht_name.size())) ss << "\"cht_name\":" << "\"" << cht_name << "\"" << ",";
		if (!b_simplify || (b_simplify && chs_name.size())) ss << "\"chs_name\":" << "\"" << chs_name << "\"" << ",";
		if (!b_simplify || (b_simplify && fax.size())) ss << "\"fax\":" << "\"" << fax << "\"" << ",";
		if (!b_simplify || (b_simplify && tel.size())) ss << "\"tel\":" << "\"" << tel << "\"" << ",";
		if (!b_simplify || (b_simplify && address.size())) ss << "\"address\":" << "\"" << address << "\"" << ",";
		ss << "\"status\":" << "\"" << EnumNameStatus(status) << "\"" << ",";
		if (!b_simplify || (b_simplify && open_date.size())) ss << "\"open_date\":" << "\"" << open_date << "\"" << ",";
		if (!b_simplify || (b_simplify && extra_buying_power.size())) ss << "\"extra_buying_power\":" << "\"" << extra_buying_power << "\"" << ",";
		if (!b_simplify || (b_simplify && bankids.size())) ss << "\"bankids\":" << read_vct_2_json<Bank>(bankids) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		if (!b_simplify || (b_simplify && credit_value.size())) ss << "\"credit_value\":" << "\"" << credit_value << "\"" << ",";
		if (!b_simplify || (b_simplify && margin_scale_code.size())) ss << "\"margin_scale_code\":" << "\"" << margin_scale_code << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, AccountInfo &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct UserInfo
{
	Result res;
	std::vector<AccountInfo> items;

	UserInfo()
	{
	}
	UserInfo(const UserInfo &src)
	{
		res = src.res;
		items = src.items;
	}
	UserInfo(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = UserInfo();
			return;
		}
		READ_FBS(fbs_obj, mm::UserInfo, ptr_data, n_len);
		*this = UserInfo(fbs_obj);
	}
	UserInfo(const mm::UserInfo *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		items = read_vct<AccountInfo, mm::AccountInfo>(ptr_fbs->items());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::UserInfo>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::UserInfo> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateUserInfo(fb, res.to_fbs(fb), build_vct<AccountInfo, mm::AccountInfo>(fb, items));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<AccountInfo>(items) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, UserInfo &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Fund
{
	Account acc;
	mm::Currency ccy;
	std::string balance;
	std::string frozen;
	std::string usable;
	std::string withdrawn;
	std::string uncleared;
	std::string credit_value;
	std::string margin_value;
	std::string bod_balance;
	std::string today_cashio;
	std::string unclear;
	std::string basic_margin;
	std::vector<Pair> extras;
	std::string min_margin;

	Fund()
	{
		ccy = mm::Currency_NONE;
	}
	Fund(const Fund &src)
	{
		acc = src.acc;
		ccy = src.ccy;
		balance = src.balance;
		frozen = src.frozen;
		usable = src.usable;
		withdrawn = src.withdrawn;
		uncleared = src.uncleared;
		credit_value = src.credit_value;
		margin_value = src.margin_value;
		bod_balance = src.bod_balance;
		today_cashio = src.today_cashio;
		unclear = src.unclear;
		basic_margin = src.basic_margin;
		extras = src.extras;
		min_margin = src.min_margin;
	}
	Fund(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Fund();
			return;
		}
		READ_FBS(fbs_obj, mm::Fund, ptr_data, n_len);
		*this = Fund(fbs_obj);
	}
	Fund(const mm::Fund *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		ccy = ptr_fbs->ccy();
		balance = GX3(ptr_fbs, balance(), c_str(), "");
		frozen = GX3(ptr_fbs, frozen(), c_str(), "");
		usable = GX3(ptr_fbs, usable(), c_str(), "");
		withdrawn = GX3(ptr_fbs, withdrawn(), c_str(), "");
		uncleared = GX3(ptr_fbs, uncleared(), c_str(), "");
		credit_value = GX3(ptr_fbs, credit_value(), c_str(), "");
		margin_value = GX3(ptr_fbs, margin_value(), c_str(), "");
		bod_balance = GX3(ptr_fbs, bod_balance(), c_str(), "");
		today_cashio = GX3(ptr_fbs, today_cashio(), c_str(), "");
		unclear = GX3(ptr_fbs, unclear(), c_str(), "");
		basic_margin = GX3(ptr_fbs, basic_margin(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		min_margin = GX3(ptr_fbs, min_margin(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Fund>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Fund> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateFund(fb, acc.to_fbs(fb), ccy, fs(balance), fs(frozen), fs(usable), fs(withdrawn), fs(uncleared), fs(credit_value), fs(margin_value), fs(bod_balance), fs(today_cashio), fs(unclear), fs(basic_margin), build_vct<Pair, mm::Pair>(fb, extras), fs(min_margin));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && balance.size())) ss << "\"balance\":" << "\"" << balance << "\"" << ",";
		if (!b_simplify || (b_simplify && frozen.size())) ss << "\"frozen\":" << "\"" << frozen << "\"" << ",";
		if (!b_simplify || (b_simplify && usable.size())) ss << "\"usable\":" << "\"" << usable << "\"" << ",";
		if (!b_simplify || (b_simplify && withdrawn.size())) ss << "\"withdrawn\":" << "\"" << withdrawn << "\"" << ",";
		if (!b_simplify || (b_simplify && uncleared.size())) ss << "\"uncleared\":" << "\"" << uncleared << "\"" << ",";
		if (!b_simplify || (b_simplify && credit_value.size())) ss << "\"credit_value\":" << "\"" << credit_value << "\"" << ",";
		if (!b_simplify || (b_simplify && margin_value.size())) ss << "\"margin_value\":" << "\"" << margin_value << "\"" << ",";
		if (!b_simplify || (b_simplify && bod_balance.size())) ss << "\"bod_balance\":" << "\"" << bod_balance << "\"" << ",";
		if (!b_simplify || (b_simplify && today_cashio.size())) ss << "\"today_cashio\":" << "\"" << today_cashio << "\"" << ",";
		if (!b_simplify || (b_simplify && unclear.size())) ss << "\"unclear\":" << "\"" << unclear << "\"" << ",";
		if (!b_simplify || (b_simplify && basic_margin.size())) ss << "\"basic_margin\":" << "\"" << basic_margin << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		if (!b_simplify || (b_simplify && min_margin.size())) ss << "\"min_margin\":" << "\"" << min_margin << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Fund &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Hold
{
	Account acc;
	mm::Market market;
	std::string symbol;
	std::string qty;
	std::string margin_rato;
	std::string uncleared;
	std::string today_buy_qty;
	std::string today_sell_qty;
	std::string today_buy_amount;
	std::string today_sell_amount;
	std::string avg_price;
	std::string cost_price;
	std::string bod_qty;
	std::string bod_cost_price;
	std::string bod_avg_price;
	std::string long_position;
	std::string long_avg_price;
	std::string short_position;
	std::string short_avg_price;
	std::vector<Pair> extras;
	std::string hold_avg_price;

	Hold()
	{
		market = mm::Market_NONE;
	}
	Hold(const Hold &src)
	{
		acc = src.acc;
		market = src.market;
		symbol = src.symbol;
		qty = src.qty;
		margin_rato = src.margin_rato;
		uncleared = src.uncleared;
		today_buy_qty = src.today_buy_qty;
		today_sell_qty = src.today_sell_qty;
		today_buy_amount = src.today_buy_amount;
		today_sell_amount = src.today_sell_amount;
		avg_price = src.avg_price;
		cost_price = src.cost_price;
		bod_qty = src.bod_qty;
		bod_cost_price = src.bod_cost_price;
		bod_avg_price = src.bod_avg_price;
		long_position = src.long_position;
		long_avg_price = src.long_avg_price;
		short_position = src.short_position;
		short_avg_price = src.short_avg_price;
		extras = src.extras;
		hold_avg_price = src.hold_avg_price;
	}
	Hold(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Hold();
			return;
		}
		READ_FBS(fbs_obj, mm::Hold, ptr_data, n_len);
		*this = Hold(fbs_obj);
	}
	Hold(const mm::Hold *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		qty = GX3(ptr_fbs, qty(), c_str(), "");
		margin_rato = GX3(ptr_fbs, margin_rato(), c_str(), "");
		uncleared = GX3(ptr_fbs, uncleared(), c_str(), "");
		today_buy_qty = GX3(ptr_fbs, today_buy_qty(), c_str(), "");
		today_sell_qty = GX3(ptr_fbs, today_sell_qty(), c_str(), "");
		today_buy_amount = GX3(ptr_fbs, today_buy_amount(), c_str(), "");
		today_sell_amount = GX3(ptr_fbs, today_sell_amount(), c_str(), "");
		avg_price = GX3(ptr_fbs, avg_price(), c_str(), "");
		cost_price = GX3(ptr_fbs, cost_price(), c_str(), "");
		bod_qty = GX3(ptr_fbs, bod_qty(), c_str(), "");
		bod_cost_price = GX3(ptr_fbs, bod_cost_price(), c_str(), "");
		bod_avg_price = GX3(ptr_fbs, bod_avg_price(), c_str(), "");
		long_position = GX3(ptr_fbs, long_position(), c_str(), "");
		long_avg_price = GX3(ptr_fbs, long_avg_price(), c_str(), "");
		short_position = GX3(ptr_fbs, short_position(), c_str(), "");
		short_avg_price = GX3(ptr_fbs, short_avg_price(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		hold_avg_price = GX3(ptr_fbs, hold_avg_price(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Hold>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Hold> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateHold(fb, acc.to_fbs(fb), market, fs(symbol), fs(qty), fs(margin_rato), fs(uncleared), fs(today_buy_qty), fs(today_sell_qty), fs(today_buy_amount), fs(today_sell_amount), fs(avg_price), fs(cost_price), fs(bod_qty), fs(bod_cost_price), fs(bod_avg_price), fs(long_position), fs(long_avg_price), fs(short_position), fs(short_avg_price), build_vct<Pair, mm::Pair>(fb, extras), fs(hold_avg_price));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && qty.size())) ss << "\"qty\":" << "\"" << qty << "\"" << ",";
		if (!b_simplify || (b_simplify && margin_rato.size())) ss << "\"margin_rato\":" << "\"" << margin_rato << "\"" << ",";
		if (!b_simplify || (b_simplify && uncleared.size())) ss << "\"uncleared\":" << "\"" << uncleared << "\"" << ",";
		if (!b_simplify || (b_simplify && today_buy_qty.size())) ss << "\"today_buy_qty\":" << "\"" << today_buy_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && today_sell_qty.size())) ss << "\"today_sell_qty\":" << "\"" << today_sell_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && today_buy_amount.size())) ss << "\"today_buy_amount\":" << "\"" << today_buy_amount << "\"" << ",";
		if (!b_simplify || (b_simplify && today_sell_amount.size())) ss << "\"today_sell_amount\":" << "\"" << today_sell_amount << "\"" << ",";
		if (!b_simplify || (b_simplify && avg_price.size())) ss << "\"avg_price\":" << "\"" << avg_price << "\"" << ",";
		if (!b_simplify || (b_simplify && cost_price.size())) ss << "\"cost_price\":" << "\"" << cost_price << "\"" << ",";
		if (!b_simplify || (b_simplify && bod_qty.size())) ss << "\"bod_qty\":" << "\"" << bod_qty << "\"" << ",";
		if (!b_simplify || (b_simplify && bod_cost_price.size())) ss << "\"bod_cost_price\":" << "\"" << bod_cost_price << "\"" << ",";
		if (!b_simplify || (b_simplify && bod_avg_price.size())) ss << "\"bod_avg_price\":" << "\"" << bod_avg_price << "\"" << ",";
		if (!b_simplify || (b_simplify && long_position.size())) ss << "\"long_position\":" << "\"" << long_position << "\"" << ",";
		if (!b_simplify || (b_simplify && long_avg_price.size())) ss << "\"long_avg_price\":" << "\"" << long_avg_price << "\"" << ",";
		if (!b_simplify || (b_simplify && short_position.size())) ss << "\"short_position\":" << "\"" << short_position << "\"" << ",";
		if (!b_simplify || (b_simplify && short_avg_price.size())) ss << "\"short_avg_price\":" << "\"" << short_avg_price << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		if (!b_simplify || (b_simplify && hold_avg_price.size())) ss << "\"hold_avg_price\":" << "\"" << hold_avg_price << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Hold &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Notify
{
	Account acc;
	std::string msg;
	mm::Action operation;
	std::vector<Pair> extras;

	Notify()
	{
		operation = mm::Action_NONE;
	}
	Notify(const Notify &src)
	{
		acc = src.acc;
		msg = src.msg;
		operation = src.operation;
		extras = src.extras;
	}
	Notify(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Notify();
			return;
		}
		READ_FBS(fbs_obj, mm::Notify, ptr_data, n_len);
		*this = Notify(fbs_obj);
	}
	Notify(const mm::Notify *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		msg = GX3(ptr_fbs, msg(), c_str(), "");
		operation = ptr_fbs->operation();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Notify>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Notify> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateNotify(fb, acc.to_fbs(fb), fs(msg), operation, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && msg.size())) ss << "\"msg\":" << "\"" << msg << "\"" << ",";
		ss << "\"operation\":" << "\"" << EnumNameAction(operation) << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Notify &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct PositionNotify
{
	Account acc;
	std::string time;
	std::string serialno;
	mm::Market market;
	std::string symbol;
	std::string qty;
	std::vector<Pair> extras;

	PositionNotify()
	{
		market = mm::Market_NONE;
	}
	PositionNotify(const PositionNotify &src)
	{
		acc = src.acc;
		time = src.time;
		serialno = src.serialno;
		market = src.market;
		symbol = src.symbol;
		qty = src.qty;
		extras = src.extras;
	}
	PositionNotify(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = PositionNotify();
			return;
		}
		READ_FBS(fbs_obj, mm::PositionNotify, ptr_data, n_len);
		*this = PositionNotify(fbs_obj);
	}
	PositionNotify(const mm::PositionNotify *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		time = GX3(ptr_fbs, time(), c_str(), "");
		serialno = GX3(ptr_fbs, serialno(), c_str(), "");
		market = ptr_fbs->market();
		symbol = GX3(ptr_fbs, symbol(), c_str(), "");
		qty = GX3(ptr_fbs, qty(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::PositionNotify>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::PositionNotify> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreatePositionNotify(fb, acc.to_fbs(fb), fs(time), fs(serialno), market, fs(symbol), fs(qty), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && time.size())) ss << "\"time\":" << "\"" << time << "\"" << ",";
		if (!b_simplify || (b_simplify && serialno.size())) ss << "\"serialno\":" << "\"" << serialno << "\"" << ",";
		ss << "\"market\":" << "\"" << EnumNameMarket(market) << "\"" << ",";
		if (!b_simplify || (b_simplify && symbol.size())) ss << "\"symbol\":" << "\"" << symbol << "\"" << ",";
		if (!b_simplify || (b_simplify && qty.size())) ss << "\"qty\":" << "\"" << qty << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, PositionNotify &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Margin
{
	Account acc;
	mm::Currency ccy;
	std::string basic_margin;
	std::string min_magin;
	std::vector<Pair> extras;

	Margin()
	{
		ccy = mm::Currency_NONE;
	}
	Margin(const Margin &src)
	{
		acc = src.acc;
		ccy = src.ccy;
		basic_margin = src.basic_margin;
		min_magin = src.min_magin;
		extras = src.extras;
	}
	Margin(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Margin();
			return;
		}
		READ_FBS(fbs_obj, mm::Margin, ptr_data, n_len);
		*this = Margin(fbs_obj);
	}
	Margin(const mm::Margin *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		ccy = ptr_fbs->ccy();
		basic_margin = GX3(ptr_fbs, basic_margin(), c_str(), "");
		min_magin = GX3(ptr_fbs, min_magin(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Margin>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Margin> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateMargin(fb, acc.to_fbs(fb), ccy, fs(basic_margin), fs(min_magin), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"ccy\":" << "\"" << EnumNameCurrency(ccy) << "\"" << ",";
		if (!b_simplify || (b_simplify && basic_margin.size())) ss << "\"basic_margin\":" << "\"" << basic_margin << "\"" << ",";
		if (!b_simplify || (b_simplify && min_magin.size())) ss << "\"min_magin\":" << "\"" << min_magin << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Margin &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Recovery
{
	Account acc;
	uint msgid_begin;
	uint msgid_end;
	std::vector<Pair> extras;

	Recovery()
	{
		msgid_begin = 0;
		msgid_end = 0;
	}
	Recovery(const Recovery &src)
	{
		acc = src.acc;
		msgid_begin = src.msgid_begin;
		msgid_end = src.msgid_end;
		extras = src.extras;
	}
	Recovery(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Recovery();
			return;
		}
		READ_FBS(fbs_obj, mm::Recovery, ptr_data, n_len);
		*this = Recovery(fbs_obj);
	}
	Recovery(const mm::Recovery *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		msgid_begin = ptr_fbs->msgid_begin();
		msgid_end = ptr_fbs->msgid_end();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Recovery>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Recovery> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateRecovery(fb, acc.to_fbs(fb), msgid_begin, msgid_end, build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"msgid_begin\":" << (uint)msgid_begin << ",";
		ss << "\"msgid_end\":" << (uint)msgid_end << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Recovery &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct VerifyCode_req
{
	Account acc;
	std::string device_name;
	std::string device_code;
	mm::TerminalType terminal;
	std::string ip;
	std::vector<Pair> extras;

	VerifyCode_req()
	{
		terminal = mm::TerminalType_NONE;
	}
	VerifyCode_req(const VerifyCode_req &src)
	{
		acc = src.acc;
		device_name = src.device_name;
		device_code = src.device_code;
		terminal = src.terminal;
		ip = src.ip;
		extras = src.extras;
	}
	VerifyCode_req(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = VerifyCode_req();
			return;
		}
		READ_FBS(fbs_obj, mm::VerifyCode_req, ptr_data, n_len);
		*this = VerifyCode_req(fbs_obj);
	}
	VerifyCode_req(const mm::VerifyCode_req *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		device_name = GX3(ptr_fbs, device_name(), c_str(), "");
		device_code = GX3(ptr_fbs, device_code(), c_str(), "");
		terminal = ptr_fbs->terminal();
		ip = GX3(ptr_fbs, ip(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::VerifyCode_req>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::VerifyCode_req> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateVerifyCode_req(fb, acc.to_fbs(fb), fs(device_name), fs(device_code), terminal, fs(ip), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && device_name.size())) ss << "\"device_name\":" << "\"" << device_name << "\"" << ",";
		if (!b_simplify || (b_simplify && device_code.size())) ss << "\"device_code\":" << "\"" << device_code << "\"" << ",";
		ss << "\"terminal\":" << "\"" << EnumNameTerminalType(terminal) << "\"" << ",";
		if (!b_simplify || (b_simplify && ip.size())) ss << "\"ip\":" << "\"" << ip << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, VerifyCode_req &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct VerifyCode_rsp
{
	Result res;
	std::string timeout;
	std::string address;

	VerifyCode_rsp()
	{
	}
	VerifyCode_rsp(const VerifyCode_rsp &src)
	{
		res = src.res;
		timeout = src.timeout;
		address = src.address;
	}
	VerifyCode_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = VerifyCode_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::VerifyCode_rsp, ptr_data, n_len);
		*this = VerifyCode_rsp(fbs_obj);
	}
	VerifyCode_rsp(const mm::VerifyCode_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		timeout = GX3(ptr_fbs, timeout(), c_str(), "");
		address = GX3(ptr_fbs, address(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::VerifyCode_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::VerifyCode_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateVerifyCode_rsp(fb, res.to_fbs(fb), fs(timeout), fs(address));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && timeout.size())) ss << "\"timeout\":" << "\"" << timeout << "\"" << ",";
		if (!b_simplify || (b_simplify && address.size())) ss << "\"address\":" << "\"" << address << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, VerifyCode_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct exrates_req
{
	Account acc;
	mm::Currency cur;

	exrates_req()
	{
		cur = mm::Currency_NONE;
	}
	exrates_req(const exrates_req &src)
	{
		acc = src.acc;
		cur = src.cur;
	}
	exrates_req(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = exrates_req();
			return;
		}
		READ_FBS(fbs_obj, mm::exrates_req, ptr_data, n_len);
		*this = exrates_req(fbs_obj);
	}
	exrates_req(const mm::exrates_req *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		cur = ptr_fbs->cur();
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::exrates_req>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::exrates_req> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::Createexrates_req(fb, acc.to_fbs(fb), cur);
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"cur\":" << "\"" << EnumNameCurrency(cur) << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, exrates_req &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_order_oprecord
{
	Account acc;
	Query_page page;
	std::string entrust_no;

	Query_order_oprecord()
	{
	}
	Query_order_oprecord(const Query_order_oprecord &src)
	{
		acc = src.acc;
		page = src.page;
		entrust_no = src.entrust_no;
	}
	Query_order_oprecord(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_order_oprecord();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_order_oprecord, ptr_data, n_len);
		*this = Query_order_oprecord(fbs_obj);
	}
	Query_order_oprecord(const mm::Query_order_oprecord *ptr_fbs)
	{
		if (!ptr_fbs) return;
		acc = ptr_fbs->acc();
		page = ptr_fbs->page();
		entrust_no = GX3(ptr_fbs, entrust_no(), c_str(), "");
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_order_oprecord>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_order_oprecord> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_order_oprecord(fb, acc.to_fbs(fb), page.to_fbs(fb), fs(entrust_no));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"acc\":" << acc.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && entrust_no.size())) ss << "\"entrust_no\":" << "\"" << entrust_no << "\"" << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_order_oprecord &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Order_operation_record
{
	mm::Entrust_mode direction;
	std::string price;
	std::string qty;
	mm::Op_status op_status;
	mm::TerminalType input_channel;
	std::string input_time;
	std::string rej_msg;
	SpecialCond spec_cond;
	std::string remark;
	std::vector<Pair> extras;

	Order_operation_record()
	{
		direction = mm::Entrust_mode_NONE;
		op_status = mm::Op_status_SUCC;
		input_channel = mm::TerminalType_NONE;
	}
	Order_operation_record(const Order_operation_record &src)
	{
		direction = src.direction;
		price = src.price;
		qty = src.qty;
		op_status = src.op_status;
		input_channel = src.input_channel;
		input_time = src.input_time;
		rej_msg = src.rej_msg;
		spec_cond = src.spec_cond;
		remark = src.remark;
		extras = src.extras;
	}
	Order_operation_record(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Order_operation_record();
			return;
		}
		READ_FBS(fbs_obj, mm::Order_operation_record, ptr_data, n_len);
		*this = Order_operation_record(fbs_obj);
	}
	Order_operation_record(const mm::Order_operation_record *ptr_fbs)
	{
		if (!ptr_fbs) return;
		direction = ptr_fbs->direction();
		price = GX3(ptr_fbs, price(), c_str(), "");
		qty = GX3(ptr_fbs, qty(), c_str(), "");
		op_status = ptr_fbs->op_status();
		input_channel = ptr_fbs->input_channel();
		input_time = GX3(ptr_fbs, input_time(), c_str(), "");
		rej_msg = GX3(ptr_fbs, rej_msg(), c_str(), "");
		spec_cond = ptr_fbs->spec_cond();
		remark = GX3(ptr_fbs, remark(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Order_operation_record>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Order_operation_record> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateOrder_operation_record(fb, direction, fs(price), fs(qty), op_status, input_channel, fs(input_time), fs(rej_msg), spec_cond.to_fbs(fb), fs(remark), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"direction\":" << "\"" << EnumNameEntrust_mode(direction) << "\"" << ",";
		if (!b_simplify || (b_simplify && price.size())) ss << "\"price\":" << "\"" << price << "\"" << ",";
		if (!b_simplify || (b_simplify && qty.size())) ss << "\"qty\":" << "\"" << qty << "\"" << ",";
		ss << "\"op_status\":" << "\"" << EnumNameOp_status(op_status) << "\"" << ",";
		ss << "\"input_channel\":" << "\"" << EnumNameTerminalType(input_channel) << "\"" << ",";
		if (!b_simplify || (b_simplify && input_time.size())) ss << "\"input_time\":" << "\"" << input_time << "\"" << ",";
		if (!b_simplify || (b_simplify && rej_msg.size())) ss << "\"rej_msg\":" << "\"" << rej_msg << "\"" << ",";
		ss << "\"spec_cond\":" << spec_cond.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && remark.size())) ss << "\"remark\":" << "\"" << remark << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Order_operation_record &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct Query_order_oprecord_rsp
{
	Result res;
	Query_page page;
	std::vector<Pair> extras;
	std::vector<Order_operation_record> items;

	Query_order_oprecord_rsp()
	{
	}
	Query_order_oprecord_rsp(const Query_order_oprecord_rsp &src)
	{
		res = src.res;
		page = src.page;
		extras = src.extras;
		items = src.items;
	}
	Query_order_oprecord_rsp(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = Query_order_oprecord_rsp();
			return;
		}
		READ_FBS(fbs_obj, mm::Query_order_oprecord_rsp, ptr_data, n_len);
		*this = Query_order_oprecord_rsp(fbs_obj);
	}
	Query_order_oprecord_rsp(const mm::Query_order_oprecord_rsp *ptr_fbs)
	{
		if (!ptr_fbs) return;
		res = ptr_fbs->res();
		page = ptr_fbs->page();
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
		items = read_vct<Order_operation_record, mm::Order_operation_record>(ptr_fbs->items());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::Query_order_oprecord_rsp>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::Query_order_oprecord_rsp> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateQuery_order_oprecord_rsp(fb, res.to_fbs(fb), page.to_fbs(fb), build_vct<Pair, mm::Pair>(fb, extras), build_vct<Order_operation_record, mm::Order_operation_record>(fb, items));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		ss << "\"res\":" << res.to_json(b_simplify) << ",";
		ss << "\"page\":" << page.to_json(b_simplify) << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		if (!b_simplify || (b_simplify && items.size())) ss << "\"items\":" << read_vct_2_json<Order_operation_record>(items) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, Query_order_oprecord_rsp &data)
	{
		ss << data.to_json();
		return ss;
	}
};

struct ACCOUNT_INFO
{
	std::string api_type;
	std::string account;
	std::string password;
	std::vector<Pair> extras;

	ACCOUNT_INFO()
	{
	}
	ACCOUNT_INFO(const ACCOUNT_INFO &src)
	{
		api_type = src.api_type;
		account = src.account;
		password = src.password;
		extras = src.extras;
	}
	ACCOUNT_INFO(const void *ptr_data, const size_t n_len)
	{
		if (!verify(ptr_data, n_len))
		{
			*this = ACCOUNT_INFO();
			return;
		}
		READ_FBS(fbs_obj, mm::ACCOUNT_INFO, ptr_data, n_len);
		*this = ACCOUNT_INFO(fbs_obj);
	}
	ACCOUNT_INFO(const mm::ACCOUNT_INFO *ptr_fbs)
	{
		if (!ptr_fbs) return;
		api_type = GX3(ptr_fbs, api_type(), c_str(), "");
		account = GX3(ptr_fbs, account(), c_str(), "");
		password = GX3(ptr_fbs, password(), c_str(), "");
		extras = read_vct<Pair, mm::Pair>(ptr_fbs->extras());
	}
	bool verify(const void* ptr_fbs, const size_t n_len)
	{
		return fbs_verify_table<mm::ACCOUNT_INFO>(ptr_fbs, n_len);
	}
	flatbuffers::Offset<mm::ACCOUNT_INFO> to_fbs(flatbuffers::FlatBufferBuilder &fb)
	{
		return mm::CreateACCOUNT_INFO(fb, fs(api_type), fs(account), fs(password), build_vct<Pair, mm::Pair>(fb, extras));
	}
	std::string to_json(const bool b_simplify = false)
	{
		std::stringstream ss;
		ss << "{";
		if (!b_simplify || (b_simplify && api_type.size())) ss << "\"api_type\":" << "\"" << api_type << "\"" << ",";
		if (!b_simplify || (b_simplify && account.size())) ss << "\"account\":" << "\"" << account << "\"" << ",";
		if (!b_simplify || (b_simplify && password.size())) ss << "\"password\":" << "\"" << password << "\"" << ",";
		if (!b_simplify || (b_simplify && extras.size())) ss << "\"extras\":" << read_vct_2_json<Pair>(extras) << ",";
		ss_cut_back_c(ss);
		ss << "}";
		return ss.str();
	}
	friend std::ostream& operator << (std::ostream &ss, ACCOUNT_INFO &data)
	{
		ss << data.to_json();
		return ss;
	}
};

}
