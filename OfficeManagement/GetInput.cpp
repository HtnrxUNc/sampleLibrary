#include "GetInput.h"

//��ȡ �û������˵�������
//���� -1 �����������
int GetInput::getUserMainInput() {
	//���� userInput ���������ڴ洢�û�����
	int userInput;
	//���û������봫�뵽 userInput
	GetInput::getUserInput(userInput);

	//�ж� �û�������Ƿ������֣�
	//�ж� �û���������� �Ƿ���ڵ���0��
	//�ж� �û���������� �Ƿ�С��8��
	//������ǣ��򷵻� -1
	if (GetInput::ifInputIsInt(cin) 
		&& GetInput::ifInputMoreThanEqualZero(userInput) 
		&& userInput < 8)
	{
			//��� �û���������ֺϷ����򷵻��û�������
			return userInput;

	}

	//��� �û�����Ĳ������֣��������벻�Ϸ����򷵻� -1
	return -1;
}

//��ȡ �û������ְ��ʱ����Ҫ��ӵ�����
int GetInput::getUserAddOfficeSumInput() {
	//���� userInput ���������ڴ洢�û�����
	int userInput;

	//���û������봫�뵽 userInput
	GetInput::getUserInput(userInput);

	//�ж� �û�������Ƿ������֣�
	//�ж� �û���������� �Ƿ���ڵ���0��
	//������ǣ��򷵻� -1
	if (ifInputIsInt(cin) 
		&& ifInputMoreThanEqualZero(userInput))
	{
		//��� �û���������ֺϷ����򷵻��û�������
		return userInput;
	}

	//��� �û�����Ĳ������֣������û����벻�Ϸ����򷵻� -1
	return -1;
}

//��ȡ �û����ְ����ID
int GetInput::getUserAddOfficeIdInput() {
	//���� userInput ���������ڴ洢�û�����
	int userInput;

	//���û������봫�뵽 userInput
	GetInput::getUserInput(userInput);

	if (ifInputIsInt(cin) 
		&& ifInputMoreThanZero(userInput))
	{
		//��� �û���������ֺϷ����򷵻��û�������
		return userInput;
	}

	//��� �û�����Ĳ������֣������û����벻�Ϸ����򷵻� -1
	return -1;
}

//��ȡ �û����ְ���� ����
void GetInput::getUserAddOfficeNameInput(char (& name) [64]) {
	cin >> name;
}

//��ȡ �û����ְ���� ְλ
int GetInput::getUserAddOfficeRankInput() {
	//���� userInput ���������ڴ洢�û�����
	int userInput;

	//���û������봫�뵽 userInput
	GetInput::getUserInput(userInput);

	//�ж��û�������Ƿ������֣������Ƿ�Ϸ�
	if (ifInputIsInt(cin)
		&& ifInputMoreThanZero(userInput)
		&& userInput < 4)
	{
		//��� �û���������ֺϷ����򷵻��û�������
		return userInput;
	}

	//��� �û�����Ĳ������֣������û����벻�Ϸ����򷵻� -1
	return -1;
}

//��ȡ �û�ɾ��ְ���� ID ���� ����
//����û�����������֣��򷵻� true ������û�����Ĳ������֣��򷵻� false
bool GetInput::getUserDeleteOfficeIdOrName(int& deleteId, char(&deleteName)[64]) {
	//���� userInputInt ���������ڴ洢�û������ int ��������
	int userInputInt;

	//���û���������ݴ��� userInput
	getUserInput(userInputInt);

	//�ж��û�����������Ƿ�������
	if (ifInputIsInt(cin))
	{
		//�ж��û�����������Ƿ�Ϸ�
		if (ifInputMoreThanZero(userInputInt))
		{
			//����û�����Ϸ����򷵻� true ���ҽ��û�������洢�� deleteId ��
			deleteId = userInputInt;
			return true;
		}
	}
	else
	{
		//����û�����Ĳ������֣���ֱ�ӷ��� false �������û�������洢�� deleteName
		getUserInput(deleteName);
		return false;
	}
}

//��ȡ �û��޸�ְ���� id
int GetInput::getUserReviseOfficeId() {
	//���� userInput �����洢�û�����
	int userInput;

	getUserInput(userInput);

	if (ifInputIsInt(cin)
		&& ifInputMoreThanZero(userInput))
	{
		return userInput;
	}

	return -1;
}

//��ȡ �û�����ְ��ʱ�Ĳ��ҷ�ʽ
int GetInput::getUserFindOfficeWayInput() {
	//���� userInput �����洢�û�����
	int userInput;
	
	//��ȡ�û����벢�洢�� userInput
	getUserInput(userInput);

	//�ж��û������Ƿ������ֲ����Ƿ�Ϸ�
	if (ifInputIsInt(cin) 
		&& ifInputMoreThanZero(userInput))
	{
		return userInput;
	}

	return -1;
}

//��ȡ �û�����ְ���� ID
int GetInput::getUserFindOfficeId() {
	//�����������洢�û�������
	int userInput;

	//��ȡ�û�������
	getUserInput(userInput);

	//�ж��û��������Ƿ�Ϸ�
	if (ifInputIsInt(cin)
		&& ifInputMoreThanZero(userInput))
	{
		return userInput;
	}

	return -1;
}

//��ȡ �û�����ְ���� ����
void GetInput::getUserFindOfficeName(char(&name)[64]) {
	getUserInput(name);
}

//��ȡ �û��Ƿ��������ְ����Ϣ
bool GetInput::getUserIsClearAllOffice() {
	//���������洢�û��Ƿ����
	char userIsClear;

	getUserInput(userIsClear);
	
	return userIsClear == 'y' ? true : false;
}

//���� cin ״̬����� cin ����
void GetInput::reCinClearCin() {
	//���� cin ����״̬
	cin.clear();
	//����������е�����
	cin.ignore(1000, '\n');
}




//���û������봫�ݸ�����Ĳ���
void GetInput::getUserInput(int& userInput) {
	cin >> userInput;
}
//���û������봫�ݸ�����Ĳ���  
//char[64] ������ getUserInput ��������
void GetInput::getUserInput(char(&userInput)[64]) {
	cin >> userInput;
}
//���û������봫�ݸ�����Ĳ���  
//char ������ getUserInput ��������
void GetInput::getUserInput(char& userInput) {
	cin >> userInput;
}


//�ж� �û��������Ƿ�Ϊ����
bool GetInput::ifInputIsInt(std:: istream& input) {
	return !input.fail();
}

//�ж� �û��������Ƿ���� 0
bool GetInput::ifInputMoreThanZero(int userInput) {
	return userInput > 0;
}

//�ж� �û��������Ƿ���� 0
bool GetInput::ifInputEqualZero(int userInput) {
	return userInput == 0;
}

//�ж� �û��������Ƿ� ���ڵ��� 0
bool GetInput::ifInputMoreThanEqualZero(int userInput) {
	return ifInputMoreThanZero(userInput) || ifInputEqualZero(userInput);
}

//�ж� �û��������Ƿ� С������ĳ�Ա��
bool ifInputLessThanListLength(const std::vector<Office>) {
	return false;
}