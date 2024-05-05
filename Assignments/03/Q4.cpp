#include <iostream>

class Drone
{
protected:
    float latitude, longitude, altitude, speed;
public:
    Drone(float latitude, float longitude, float altitude, float speed) : latitude(latitude), longitude(longitude), altitude(altitude), speed(speed) {}
    ~Drone(){}

    void adjustAltitude(float meters) {this->altitude = meters;}
    void setSpeed(float speed) {this->speed = speed;}
};

class Flyable
{
protected:
    
public:
    Flyable(/* args */){}
    ~Flyable(){}

    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable
{
protected:
    float radius;
public:
    Scannable(/* args */){}
    ~Scannable(){}

    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable
{
private:
    std::string cameraResolution;
    float maxFlightTime;
public:
    ReconDrone(float latitude, float longitude, float altitude, float speed, std::string cameraResolution, float maxFlightTime) 
    : Drone(latitude, longitude, altitude, speed), maxFlightTime(maxFlightTime), cameraResolution(cameraResolution) {}
    ~ReconDrone(){}

    void takeoff() override {this->speed = 20.f;}
    void land() override {this->speed = 0.f;}
    void navigateTo(float latitude, float longitude, float altitude) override
    {
        float distance;
        this->latitude = latitude;
        this->longitude = longitude;
        try
        {
            distance = altitude - this->altitude;
            if (distance < 0)
                throw("Lost Signal!\n");
        }
        catch(const char* error)
        {
            std::cout << error << '\n';
        }
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Time: " << distance / this->speed << std::endl;
        this->altitude = altitude;
    }

    void scanArea(float radius) override 
    {
        this->radius = radius;
        std::cout << "Scanned 5 Objects In " << this->radius << std::endl;    
    }
};

int main()
{
    ReconDrone myDrone(20.f, 30.f, 50.f, 0.f, "800x600", 100.f);
    myDrone.takeoff();
    myDrone.navigateTo(50.f, 60.f, 150.f);
    myDrone.scanArea(80.f);
    myDrone.land();
}