/**
 * Programmer: Muhammed Owais 
 * Desc: Q3, Salon Appointment
 * Date: 18/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>

class SalonAppointment
{
private:
	std::string customerName;  
    std::string appointmentDate;
    int fee;
    bool confirmed;
    static int appointmentsNum, totalEarning;
public:
	SalonAppointment(std::string customerName, std::string appointmentDate, int fee, bool confirmed)
	{
		this->customerName = customerName;
		this->appointmentDate = appointmentDate;
		this->fee = fee;
		this->confirmed = confirmed;
		this->updateEarnings(fee);
	}

	void updateEarnings(int fee)
	{
		totalEarning += fee;
		appointmentsNum++;
	}

    std::string getCustomerName() const {return customerName;}
    std::string getAppointmentDate() const {return appointmentDate;}
    bool isConfirmed() const {return confirmed;}
    static int getAppointmentsNum() {return appointmentsNum;}
    static int getTotalEarning() {return totalEarning;}

    static int calcAverage()
    {
    	int avg = totalEarning / appointmentsNum;
    	return avg;
    }

};

int SalonAppointment::appointmentsNum = 0;
int SalonAppointment::totalEarning = 0;

int main()
{
	SalonAppointment appointment1("John Doe", "2024-03-17", 50, true);
	SalonAppointment appointment2("Jane Smith", "2024-03-18", 40, false);
	SalonAppointment appointment3("Alice Johnson", "2024-03-19", 60, true);
	SalonAppointment appointment4("Bob Brown", "2024-03-20", 55, true);

	int average = SalonAppointment::calcAverage();
	std::cout << average;
}