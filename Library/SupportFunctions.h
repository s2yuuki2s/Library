#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>


#define MAX  50

using namespace std;

struct Readers {
	char id[MAX];
	char name[MAX];
	char CMND[MAX];
	char birthday[MAX];
	char gender[MAX];
	char email[MAX];
	char address[MAX];
	char cardCreationDate[MAX];
	char cardExpirationDate[MAX];
};


struct Books {
	char ISBN[MAX];
	char bookName[MAX];
	char author[MAX];
	char NXB[MAX];
	char year[MAX];
	char type[MAX];
	char price[MAX];
};


struct BorrowAndReturn {
	char borrowedDate[MAX];
	char returnDateExpected[MAX];
	char bookISBNs[MAX];
	char borrowedReaders[MAX];
	char lateReaders[MAX];
	char borrowedIdReaders[MAX];
};
// Kiem tra thong tin ngay nhap vao
bool isValidDate(
	char inputDate[]
);
// In ra thong tin ngay het han
void getExpiryDate(
	const char issueDate[],
	char expiryDate[]
);
// Kiem tra ID
bool isIdReaderExist(
	const char ID[],
	Readers listReader[], int numberOfReaders
);

// Kiem tra ISBN
bool isISBNExist(
	const char ID[],
	Books listBook[], int numberOfBooks
);
// In thong tin doc gia
void printReader(
	Readers listReader
);
// Tinh ngay tra sach
void getReturnDate(
	const char issueDate[],
	char returnDate[]
);
// Tinh so ngay trong thang
int daysInMonth(int month, int year);
// Tinh tong so ngay 
int calculateTotalDays(int day, int month, int year);
// Tinh toan su chenh lech giua 2 khoang thoi gian
int getDifferenceInDays(
	const char Date1[],
	const char Date2[]
);

