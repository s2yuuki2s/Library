#include "Return.h"

// Hien thi danh sach sach muon
void listBorrowedBook(BorrowAndReturn listBorrow[], char fileName[])
{
	int borringBook = 0;
	readBorrowFile(listBorrow, borringBook, fileName);
	system("cls");
	if (borringBook == 0) {
		cout << "Khong co sach duoc muon" << "\n";
		system("pause");
		return;
	}
	cout << "Thong tin muon sach: " << "\n";
	int idxOfreader = -1;
	for (int i = 0; i < borringBook; i++)
	{
		cout << "Ma doc gia: " << listBorrow[i].borrowedIdReaders << " | Ma sach muon: " << listBorrow[i].bookISBNs << " | Ngay muon: " << listBorrow[i].borrowedDate << " | Ngay tra du kien: " << listBorrow[i].returnDateExpected << "\n";
	}
	system("pause");
	return;
}

// Tra sach
void returnBook(
	BorrowAndReturn returnBooks[], Books listBook[],
	int& totalLateReaders, char fileNameBooks[], char borrowFile[]
) {
	int borringBook = 0;
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileNameBooks);
	readBorrowFile(returnBooks, borringBook, borrowFile);
	// Kiem tra thong tin muon sach
	if (borringBook == 0)
	{
		cout << "Hien khong co sach duoc muon" << "\n";
		system("pause");
		return;
	}
	cin.ignore();

	// Tim kiem ma doc gia de tra sach
	char idReaderReturnBook[MAX]{};
	cout << "Nhap ma cua doc gia de tra sach: ";
	cin.getline(idReaderReturnBook, MAX);

	int indexOfRederReturn = -1;
	for (int i = 0; i < borringBook; i++) {
		if (strcmp(idReaderReturnBook, returnBooks[i].borrowedIdReaders) == 0)
		{
			indexOfRederReturn = i;
			break;
		}
	}
	if (indexOfRederReturn == -1) {
		cout << "Khong tim doc gia co ma " << idReaderReturnBook << " dang muon sach" << endl;
		system("pause");
		return;
	}

	int count = 0;
	for (int i = 0; i < borringBook; i++)
	{
		if (strcmp(idReaderReturnBook, returnBooks[i].borrowedIdReaders) == 0)
			count++;
	}
	cout << "============Ban dang muon " << count << " quyen sach===================\n";
	system("pause");

	listBorrowedBook(returnBooks, borrowFile);

	// Nhap so luong sach muon tra
	int numBook;
	while (true) {
		cout << "Nhap vao so sach ban muon tra: ";
		cin >> numBook;
		cin.ignore();
		if (numBook > 0 && numBook <= borringBook) break;
		cout << "So luong sach tra khong hop le" << "\n";
	}

	// Xem thong tin ngay tra
	char returnDate[MAX]{};
	while (true)
	{
		cout << "Nhap vao ngay tra sach (dd/mm/yyyy): ";
		cin.getline(returnDate, MAX);
		if (isValidDate(returnDate) == true)
		{
			break;
		}
		cout << "Vui long nhap lai theo dung dinh dang" << "\n";
	}

	double totalMoney = 0;
	char infoLateReader[MAX]{};

	for (int i = 0; i < numBook; i++) {

		char findISBN[MAX]{};

		// Tra sach theo ma sach
		cout << "Nhap ma sach ma ban muon tra: ";
		cin.getline(findISBN, MAX);

		int found = -1;
		for (int j = 0; j < borringBook; j++) {
			if (strcmp(findISBN, returnBooks[j].bookISBNs) == 0)
			{
				found = j;
				break;
			}
		}

		if (found == -1)
		{
			cout << "Khong the tim thay ma ISBN can tim \n";
			system("pause");
			return;
		}

		char statusp[MAX]{};
		cout << "Nhap vao trang thai sach (con hay mat): ";
		cin.getline(statusp, MAX);

		if (strcmp(statusp, "mat") == 0) {
			totalMoney += atoi(listBook[found].price) * 2;
		}

		for (int j = found; j < borringBook - 1; j++)
		{
			returnBooks[j].borrowedIdReaders, MAX, returnBooks[j + 1].borrowedIdReaders;
			returnBooks[j].borrowedDate, returnBooks[j + 1].borrowedDate;
			returnBooks[j].returnDateExpected, returnBooks[j + 1].returnDateExpected;
			returnBooks[j].bookISBNs, returnBooks[j + 1].bookISBNs;
		}


		int dif = getDifferenceInDays(returnBooks[found].returnDateExpected, returnDate);

		if (dif > 0) {
			totalMoney += 5000 * dif;
			totalLateReaders++;

			strcpy_s(returnBooks[totalLateReaders - 1].lateReaders, returnBooks[found].borrowedIdReaders);
		}

		if (found == borringBook - 1) {
			cout << "Tra sach thanh cong\n";
			system("pause");
			borringBook--;
			continue;
		}
		borringBook--;
	}

	if (totalMoney > 0) {
		cout << "So tien ban phai tra la: " << totalMoney << "\n";
		system("pause");
	}

	writeBorrow(returnBooks, borringBook, borrowFile);
}





