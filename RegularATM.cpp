#include "Tester.h"
#include "ATM.h"
#include "RegularATM.h"


RegularATM::RegularATM(int pin, int accountBalance) : ATM(pin, accountBalance)
{
	
	this->limit = 10000;
}

result_en RegularATM::checkBalance(int& balance)
{
	if (this->isLocked == true)
	{
		return res_atm_blocked;
	}
	else
	{
		balance = this->accountBalance;
		this->isLocked = true;
		return res_ok;
	}

}

void RegularATM::serviceInfo(atmInfo &info, string &address)
{
	info.accountBalance = this->accountBalance;
	info.isLocked = this->isLocked;
	info.limit = this->limit;
	address = "Bankomat RegularATM";
}