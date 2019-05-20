#include "CashInATM.h"

CashInATM::CashInATM(int pin, int accountBalance) : RegularATM(pin, accountBalance)
{


}

result_en CashInATM::deposit(int amount)
{
	if (this->isLocked == true)
	{
		return res_atm_blocked;
	}
	else
	{
		if (amount <= 0)
		{
			this->isLocked = true;
			return res_error;
		}
		this->accountBalance = this->accountBalance + amount;
		this->isLocked = true;
		return res_ok;
	}

}

void CashInATM::serviceInfo(atmInfo &info, string &address)
{
	info.accountBalance = this->accountBalance;
	info.isLocked = this->isLocked;
	info.limit = this->limit;
	address = "Bankomat CashInATM";
}