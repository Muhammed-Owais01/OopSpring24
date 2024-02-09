#include <iostream>

using namespace std;

class BoardMarker {
private:
	string brand, shade;
	bool refill, inkStatus;
public:
	BoardMarker()
	: refill(false), inkStatus(false)
	{}

	// Getter
	string getBrand(){return brand;}
	string getShade(){return shade;}
	bool getRefill(){return refill;}
	bool getInkStatus(){return inkStatus;}

	// Setter
	void setBrand(string brand) {this->brand = brand;}
	void setShade(string shade) {this->shade = shade;}
	void setRefill(bool refill) {this->refill = refill;}
	void setInkStatus(bool inkStatus) {this->inkStatus = inkStatus;}

	// Functions
	void writing()
	{
		(refill == true) ? cout << "Ink can be refilled\n" : cout << "Ink cannot be refilled\n";
	}

	void canRefill()
	{
		(inkStatus == true) ? cout << "Ink Depleted\n" : cout << "Ink Not Depleted\n";
	}
};

int main()
{
	BoardMarker marker;
	marker.setBrand("Dollar");
	marker.setShade("Black");
	marker.setRefill(false);
	marker.setInkStatus(false);

	cout << "Brand: " << marker.getBrand() << "\nShade: " << marker.getShade() << endl; 

	marker.writing();
	marker.canRefill();
}