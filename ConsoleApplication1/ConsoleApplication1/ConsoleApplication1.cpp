#include <iostream>

using namespace std;

//Needed for the counting of the days
int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year);
int dateToNumber(int day, int month, int year);

int main()
{
	unsigned int inputNumber = 0;
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

	//Checks the month of the expiry date
	month = (inputNumber & check_Month) >> 5;


	//Checks the year of the expiry date
	year = (inputNumber & check_Year) >> 9;

	//Checks the if the day and month are appropriate format
	if (day > 31) {
		cout << "\nInvalid!";
		return 0;
	}
	else if (month > 12) {
		cout << "\nInvalid!";
		return 0;
	}

	//Turns the days to numbers
	int days1 = dateToNumber(currentDay,currentMonth,currentYear);
	int days2 = dateToNumber(day, month, year+1900);
	int difference = days1 - days2;


	cout << "\nCurrent date is: 0" << currentDay << "." << currentMonth << "." << currentYear;
	cout << "\nThe production date of the product is: " << day << "." << month << "." << year + 1900;


	//Checks the length of the expiration date in days
	lengthExpiryDate = (inputNumber & check_Length_Expiry_Date) >> 18;
	cout << "\n" << "Length of the expiry date in days: " << lengthExpiryDate;



	//Checks the number of controlled bits
	for (int i = 0; i < 31; i++) {
		if ((inputNumber & check_Control_Bits) != 0) {
			countControlBits++;
		}
		check_Control_Bits += check_Control_Bits;
	}

	cout << "\n\nThe number of control bits is: " << countControlBits;


	//Checks the most significant bit
	if (countControlBits % 2 == 0) {
		if ((inputNumber & (1 << 31)) == 0) {
			cout << "\n\nThe number is correct!";
		}
		if ((inputNumber & (1 << 31)) != 0) {
			cout << "\n\nInvalid!";
			return 0;
		}
	}

	//Checks the most significant bit and turn is to 1 if the number of control bits is odd
	if (countControlBits % 2 == 1) {
		if ((inputNumber & (1 << 31)) != 1) {
			cout << "\nThe number is correct!";
		}
		if ((inputNumber & (1 << 31)) != 1) {
			inputNumber = inputNumber ^ (1 << 31);
		}
	}

	//Checks if the product is over or in the expiry date
	if (difference > lengthExpiryDate) {
		cout << "\n\nToo old!";
	}
	if (difference <= lengthExpiryDate) {
		cout << "\n\nGood!";
	}


}

//Checks if the year is a leap year
bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

//Turns the date into a number
int dateToNumber(int day, int month, int year) {
	int days = year * 365 + day;

	for (int i = 0; i < month - 1; i++) {
		days += monthDays[i];
	}

	if (month > 2 && isLeapYear(year)) {
		days += 1;
	}

	days += (year / 4) - (year / 100) + (year / 400);

	return days;
}

