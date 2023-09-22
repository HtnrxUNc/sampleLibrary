#pragma once
#include <iostream>
using namespace std;

class Office {
public:
	//重载 运算符==
	bool operator==(Office& office);

	//无参构造函数
	Office();

	//有参构造函数
	Office(int id, char name[64], int rank);

	//拷贝构造函数
	Office(const Office& office);

	//重载 operator= 赋值符号
	Office& operator=(const Office& office);

	//析构函数
	~Office();


	//get 和 set 函数
	int getId();
	char* getName();
	int getRank();

	void setId(int id);
	void setName(char name[64]);
	void setRank(int rank);

	//删除堆区数据
	void deleteId();
	void deleteName();
	void deleteRank();

private:
	int* id;
	char* name;
	int* rank;
};