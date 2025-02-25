#include "BookManagement.h"

void readBooksFromFile(Books listBooks[], int& numberOfBooks, char fileName[])
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
		strcpy_s(listBooks[count].ISBN, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listBooks[count].bookName, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listBooks[count].author, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listBooks[count].NXB, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listBooks[count].year, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listBooks[count].type, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listBooks[count].price, token.c_str());
		count++;
	}
	numberOfBooks = count;
	ifs.close();

}

// Ghi thong tin vao file
void writeBooks(Books listBooks[], int numberOfBooks, char fileName[])
{
	ofstream ofs(fileName);

	if (!ofs.is_open()) {
		cout << "Khong the mo file\n";
		system("pause");
		return;
	}

	for (int i = 0; i < numberOfBooks; i++)
	{
		ofs << listBooks[i].ISBN << "-"
			<< listBooks[i].bookName << "-"
			<< listBooks[i].author << "-"
			<< listBooks[i].NXB << "-"
			<< listBooks[i].year << "-"
			<< listBooks[i].type << "-"
			<< listBooks[i].price << ".\n";
	}

	ofs.close();
}


// Xem danh sach cac sach trong thu vien
void showBookList(
	Books listBook[], char fileName[]
) {

	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileName);
	cout << "==============================================================================" << endl;
	cout << "||                             THONG TIN SACH                               ||" << endl;
	cout << "==============================================================================" << endl;

	if (numberOfBooks == 0)
	{
		cout << "Danh sach hien tai khong co sach!" << endl;
		system("pause");
		return;

	}
	else {
		cout << "====================================================================================" << endl;
		for (int i = 0; i < numberOfBooks; i++)
		{
			cout << "ISBN: " << listBook[i].ISBN << "|||";
			cout << "Name: " << listBook[i].bookName << "|||";
			cout << "Author: " << listBook[i].author << "|||";
			cout << "NXB: " << listBook[i].NXB << "|||";
			cout << "Year: " << listBook[i].year << "|||";
			cout << "Type: " << listBook[i].type << "|||";
			cout << "GIa: " << listBook[i].price << "|||";
			cout << "Thu tu: " << i + 1 << "/" << numberOfBooks << "|||\n";
		}
		cout << "====================================================================================" << endl;
	}
	cout << endl;
	system("pause");

}

// Them sach
// Them sach
void addBook(
	Books listBook[], char fileName[]
) {
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileName);
	cout << "==============================================================================" << endl;
	cout << "||                               THEM SACH                                  ||" << endl;
	cout << "==============================================================================" << endl;
	cout << "Nhap thong tin sach: " << endl;

	do {
		cout << "Nhap ma sach: ";
		cin.getline(listBook[numberOfBooks].ISBN, MAX);
	} while (isISBNExist(listBook[numberOfBooks].ISBN, listBook, numberOfBooks));

	cout << "Nhap ten sach: ";
	cin.getline(listBook[numberOfBooks].bookName, MAX);

	cout << "Nhap ten tac gia: ";
	cin.getline(listBook[numberOfBooks].author, MAX);

	cout << "Nhap nha xuat ban: ";
	cin.getline(listBook[numberOfBooks].NXB, MAX);

	do {
		cout << "Nhap ngay thang nam xuat ban (dd/mm/yyyy): ";
		cin.getline(listBook[numberOfBooks].year, MAX);
	} while (!isValidDate(listBook[numberOfBooks].year));

	cout << "Nhap the loai: ";
	cin.getline(listBook[numberOfBooks].type, MAX);

	cout << "Nhap gia sach: ";
	cin.getline(listBook[numberOfBooks].price, MAX);

	numberOfBooks++;

	writeBooks(listBook, numberOfBooks, fileName);
}

// Chinh sua thong tin mot quyen sach
void editBook(
	Books listBook[], char fileName[]
) {
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileName);
	cout << "==============================================================================" << endl;
	cout << "||                              CHINH SUA SACH                              ||" << endl;
	cout << "==============================================================================" << endl;
	if (numberOfBooks == 0)
	{
		cout << "Danh sach hien tai khong co sach!" << endl;
		system("pause");
		return;
	}
	char searchChangeInformation[MAX]{};
	cout << "Nhap vao ma ISBN cua sach can thay doi thong tin: ";
	cin.getline(searchChangeInformation, MAX);

	int index = -1;
	for (int i = 0; i < numberOfBooks; ++i) {
		if (strcmp(listBook[i].ISBN, searchChangeInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay sach co ma " << searchChangeInformation << endl;
		return;
	}

	// Hien thi thong tin sach
	cout << "Thong tin sach can chinh sua:\n";
	cout << "Ma sach (ISBN): " << listBook[index].ISBN << "\n";
	cout << "Ten sach: " << listBook[index].bookName << "\n";
	cout << "Tac gia: " << listBook[index].author << "\n";
	cout << "Nha xuat ban: " << listBook[index].NXB << "\n";
	cout << "Nam xuat ban: " << listBook[index].year << "\n";
	cout << "The loai: " << listBook[index].type << "\n";
	cout << "Gia: " << listBook[index].price << "\n";
	cout << "Thu tu: " << index + 1 << "/" << numberOfBooks << "\n\n";

	while (true)
	{
		cout << "Chon thong tin can chinh sua: " << "\n";
		cout << "1. ma sach (ISBN): " << "\n";
		cout << "2. ten sach: " << "\n";
		cout << "3. Tac gia: " << "\n";
		cout << "4. Nha xuat ban: " << "\n";
		cout << "5. Nam xuat ban: " << "\n";
		cout << "6. The loai: " << "\n";
		cout << "7. GIa: " << "\n";
		cout << "0. Thoat. " << "\n";

		int option;
		cin >> option;
		cin.ignore();
		if (option == 1) {
			cout << "Nhap ma sach moi: ";
			cin.getline(listBook[index].ISBN, MAX);
		}
		else if (option == 2) {
			cout << "Nhap ten sach moi: ";
			cin.getline(listBook[index].bookName, MAX);
		}
		else if (option == 3) {
			cout << "Nhap ten tac gia moi: ";
			cin.getline(listBook[index].author, MAX);
		}
		else if (option == 4) {
			cout << "Nhap nha xuat ban moi: ";
			cin.getline(listBook[index].NXB, MAX);
		}
		else if (option == 5) {
			do {
				cout << "Nhap ngay phat hanh moi: ";
				cin.getline(listBook[index].year, MAX);
			} while (!isValidDate(listBook[index].year));

		}
		else if (option == 6) {
			cout << "Nhap the loai moi: ";
			cin.getline(listBook[index].type, MAX);

		}
		else if (option == 7) {
			cout << "Nhap gia moi: ";
			cin.getline(listBook[index].price, MAX);

		}
		else if (option == 0) {
			break;
		}
		cout << "Thong tin da duoc chinh sua!\n";

	};

	writeBooks(listBook, numberOfBooks, fileName);
}

// Xoa thong tin sach
void deleteBook(
	Books listBook[], char fileName[]
) {
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileName);
	cout << "==============================================================================" << endl;
	cout << "||                          XOA THONG TIN SACH                              ||" << endl;
	cout << "==============================================================================" << endl;
	if (numberOfBooks == 0)
	{
		cout << "Danh sach hien tai khong co sach!" << endl;
		system("pause");
		return;
	}
	char searchInformation[MAX]{};
	cout << "Nhap vao ma sach can xoa thong tin: ";

	cin.getline(searchInformation, MAX);
	//cin.ignore();

	int index = -1;
	for (int i = 0; i < numberOfBooks; ++i) {
		if (strcmp(listBook[i].ISBN, searchInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		std::cout << "Khong tim thay sach co ma can tim" << std::endl;
		system("pause");
		return;
	}

	for (int i = index; i < numberOfBooks - 1; i++) {
		strcpy_s(listBook[i].ISBN, listBook[i + 1].ISBN);
		strcpy_s(listBook[i].bookName, listBook[i + 1].bookName);
		strcpy_s(listBook[i].author, listBook[i + 1].author);
		strcpy_s(listBook[i].NXB, listBook[i + 1].NXB);
		strcpy_s(listBook[i].year, listBook[i + 1].year);
		strcpy_s(listBook[i].type, listBook[i + 1].type);
		strcpy_s(listBook[i].price, listBook[i + 1].price);
	}
	numberOfBooks--;
	writeBooks(listBook, numberOfBooks, fileName);
	cout << "Thong tin da duoc xoa" << "\n";
	system("pause");

}

// Tim kiem sach theo ISBN
void findBookByISBN(
	Books listBook[], char fileName[]
) {
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileName);
	if (numberOfBooks == 0)
	{
		cout << "Danh sach hien tai khong co sach!" << endl;
		system("pause");
		return;
	}
	char searchInformation[MAX]{};
	cout << "Nhap vao so ma sach (ISBN) cua sach can tim thong tin: ";
	cin >> searchInformation;

	int index = -1;
	for (int i = 0; i < numberOfBooks; ++i) {
		if (strcmp(listBook[i].ISBN, searchInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		std::cout << "Khong tim thay sach co ma so" << std::endl;
		system("pause");
		return;
	}

	// Hien thi thong tin doc gia
	cout << "Thong tin sach can tim la:\n";
	cout << "Ma sach (ISBN): " << listBook[index].ISBN << "\n";
	cout << "Ten sach: " << listBook[index].bookName << "\n";
	cout << "Tac gia: " << listBook[index].author << "\n";
	cout << "Nha xuat ban: " << listBook[index].NXB << "\n";
	cout << "Nam xuat ban: " << listBook[index].year << "\n";
	cout << "The loai: " << listBook[index].type << "\n";
	cout << "Gia: " << listBook[index].price << "\n\n";
	cout << "Thu tu: " << index << "/" << numberOfBooks << "\n\n";

	system("pause");
}

// Tim kiem sach theo ten sach
void findBookByBookName(
	Books listBook[], char fileName[]
) {
	int numberOfBooks = 0;
	readBooksFromFile(listBook, numberOfBooks, fileName);
	if (numberOfBooks == 0)
	{
		cout << "Danh sach hien tai khong co sach!" << endl;
		system("pause");
		return;
	}
	char searchInformation[MAX]{};
	cout << "Nhap vao so ten sach can tim thong tin: ";
	cin.getline(searchInformation, MAX);
	cin.ignore();

	int index = -1;
	for (int i = 0; i < numberOfBooks; ++i) {
		if (strcmp(listBook[i].bookName, searchInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		std::cout << "Khong tim thay sach co ten can tim " << std::endl;
		system("pause");

		return;
	}

	// Hien thi thong tin doc gia
	cout << "Thong tin sach can tim la:\n";
	cout << "Ma sach (ISBN): " << listBook[index].ISBN << "\n";
	cout << "Ten sach: " << listBook[index].bookName << "\n";
	cout << "Tac gia: " << listBook[index].author << "\n";
	cout << "Nha xuat ban: " << listBook[index].NXB << "\n";
	cout << "Nam xuat ban: " << listBook[index].year << "\n";
	cout << "The loai: " << listBook[index].type << "\n";
	cout << "Gia: " << listBook[index].price << "\n\n";
	cout << "Thu tu: " << index + 1 << "/" << numberOfBooks << "\n\n";

	system("pause");
}