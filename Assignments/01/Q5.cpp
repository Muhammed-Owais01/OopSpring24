/**
 * Programmer: Muhammed Owais 
 * Desc: Scenario 5, BOGO
 * Date: 25/02/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <vector>

class BOGOCoupon
{
private:
	std::string coupon_code, valid_from, valid_until, restaurant_code;
public:
	BOGOCoupon(std::string coupon_code, std::string valid_from, std::string valid_until)
	: coupon_code(coupon_code), valid_from(valid_from), valid_until(valid_until), restaurant_code(coupon_code.substr(0, 2)) {}

	// Getters
	std::string getCouponCode() {return this->coupon_code;}

	// Setters
	void setCouponCode(std::string coupon_code) {this->coupon_code = coupon_code;}
	void setValidFrom(std::string valid_from) {this->valid_from = valid_from;}
	void setValidUntil(std::string valid_until) {this->valid_until = valid_until;}
	void setRestaurantCode(std::string restaurant_code) {this->restaurant_code = restaurant_code;}

	bool is_valid(std::string coupon_code, std::string valid_from, std::string valid_until)
	{
		std::string matchRestaurantCode = coupon_code.substr(0, 2);
		if (this->restaurant_code != coupon_code.substr(0, 2)) return false;
		
		if (this->coupon_code == coupon_code)
		{
			if (this->valid_from == valid_from && this->valid_until == valid_until)
				return true;
		}
		return false;
	}
};

class Restaurant
{
private:
	std::string restaurant_name, location;
	std::vector<std::string> menu_list;
	std::vector<BOGOCoupon> coupon_codes;
	std::vector<int> price_list;
	static int coupons_redeemed_count;
public:
	Restaurant(std::string restaurant_name, std::string location)
	{
		this->restaurant_name = restaurant_name;
		this->location = location;

		std::cout << restaurant_name << std::endl;

		std::string temp;
		int temp2;
		
		do 
		{
			std::cout << "Enter Menu Item(Enter Nothing to Exit): ";
			getline(std::cin, temp);
			if (temp == "") break;
			menu_list.push_back(temp);

			std::cout << "Enter Price(Enter 0 to Exit): ";
			std::cin >> temp2;
			price_list.push_back(temp2);
			std::cin.ignore();
		} while (1);

		do 
		{
			std::string coupon_code, valid_from, valid_until;
			std::cout << "Enter Coupon Code(Enter Nothing To Exit): ";
			getline(std::cin, coupon_code);
			if (coupon_code == "") break;

			std::cout << "Enter Valid From: ";
			getline(std::cin, valid_from);

			std::cout << "Enter Valid Until: ";
			getline(std::cin, valid_until);

			coupon_codes.push_back(BOGOCoupon(coupon_code, valid_from, valid_until));
		} while (1);
	}
	// Setters
	void setRestaurantName(std::string restaurant_name) {this->restaurant_name = restaurant_name;}
	void setMenuList(std::string menu_item) {this->menu_list.push_back(menu_item);}
	void addCouponCodes(BOGOCoupon coupon_code) {this->coupon_codes.push_back(coupon_code);}
	void setPriceList(int price) {this->price_list.push_back(price);}
	void updateRedeemedCount() {this->coupons_redeemed_count++;}

	// Getters
	std::string getRestaurantName() {return this->restaurant_name;}
	int getCouponRedeemedCount() {return this->coupons_redeemed_count;}
	std::vector<BOGOCoupon> getCouponList() {return this->coupon_codes;}
	int getPrice(std::string item)
	{
		for (int i = 0; i < this->menu_list.size(); ++i)
		{
			if (this->menu_list[i] == item) return this->price_list[i];
		}
		return 0;
	}

	void display_menu() {
		for (int i = 0; i < menu_list.size(); i++) std::cout << "Item: " << this->menu_list[i] << ", Price: " << this->price_list[i] << std::endl;
	}
	void generate_bill(std::vector<std::string> userItems, std::vector<int> userPrices)
	{
		int total = 0;
		for (int i = 0; i < userItems.size(); ++i)
		{
			 std::cout << "Item\t\t\tPrice\n";
			 std::cout << userItems[i] << "\t\t\t" << userPrices[i] << std::endl;
			 total += userPrices[i];
		}
		std::cout << "Total\t\t\t" << total;
	}
	void apply_discount(std::vector<int>& userPrices)
	{
		for (int i = 0; i < userPrices.size(); ++i)
		{
			userPrices[i] = userPrices[i] * 0.9;
		}
		std::cout << "All Items Discounted By 10%\n";
	}
};

int Restaurant::coupons_redeemed_count = 0;

class User
{
private:
	std::string name;
	int age, mobile_number;
	std::vector<BOGOCoupon> coupons_list, redeemed_coupons_list;
public:
	User(std::string name, int age, int mobile_number) : name(name), age(age), mobile_number(mobile_number) {}

	// Getters
	std::vector<BOGOCoupon> getCouponList() {return this->coupons_list;}

	void accumulate_coupon(BOGOCoupon coupon)
	{
		this->coupons_list.push_back(coupon);
	}

	bool has_valid_coupon(BOGOCoupon coupon, Restaurant restaurant)
	{
		for (BOGOCoupon i : restaurant.getCouponList())
		{
			if (i.getCouponCode() == coupon.getCouponCode())
				return true;
		}
		return false;
	}

	void redeem_coupon(BOGOCoupon coupon, Restaurant restaurant) 
	{
		if (has_valid_coupon(coupon, restaurant))
		{
			for (int i = 0; i < restaurant.getCouponList().size(); i++)
			{
				if (restaurant.getCouponList()[i].getCouponCode() == coupon.getCouponCode())
				{
					for (int i = 0; i < this->coupons_list.size(); ++i)
					{
						if (this->coupons_list[i].getCouponCode() == coupon.getCouponCode()) coupons_list.erase(coupons_list.begin() + i);
					}
					restaurant.updateRedeemedCount();
					redeemed_coupons_list.push_back(coupon);
				}
			}
		}
	}
};

int main()
{
	std::cout << "Name: Muhammed Owais, Student ID: 23K-0047\n";
	User person("Owais", 20, 20391);
	Restaurant restaurant[2] = {
		{"Food Haven", "City Center"},
		{"Pixel Bites", "Cyber Street"}
	};

	std::cout << "Food Haven: \n";
	restaurant[0].display_menu();
	std::cout << "Pixel Bites: \n";
	restaurant[1].display_menu();

	int choice;
	std::cout << "Choose A Restaurant:\n1- Food Haven\n2- Pixel Bites\nInput: ";
	std::cin >> choice;

	std::vector<std::string> userItems;
	std::vector<int> userPrices;

	std::cin.ignore();
	while(1)
	{
		std::string item;
		std::cout << "Enter Item(Enter Nothing To Exit): ";
		getline(std::cin, item);
		if (item == "") break;
		userItems.push_back(item);
		userPrices.push_back(restaurant[choice - 1].getPrice(item));
	}

	while(1)
	{
		std::string coupon, valid_from, valid_until;
		std::cout << "Enter A Coupon(Enter Nothing To Exit): ";
		getline(std::cin, coupon);
		if (coupon == "") break;

		std::cout << "Enter Valid From: ";
		getline(std::cin, valid_from);

		std::cout << "Enter Valid Until: ";
		getline(std::cin, valid_until);

		person.accumulate_coupon(BOGOCoupon(coupon, valid_from, valid_until));
	}

	char use;
	std::cout << "Enter Y if you want to use your coupons: ";
	std::cin >> use;

	if (use == 'Y')
	{
		for (BOGOCoupon i : person.getCouponList())
		{
			person.redeem_coupon(i, restaurant[choice - 1]);
			restaurant[choice - 1].apply_discount(userPrices);
		}
	}

	restaurant[choice - 1].generate_bill(userItems, userPrices);
}