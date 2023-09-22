#pragma once
#include <iostream>
using namespace std;

class Office {
public:
	//���� �����==
	bool operator==(Office& office);

	//�޲ι��캯��
	Office();

	//�вι��캯��
	Office(int id, char name[64], int rank);

	//�������캯��
	Office(const Office& office);

	//���� operator= ��ֵ����
	Office& operator=(const Office& office);

	//��������
	~Office();


	//get �� set ����
	int getId();
	char* getName();
	int getRank();

	void setId(int id);
	void setName(char name[64]);
	void setRank(int rank);

	//ɾ����������
	void deleteId();
	void deleteName();
	void deleteRank();

private:
	int* id;
	char* name;
	int* rank;
};