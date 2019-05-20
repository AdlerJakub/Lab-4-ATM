#include "ATM.h"
#include "Tester.h"
#include "Defines.h"
ATM::ATM(int pin, int accountBalance)
{
	this->pin = pin;
	this->accountBalance = accountBalance;
	this->limit = 1000;
	this->isLocked = true;
}

result_en ATM::unlock(int pin)
{
	if (this->pin == pin)
	{
		this->isLocked = false;
		return res_ok;
	}
	else
	{
		return res_wrong_pin;
	}
}

 result_en ATM::withdraw(int amount)
{
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


 void ATM::serviceInfo(atmInfo &info, string &address)
 {
	 info.accountBalance = this->accountBalance;
	 info.isLocked = this->isLocked;
	 info.limit = this->limit;
	 address = "Bankomat ATM";
 }