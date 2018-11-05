#include "stdafx.h"
#include "BookData.h"


BookData::BookData() {
}
BookData::BookData(CString genre, CString title, CString author, CString Publisher, bool borrow) {
	this->genre = genre;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->borrow = borrow;
}


BookData::~BookData() {
}


void BookData::getBookData(CString genre, CString title, CString author, CString Publisher, bool borrow) {
	this->genre = genre;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->borrow = borrow;
}

bool BookData::compare(CString x1) {
	if (this->title == x1) {
		return 1;
	}
	else return 0;
}//å ������ ���� �Լ�


void BookData::borrowBook() {
	this->borrow = 1;
}


void BookData::receiveBook() {
	this->borrow = 0;
}

CString BookData::getBorrow() {
	if (this->borrow == 1) return _T("������");
	else return _T("��ġ��");

}
