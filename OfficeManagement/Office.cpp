#include "Office.h"


//重载 运算符==
bool Office::operator==(Office& office) {
	return this == &office;
}

//无参构造函数
Office::Office() {}

//有参构造函数
Office::Office(int id, char name[64], int rank) {
	this->id = new int(id);
	this->name = new char[64];
	strcpy_s(this->name, sizeof(this->name), name);
	this->rank = new int(rank);
}

//拷贝构造函数
Office::Office(const Office& office) {
	this->id = new int(*office.id);
	this->name = new char[64];
	strcpy_s(this->name,sizeof(this->name), office.name);
	this->rank = new int(*office.rank);
}

//重载 operator= 赋值符号
Office& Office::operator=(const Office& office) {
	if (this != &office)
	{
		//清空本对象的数据
		this->deleteId();
		this->deleteName();
		this->deleteRank();

		//将需要源对象的数据赋值到本对象
		this->setId(*office.id);
		this->name = new char[64];
		strcpy_s(this->name, sizeof(this->name), office.name);
		this->rank = new int(*office.rank);
	}

	return *this;
}

//析构函数
Office::~Office() {
	deleteId();
	deleteName();
	deleteRank();
}


//get 和 set 函数
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

//删除堆区数据
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