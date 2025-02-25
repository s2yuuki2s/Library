#include "Libs.h"

void mainMenu() {
	Readers listReader[MAX]{};
	Books listBook[MAX]{};
	BorrowAndReturn BnR[MAX]{};

	int totalLateReaders = 0;
	int borringBook = 0;
	int choice;
	int feature;

	char fileName[] = "Readers.txt";
	char fileNameBook[] = "Books.txt";
	char borringFile[] = "BnR.txt";
	while (true)
	{
		system("cls");
		cout << "================================================================"
			<< endl;
		cout << "|                    Library Management System                 |"
			<< endl;
		cout << "================================================================"
			<< endl;
		cout << "                     1. Quan li doc gia                         "
			<< endl;
		cout << "                     2. Quan li sach                            "
			<< endl;
		cout << "                     3. Lap phieu muon sach                     "
			<< endl;
		cout << "                     4. Lap phieu tra sach                      "
			<< endl;
		cout << "                     5. Cac thong ke co ban                     "
			<< endl;
		cout << "                     6. Thoat                                   "
			<< endl;
		cout << "================================================================"
			<< endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		cin.ignore();
		if (choice == 6) {
			break;
		}
		switch (choice)
		{
		case 1:
			while (true)
			{

				system("cls");
				cout << "================================================================"
					<< endl;
				cout << "||                       QUAN LI DOC GIA                      ||"

					<< endl;
				cout << "================================================================"
					<< endl;
				cout << "                     1. Danh sach doc gia                       "
					<< endl;
				cout << "                     2. Them doc gia                            "
					<< endl;
				cout << "                     3. Chinh sua thong tin                     "
					<< endl;
				cout << "                     4. Xoa thong tin                           "
					<< endl;
				cout << "                     5. Tim kiem doc gia theo CMND/CCCD         "
					<< endl;
				cout << "                     6. Tim kiem doc gia theo ho ten            "
					<< endl;
				cout << "                     7. Tro lai                                 "
					<< endl;
				cout << "================================================================"
					<< endl;
				cout << "Nhap lua chon cua ban: ";
				cin >> feature;
				cin.ignore();
				switch (feature)
				{
				case 1:
					system("cls");
					showReaderList(listReader, fileName);
					break;
				case 2:
					system("cls");
					addReader(listReader, fileName);
					break;

				case 3:
					system("cls");
					editReader(listReader, fileName);
					break;

				case 4:
					system("cls");
					deleteReader(listReader, fileName);
					break;

				case 5:
					system("cls");
					findReaderByCMNDOrCCCD(listReader, fileName);
					break;

				case 6:
					system("cls");
					findReaderByName(listReader, fileName);
					break;
				}
				if (feature == 7)
					break;
			}
			break;
		case 2:
			while (true)
			{
				system("cls");
				cout << "================================================================"
					<< endl;
				cout << "||                       QUAN LI SACH                         ||"

					<< endl;
				cout << "================================================================"
					<< endl;
				cout << "                     1. Danh sach sach                          "
					<< endl;
				cout << "                     2. Them sach                               "
					<< endl;
				cout << "                     3. Chinh sua thong tin sach                "
					<< endl;
				cout << "                     4. Xoa thong tin                           "
					<< endl;
				cout << "                     5. Tim kiem sach theo ma sach (ISBN)		 "
					<< endl;
				cout << "                     6. Tim kiem sach theo ten sach	         "
					<< endl;
				cout << "                     7. Tro lai                                 "
					<< endl;
				cout << "================================================================"
					<< endl;
				cout << "Nhap lua chon cua ban: ";
				cin >> feature;
				cin.ignore();
				switch (feature)
				{
				case 1:
					system("cls");

					showBookList(listBook, fileNameBook);
					break;
				case 2:
					system("cls");

					addBook(listBook, fileNameBook);
					break;
				case 3:
					system("cls");

					editBook(listBook, fileNameBook);
					break;
				case 4:
					system("cls");

					deleteBook(listBook, fileNameBook);
					break;
				case 5:
					system("cls");

					findBookByISBN(listBook, fileNameBook);
					break;
				case 6:
					system("cls");

					findBookByBookName(listBook, fileNameBook);
					break;
				}
				if (feature == 7)
					break;
			}
			break;
		case 3:
			borrowBook(BnR, listReader, listBook, borringFile, fileName, fileNameBook);
			break;
		case 4:
			while (true)
			{
				system("cls");
				cout << "================================================================" << endl;
				cout << "||                       THONG TIN TRA SACH                   ||" << endl;
				cout << "================================================================" << endl;
				cout << "                     1. Danh sach phieu muon                    " << endl;
				cout << "                     2. Tra sach                                " << endl;
				cout << "                     3. Tro lai                                 " << endl;
				cout << "================================================================" << endl;
				cout << "Nhap lua chon cua ban: " << endl;
				cin >> feature;
				switch (feature)
				{
				case 1:
					system("cls");
					listBorrowedBook(BnR, borringFile);
					break;
				case 2:
					system("cls");
					returnBook(BnR, listBook, totalLateReaders, fileNameBook, borringFile);
					break;
				}
				if (feature == 3)
					break;
			}
			break;
		case 5:
			while (true)
			{
				system("cls");
				cout << "================================================================"
					<< endl;
				cout << "||                           THONG KE                         ||"

					<< endl;
				cout << "================================================================"
					<< endl;
				cout << "                     1. So luong sach trong thu vien            "
					<< endl;
				cout << "                     2. So luong sach theo the loai             "
					<< endl;
				cout << "                     3. So luong doc gia                        "
					<< endl;
				cout << "                     4. So luong doc gia theo gioi tinh         "
					<< endl;
				cout << "                     5. So luong sach dang muon                 "
					<< endl;
				cout << "                     6. Danh sach doc gia bi tre                "
					<< endl;
				cout << "                     7. Tro lai                                 "
					<< endl;
				cout << "================================================================"
					<< endl;
				cout << "Nhap lua chon cua ban: " << endl;
				cin >> feature;
				cin.ignore();
				switch (feature)
				{
				case 1:
					system("cls");

					bookStatistics(listBook, fileNameBook);
					break;
				case 2:
					system("cls");

					bookOfType(listBook, fileNameBook);
					break;
				case 3:
					system("cls");

					totalReaders(listReader, fileName);
					break;
				case 4:
					system("cls");

					quantityReadersOfGender(listReader, fileName);
					break;
				case 5:
					system("cls");

					quantityBookBorrow(BnR, borringFile);
					break;
				case 6:
					system("cls");

					quantityLateReaders(BnR, borringFile, totalLateReaders);
					break;
				}
				if (feature == 7)
					break;
			}
			break;
		};

	};
}
