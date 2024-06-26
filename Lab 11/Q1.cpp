#include <iostream>

class convert
{
protected:
    float val1, val2;
public:
    convert(float val1) : val1(val1) {}

    virtual void compute() = 0;
};

class l_to_g : public convert
{
public:
    l_to_g(float val1) : convert(val1) {}
    void compute() override
    {
        this->val2 = this->val1 / 3.785;
        std::cout << this->val2 << std::endl;
    }
};

class f_to_c : public convert
{
public:
    f_to_c(float val1) : convert(val1) {}
    void compute() override
    {
        this->val2 = (this->val1 - 32.f) * (5.f/9.f);
        std::cout << this->val2 << std::endl;
    }
};


int main()
{
    convert *litres_to_gallons = new l_to_g(4);
    convert *faren_to_celc = new f_to_c(70);

    litres_to_gallons->compute();
    faren_to_celc->compute(); 
}