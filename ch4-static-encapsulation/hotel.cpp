#include <iostream>
#include <string>
using namespace std;

class Hotel
{
private:
	int hotel_id;
	string hotel_name;
	string hotel_type;
	int hotel_rating;
	string hotel_location;
	int hotel_establish_year;
	int hotel_staff_quantity;
	int hotel_room_quantity;

	static int totalCount;

public:
	void setData(int id, string name, string type, int rating,
				 string location, int year, int staff, int room)
	{
		hotel_id = id;
		hotel_name = name;
		hotel_type = type;
		hotel_rating = rating;
		hotel_location = location;
		hotel_establish_year = year;
		hotel_staff_quantity = staff;
		hotel_room_quantity = room;

		totalCount++;
	}

	void getData(int i)
	{
		cout << "\n\nRecord of Hotel   :" << i + 1 << endl;
		cout <<"hotel id          :" <<hotel_id << endl;
		cout <<"hotel name        :"<< hotel_name << endl;
		cout <<"hotel type        :"<< hotel_type << endl;
		cout <<"hotel rating      :"<< hotel_rating << endl;
		cout <<"hotel location    :"<< hotel_location << endl;
		cout <<"establish year    :"<< hotel_establish_year << endl;
		cout <<"staff quantity    :"<< hotel_staff_quantity << endl;
		cout <<"room quantity     :"<< hotel_room_quantity << endl;
	}

	static void countHotels()
	{
		cout << "\nTotal hotels are : " << totalCount << endl;
	}
};

int Hotel::totalCount = 0;

int main()
{
	int n;

	cout << "Enter Total Hotel Index: ";
	cin >> n;

	Hotel* h = new Hotel[n];

	for (int i = 0; i < n; i++)
	{
		int id, rating, year, staff, room;
		string name, type, location;

		cout << "\nEnter Detail Of Hotel: " << i + 1 << endl;

		cout << " ID: ";
        cin >> id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Type: ";
        getline(cin, type);
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();
        cout << "Location: ";
        getline(cin, location);
        cout << "Year: ";
        cin >> year;
        cin.ignore();
        cout << "Staff quantity: ";
        cin >>staff;
        cin.ignore();

        cout << "Room quantity: ";
        cin >>room;
        cin.ignore();

		h[i].setData(id, name, type, rating, location, year, staff, room);
	}

	for (int i = 0; i < n; i++)
	{
		h[i].getData(i);
	}

	Hotel::countHotels();

	
	return 0;
}
