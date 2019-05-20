#include "SuperATM.h"

SuperATM::SuperATM(int pin, int accountBalance) : CashInATM(pin, accountBalance)
{

}

result_en SuperATM::rfidWithdraw()
{
	if (accountBalance >= 50)
	{

		accountBalance = accountBalance -  50;
		
		return res_ok;
	}
	else
	{
		return res_no_funds;
	}
}

result_en SuperATM::withdraw(int amount)
{
	if (amount == 50)
	{
		this->accountBalance = this->accountBalance - 50;
		return res_ok;
	}
	if (this->isLocked == true)
	{
		return res_atm_blocked;
	}

	if (amount <= 0)
	{
		this->isLocked = true;
		return res_error;
	}
	if (amount <= this->limit)
	{
		if (amount <= this->accountBalance)
		{

			this->accountBalance = this->accountBalance - amount;
			this->isLocked = true;
			return res_ok;
		}
		else
		{
			this->isLocked = true;
			return res_no_funds;
		}
	}
	else
	{
		this->isLocked = true;
		return res_withdraw_limit;


	}
}

void SuperATM::serviceInfo(atmInfo &info, string &address)
{
	info.accountBalance = this->accountBalance;
	info.isLocked = this->isLocked;
	info.limit = this->limit;
	address = "Bankomat SuperATM";
}