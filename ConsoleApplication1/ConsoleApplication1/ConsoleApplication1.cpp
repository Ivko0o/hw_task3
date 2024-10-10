#include <iostream>

using namespace std;

int main()
{
	unsigned int inputNumber = 0;
	int day = 0;
	int month = 0;
	int year = 0;

	int check_Day = 31;
	int check_Month = 480;
	int check_Year = 261632;

	//Takes a number from the user
	cout << "Enter a whole positive number to check the expiry date of a product: ";
	cin >> inputNumber;

	//Checks the day of the expiry date
	day = inputNumber & check_Day;
	cout << "\n" << "Day: " << day;

	//Checks the month of the expiry date
	month = (inputNumber & check_Month) >> 5;
	cout << "\n" << "Month: " << month;

	//Checks the year of the expiry date
	year = (inputNumber & check_Year) >> 9;
	cout << "\n" << "Year: " << year;

	//Test

}