#pragma once
#include <vector>
#include "Office.h"

#include <iostream>
using namespace std;

// ��ӡ�������
class Print {
public:
	//��� ���˵�
	void printMain();

	//��� ��ʾ�û�������
	void printUserInput();

	//��� ѯ���û�����ְ��������
	void printUserAddOfficeSum();

	//��� ѯ���û����ְ���� ID
	void printUserAddOfficeId();

	//��� ѯ���û����ְ���� ����
	void printUserAddOfficeName();

	//��� ѯ���û����ְ���� ְλ
	void printUserAddOfficeRank();

	//��� ���п����õ� ְλ
	void printAllAddRank();

	//��� ��ʾ����ְ������Ϣ
	void printOffice(Office office);

	//��� ��ʾ����ְ������Ϣ
	void printAllOffice(vector<Office>& officeList);

	//��� ְ���ĸ�λ��str���ͣ�
	string printOfficeStringRank(int rank);

	//��� ѯ���û�ɾ��ְ���� ID ���� ����
	void printUserDeleteOfficeIdOrName();

	//��� ɾ��ʧ��
	void printUserDeleteOfficeFail();

	//��� ѯ���û��޸�ְ���� ID
	void printUserReviseOfficeId();

	//��� ѯ���û��޸�ְ���µ� ID
	void printUserReviseOfiiceNewId();

	//��� ѯ���û�����ְ���ķ�ʽ
	void printUserFindOfficeWay();

	//��� ���ҷ�ʽ
	void printAllFindWay();

	//��� ѯ���û�����ְ���� ID
	void printUserFindOfficeId();

	//��� ѯ���û�����ְ���� ����
	void printUserFindOfficeName();

	//��� ѯ���û��Ƿ�ȷ���������ְ��
	void printUserIsClearAllOffice();

	//��� ��ʾ�û�������󲢵ȴ�
	void printUserInputErrorWiat();
};
