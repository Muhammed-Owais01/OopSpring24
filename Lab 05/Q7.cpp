/**
 * Programmer: Muhammed Owais 
 * Desc: Q7, Restaurant Ordering System
 * Date: 07/03/2024
 * Roll-No: 23K-0047
 */ 
#include <iostream>
#include <vector>

// Menu Item class
class MenuItem {
public:
    std::string foodName;
    double foodPrice;

    MenuItem(const std::string& name, double price) : foodName(name), foodPrice(price) {}
};

// Menu class
class Menu {
private:
    std::vector<MenuItem> menuItems;

public:
    void addItem(const std::string& name, double price) {
        menuItems.push_back(MenuItem(name, price));
    }

    void removeItem(const std::string& name) {
        menuItems.erase(
            std::remove_if(menuItems.begin(), menuItems.end(),
                           [name](const MenuItem& item) { return item.foodName == name; }),
            menuItems.end());
    }

    void displayMenu() const {
        std::cout << "Menu:\n";
        for (const auto& item : menuItems) {
            std::cout << item.foodName << " - $" << item.foodPrice << "\n";
        }
    }
};

// Payment class
class Payment {
public:
    double amount;

    Payment(double amt) : amount(amt) {}
};

// Order class
class Order {
private:
    std::vector<MenuItem> items;
    Payment payment;

public:
    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    void setPayment(const Payment& pay) {
        payment = pay;
    }

    double getTotalAmount() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.foodPrice;
        }
        return total;
    }
};

// Restaurant Ordering System class
class RestaurantOrderingSystem {
private:
    Menu menu;

public:
    void addMenuItem(const std::string& name, double price) {
        menu.addItem(name, price);
    }

    void removeMenuItem(const std::string& name) {
        menu.removeItem(name);
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    void placeOrder(const Order& order) {
        std::cout << "Order placed with a total amount of $" << order.getTotalAmount() << "\n";
    }
};

int main() {
    RestaurantOrderingSystem restaurant;

    // Adding items to the menu
    restaurant.addMenuItem("Burger", 5.99);
    restaurant.addMenuItem("Pizza", 8.99);
    restaurant.addMenuItem("Salad", 3.99);

    // Displaying the menu
    restaurant.displayMenu();

    // Placing an order
    Order order;
    order.addItem(MenuItem("Burger", 5.99));
    order.addItem(MenuItem("Pizza", 8.99));
    order.setPayment(Payment(order.getTotalAmount()));

    restaurant.placeOrder(order);

    return 0;
}