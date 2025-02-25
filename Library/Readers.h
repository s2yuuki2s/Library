#pragma once
#include "SupportFunctions.h"

// Doc thong tin doc gia tu file
void ReadFileReaders(Readers listReaders[], int& numberOfReaders, char fileName[]);

// Ghi thon tin doc gia vao file
void WriteFileReaders(Readers listReaders[], int numberOfReaders, char fileName[]);

// Xem danh sach doc gia trong thu vien
void showReaderList(Readers listReader[], char fileName[]);

// Them doc gia 
void addReader(Readers listReader[], char fileName[]);

// Chinh sua thong tin mot doc gia
void editReader(Readers listReader[], char fileName[]);

// Xoa thong tin mot doc gia
void deleteReader(Readers listReader[], char fileName[]);

// Tim kiem thong tin doc gia theo CMND/CCCD
void findReaderByCMNDOrCCCD(Readers listReader[], char fileName[]);

// Tim kiem thong tin doc gia theo ho ten
void findReaderByName(Readers listReader[], char fileName[]);

