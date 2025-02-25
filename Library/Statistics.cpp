#include "Statistics.h"

//Thong ke so luong sach trong thu vien
void bookStatistics(Books listBooks[], char fileNameBooks[])
{
	int numberOfBooks = 0;
	readBooksFromFile(listBooks, numberOfBooks, fileNameBooks);
	if (numberOfBooks == 0)
	{
		cout << "Hien tai thu vien khong co sach\nVui long them sach vao thu vien\n";
		system("pause");
		return;
	}

	cout << "Hien tai thu vien dang co " << numberOfBooks << " quyen sach thuoc du cac the loai.\n";
	system("pause");

}

//Thong ke so luong sach theo the loai
void bookOfType(Books listBook[], char fileNameBooks[])
{
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileNameBooks);
	if (numberOfBooks == 0)
	{
		cout << "Hien tai thu vien khong co sach\nVui long them sach vao thu vien\n";
		system("pause");
		return;
	}

	int count = 0;
	char uniqueTypes[MAX][MAX]{}; // Mang chua cac loai sach khac nhau
	int found;

	for (int i = 0; i < numberOfBooks; ++i) {
		found = 0;

		// Kiem tra loai sach da ton tai trong mang unique chua
		for (int j = 0; j < count; ++j) {
			if (strcmp(listBook[i].type, uniqueTypes[j]) == 0) {
				found = 1;
				break;
			}
		}
		// Neu chua ton tai, them vao mang, cong bien dem
		if (!found) {
			strcpy_s(uniqueTypes[count], listBook[i].type);
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		int soSach = 0;
		cout << uniqueTypes[i] << " : ";
		for (int j = 0; j < numberOfBooks; j++) {
			if (strcmp(uniqueTypes[i], listBook[j].type) == 0) {
				soSach++;
			}
		}
		cout << soSach << "\n";
	}
	system("pause");
}

//Thong ke so luong doc gia 
void totalReaders(Readers listReaders[], char fileReaders[])
{
	int numberOfReaders = 0;
	ReadFileReaders(listReaders, numberOfReaders, fileReaders);
	if (numberOfReaders == 0)
	{
		cout << "Khong co doc gia trong danh sach\nVui long them doc gia vao danh sach\n";
		system("pause");
		return;

	}
	cout << "So luong doc gia la: " << numberOfReaders << "\n";
	system("pause");

}

//Thong ke so luong doc gia theo gioi tinh
void quantityReadersOfGender(Readers listReader[], char fileReaders[])
{
	int numberOfReaders = 0;
	ReadFileReaders(listReader, numberOfReaders, fileReaders);
	if (numberOfReaders == 0)
	{
		cout << "Khong co doc gia trong danh sach\nVui long them doc gia vao danh sach\n";
		system("pause");
		return;

	}
	int nam = 0;
	int nu = 0;
	for (int i = 0; i < numberOfReaders; i++) {
		if (strcmp(listReader[i].gender, "nam") == 0)
			nam++;
		else
			nu++;
	}
	cout << "So doc gia nam: " << nam << "\n";
	cout << "So doc gia nu: " << nu << "\n";
	system("pause");
}

//Thong ke so sach dang duoc muon
void quantityBookBorrow(BorrowAndReturn BnR[], char fileBorrow[])
{
	int borringBook = 0;
	readBorrowFile(BnR, borringBook, fileBorrow);
	if (borringBook == 0)
	{
		cout << "Khong co sach duoc muon" << "\n";
		system("pause");
		return;

	}
	cout << "So quyen sach dang duoc muon la: " << borringBook << "\n";
	system("pause");
}

//Thong ke danh sach doc gia bi tre
void quantityLateReaders(BorrowAndReturn BnR[], char fileBorrow[], int totalLateReaders)
{
	int borringBooks = 0;
	readBorrowFile(BnR, borringBooks, fileBorrow);
	if (totalLateReaders == 0)
	{
		cout << "Khong co doc gia nao tra sach tre\n";
		system("pause");
		return;

	}
	cout << "Danh sach doc gia bi tre han:" << endl;
	for (int i = 0; i < totalLateReaders; i++) {
		cout << i + 1 << ": " << BnR[i].lateReaders << endl;
	}
	system("pause");

}










