#include <string>
#include <iostream>
#include <vector>
#include <random>

#include "Checking.h"
#include "Savings.h"
#include "PremiumChecking.h"

int intRandomNumberGenerator(int start, int end) {
	std::random_device randNum;
	std::uniform_int_distribution<int> dist(start, end);
	return dist(randNum);
}

double doubleRandomNumberGenerator(double start, double end)
{
    double f = (double)rand() / RAND_MAX;
    return start + f * (end - start);
}
unsigned long long longRandomNumberGenerator(unsigned long long start, unsigned long long end) {
	std::random_device randNum;
	std::uniform_int_distribution<unsigned long long> dist(start, end);
	return dist(randNum);
}

int main() {
	int userInput = 0;

	std::vector<std::string> firstNames;
	firstNames.push_back("Luke");
	firstNames.push_back("Juliet");
	firstNames.push_back("George");
	firstNames.push_back("Bob");
	firstNames.push_back("Isabelle");
	firstNames.push_back("Frank");
	firstNames.push_back("Alice");
	firstNames.push_back("Donald");

	std::vector<std::string> lastNames;
	lastNames.push_back("Wu");
	lastNames.push_back("Goldsworthy");
	lastNames.push_back("Philbrick");
	lastNames.push_back("Kagan");
	lastNames.push_back("Skywalker");
	lastNames.push_back("Meacham");
	lastNames.push_back("Fagles");
	lastNames.push_back("Trump");

	std::vector<Account*> vectorOfAccounts;

	while (userInput != 5) {

		std::cout << "Menu:\n1. Create Checking accounts\n2. Create Premium accounts\n3. Create Savings accounts\n4. Display all accounts\n5. Quit" << std::endl;
		std::cin >> userInput;

		if (userInput == 1) {

			int amountOfAccounts;

			std::cout << "How many acounts would you like to create?  ";
			std::cin.ignore();
			std::cin >> amountOfAccounts;

			while (amountOfAccounts > 0) {

				Checking* checkingAccount = new Checking;

				checkingAccount->setFirstName(firstNames[intRandomNumberGenerator(0, firstNames.size() - 1)]);

				checkingAccount->setLastName(lastNames[intRandomNumberGenerator(0, lastNames.size() - 1)]);

				checkingAccount->deposit(longRandomNumberGenerator(0, 10000000));

				checkingAccount->display();

				vectorOfAccounts.push_back(checkingAccount);

				amountOfAccounts -= 1;
			}
		}
		else if (userInput == 2) {

			int amountOfAccounts;

			std::cout << "How many acounts would you like to create?  ";
			std::cin.ignore();
			std::cin >> amountOfAccounts;

			while (amountOfAccounts > 0) {
				
				PremiumChecking* premiumAccount = new PremiumChecking;

				premiumAccount->setFirstName(firstNames[intRandomNumberGenerator(0, firstNames.size() - 1)]);

				premiumAccount->setLastName(lastNames[intRandomNumberGenerator(0, lastNames.size() - 1)]);

				premiumAccount->deposit(longRandomNumberGenerator(0, 10000000));

				premiumAccount->chargeMonthlyFee();

				vectorOfAccounts.push_back(premiumAccount);

				amountOfAccounts -= 1;

				premiumAccount->display();

			}

		}

		else if (userInput == 3) {
			
			int amountOfAccounts;

			std::cout << "How many acounts would you like to create?  ";
			std::cin.ignore();
			std::cin >> amountOfAccounts;

			while (amountOfAccounts > 0) {

				Savings* savingsAccount = new Savings;

				savingsAccount->setFirstName(firstNames[intRandomNumberGenerator(0, firstNames.size() - 1)]);

				savingsAccount->setLastName(lastNames[intRandomNumberGenerator(0, lastNames.size() - 1)]);

				savingsAccount->deposit(longRandomNumberGenerator(0, 10000000));

				savingsAccount->setInterestRate(doubleRandomNumberGenerator(1.00, 10.00));

				savingsAccount->display();

				vectorOfAccounts.push_back(savingsAccount);

				amountOfAccounts -= 1;

			}

		}

		else if (userInput == 4) {
			for (int i = 0; i < vectorOfAccounts.size(); i++) {
				vectorOfAccounts[i]->display();
			}
		}

		else {
			std::cout << "Please select a number from the menu!" << std::endl;
		}

	}

}
