#include <iostream>

class Medicine
{
protected:
    std::string name, formula, manufacture_date, expiration_date;
    int price;
public:
    Medicine(std::string name, std::string formula, std::string manufacture_date, std::string expiration_date) 
    : name(name), formula(formula), manufacture_date(manufacture_date), expiration_date(expiration_date) {}

    // Getter methods
    std::string get_name() const { return name; }
    std::string get_formula() const { return formula; }
    std::string get_manufacture_date() const { return manufacture_date; }
    std::string get_expiration_date() const { return expiration_date; }
    int get_price() const { return price; }

    // Setter methods
    void set_name(const std::string& name) { this->name = name; }
    void set_formula(const std::string& formula) { this->formula = formula; }
    void set_manufacture_date(const std::string& manufacture_date) {
        this->manufacture_date = manufacture_date;
    }
    void set_expiration_date(const std::string& expiration_date) {
        this->expiration_date = expiration_date;
    }
    void set_price(int price) { this->price = price; }
        
    virtual void printDetails() {
        std::cout << "Name: " << name << std::endl
        << "Formula: " << formula << std::endl
        << "Manufacture Date: " << manufacture_date << std::endl
        << "Expiration Date: " << expiration_date << std::endl
        << "Price: $" << price << std::endl; 
    }

    bool operator == (const Medicine& obj)
    {
        return this->expiration_date == obj.expiration_date;
    }
};

class Table : public Medicine
{
private:
    int sucroseLevel;
public:
    Table(std::string name, std::string formula, std::string manufacture_date, std::string expiration_date, int sucroseLevel)
    : Medicine(name, formula, manufacture_date, expiration_date), sucroseLevel(sucroseLevel) {}

    void printDetails();
};

class CapsuleClass : public Medicine
{
private:
    int absorptionPercen;
public:
    CapsuleClass(std::string name, std::string formula, std::string manufacture_date, std::string expiration_date, int absorptionPercen)
    : Medicine(name, formula, manufacture_date, expiration_date), absorptionPercen(absorptionPercen) {}
};

class SyrupClass : public Medicine
{
public:
    SyrupClass(std::string name, std::string formula, std::string manufacture_date, std::string expiration_date)
    : Medicine(name, formula, manufacture_date, expiration_date) {}
};

class Pharmacist
{
    void Search_Medicine();
};

class Counter
{
    void Search_Medicine();
    void Update_Revenue();
};

int main()
{

}