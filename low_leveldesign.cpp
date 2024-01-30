#include <iostream>
#include <vector>

class Car {
public:
    std::string licensePlate;

    Car(const std::string& plate) : licensePlate(plate) {}
};

class ParkingSpace {
public:
    bool isOccupied;
    Car* parkedCar;

    ParkingSpace() : isOccupied(false), parkedCar(nullptr) {}
};

class ParkingLot {
private:
    std::vector<ParkingSpace> spaces;

public:
    ParkingLot(int capacity) {
        spaces.resize(capacity);
    }

    bool parkCar(Car* car) {
        for (auto& space : spaces) {
            if (!space.isOccupied) {
                space.isOccupied = true;
                space.parkedCar = car;
                return true;
            }
        }
        return false; // Parking lot is full
    }

    void removeCar(Car* car) {
        for (auto& space : spaces) {
            if (space.isOccupied && space.parkedCar == car) {
                space.isOccupied = false;
                space.parkedCar = nullptr;
                return;
            }
        }
    }

    void printParkingStatus() {
        for (int i = 0; i < spaces.size(); ++i) {
            if (spaces[i].isOccupied) {
                std::cout << "Space " << i + 1 << ": Occupied by Car with License Plate - " << spaces[i].parkedCar->licensePlate << std::endl;
            } else {
                std::cout << "Space " << i + 1 << ": Empty" << std::endl;
            }
        }
    }
};

int main() {
    ParkingLot parkingLot(10);

    Car car1("ABC123");
    Car car2("XYZ789");
     Car car6("XYZ789");

    parkingLot.parkCar(&car1);
    parkingLot.parkCar(&car2);

    parkingLot.printParkingStatus();

    parkingLot.removeCar(&car1);

    std::cout << "\nAfter removing car with license plate ABC123:\n";
    parkingLot.printParkingStatus();

    return 0;
}
