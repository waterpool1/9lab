#include "objects.h"

Objects::Objects()
{
}
bool AbstractCar::drive(int kilometres)
{
    bool tffuel = true;
    if (fuel >= fuelrate * kilometres) {
        fuel = fuel - fuelrate * kilometres;
        cout << "Passed " << kilometres << " km " << endl;
        mileage += kilometres;

    }
    else {
        cout << "Not enough fuel" << endl;
        tffuel = false;
    }
    return tffuel;
};
void AbstractCar::refuel()
{
    fuel = tank; cout << "You refueled " << endl;
};
void AbstractCar::printStatus()
{
    int pr;
    float pp = 100 * fuel / tank;
    cout << "Fuel: " << fuel / 1000 << "/" << tank / 1000 << " ";
    pr = 10 * fuel / tank;
    for (int i = 0; i < 10; i++) {
        if (pr > i)
        {
            cout << "[+]";
        }
        else
        {
            cout << "[ ]";
        }
    }
    cout << " " << pp << "%";
    cout << endl << "You can drive no more than " << fuel / fuelrate << " км. " << endl;
    cout << "Mileage: " << mileage << " km" << endl;
};
Sedan::Sedan()
{
    tank = 40000;
    fuelrate = 80;
    fuel = 0;
    mileage = 0;
}
Bus::Bus()
{
    tank = 120000;
    fuelrate = 200;
    fuel = 0;
    mileage = 0;
}
Suv::Suv()
{
    tank = 70000;
    fuelrate = 130;
    fuel = 0;
    mileage = 0;
}
Bicycle::Bicycle(){ mileage = 0;}
bool Bicycle::drive(int kilometres)
{
    cout << "Have you passed " << kilometres << " km" << endl;
    mileage += kilometres;
    return true;
};
void Bicycle::refuel() { cout << "The bike can't be refueled :/" << endl; };

    void Bicycle::printStatus()
    {
        cout << "Mileage: " << mileage << "km" << endl;
    };

    void Route::addPoint(const RoutePoint& point)
    {
        vpoint.push_back(point);

    };
    bool Route::run(IVehicle* vehicle)
    {
        travel = 0;
        if (vpoint.size() < 2)
        {
            cout << "Error. Add more than 1 waypoint. Now you have such a number of points:" << vpoint.size() << endl;
            return false;
        }
        else
        {
            int f = 1;

            for (int i = 1; i < vpoint.size(); i++)
            {
                travel = sqrt(pow(vpoint[i].xKm - vpoint[i - 1].xKm, 2) + pow(vpoint[i].yKm - vpoint[i - 1].yKm, 2));
                if (vehicle->drive(travel) == true)
                {
                    cout << "You have passed from the point '" << vpoint[i - 1].name << "' to the point '" << vpoint[i].name << "' " << endl;
                    f++;
                }
                else
                {
                    vehicle->refuel();
                    --i;
                    --f;
                }
                if (f < 0)
                {
                    cout << "Error! You don't have enough tank to overcome one of the points. " << endl;
                    break;
                }
            }
        }
        return true;
    };
    double AbstractCar::getFuelLevel(){return this->fuel;};
    double AbstractCar::getMilage(){return this->mileage;};
    float Bicycle::getBiMilage(){return this->mileage;};
    int Route::getTravel(){return this->travel;};
