#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Room {
    int roomNumber;
    string roomType;
    double price;
    bool isBooked;
};

struct Booking {
    int bookingId;
    int roomNumber;
    string customerName;
    int days;
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    vector<Booking> bookings;
    int nextBookingId;

public:
    HotelManagementSystem() : nextBookingId(1) {
        // Initialize with some sample rooms
        rooms.push_back({ 101, "Single", 100.0, false });
        rooms.push_back({ 102, "Double", 150.0, false });
        rooms.push_back({ 103, "Suite", 200.0, false });
    }

    void addRoom() {
        Room room;
        cout << "Enter room number: ";
        cin >> room.roomNumber;
        cout << "Enter room type: ";
        cin >> room.roomType;
        cout << "Enter room price: ";
        cin >> room.price;
        room.isBooked = false;
        rooms.push_back(room);
        cout << "Room added successfully.\n";
    }

    void bookRoom() {
        int roomNumber;
        cout << "Enter room number to book: ";
        cin >> roomNumber;
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && !room.isBooked) {
                Booking booking;
                booking.bookingId = nextBookingId++;
                booking.roomNumber = room.roomNumber;
                cout << "Enter customer name: ";
                cin >> booking.customerName;
                cout << "Enter number of days: ";
                cin >> booking.days;
                bookings.push_back(booking);
                room.isBooked = true;
                cout << "Room booked successfully.\n";
                return;
            }
        }
        cout << "Room is not available or doesn't exist.\n";
    }

    void checkoutRoom() {
        int bookingId;
        cout << "Enter booking ID to checkout: ";
        cin >> bookingId;
        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->bookingId == bookingId) {
                for (auto& room : rooms) {
                    if (room.roomNumber == it->roomNumber) {
                        room.isBooked = false;
                        break;
                    }
                }
                bookings.erase(it);
                cout << "Checked out successfully.\n";
                return;
            }
        }
        cout << "Booking ID not found.\n";
    }

    void listRooms() {
        cout << setw(10) << "Room No" << setw(20) << "Type" << setw(10) << "Price" << setw(10) << "Status" << '\n';
        for (const auto& room : rooms) {
            cout << setw(10) << room.roomNumber << setw(20) << room.roomType << setw(10) << room.price << setw(10) << (room.isBooked ? "Booked" : "Available") << '\n';
        }
    }

    void listBookings() {
        cout << setw(10) << "Booking ID" << setw(10) << "Room No" << setw(20) << "Customer Name" << setw(10) << "Days" << '\n';
        for (const auto& booking : bookings) {
            cout << setw(10) << booking.bookingId << setw(10) << booking.roomNumber << setw(20) << booking.customerName << setw(10) << booking.days << '\n';
        }
    }
};

int main() {
    HotelManagementSystem hotel;
    int choice;

    do {
        cout << "\nHotel Management System\n";
        cout << "1. Add Room\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout Room\n";
        cout << "4. List Rooms\n";
        cout << "5. List Bookings\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.addRoom();
            break;
        case 2:
            hotel.bookRoom();
            break;
        case 3:
            hotel.checkoutRoom();
            break;
        case 4:
            hotel.listRooms();
            break;
        case 5:
            hotel.listBookings();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
