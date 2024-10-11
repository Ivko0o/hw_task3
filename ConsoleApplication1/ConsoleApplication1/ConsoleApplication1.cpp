#include <iostream>

using namespace std;

int main()
{
	int inputNumber = 0;
	int day = 0;
	int month = 0;
	int year = 0;
	int lengthExpiryDate = 0;
	int currentDay = 1;
	int currentMonth = 11;
	int currentYear = 2023;
	int countControlBits = 0;

	int check_Day = 31;
	int check_Month = 480;
	int check_Year = 261632;
	int check_Length_Expiry_Date = 2147418112;
	int check_Control_Bits = 1;

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
	cout << "\n" << "Year: " << year + 1900;

	//Checks the length of the expiration date in days
	lengthExpiryDate = (inputNumber & check_Length_Expiry_Date) >> 18;
	cout << "\n" << "Length of the expiry date in days: " << lengthExpiryDate;

	//Checks if the number of control bits is even or odd
	for (int i = 0; i < 31; i++) {
		if ((inputNumber & check_Control_Bits) != 0) {
			countControlBits++;
		}
		check_Control_Bits += check_Control_Bits;
	}

	cout << "\nThe number of control bits is: " << countControlBits;


	//Checks the most significant bit
	if (countControlBits % 2 == 0) {
		if ((inputNumber & (1 << 31)) == 0) {
			cout << "\n\n The number is correct!";
		}
	}

	// Has to check the most significant bit as well - not finished 
	if (countControlBits % 2 == 1) {
		if ((inputNumber & (1 << 31)) == 0) {

		}
	}





}