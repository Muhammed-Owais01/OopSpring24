/**
 * Programmer: Muhammed Owais 
 * Desc: Q3, ValidateString
 * Date: 26/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <string>

// Class ValidateString
class ValidateString
{
private:
	std::string sen;
public:
	// Parameterized Constructor
	ValidateString(std::string sen)
	{
		this->sen = sen;
	}

	// Const function so that the returned object value cannot be modified, else there is a chance the object value could be modified
	bool isValid() const
	{
		// Loops through the whole string
		for (int i = 0; i < sen.length(); ++i)
		{
			// If any character is not alphabet return false
			if (tolower(sen[i]) < 'a' || tolower(sen[i]) > 'z')
				return false;
		}
		return true;
	}
};

int main()
{
	// Objects
	ValidateString str1("HelloWorld");
	ValidateString str2("Hello2");

	// Validation Outputs
	(str1.isValid()) ? std::cout << "str1 is valid" << std::endl : std::cout << "str1 is not valid" << std::endl;
	(str2.isValid()) ? std::cout << "str2 is valid" << std::endl : std::cout << "str2 is not valid" << std::endl;
}