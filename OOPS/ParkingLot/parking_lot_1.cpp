#include <iostream>
#include <string>
#include <ctime>
#include <unordered_map>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// --- ENUM + HASH ---
enum class VehicleType {
    TwoWheeler,
    Car,
    Truck
};

namespace std {
    template <>
    struct hash<VehicleType> {
        size_t operator()(const VehicleType& type) const {
            return hash<int>()(static_cast<int>(type));
        }
    };
}

string vehicleTypeToString(VehicleType type) {
    switch (type) {
        case VehicleType::TwoWheeler: return "TwoWheeler";
        case VehicleType::Car: return "Car";
        case VehicleType::Truck: return "Truck";
        default: return "Unknown";
    }
}

// --- VEHICLE ---
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

// --- PARKING SPOT ---
class ParkingSpot {
public:
    int floor;
    int spotNumber;

    ParkingSpot() : floor(-1), spotNumber(-1) {} //default constructor


    ParkingSpot(int _floor, int _spotNumber)
        : floor(_floor), spotNumber(_spotNumber) {}

    void display() const {
        cout << "Floor: " << floor << ", Spot: " << spotNumber << endl;
    }
};

// --- TICKET ---
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

    int getTicketId() const {
        return ticketId;
    }

    void display() const {
        cout << "Ticket ID: " << ticketId
             << ", Check-in: " << ctime(&checkin_ts)
             << ", Checkout: " << (checkout_ts ? ctime(&checkout_ts) : string("Not yet checked out")) << endl;
        parkingSpot.display();
    }
};
int Ticket::nextId = 1;

// --- FARE CALCULATOR ---
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
        int hours = max(1L, duration / 3600); // At least 1 hour
        return hours * ratePerHour[type];
    }
};

// --- PARKING LOT ---
class ParkingLot {
private:
    unordered_map<VehicleType, vector<ParkingSpot>> availableSpots;
    unordered_map<int, ParkingSpot> allocatedSpots;

public:
    ParkingLot() {
        for (int i = 1; i <= 3; ++i) {
            availableSpots[VehicleType::TwoWheeler].emplace_back(0, i);
            availableSpots[VehicleType::Car].emplace_back(1, i);
            availableSpots[VehicleType::Truck].emplace_back(2, i);
        }
    }

    ParkingSpot allocateSpot(VehicleType type, int ticketId) {
        if (availableSpots[type].empty()) {
            throw runtime_error("No available spots for this vehicle type.");
        }
        ParkingSpot spot = availableSpots[type].back();
        availableSpots[type].pop_back();
        allocatedSpots[ticketId] = spot;
        return spot;
    }

    void freeSpot(int ticketId, VehicleType type) {
        if (allocatedSpots.find(ticketId) == allocatedSpots.end()) return;
        ParkingSpot spot = allocatedSpots[ticketId];
        availableSpots[type].push_back(spot);
        allocatedSpots.erase(ticketId);
    }

    void showAvailability() {
        cout << "\n--- Parking Availability ---\n";
        for (auto& [type, spots] : availableSpots) {
            cout << vehicleTypeToString(type) << ": " << spots.size() << " spots available\n";
        }
        cout << "----------------------------\n";
    }
};

// --- MAIN ---
int main() {
    ParkingLot lot;
    Vehicle v1(1234, VehicleType::Car);
    v1.display();

    lot.showAvailability();

    // Allocate spot and create ticket
    ParkingSpot spot = lot.allocateSpot(v1.getType(), 1);
    Ticket t1(spot);
    t1.display();

    // Simulate stay
    std::this_thread::sleep_for(std::chrono::seconds(2));
    t1.checkout();
    t1.display();

    // Calculate fare
    FareCalculator fc;
    int fare = fc.calculateFare(t1, v1.getType());
    cout << "Total Fare: Rs. " << fare << endl;

    // Free spot
    lot.freeSpot(t1.getTicketId(), v1.getType());
    lot.showAvailability();

    return 0;
}
