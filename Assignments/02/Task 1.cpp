/**
 * Programmer: Muhammed Owais 
 * Desc: Q1, SecurityTool and FirewallTool
 * Date: 27/03/2024
 * Roll-No: 23K-0047
 */
#include <iostream>

class SecurityTool
{
private:
	std::string securityLevel;
	int cost, noOfDevices;
public:
	SecurityTool()
	{
		do
		{
			std::cout << "Enter Security Level: ";
			std::cin >> this->securityLevel;
		} while (this->securityLevel != "High" && this->securityLevel != "Medium" && this->securityLevel != "Low");
		std::cout << "Enter Cost: ";
		std::cin >> this->cost;
		do
		{
			std::cout << "Enter No Of Devices: ";
			std::cin >> this->noOfDevices;
		} while (this->noOfDevices > 10 && this->noOfDevices < 0);
	}
	void performScan()
	{
		std::cout << "Running security scan..." << std::endl << "Security Level: " << this->securityLevel
		<< std::endl << "Cost: " << this->cost << std::endl << "No Of Devices: " << this->noOfDevices << std::endl;
	}
	std::string getSecurityLevel() {return this->securityLevel;}
	int getCost() {return this->cost;}
	int getNoOfDevices() {return this->noOfDevices;}
};

class FirewallTool : public SecurityTool
{
private:
	int ports[23];
	std::string protocols[6] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
public:
	FirewallTool() { this->generateList(); }
	void generateList()
	{
		int id;
		std::cout << "Enter Your Id: ";
		std::cin >> id;
		for (int i = 0; i < 23; ++i)
		{
			ports[i] = i + id + 1;
		}
	}
	void performScan(int port, std::string protocol)
	{
		bool flag = false;
		if (getSecurityLevel() == "High")
		{
			for (int i = 0; i < 6; ++i)
			{
				if (protocols[i] == protocol)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				std::cout << "Incorrect Protocol!!" << std::endl;
				return;
			}
			for (int i = 0; i < 23; ++i)
			{
				if (ports[i] == port)
				{
					std::cout << "Scan Complete, No Issues Found!!" << std::endl;
					return;
				}
			}
			std::cout << "Incorrect Port!!" << std::endl;
		}
		else if (getSecurityLevel() == "Medium")
		{
			for (int i = 0; i < 6; ++i)
			{
				if (protocols[i] == protocol)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				std::cout << "Incorrect Protocol!!" << std::endl;
				return;
			}
			for (int i = 0; i < 23; ++i)
			{
				if (ports[i] == port || port == ports[23] + 1 || port == ports[23] + 2 )
				{
					std::cout << "Scan Complete, No Issues Found!!" << std::endl;
					return;
				}
			}
			std::cout << "Incorrect Port!!" << std::endl;
		}
		else if (getSecurityLevel() == "Low")
		{
			for (int i = 0; i < 6; ++i)
			{
				if (protocols[i] == protocol || protocol == "TCP" || protocol == "DNS")
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				std::cout << "Incorrect Protocol!!" << std::endl;
				return;
			}
			for (int i = 0; i < 23; ++i)
			{
				if (ports[i] == port || port == ports[23] + 1 || port == ports[23] + 2 )
				{
					std::cout << "Scan Complete, No Issues Found!!" << std::endl;
					return;
				}
			}
			for (int i = 1; i <= 6; ++i)
			{
				if (ports[22] + i == port)
				{
					std::cout << "Scan Complete, No Issues Found!!" << std::endl;
					return;
				}
			}
			std::cout << "Incorrect Port!!" << std::endl;
		}
	}
};

int main()
{
	FirewallTool tool;
	int port;
	std::string protocol;
	std::cout << "Enter Port: ";
	std::cin >> port;
	std::cout << "Enter Protocol: ";
	std::cin >> protocol;
	std::cout << "Muhammed Owais 23K-0047" << std::endl;
	tool.performScan(port, protocol);
}