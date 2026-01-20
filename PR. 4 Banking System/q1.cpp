#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
	int accountNumber;
	string accountHolderName;
private:
	double balance;   

public:
	BankAccount(int accNo, string name, double bal) {
		accountNumber = accNo;
		accountHolderName = name;
		balance = bal;
	}

	virtual void calculateInterest() = 0; 

	void deposit(double amount) {
		balance += amount;
		cout << "Amount Deposited Successfully!\n";
	}

	virtual void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
			cout << "Amount Withdrawn Successfully!\n";
		} else {
			cout << "Insufficient Balance!\n";
		}
	}

	double getBalance() {
		return balance;
	}

	void displayAccountInfo() {
		cout << "\nAccount Number : " << accountNumber;
		cout << "\nHolder Name    : " << accountHolderName;
		cout << "\nBalance        : " << balance << endl;
	}
};

class SavingsAccount : public BankAccount {
	double interestRate;
public:
	SavingsAccount(int accNo, string name, double bal, double rate)
		: BankAccount(accNo, name, bal) {
		interestRate = rate;
	}

	void calculateInterest() override {
		double interest = getBalance() * interestRate / 100;
		cout << "Savings Interest: " << interest << endl;
	}
};

class CheckingAccount : public BankAccount {
	double overdraftLimit;
public:
	CheckingAccount(int accNo, string name, double bal, double limit)
		: BankAccount(accNo, name, bal) {
		overdraftLimit = limit;
	}

	void withdraw(double amount) override {
		if (amount <= getBalance() + overdraftLimit) {
			cout << "Withdrawal Successful (Overdraft Applied if needed)\n";
		} else {
			cout << "Overdraft Limit Exceeded!\n";
		}
	}

	void calculateInterest() override {
		cout << "Checking Account has no interest.\n";
	}
};

class FixedDepositAccount : public BankAccount {
	int term; 
public:
	FixedDepositAccount(int accNo, string name, double bal, int t)
		: BankAccount(accNo, name, bal) {
		term = t;
	}

	void calculateInterest() override {
		double interest = getBalance() * 0.07 * term / 12;
		cout << "Fixed Deposit Interest: " << interest << endl;
	}
};

int main() {
	vector<BankAccount*> accounts;
	int choice;

	do {
		cout << "\n--- Banking System Menu ---\n";
		cout << "1. Create Savings Account"<<endl;
		cout << "2. Create Checking Account"<<endl;
		cout << "3. Create Fixed Deposit Account"<<endl;
		cout << "4. Deposit"<<endl;
		cout << "5. Withdraw"<<endl;
		cout << "6. Display Account Info"<<endl;
		cout << "7. Calculate Interest"<<endl;
		cout << "0. Exit"<<endl;
		cout << "Enter choice: ";
		cin >> choice;

		int accNo; 
		string name; 
		double bal, rate, limit, amt; 
		int term;

		if (choice == 1) {		

			cout << "Enter Account No :";
			cin >> accNo;
			cin.ignore();
			
			cout << "Enter Name :";			
			getline(cin, name);
			
			cout << "Enter Balance :";
			cin >> bal;
			cin.ignore();
			
			cout << "Enter Interest Rate :";
			cin >> rate;
			cin.ignore();			
			 
			accounts.push_back(new SavingsAccount(accNo, name, bal, rate));
		}
		else if (choice == 2) {
			cout << "Enter Account No :";
			cin >> accNo;
			cin.ignore();
			
			cout << "Enter Name :";			
			getline(cin, name);
			
			cout << "Enter Balance :";
			cin >> bal;
			cin.ignore();
			
			cout << "Enter Overdraft Limit :";
			cin >> limit;
			cin.ignore();
			
			accounts.push_back(new CheckingAccount(accNo, name, bal, limit));
		}
		else if (choice == 3) {
			cout << "Enter Account No: ";
			cin >> accNo;
			cin.ignore();
			
			cout << "Enter Name :";			
			getline(cin, name);
			
			cout << "Enter Balance :";
			cin >> bal;
			cin.ignore();
			
			cout << "Enter Term (months) :";
			cin >> term;
			cin.ignore();
			
			accounts.push_back(new FixedDepositAccount(accNo, name, bal, term));
		}
		else if (choice == 4) {
			cout << "Enter amount: ";
			cin >> amt;
			accounts.back()->deposit(amt);
		}
		else if (choice == 5) {
			cout << "Enter amount: ";
			cin >> amt;
			accounts.back()->withdraw(amt);
		}
		else if (choice == 6) {
			accounts.back()->displayAccountInfo();
		}
		else if (choice == 7) {
			accounts.back()->calculateInterest();
		}

	} while (choice != 0);

	return 0;
}
