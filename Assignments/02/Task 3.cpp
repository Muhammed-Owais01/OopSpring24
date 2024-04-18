/**
 * Programmer: Muhammed Owais 
 * Desc: Q3, Daraz Loyalty Points
 * Date: 28/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>
#include <cstdlib>

class DarazPersonData
{
private:
	std::string lastName, firstName, address, city, state, zip, phone;
public:	
	DarazPersonData(
		std::string lastName, 
		std::string firstName, 
		std::string address, 
		std::string city, 
		std::string state, 
		std::string zip, 
		std::string phone
		) 
	: lastName(lastName), firstName(firstName), address(address), city(city), state(state), zip(zip), phone(phone) {}

	// Getters
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getAddress() const { return address; }
    std::string getCity() const { return city; }
    std::string getState() const { return state; }
    std::string getZip() const { return zip; }
    std::string getPhone() const { return phone; }

    // Setters
    void setLastName(const std::string &lastName) { this->lastName = lastName; }
    void setFirstName(const std::string &firstName) { this->firstName = firstName; }
    void setAddress(const std::string &address) { this->address = address; }
    void setCity(const std::string &city) { this->city = city; }
    void setState(const std::string &state) { this->state = state; }
    void setZip(const std::string &zip) { this->zip = zip; }
    void setPhone(const std::string &phone) { this->phone = phone; }
};

class DarazCustomerData : public DarazPersonData
{
private:
	int customerNumber, loyalPoints;
public:
	DarazCustomerData(
		int customerNumber = 0, 
		int loyalPoints = 0,
		std::string lastName = "", 
		std::string firstName = "", 
		std::string address = "", 
		std::string city = "", 
		std::string state = "", 
		std::string zip = "", 
		std::string phone = ""
		) 
	: customerNumber(customerNumber), loyalPoints(loyalPoints), 
	DarazPersonData(lastName, firstName, address, city, state, zip, phone) {}

	// Getters
	int getCustomerNumber() {return customerNumber;}
	int getLoyalPoints() {return loyalPoints;}

	// Setters
	void setCustomerNumber(int customerNumber) {this->customerNumber = customerNumber;}
	void setLoyalPoints(int loyalPoints) {this->loyalPoints += loyalPoints;}

	void display() const {
        std::cout << "Customer Number: " << customerNumber << std::endl;
        std::cout << "Loyalty Points: " << loyalPoints << std::endl;
        std::cout << "Name: " << getFirstName() << " " << getLastName() << std::endl;
        std::cout << "Address: " << getAddress() << ", " << getCity() << ", " << getState() << " " << getZip() << std::endl;
        std::cout << "Phone: " << getPhone() << std::endl;
    }
};

class DarazLoyaltyPoints
{
private:
	DarazCustomerData customer;
public:
	DarazLoyaltyPoints(
		int customerNumber, 
		int loyalPoints,
		std::string lastName, 
		std::string firstName, 
		std::string address, 
		std::string city, 
		std::string state, 
		std::string zip, 
		std::string phone
		)
	{
		customer = DarazCustomerData(customerNumber, loyalPoints, lastName, firstName, address, city, state, zip, phone);
	}
	void addPoints()
	{
		customer.setLoyalPoints(5);
	}
	void redeemPoints(int redeem)
	{
		customer.setLoyalPoints(-redeem);
	}
	void getTotalPoints() {std::cout << "Total Points: " << customer.getLoyalPoints() << std::endl;}
	void display() {customer.display();}
};

int main()
{
	srand(time(NULL));
	std::cout << "Muhammed Owais 23K-0047\n";
	DarazLoyaltyPoints darazSystem(1234, 100, "Doe", "Joseph", "123 Main St", "Anytown", "CA", "12345", "123-456-7890");
	darazSystem.display();

	darazSystem.addPoints();
	darazSystem.redeemPoints(20);

	darazSystem.getTotalPoints();

}