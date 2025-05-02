/*
Vehicle             → Holds vehicle details and type
Ticket              → Holds check-in, check-out, and vehicle info
FareCalculator      → Calculates fare based on duration + vehicle type
ParkingSpot         → Keeps info about spot type, if it's available, and on which floor
ParkingLotManager   → Allocates & frees spots, maintains mapping
DisplayBoard        → Shows number of available slots per type
*/

#include <iostream>
#include <string>
#include <ctime>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

// ---- ENUM for Vehicle Type ----
enum class VehicleType {
    TwoWheeler,
    Car,
    Truck
};

string vehicleTypeToString(VehicleType type) {
    switch (type) {
        case VehicleType::TwoWheeler: return "TwoWheeler";
        case VehicleType::Car: return "Car";
        case VehicleType::Truck: return "Truck";
        default: return "Unknown";
    }
}

// ---- VEHICLE CLASS ----
class Vehicle {
private:
    int vehicleNumber;
    VehicleType vType;

public:
    Vehicle(int _vehicleNumber, VehicleType _vType)
        : vehicleNumber(_vehicleNumber), vType(_vType) {}

    VehicleType getType() const {
        return vType;
    }

    void display() const {
        cout << "Vehicle Number: " << vehicleNumber
             << ", Type: " << vehicleTypeToString(vType) << endl;
    }
};

// ---- PARKING SPOT CLASS (Placeholder) ----
class ParkingSpot {
public:
    int floor;
    int spotNumber;

    ParkingSpot(int _floor, int _spotNumber)
        : floor(_floor), spotNumber(_spotNumber) {}

    void display() const {
        cout << "Floor: " << floor << ", Spot: " << spotNumber << endl;
    }
};

// ---- TICKET CLASS ----
class Ticket {
private:
    static int nextId;
    int ticketId;
    time_t checkin_ts;
    time_t checkout_ts;
    ParkingSpot parkingSpot;

public:
    Ticket(ParkingSpot _spot)
        : parkingSpot(_spot), checkin_ts(time(nullptr)), checkout_ts(0), ticketId(nextId++) {}

    void checkout() {
        checkout_ts = time(nullptr);
    }

    time_t getCheckinTime() const {
        return checkin_ts;
    }

    time_t getCheckoutTime() const {
        return checkout_ts;
    }

    void display() const {
        cout << "Ticket ID: " << ticketId << ", Check-in: " << checkin_ts
             << ", Checkout: " << checkout_ts << endl;
        parkingSpot.display();
    }
};
int Ticket::nextId = 1;

// ---- FARE CALCULATOR CLASS ----
class FareCalculator {
private:
    unordered_map<VehicleType, int> ratePerHour = {
        {VehicleType::TwoWheeler, 20},
        {VehicleType::Car, 50},
        {VehicleType::Truck, 100}
    };

public:
    int calculateFare(const Ticket& ticket, VehicleType type) {
        time_t duration = ticket.getCheckoutTime() - ticket.getCheckinTime();
        int hours = max(1L, duration / 3600); // Round up to at least 1 hour
        return hours * ratePerHour[type];
    }
};

// ---- MAIN ----
int main() {
    Vehicle v1(1234, VehicleType::Car);
    v1.display();

    ParkingSpot ps(1, 5);
    Ticket t1(ps);
    t1.display();

    // Simulate checkout
    sleep(2); // simulate some parking time
    t1.checkout();
    t1.display();

    FareCalculator fc;
    int fare = fc.calculateFare(t1, v1.getType());
    cout << "Total Fare: Rs. " << fare << endl;

    return 0;
}
