#pragma once
#include "BookManagement.h"
#include "Readers.h"

// Doc File
void readBorrowFile(BorrowAndReturn BnR[], int& borringBook, char fileName[]);

// Ghi File
// 
void writeBorrow(BorrowAndReturn BnR[], int borringBook, char fileName[]);
// Lap phieu muon sach
void borrowBook(
	BorrowAndReturn borrow[], Readers listReader[], Books listBook[],
	char borringFile[], char readerFile[], char bookFile[]
);

