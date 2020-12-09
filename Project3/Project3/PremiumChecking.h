#pragma once
#include "Account.h"


class PremiumChecking : public Account {
public:
	PremiumChecking();
	PremiumChecking(std::string firstName, std::string lastName);
	void withdraw(unsigned long long amount);
	void chargeMonthlyFee();
	unsigned long long getMonthlyFee();
	void setMonthlyFee(unsigned long long fee);
	virtual void display() const override;

private:
	unsigned long long monthlyFee = 5.75;
};
