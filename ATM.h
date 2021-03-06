#pragma once
#include "Tester.h"

class ATM : IATester {
protected:
	bool isLocked;
	int pin;
	int accountBalance;
	int limit;
public:
	ATM(int pin, int accountBalance);

	result_en unlock(int pin); ///sprawdzanie PINu
    virtual result_en withdraw(int amount); ///wypłacanie
	virtual void serviceInfo(atmInfo &info, string &address);
};

