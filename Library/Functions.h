#pragma once
#include "libs.h"
#include "SupportFunctions.h"

//================================QUAN LI DOC GIA=====================================//

// Xem danh sach doc gia trong thu vien
void showReaderList(char idReader[][MAX], char name[][MAX], char CMND[][MAX], char birthDay[][MAX],
	char gender[][MAX], char email[][MAX], char address[][MAX],
	char cardCreationDate[][MAX],
	char cardExpirationDate[][MAX], int qualityReaders);

// Them doc gia 
void addReader(char idReader[][MAX], char name[][MAX], char CMND[][MAX], char birthDay[][MAX],
	char gender[][MAX], char email[][MAX], char address[][MAX],
	char cardCreationDate[][MAX],
	char cardExpirationDate[][MAX], int& qualityReaders);

// Chinh sua doc gia thong tin mot doc gia
void editReader(char idReader[][MAX], char name[][MAX], char CMND[][MAX], char birthDay[][MAX],
	char gender[][MAX], char email[][MAX], char address[][MAX],
	char cardCreationDate[][MAX],
	char cardExpirationDate[][MAX], int qualityReaders);

// Xoa thong tin mot doc gia
void deleteReader(char idReader[][MAX], char name[][MAX], char CMND[][MAX], char birthDay[][MAX],
	char gender[][MAX], char email[][MAX], char address[][MAX],
	char cardCreationDate[][MAX],
	char cardExpirationDate[][MAX], int& qualityReaders);

// Tim kiem thong tin doc gia theo CMND/CCCD
void findReaderByCMNDOrCCCD(char idReader[][MAX], char name[][MAX], char CMND[][MAX], char birthDay[][MAX],
	char gender[][MAX], char email[][MAX], char address[][MAX],
	char cardCreationDate[][MAX],
	char cardExpirationDate[][MAX], int qualityReaders);

// Tim kiem sach theo ho ten
void findReaderByName(char idReader[][MAX], char name[][MAX], char CMND[][MAX], char birthDay[][MAX],
	char gender[][MAX], char email[][MAX], char address[][MAX],
	char cardCreationDate[][MAX],
	char cardExpirationDate[][MAX], int qualityReaders);

//===============================QUAN LI SACH======================================//

// Xem danh sach cac sach trong thu vien
void showBookList(char ISBN[][MAX], char bookName[][MAX], char author[][MAX],
	char NXB[][MAX], char year[][MAX], char type[][MAX],
	char price[][MAX], int quantity);

// Them sach
void addBook(char ISBN[][MAX], char bookName[][MAX], char author[][MAX],
	char NXB[][MAX], char year[][MAX], char type[][MAX],
	char price[][MAX], int& quantity);

// Chinh sua thong tin mot quyen sach
void editBook(char ISBN[][MAX], char bookName[][MAX], char author[][MAX],
	char NXB[][MAX], char year[][MAX], char type[][MAX],
	char price[][MAX], int quantity);

// Xoa thong tin sach
void deleteBook(char ISBN[][MAX], char bookName[][MAX], char author[][MAX],
	char NXB[][MAX], char year[][MAX], char type[][MAX],
	char price[][MAX], int& quantity);

// Tim kiem sach theo ISBN
void findBookByISBN(char ISBN[][MAX], char bookName[][MAX], char author[][MAX],
	char NXB[][MAX], char year[][MAX], char type[][MAX],
	char price[][MAX], int quantity);

// Tim kiem sach theo ten sach
void findBookByBookName(char ISBN[][MAX], char bookName[][MAX], char author[][MAX],
	char NXB[][MAX], char year[][MAX], char type[][MAX],
	char price[][MAX], int quantity);

// =======================================LAP PHIEU MUON SACH====================================//

// Lap phieu muon sach
