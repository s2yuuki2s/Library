#include "BorringBook.h"

void readBorrowFile(BorrowAndReturn BnR[], int& borringBook, char fileName[])
{
	ifstream ifs(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "Khong mo duoc file\n";
	}

	int count = 0;
	string line;
	string token;
	while (getline(ifs, line, '\n')) {
		if (line.empty()) {
			break;
		}
		stringstream ss(line);

		getline(ss, token, '-');
		strcpy_s(BnR[count].bookISBNs, token.c_str());

		getline(ss, token, '-');
		strcpy_s(BnR[count].borrowedDate, token.c_str());

		getline(ss, token, '-');
		strcpy_s(BnR[count].returnDateExpected, token.c_str());

		getline(ss, token, '-');
		strcpy_s(BnR[count].borrowedIdReaders, token.c_str());

		getline(ss, token, '-');
		strcpy_s(BnR[count].borrowedReaders, token.c_str());

		getline(ss, token, '-');
		strcpy_s(BnR[count].lateReaders, token.c_str());

		count++;
	}
	borringBook = count;
	ifs.close();
}

void writeBorrow(BorrowAndReturn BnR[], int borringBook, char fileName[])
{
	ofstream ofs(fileName);

	if (!ofs.is_open()) {
		cout << "Khong the mo file\n";
		system("pause");
		return;
	}

	for (int i = 0; i < borringBook; i++)
	{
		ofs << BnR[i].bookISBNs << "-"
			<< BnR[i].borrowedDate << "-"
			<< BnR[i].returnDateExpected << "-"
			<< BnR[i].borrowedIdReaders << "-"
			<< BnR[i].borrowedReaders << "-"
			<< BnR[i].lateReaders << ".\n";
	}
	ofs.close();
}

// Lap phieu muon sach
void borrowBook(
	BorrowAndReturn borrow[], Readers listReader[], Books listBook[],
	char borringFile[], char readerFile[], char bookFile[]
) {
	system("cls");
	// Kiem tra du lieu sach va doc gia
	int borringBooks = 0;
	int numberOfReaders = 0;
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, bookFile);
	ReadFileReaders(listReader, numberOfReaders, readerFile);

	if (numberOfReaders == 0)
	{
		cout << "Khong co du lieu doc gia!\n";
		cout << "Hay them du lieu ve doc gia!\n";
		system("pause");
		return;
	}
	if (numberOfBooks == 0)
	{
		cout << "Thu vien hien tai khong co du lieu sach!" << "\n";
		system("pause");
		return;
	}
	// Hien danh sach sach trong thu vien khi  thu vien co sach
	showBookList(listBook, bookFile);
	// Tim kiem thong tin doc gia muon sach
	char idReaderToFind[MAX]{};
	cout << "Nhap ma so cua doc gia: ";
	cin.getline(idReaderToFind, MAX);
	//cin.ignore();

	int index = -1;
	for (int i = 0; i < numberOfReaders; ++i) {
		if (strcmp(listReader[i].id, idReaderToFind) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay doc gia co ma " << idReaderToFind << endl;
		cout << "Vui long them doc gia vao thu vien\n";
		system("pause");
		return;
	}
	// In ra thong tin doc gia muon sach
	printReader(listReader[index]);

	// Nhap so luong sach muon
	int soLuongSachMuon;
	cout << "Nhap vao so sach muon muon: ";
	cin >> soLuongSachMuon;
	cin.ignore();

	if (soLuongSachMuon == 0) {
		return;
	}

	int soLuongSachMuonHienTai = soLuongSachMuon;

	if (soLuongSachMuon > numberOfBooks || soLuongSachMuon < 0) {
		cout << "Hien tai thu vien khong du so sanh ban muon muon !!!\n";
		system("pause");
		return;
	}

	// Thong tin ngay muon
	do {
		cout << "Nhap vao ngay muon sach (dd/mm/yyyy): ";
		cin.getline(borrow[borringBooks].borrowedDate, MAX);
	} while (!isValidDate(borrow[borringBooks].borrowedDate));

	// Ngay tra toi da cho phep 
	char maxDateReturn[MAX]{};
	getReturnDate(borrow[borringBooks].borrowedDate, maxDateReturn);

	// Ngay tra du kien
	while (true) {
		cout << "Nhap ngay tra du kien (toi da 7 ngay tu ngay muon): ";
		cin.getline(borrow[borringBooks].returnDateExpected, MAX);
		int diff = getDifferenceInDays(borrow[borringBooks].returnDateExpected, maxDateReturn);
		// So sanh ngay tra nhap vao co hop le khong
		if (diff > 0 && diff < 8) {
			break;
		}
		cout << "Ngay tra du kien lon hon muc cho phep vui long nhap lai" << "\n";
	};
	// Ghi nhan thong tin sach muon muon
	while (soLuongSachMuon > 0) {
		// Thong tin ve ma sach muon muon
		char ISBNOfBorrowBook[MAX]{};
		cout << "Nhap ma sach ban muon: ";
		cin.getline(ISBNOfBorrowBook, MAX);

		int indexofBorrowBooks = -1;
		for (int i = 0; i < numberOfBooks; i++)
		{
			if (strcmp(ISBNOfBorrowBook, listBook[i].ISBN) == 0) {
				indexofBorrowBooks = i;
			}
		}
		if (indexofBorrowBooks == -1) {
			cout << "Khong co ma tren trong thu vien !\n";
			system("pause");
			continue;
		}

		for (int i = 0; i < borringBooks; i++)
		{
			if (strcmp(ISBNOfBorrowBook, borrow[i].bookISBNs) == 0)
			{
				cout << "Sach da duoc muon\n";
				system("pause");
				return;
			}
		}
		// sao chep ma sach muon vao danh sach cac ma sach muon
		strcpy_s(borrow[borringBooks].bookISBNs, listBook[indexofBorrowBooks].ISBN);
		strcpy_s(borrow[borringBooks].borrowedIdReaders, listReader[index].id);
		borringBooks++;
		soLuongSachMuon--;
	}

	writeBorrow(borrow, borringBooks, borringFile);
	cout << "-----------------------------------------Thong tin muon sach----------------------------" << "\n";
	cout << "Thong tin doc gia: " << "\n";
	printReader(listReader[index]);
	cout << "Danh sach sach muon:" << "\n";
	cout << "Thong tin sach muon:\n";
	for (int i = borringBooks - soLuongSachMuonHienTai; i < borringBooks; i++) {
		for (int j = 0; j < numberOfBooks; j++) {
			if (strcmp(borrow[i].bookISBNs, listBook[j].ISBN) == 0) {
				cout << "Ma sach (ISBN): " << listBook[j].ISBN << "\n";
				cout << "Ten sach: " << listBook[j].bookName << "\n";
				cout << "Tac gia: " << listBook[j].author << "\n";
				cout << "Nha xuat ban: " << listBook[j].NXB << "\n";
				cout << "Nam xuat ban: " << listBook[j].year << "\n";
				cout << "The loai: " << listBook[j].type << "\n";
				cout << "Gia: " << listBook[j].price << "\n";
				cout << "Thu tu: " << j + 1 << "/" << numberOfBooks << "\n";
			}
		}
		//cout << bookISBNs[i] << "|||";
		cout << "Ngay muon: " << borrow[i].borrowedDate << "\n";
		cout << "Ngay tra du kien: " << borrow[i].returnDateExpected << "\n";
		cout << "\n";
	}

	system("pause");
}