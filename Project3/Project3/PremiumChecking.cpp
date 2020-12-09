#include <iostream>

#include "PremiumChecking.h"

PremiumChecking::PremiumChecking() {

}

PremiumChecking::PremiumChecking(std::string firstName, std::string lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}

void withdraw(unsigned long long amount) {
if (Account::balance <= amount) {
		if (Account::balance - amount <= -200) {
			std::cout << "Unable to withdraw due to low funds" << std::endl;
		}
		else {
			Account::balance -= amount;
		}
	}
	else {
		Account::balance -= amount;
	}
}

void PremiumChecking::setMonthlyFee(unsigned long long fee) {
	this->monthlyFee = fee;
}
unsigned long long PremiumChecking::getMonthlyFee() {
	return(this->monthlyFee);
}

void PremiumChecking::chargeMonthlyFee() {
	this->balance -= this->monthlyFee;
}

void PremiumChecking::display() const {
	Account::display();
	std::cout << "Monthly Fee: " << this->monthlyFee << std::endl;
}
