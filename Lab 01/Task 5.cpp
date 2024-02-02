#include <iostream>

struct Event{
	std::string eventName;
	std::string date;
	std::string venue;
	std::string organizer;
};

int main()
{
	int n;
	std::cout << "Enter Number of Events: ";
	std::cin >> n;

	Event *events = new Event[n];

	for (int i = 0; i < n; ++i)
	{
		std::cout << "Event " << i + 1 << std::endl;
		std::cout << "Event Name: ";
		std::cin >> events[i].eventName;
		std::cout << "Date: ";
		std::cin >> events[i].date;
		std::cout << "Venue: ";
		std::cin >> events[i].venue;
		std::cout << "Organizer: ";
		std::cin >> events[i].organizer;
	}

	std::string date;
	std::cout << "Enter Date You Want To Search: ";
	std::cin >> date;
	std::cout << "\n";

	for (int i = 0; i < n; ++i)
	{
		if (events[i].date == date)
		{
			std::cout << "Event Name: " << events[i].eventName << std::endl;
			std::cout << "Date: " << events[i].date << std::endl;
			std::cout << "Venue: " << events[i].venue << std::endl;
			std::cout << "Organizer: " << events[i].organizer << std::endl;
			std::cout << "\n"; 
		}
	}

}