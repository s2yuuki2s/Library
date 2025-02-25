#include "SupportFunctions.h"

// Kiem tra thong tin ngay nhap vao
bool isValidDate(
	char inputDate[]
) {
	// Kiem tra do dai nhap vao
	if (strlen(inputDate) != 10) {
		return false;
	}

	// Kiem tra ki tu o vi tri
	if (inputDate[2] != '/' || inputDate[5] != '/') {
		return false;
	}

	int day, month, year;
	char delimiter = '/';

	// Chuyen ky tu sang so
	day = (inputDate[0] - '0') * 10 + (inputDate[1] - '0');
	month = (inputDate[3] - '0') * 10 + (inputDate[4] - '0');
	year = (inputDate[6] - '0') * 1000 + (inputDate[7] - '0') * 100 + (inputDate[8] - '0') * 10 + (inputDate[9] - '0');

	// Kiem tra so ngay thang nam nhap vao co nam trong khoang cho phep khong
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1 || year > 3000) {
		return false;
	}

	// Kiem tra so ngay trong thang
	int daysInMonth[] = { 31,((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (day > daysInMonth[month - 1]) {
		return false;
	}

	return true;
}

// In ra thong tin ngay het han
void getExpiryDate(
	const char issueDate[],
	char expiryDate[]
) {
	int day = (issueDate[0] - '0') * 10 + (issueDate[1] - '0');
	int month = (issueDate[3] - '0') * 10 + (issueDate[4] - '0');
	int year = (issueDate[6] - '0') * 1000 + (issueDate[7] - '0') * 100 + (issueDate[8] - '0') * 10 + (issueDate[9] - '0');

	year += 4;

	if (day < 10)
	{
		expiryDate[0] = '0';
		expiryDate[1] = '0' + static_cast<char>(day);
	}
	else
	{
		expiryDate[0] = '0' + static_cast<char>(day / 10);
		expiryDate[1] = '0' + static_cast<char>(day % 10);
	}

	if (month < 10)
	{
		expiryDate[3] = '0';
		expiryDate[4] = '0' + static_cast<char>(month);
	}
	else
	{
		expiryDate[3] = '0' + static_cast<char>(month / 10);
		expiryDate[4] = '0' + static_cast<char>(month % 10);
	}

	expiryDate[2] = '/';
	expiryDate[5] = '/';

	expiryDate[6] = '0' + static_cast<char>(year / 1000);
	expiryDate[7] = '0' + static_cast<char>((year / 100) % 10);
	expiryDate[8] = '0' + static_cast<char>((year / 10) % 10);
	expiryDate[9] = '0' + static_cast<char>(year % 10);

	// Null-terminate the result string
	expiryDate[10] = '\0';
}

// Kiem tra ID doc gia
bool isIdReaderExist(
	const char ID[],
	Readers listReader[], int numberOfReaders
) {
	for (int i = 0; i < numberOfReaders; ++i) {
		if (strcmp(ID, listReader[i].id) == 0) {
			return true; // ID da co
		}
	}
	return false; // ID chua co
}

// Kiem tra ISBN
bool isISBNExist(
	const char ID[],
	Books listBook[], int numberOfBooks
) {
	for (int i = 0; i < numberOfBooks; ++i) {
		if (strcmp(ID, listBook[i].ISBN) == 0) {
			return true; // ID da co
		}
	}
	return false; // ID chua co
}
// In thong tin doc gia
void printReader(
	Readers listReader
) {
	cout << "ID: " << listReader.id << "|||";
	cout << "Name: " << listReader.name << "|||";
	cout << "CMND/CCCD: " << listReader.CMND << "|||";
	cout << "BirthDay: " << listReader.birthday << "|||";
	cout << "Gender: " << listReader.gender << "|||";
	cout << "Email: " << listReader.email << "|||";
	cout << "Address: " << listReader.address << "|||";
	cout << "Card Creation Date: " << listReader.cardCreationDate << "|||";
	cout << "Card Expiration Date: " << listReader.cardExpirationDate << "|||";
	cout << endl;
}

// Tinh ngay tra sach
void getReturnDate(
	const char issueDate[],
	char returnDate[]
) {
	int day = (issueDate[0] - '0') * 10 + (issueDate[1] - '0');
	int month = (issueDate[3] - '0') * 10 + (issueDate[4] - '0');
	int year = (issueDate[6] - '0') * 1000 + (issueDate[7] - '0') * 100 + (issueDate[8] - '0') * 10 + (issueDate[9] - '0');

	day += 7;

	if (day > 31) {
		day -= 31;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}

	if (day < 10)
	{
		returnDate[0] = '0';
		returnDate[1] = '0' + static_cast<char>(day);
	}
	else
	{
		returnDate[0] = '0' + static_cast<char>(day / 10);
		returnDate[1] = '0' + static_cast<char>(day % 10);
	}

	if (month < 10)
	{
		returnDate[3] = '0';
		returnDate[4] = '0' + static_cast<char>(month);
	}
	else
	{
		returnDate[3] = '0' + static_cast<char>(month / 10);
		returnDate[4] = '0' + static_cast<char>(month % 10);
	}

	returnDate[2] = '/';
	returnDate[5] = '/';

	returnDate[6] = '0' + static_cast<char>(year / 1000);
	returnDate[7] = '0' + static_cast<char>((year / 100) % 10);
	returnDate[8] = '0' + static_cast<char>((year / 10) % 10);
	returnDate[9] = '0' + static_cast<char>(year % 10);

	// Null-terminate the result string
	returnDate[10] = '\0';
}
// Tinh so ngay trong thang
int daysInMonth(int month, int year) {
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return 29; // Nam nhuan
		}
		else {
			return 28; // Nam khong nhuan
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}
// Tinh tong so ngay 
int calculateTotalDays(int day, int month, int year) {
	int totalDays = 0;
	for (int y = 0; y < year; ++y) {
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
			totalDays += 366; // Nam nhuan
		}
		else {
			totalDays += 365; // Nam khong nhuan
		}
	}

	for (int m = 1; m < month; ++m) {
		totalDays += daysInMonth(m, year); // Tinh tong ngay trong cac thang truoc
	}

	totalDays += day; // So ngay o thang hien tai

	return totalDays;
}
// Tinh toan su chenh lech giua hai khoang thoi gian
// Tinh toan su chenh lech giua 2 khoang thoi gian
int getDifferenceInDays(
	const char Date1[],
	const char Date2[]
) {

	// Bien doi thanh ngay, thang, nam
	int day1 = (Date1[0] - '0') * 10 + (Date1[1] - '0');
	int month1 = (Date1[3] - '0') * 10 + (Date1[4] - '0');
	int year1 = (Date1[6] - '0') * 1000 + (Date1[7] - '0') * 100 + (Date1[8] - '0') * 10 + (Date1[9] - '0');

	int day2 = (Date2[0] - '0') * 10 + (Date2[1] - '0');
	int month2 = (Date2[3] - '0') * 10 + (Date2[4] - '0');
	int year2 = (Date2[6] - '0') * 1000 + (Date2[7] - '0') * 100 + (Date2[8] - '0') * 10 + (Date2[9] - '0');

	// Tinh ra so ngay
	int dayOther1 = calculateTotalDays(day1, month1, year1);
	int dayOther2 = calculateTotalDays(day2, month2, year2);

	// So sanh xem do chenh lech giua ngay tra toi da va ngay tra du kien
	return dayOther2 - dayOther1;
}


