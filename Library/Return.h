#pragma once
#include "BorringBook.h"

// Hien thi danh sach sach muon
void listBorrowedBook(
	BorrowAndReturn listBorrow[], char fileName[]
);

// Tra sach
void returnBook(
	BorrowAndReturn returnBooks[], Books listBook[],
	int& totalLateReaders, char fileNameBooks[], char borrowFile[]
);
