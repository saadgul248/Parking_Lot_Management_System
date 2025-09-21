#include <iostream>
using namespace std;

const int SIZE = 5;

// ===== LOGIN FUNCTION =====
bool login() {
    string username, password;
    const string correctUsername = "admin";
    const string correctPassword = "1234";

    cout << "===== PARKING LOT LOGIN =====\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "Login successful!\n\n";
        return true;
    } else {
        cout << "Login failed! Access denied.\n\n";
        return false;
    }
}

// ===== PARKING SYSTEM FUNCTIONS =====
void displayParking(string lot[], int totalParked) {
    cout << "\n===== PARKING LOT STATUS =====\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i + 1 << ": " << lot[i] << endl;
    }

    int available = 0;
  
  for (int i = 0; i < SIZE; i++) {
        if (lot[i] == "Empty") {
            available++;
        }
    }

    cout << "\nAvailable Slots: " << available << endl;
    cout << "Total Vehicles Ever Parked: " << totalParked << endl;
    cout << "===============================\n";
}

bool parkVehicle(string lot[], string plate, int &totalParked) {
    for (int i = 0; i < SIZE; i++) {
        if (lot[i] == plate) {
            cout << "This vehicle is already parked in Slot " << i + 1 << endl;
            return false;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (lot[i] == "Empty") {
            lot[i] = plate;
            totalParked++;
            cout << "Vehicle parked in Slot " << i + 1 << endl;
            return true;
        }
    }

    cout << "Parking Lot is Full!" << endl;
    return false;
}
bool removeVehicle(string lot[], string plate) {
    for (int i = 0; i < SIZE; i++) {
        if (lot[i] == plate) {
            lot[i] = "Empty";
            cout << "Vehicle removed from Slot " << i + 1 << endl;
            return true;
        }
    }
    cout << "Vehicle not found!" << endl;
    return false; }

void searchVehicle(string lot[]) {
    string plate;
    cout << "Enter license plate to search: ";
    cin >> plate;

    for (int i = 0; i < SIZE; i++) {
        if (lot[i] == plate) {
            cout << "Vehicle found in Slot " << i + 1 << endl;
            return;
        }
    }

    cout << "Vehicle not found!" << endl;
}

// ===== MAIN FUNCTION =====
int main() {
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts) {
        if (login()) {
            break; // success
        }
        attempts++;
        if (attempts == maxAttempts) {
            cout << "Too many failed attempts. Program will now exit.\n";
            return 0;
        }
        cout << "Attempts left: " << (maxAttempts - attempts) << "\n";
    }

    string lot[SIZE];
    int totalParked = 0;

    for (int i = 0; i < SIZE; i++) {
        lot[i] = "Empty";
    }



    int choice;
    string plate;

    do {
        cout << "\n===== PARKING MENU =====\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Parking Lot\n";
        cout << "4. Search Vehicle by Plate\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "Enter license plate: ";
            cin >> plate;
            parkVehicle(lot, plate, totalParked);
        }
        else if (choice == 2) {
            cout << "Enter license plate: ";
            cin >> plate;
            removeVehicle(lot, plate);
        }
        else if (choice == 3) {
            displayParking(lot, totalParked);
        }
        else if (choice == 4) {
            searchVehicle(lot);
        }
        else if (choice == 5) {
            cout << "Final Parking Lot Summary:\n";
            displayParking(lot, totalParked);
            cout << "Thank you for using the Parking Lot System!\n";
        }
        else {
            cout << "Invalid input! Try again.\n";
        }

    } while (choice != 5);
}
