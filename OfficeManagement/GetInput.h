#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include "Office.h"

class GetInput {
public:
	//��ȡ �û������˵�������
	int getUserMainInput();

	//��ȡ �û������ְ��ʱ����Ҫ��ӵ�����
	int getUserAddOfficeSumInput();

	//��ȡ �û����ְ���� ID
	int getUserAddOfficeIdInput();

	//��ȡ �û����ְ���� ����
	void getUserAddOfficeNameInput(char (& name) [64]);

	//��ȡ �û����ְ���� ְλ
	int getUserAddOfficeRankInput();

	//��ȡ �û�ɾ��ְ���� ID ���� ����
	//����û�����������֣��򷵻� true ������û�����Ĳ������֣��򷵻� false
	bool getUserDeleteOfficeIdOrName(int& deleteId,char (&deleteName) [64]);

	//��ȡ �û��޸�ְ���� id
	int getUserReviseOfficeId();

	//��ȡ �û�����ְ��ʱ�Ĳ��ҷ�ʽ
	int getUserFindOfficeWayInput();

	//��ȡ �û�����ְ���� ID
	int getUserFindOfficeId();

	//��ȡ �û�����ְ���� ����
	void getUserFindOfficeName(char(&name)[64]);

	//��ȡ �û��Ƿ��������ְ����Ϣ
	bool getUserIsClearAllOffice();

	//���� cin ״̬����� cin ����
	void reCinClearCin();


private:
	//�ж� �û�������Ƿ�������
	bool ifInputIsInt(std::istream& cin);

	//�ж� �û�����������Ƿ���� 0
	bool ifInputMoreThanZero(int userInput);

	//��ȡ �û������� �����ݸ�����Ĳ���
	void getUserInput(int& userInput);
	//���û������봫�ݸ�����Ĳ���  
	//char[64] ������ getUserInput ��������
	void getUserInput(char(&userInput)[64]);
	//���û������봫�ݸ�����Ĳ���  
	//char ������ getUserInput ��������
	void getUserInput(char& userInput);

	//�ж� �û�����������Ƿ���� 0
	bool ifInputEqualZero(int userInput);

	//�ж� �û��������Ƿ� ���ڵ��� 0
	bool ifInputMoreThanEqualZero(int userInput);

	//�ж� �û��������Ƿ� С������ĳ�Ա��
	bool ifInputLessThanListLength(const std::vector<Office>);
};