#include <iostream>
#include <string>
using namespace std;



class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        year = 0;
    }

    Vehicle(int id, string manu, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {}

    
    void setVehicleID(int id)
    {
        if (id > 0)
            vehicleID = id;
    }

   
    int getVehicleID()
    {
        return vehicleID;
    }

    void setManufacturer(string m)
    {
        manufacturer = m;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    virtual void display() const
    {
        cout << "ID             : " << vehicleID<<endl;
        cout  << "Manufacturer   : " << manufacturer<<endl;
        cout  << "Model          : " << model<<endl;
        cout << "Year           : " << year<<endl;
    }
};

int Vehicle::totalVehicles = 0;



class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle() {}

    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void display() const override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType;
    }
};



class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void display() const override
    {
        Car::display();
        cout << ", Battery: " << batteryCapacity << " kWh";
    }
};

class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void display() const override
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h";
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void display() const override
    {
        cout << "[Sedan] ";
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}

    void display() const override
    {
        cout << "[SUV] ";
        Car::display();
    }
};


class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft(int range = 0)
    {
        flightRange = range;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() const
    {
        cout << "[FlyingCar] ID: " << vehicleID<<endl;
        cout  << ", Manufacturer: " << manufacturer<<endl;
        cout  << ", Model: " << model<<endl;
        cout  << ", Year: " << year <<endl;
        cout  << ", Fuel: " << fuelType<<endl;
        cout  << ", Flight Range: " << flightRange << " km" <<endl;
    }
};


class VehicleRegistry
{
    Vehicle *vehicles[50];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle *v)
    {
        if (count < 50)
        {
            vehicles[count++] = v;
            cout << "Vehicle added successfully!\n";
        }
        else
        {
            cout << "Registry is full!\n";
        }
    }

    void displayAll() const
    {
        if (count == 0)
        {
            cout << "No vehicles found.\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            vehicles[i]->display();
            cout << endl;
        }
    }

    void searchByID(int id) const
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                vehicles[i]->display();
                cout << endl;
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do
{
    cout << "\n--- Vehicle Registry System ---\n";
    cout << "1. Add Sedan\n";
    cout << "2. Add SUV\n";
    cout << "3. Add Sports Car\n";
    cout << "4. Add Flying Car\n";
    cout << "5. View All Vehicles\n";
    cout << "6. Search by ID\n";
    cout << "7. Exit\n";

    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        int id, year;
        string man, model, fuel;

        cout << "Enter Vehicle ID : ";
        cin >> id;
        cin.ignore();

        cout << "Enter Manufacturer : ";
        getline(cin, man);

        cout << "Enter Model : ";
        getline(cin, model);

        cout << "Enter Year : ";
        cin >> year;
        cin.ignore();

        cout << "Enter Fuel Type : ";
        getline(cin, fuel);

        registry.addVehicle(new Sedan(id, man, model, year, fuel));
    }

    else if (choice == 2)
    {
        int id, year;
        string man, model, fuel;

        cout << "Enter Vehicle ID : ";
        cin >> id;
        cin.ignore();

        cout << "Enter Manufacturer : ";
        getline(cin, man);

        cout << "Enter Model : ";
        getline(cin, model);

        cout << "Enter Year : ";
        cin >> year;
        cin.ignore();

        cout << "Enter Fuel Type : ";
        getline(cin, fuel);

        registry.addVehicle(new SUV(id, man, model, year, fuel));
    }

    else if (choice == 3)
    {
        int id, year, battery, speed;
        string man, model, fuel;

        cout << "Enter Vehicle ID : ";
        cin >> id;
        cin.ignore();

        cout << "Enter Manufacturer : ";
        getline(cin, man);

        cout << "Enter Model : ";
        getline(cin, model);

        cout << "Enter Year : ";
        cin >> year;
        cin.ignore();

        cout << "Enter Fuel Type : ";
        getline(cin, fuel);

        cout << "Enter Battery Capacity (kWh) : ";
        cin >> battery;

        cout << "Enter Top Speed (km/h) : ";
        cin >> speed;

        registry.addVehicle(
            new SportsCar(id, man, model, year, fuel, battery, speed));
    }

    else if (choice == 4)
    {
        int id, year, range;
        string man, model, fuel;

        cout << "Enter Vehicle ID : ";
        cin >> id;
        cin.ignore();

        cout << "Enter Manufacturer : ";
        getline(cin, man);

        cout << "Enter Model : ";
        getline(cin, model);

        cout << "Enter Year : ";
        cin >> year;
        cin.ignore();

        cout << "Enter Fuel Type : ";
        getline(cin, fuel);

        cout << "Enter Flight Range (km) : ";
        cin >> range;

        registry.addVehicle(
            (Vehicle*) new FlyingCar(id, man, model, year, fuel, range));
    }

    else if (choice == 5)
    {
        registry.displayAll();
    }

    else if (choice == 6)
    {
        int id;
        cout << "Enter ID to search : ";
        cin >> id;
        registry.searchByID(id);
    }

    else if (choice == 7)
    {
        cout << "Exiting program...\n";
    }

    else
    {
        cout << "Invalid choice!\n";
    }

} while (choice != 7);

  

    cout << "Total Vehicles Created: " << Vehicle::totalVehicles << endl;
    return 0;
}


