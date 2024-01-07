#include "Readers.h"

// Doc thong tin doc gia tu file
void ReadFileReaders(Readers listReaders[], int& numberOfReaders, char fileName[])
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
		strcpy_s(listReaders[count].id, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].name, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].CMND, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].birthday, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].gender, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].email, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].address, token.c_str());

		getline(ss, token, '-');
		strcpy_s(listReaders[count].cardCreationDate, token.c_str());

		getline(ss, token, '.');
		strcpy_s(listReaders[count].cardExpirationDate, token.c_str());
		count++;
	}
	numberOfReaders = count;
	ifs.close();
}

// Ghi thong tin vao file
void WriteFileReaders(Readers listReaders[], int numberOfReaders, char fileName[])
{
	ofstream ofs(fileName);

	if (!ofs.is_open()) {
		cout << "Khong the mo file\n";
		system("pause");
		return;
	}

	for (int i = 0; i < numberOfReaders; i++)
	{
		ofs << listReaders[i].id << "-"
			<< listReaders[i].name << "-"
			<< listReaders[i].CMND << "-"
			<< listReaders[i].birthday << "-"
			<< listReaders[i].gender << "-"
			<< listReaders[i].email << "-"
			<< listReaders[i].address << "-"
			<< listReaders[i].cardCreationDate << "-"
			<< listReaders[i].cardExpirationDate << ".\n";
	}

	ofs.close();
}




// Xem danh sach doc gia trong thu vien
void showReaderList(Readers listReader[], char fileName[]) {
	int numberOfReaders = 0;
	ReadFileReaders(listReader, numberOfReaders, fileName);

	cout << "====================================================================================" << endl;
	cout << "||                               THONG TIN DOC GIA                                ||" << endl;
	cout << "====================================================================================" << endl;

	if (numberOfReaders == 0)
	{
		cout << "Danh sach hien tai khong co doc gia!" << endl;
		system("pause");
		return;
	}
	else {
		cout << "====================================================================================" << endl;
		for (int i = 0; i < numberOfReaders; i++)
		{
			cout << endl;
			cout << "ID: " << listReader[i].id << " | ";
			cout << "Name: " << listReader[i].name << " | ";
			cout << "CMND/CCCD: " << listReader[i].CMND << " | ";
			cout << "BirthDay: " << listReader[i].birthday << " | ";
			cout << "Gender: " << listReader[i].gender << " | ";
			cout << "Email: " << listReader[i].email << " | ";
			cout << "Address: " << listReader[i].address << " | ";
			cout << "Card Creation Date: " << listReader[i].cardCreationDate << " | ";
			cout << "Card Expiration Date: " << listReader[i].cardExpirationDate << " | ";
			cout << "\n\n";
		}
		cout << "====================================================================================" << endl;
	}
	system("pause");
}

// Them doc gia 
void addReader(Readers listReader[], char fileName[])
{
	int numberOfReaders;
	ReadFileReaders(listReader, numberOfReaders, fileName);
	cout << "====================================================================================" << endl;
	cout << "||                                THEM DOC GIA                                    ||" << endl;
	cout << "====================================================================================" << endl;
	cout << "Nhap thong tin doc gia: " << endl;

	// Nhap ma doc gia
	do {
		cout << "Nhap ma doc gia: ";
		cin.getline(listReader[numberOfReaders].id, MAX);
	} while (isIdReaderExist(listReader[numberOfReaders].id, listReader, numberOfReaders));

	// Nhap ten doc gia
	cout << "Nhap ten doc gia: ";
	cin.getline(listReader[numberOfReaders].name, MAX);

	// Nhap so CMMD hoac CCCD
	cout << "Nhap CMMD hoac CCCD: ";
	cin.getline(listReader[numberOfReaders].CMND, MAX);

	// Nhap ngay thang nam sinh
	do {
		cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
		cin.getline(listReader[numberOfReaders].birthday, MAX);
	} while (!isValidDate(listReader[numberOfReaders].birthday));

	// Nhap gioi tinh
	cout << "Nhap gioi tinh (nam hoac nu): ";
	cin.getline(listReader[numberOfReaders].gender, MAX);

	// Nhap dia chi email
	cout << "Nhap dia chi email (vd: absc@gmail.com): ";
	cin.getline(listReader[numberOfReaders].email, MAX);

	cout << "Nhap dia chi: ";
	cin.getline(listReader[numberOfReaders].address, MAX);

	do {
		cout << "Ngay lap the (dd/mm/yyyy): ";
		cin.getline(listReader[numberOfReaders].cardCreationDate, MAX);
	} while (!isValidDate(listReader[numberOfReaders].cardCreationDate));

	getExpiryDate(listReader[numberOfReaders].cardCreationDate, listReader[numberOfReaders].cardExpirationDate);

	++numberOfReaders;

	WriteFileReaders(listReader, numberOfReaders, fileName);
}

// Chinh sua doc gia thong tin mot doc gia
void editReader(Readers listReader[], char fileName[]) {
	int numberOfReaders;
	ReadFileReaders(listReader, numberOfReaders, fileName);

	cout << "==============================================================================" << endl;
	cout << "||                            CHINH SUA DOC GIA                             ||" << endl;
	cout << "==============================================================================" << endl;

	if (numberOfReaders == 0)
	{
		cout << "Danh sach hien tai khong co doc gia!" << endl;
		system("pause");
		return;
	}

	char searchChangeInformation[MAX]{};
	cout << "Nhap vao ma doc gia can thay doi thong tin: ";
	cin >> searchChangeInformation;

	int index = -1;
	for (int i = 0; i < numberOfReaders; ++i) {
		if (strcmp(listReader[i].id, searchChangeInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay doc gia co ma " << searchChangeInformation << endl;
		system("pause");
		return;
	}

	// Hien thi thong tin doc gia
	cout << "\nThong tin doc gia can chinh sua:\n";
	cout << "Ma doc gia: " << listReader[index].id << "\n";
	cout << "Ten doc gia: " << listReader[index].name << "\n";
	cout << "CMND hoac CCCD: " << listReader[index].CMND << "\n";
	cout << "Ngay sinh: " << listReader[index].birthday << "\n";
	cout << "Gioi tinh: " << listReader[index].gender << "\n";
	cout << "Dia chi Email: " << listReader[index].email << "\n";
	cout << "Dia chi: " << listReader[index].address << "\n";
	cout << "Ngay lap the: " << listReader[index].cardCreationDate << "\n";
	cout << "Ngay lap the: " << listReader[index].cardExpirationDate << "\n\n";

	while (true)
	{
		cout << "Chon thong tin can chinh sua: " << "\n";
		cout << "1. ma doc gia: " << "\n";
		cout << "2. ten doc gia: " << "\n";
		cout << "3. CMND hoac CCCD: " << "\n";
		cout << "4. Ngay sinh: " << "\n";
		cout << "5. Gioi tinh: " << "\n";
		cout << "6. Dia chi Email: " << "\n";
		cout << "7. Dia chi: " << "\n";
		cout << "8. Ngay lap the: " << "\n";
		cout << "0. Thoat. " << "\n";

		int option;
		cin >> option;
		cin.ignore();
		if (option == 1) {
			cout << "Nhap ma doc gia moi: ";
			cin.getline(listReader[index].id, MAX);
		}
		else if (option == 2) {
			cout << "Nhap ten moi: ";
			cin.getline(listReader[index].name, MAX);
		}
		else if (option == 3) {
			cout << "Nhap CMND moi: ";
			cin.getline(listReader[index].CMND, MAX);
		}
		else if (option == 4) {
			do {
				cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
				cin.getline(listReader[index].birthday, MAX);
			} while (!isValidDate(listReader[index].birthday));

		}
		else if (option == 5) {
			cout << "Nhap gioi tinh moi: ";
			cin.getline(listReader[index].gender, MAX);

		}
		else if (option == 6) {
			cout << "Nhap dia chi email moi (vd: absc@gmail.com): ";
			cin.getline(listReader[index].email, MAX);

		}
		else if (option == 7) {
			cout << "Nhap dia chi moi: ";
			cin.getline(listReader[index].address, MAX);

		}
		else if (option == 8) {
			do {
				cout << "Nhap ngay lap the moi (dd/mm/yyyy): ";
				cin.getline(listReader[index].cardCreationDate, MAX);
			} while (!isValidDate(listReader[index].cardCreationDate));
			getExpiryDate(listReader[index].cardCreationDate, listReader[index].cardExpirationDate);

		}
		else if (option == 0) {
			break;
		}
		cout << "Thong tin da duoc chinh sua!\n";
	};

	WriteFileReaders(listReader, numberOfReaders, fileName);
}

// Xoa thong tin mot doc gia
void deleteReader(
	Readers listReader[], char fileName[]
) {
	int numberOfReaders;
	ReadFileReaders(listReader, numberOfReaders, fileName);
	cout << "==============================================================================" << endl;
	cout << "||                          XOA THONG TIN DOC GIA                           ||" << endl;
	cout << "==============================================================================" << endl;

	if (numberOfReaders == 0)
	{
		cout << "Danh sach hien tai khong co doc gia!" << endl;
		system("pause");
		return;
	}
	char searchInformation[MAX]{};
	cout << "Nhap vao ma doc gia can xoa thong tin: ";
	cin.getline(searchInformation, MAX);


	int index = -1;
	for (int i = 0; i < numberOfReaders; ++i) {
		if (strcmp(listReader[i].id, searchInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay doc gia co ma " << searchInformation << " can tim\n";
		system("pause");
		return;
	}

	for (int i = index; i < numberOfReaders - 1; i++) {
		strcpy_s(listReader[i].id, listReader[i + 1].id);
		strcpy_s(listReader[i].name, listReader[i + 1].name);
		strcpy_s(listReader[i].CMND, listReader[i + 1].CMND);
		strcpy_s(listReader[i].birthday, listReader[i + 1].birthday);
		strcpy_s(listReader[i].gender, listReader[i + 1].gender);
		strcpy_s(listReader[i].email, listReader[i + 1].email);
		strcpy_s(listReader[i].address, listReader[i + 1].address);
		strcpy_s(listReader[i].cardCreationDate, listReader[i + 1].cardCreationDate);
		strcpy_s(listReader[i].cardExpirationDate, listReader[i + 1].cardExpirationDate);
	}
	numberOfReaders--;
	WriteFileReaders(listReader, numberOfReaders, fileName);
	cout << "Thong tin da duoc xoa" << "\n";
	system("pause");
}

// Tim kiem thong tin doc gia theo CMND/CCCD
void findReaderByCMNDOrCCCD(
	Readers listReader[], char fileName[]
) {
	int numberOfReaders;
	ReadFileReaders(listReader, numberOfReaders, fileName);
	if (numberOfReaders == 0)
	{
		cout << "Danh sach hien tai khong co doc gia!" << endl;
		system("pause");
		return;
	}
	char searchInformation[MAX]{};
	cout << "Nhap vao so CMND hoac CCCD cua doc gia can tim thong tin: ";
	cin.getline(searchInformation, MAX);


	int index = -1;
	for (int i = 0; i < numberOfReaders; ++i) {
		if (strcmp(listReader[i].CMND, searchInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay doc gia co ma CCCD hoac CMND: " << searchInformation << " can tim\n";
		system("pause");
		return;
	}

	// Hien thi thong tin doc gia
	cout << "Thong tin doc gia can tim la:\n";
	cout << "Ma doc gia: " << listReader[index].id << "\n";
	cout << "Ten doc gia: " << listReader[index].name << "\n";
	cout << "CMND hoac CCCD: " << listReader[index].CMND << "\n";
	cout << "Ngay sinh: " << listReader[index].birthday << "\n";
	cout << "Gioi tinh: " << listReader[index].gender << "\n";
	cout << "Dia chi Email: " << listReader[index].email << "\n";
	cout << "Dia chi: " << listReader[index].address << "\n";
	cout << "Ngay lap the: " << listReader[index].cardCreationDate << "\n";
	cout << "Ngay het han the: " << listReader[index].cardExpirationDate << "\n\n";

	system("pause");

}

// Tim kiem sach theo ho ten
void findReaderByName(
	Readers listReader[], char fileName[]
) {
	int numberOfReaders;
	ReadFileReaders(listReader, numberOfReaders, fileName);
	if (numberOfReaders == 0)
	{
		cout << "Danh sach hien tai khong co doc gia!" << endl;
		system("pause");
		return;
	}
	char searchInformation[MAX]{};
	cout << "Nhap vao ten cua doc gia can tim thong tin: ";
	cin.getline(searchInformation, MAX);


	int index = -1;
	for (int i = 0; i < numberOfReaders; ++i) {
		if (strcmp(listReader[i].name, searchInformation) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Khong tim thay doc gia co ten " << searchInformation << " can tim\n";
		system("pause");
		return;
	}

	// Hien thi thong tin doc gia
	cout << "Thong tin doc gia can tim la:\n";
	cout << "Ma doc gia: " << listReader[index].id << "\n";
	cout << "Ten doc gia: " << listReader[index].name << "\n";
	cout << "CMND hoac CCCD: " << listReader[index].CMND << "\n";
	cout << "Ngay sinh: " << listReader[index].birthday << "\n";
	cout << "Gioi tinh: " << listReader[index].gender << "\n";
	cout << "Dia chi Email: " << listReader[index].email << "\n";
	cout << "Dia chi: " << listReader[index].address << "\n";
	cout << "Ngay lap the: " << listReader[index].cardCreationDate << "\n";
	cout << "Ngay het han the: " << listReader[index].cardExpirationDate << "\n\n";

	system("pause");
}
