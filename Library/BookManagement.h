#pragma once
#include "SupportFunctions.h"

// Doc thong tin tu file
void readBooksFromFile(Books listBooks[], int& numberOfBooks, char fileName[]);

// Ghi thong tin vao file
void writeBooks(Books listBooks[], int numberOfBooks, char fileName[]);

// Xem danh sach cac sach trong thu vien
void showBookList(
	Books listBook[], char fileName[]
);
// Them sach
void addBook(
	Books listBook[], char fileName[]
);
// Chinh sua thong tin mot quyen sach
void editBook(
	Books listBook[], char fileName[]
);
// Xoa thong tin sach
void deleteBook(
	Books listBook[], char fileName[]
);
// Tim kiem sach theo ISBN
void findBookByISBN(
	Books listBook[], char fileName[]
);
// Tim kiem sach theo ten sach
void findBookByBookName(
	Books listBook[], char fileName[]
);