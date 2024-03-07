/**
 * Programmer: Muhammed Owais 
 * Desc: Q2, Loan Helper
 * Date: 26/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

// Class LoanHelper
class LoanHelper
{
private:
	// Interest Rate
	const float rate = 5;
	float amount;
	int months;
public:
	// Parameterized Constructor
	LoanHelper(float amount = 0.f, int months = 0)
	{
		this->amount = amount;
		this->months = months;
	}

	// Calculating loan payment period
	void loanCalc()
	{
		std::cout << "You have to pay " << (this->amount / this->months) * (1 + (rate / 100)) << " every month for " << this->months << " months to repay your loan" << std::endl;
	}
};

int main()
{
	LoanHelper loan(200, 4);
	loan.loanCalc();
}