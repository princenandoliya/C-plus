🚗 Vehicle Registry System (C++ OOP Project)

A menu-driven Vehicle Registry System implemented in C++ using core Object-Oriented Programming (OOP) concepts such as inheritance, polymorphism, encapsulation, static members, and multiple inheritance.

This project allows users to register and manage different types of vehicles and display or search them dynamically at runtime.

✨ Features

Add multiple vehicle types:

Sedan

SUV

Sports Car (Electric)

Flying Car (Car + Aircraft)

Display all registered vehicles

Search vehicles by ID

Demonstrates runtime polymorphism using virtual functions

Uses static data members to track total vehicles

Menu-driven console interface

🧱 Class Structure
1. Vehicle (Base Class)

Attributes: vehicleID, manufacturer, model, year

Static member: totalVehicles

Virtual function: display()

2. Car (Derived from Vehicle)

Attribute: fuelType

3. Specialized Cars

Sedan

SUV

ElectricCar

SportsCar (inherits from ElectricCar)

4. Aircraft

   Attribute: flightRange

5. FlyingCar

Multiple inheritance from Car and Aircraft

6. VehicleRegistry

Stores vehicle objects using base-class pointers

Supports adding, displaying, and searching vehicles

🛠️ Technologies Used

Language: C++

Concepts:

Inheritance

Polymorphism

Function overriding

Static members

Dynamic memory allocation

Multiple inheritance
