
Hotel Management System





https://www.youtube.com/watch?v=Hb6WePtPQhg&ab_channel=SoumyajitBhattacharyay





https://drive.google.com/file/d/1GFDk4DBOtefSbuUioAQ5D3T2-cH9m47l/view




https://drive.google.com/file/d/1QYX6zvIHREdJ6PjVt5-tVH-nj18F_-Zz/view



Design an online hotel booking system



Main Classes :

User
Room
Hotel
Booking
Adress




Enums :

public enum RoomStatus {
    EMPTY
    NOT_EMPTY;
}

public enum RoomType{
    SINGLE,
    DOUBLE,
    TRIPLE;
}

public enum PaymentStatus {
    PAID,
    UNPAID;
}

class User{

int userId;
String name;
Date dateOfBirth;
String mobNo;
String emailId;
String sex;
}

// For the room in any hotel
class Room{

int roomId;
int hotelId;
RoomType roomType;
RoomStatus roomStatus;
}

class Hotel{

int hotelId;
String hotelName;
Adress adress;
List<Room> rooms; // hotel contains the list of rooms
float rating;
Facilities facilities;
}

// a new booking is created for each booking done by any user
class Booking{
    int bookingId;
    int userId;
    int hotelId; 
    List<Rooms> bookedRooms; 
    int amount;
    PaymentStatus status_of_payment;
    Time bookingTime;
    Duration duration;
}

class Adress{

string city;
string pinCode;
string streetNo;
string landmark;
}

class Duration{

Time from;
Tiime to;
}

class Facilities{

bool provides_lift;
bool provides_power_backup;
bool provides_hot_water;
bool provides_breakfast_free;
}


System Requirements
We'll focus on the following set of requirements while designing the Hotel Management System:

The system should support the booking of different room types like standard, deluxe, family suite, etc.

Guests should be able to search room inventory and book any available room.

The system should be able to retrieve information like who book a particular room or what are the rooms booked by a specific customer.

The system should allow customers to cancel their booking. Full refund if the cancelation is done before 24 hours of check-in date.

The system should be able to send notifications whenever the booking is near check-in or check-out date.

The system should maintain a room housekeeping log to keep track of all housekeeping tasks.

Any customer should be able to add room services and food items.

Customers can ask for different amenities.

The customers should be able to pay their bills through credit card, check or cash.
  
  
  
  class Guest{
String name;
int guestId;
String phoneNumber;
List booking;
}

class Booking{
int userId;
Room room;
}

class Room{
int roomId;
int floorNumber;
RoomType roomType;
List reservationDetails;
int roomPrice;
}

enum RoomType{
SINGLE;
DOUBLE;
TRIPLE;
}

class Reservation{
int reservationId;
Date startDate,endDate;
Guest guest;
Payment payment;
}

class Payment{
int paymentId;
boolean status;
}

class Hotel{
int hotelId;
String hotelName;
List rooms;
Address address;
int rating;

}

class Address{
String city;
String state;
String street;
int zipCode;
String doorNumber;
}
