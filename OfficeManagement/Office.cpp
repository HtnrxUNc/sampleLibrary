#include "Office.h"


//���� �����==
bool Office::operator==(Office& office) {
	return this == &office;
}

//�޲ι��캯��
Office::Office() {}

//�вι��캯��
Office::Office(int id, char name[64], int rank) {
	this->id = new int(id);
	this->name = new char[64];
	strcpy_s(this->name, sizeof(this->name), name);
	this->rank = new int(rank);
}

//�������캯��
Office::Office(const Office& office) {
	this->id = new int(*office.id);
	this->name = new char[64];
	strcpy_s(this->name,sizeof(this->name), office.name);
	this->rank = new int(*office.rank);
}

//���� operator= ��ֵ����
Office& Office::operator=(const Office& office) {
	if (this != &office)
	{
		//��ձ����������
		this->deleteId();
		this->deleteName();
		this->deleteRank();

		//����ҪԴ��������ݸ�ֵ��������
		this->setId(*office.id);
		this->name = new char[64];
		strcpy_s(this->name, sizeof(this->name), office.name);
		this->rank = new int(*office.rank);
	}

	return *this;
}

//��������
Office::~Office() {
	deleteId();
	deleteName();
	deleteRank();
}


//get �� set ����
int Office::getId() {
	return *this->id;
}
char* Office::getName() {
	return this->name;
}
int Office::getRank() {
	return *this->rank;
}

void Office::setId(int id) {
	deleteId();
	this->id = new int(id);
}
void Office::setName(char name[64]) {
	this->name = new char[64];
	strcpy_s(this->name, sizeof(this->name), name);
}
void Office::setRank(int rank) {
	this->rank = new int(rank);
}

//ɾ����������
void Office::deleteId() {
	if (this->id != NULL)
	{
		delete this->id;
		this->id = NULL;
	}
}
void Office::deleteName() {
	if (this->name != NULL)
	{
		delete this->name;
		this->name = NULL;
	}
}
void Office::deleteRank() {
	if (this->rank != NULL)
	{
		delete this->rank;
		this->rank = NULL;
	}
}