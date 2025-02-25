#pragma once
#include "Libs.h"

//Thong ke so luong sach trong thu vien
void bookStatistics(Books listBook[], char fileNameBooks[]);

//Thong ke so luong sach theo the loai
void bookOfType(Books listBook[], char fileNameBooks[]);

//Thong ke so luong doc gia 
void totalReaders(Readers listReaders[], char fileNameReaders[]);

//Thong ke so luong doc gia theo gioi tinh
void quantityReadersOfGender(Readers listReader[], char fileNameReaders[]);

//Thong ke so sach dang duoc muon
void quantityBookBorrow(BorrowAndReturn borrowList[], char fileBorrow[]);

//Thong ke danh sach doc gia bi tre
void quantityLateReaders(
	BorrowAndReturn BnR[], char fileBorrow[], int totalLateReaders
);

