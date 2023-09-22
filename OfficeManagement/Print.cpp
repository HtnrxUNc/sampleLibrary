#include "Print.h"

//��� ���˵�
void Print::printMain() {
	cout << "********************************************************" << endl;
	cout << "***************   ��ӭʹ��ְ������ϵͳ   ***************" << endl;
	cout << "******************   0.�˳�����ϵͳ   ******************" << endl;
	cout << "******************   1.����ְ����Ϣ   ******************" << endl;
	cout << "******************   2.��ʾְ����Ϣ   ******************" << endl;
	cout << "******************   3.ɾ����ְְ��   ******************" << endl;
	cout << "******************   4.�޸�ְ����Ϣ   ******************" << endl;
	cout << "******************   5.����ְ����Ϣ   ******************" << endl;
	cout << "******************   6.���ձ������   ******************" << endl;
	cout << "******************   7.��������ĵ�   ******************" << endl;
	cout << "********************************************************" << endl;
}

//��� ��ʾ�û�������
void Print::printUserInput() {
	cout << "����������ѡ��";
}

//��� ѯ���û�����ְ��������
void Print::printUserAddOfficeSum() {
	cout << "����������ְ����������";
}


//��� ѯ���û����ְ���� ID
void Print::printUserAddOfficeId() {
	cout << "���������ְ����ID��";
}

//��� ѯ���û����ְ���� ����
void Print::printUserAddOfficeName() {
	cout << "���������ְ����������";
}

//��� ѯ���û����ְ���� ����
void Print::printUserAddOfficeRank() {
	cout << "���������ְ����ְλ��" << endl;
}

//��� ���п����õ� ְλ
void Print::printAllAddRank() {
	cout << "1���ϰ�" << endl;
	cout << "2������" << endl;
	cout << "3��ְ��" << endl;
}

//��� ��ʾ����ְ������Ϣ
void Print::printOffice(Office office) {
	cout << office.getId() << "��"
		<< office.getName() << '\t'
		<< "ְλ��" << printOfficeStringRank(office.getRank()) << endl;
}

//��� ��ʾ����ְ��
void Print::printAllOffice(vector<Office>& officeList) {
	for (int i = 0; i < officeList.size(); i++)
	{
		printOffice(officeList[i]);
	}
}

//��� ְ���ĸ�λ��str���ͣ�
string Print::printOfficeStringRank(int rank) {
	if (rank == 1)
	{
		return "�ϰ�";
	}
	else if (rank == 2)
	{
		return "����";
	}
	else if (rank == 3)
	{
		return "Ա��";
	}
}

//��� ѯ���û�ɾ��ְ���� ID ���� ����
void Print::printUserDeleteOfficeIdOrName() {
	cout << "��������Ҫɾ��ְ���� ID ���� ������";
}

//��� ɾ��ʧ��
void Print::printUserDeleteOfficeFail() {
	cout << "û���ҵ���ְ����Ϣ";
}

//��� ѯ���û��޸�ְ���� ID
void Print::printUserReviseOfficeId() {
	cout << "��������Ҫ�޸�ְ���� ID��";
}

//��� ѯ���û��޸�ְ���µ� ID
void Print::printUserReviseOfiiceNewId() {
	cout << "������ְ������ ID��";
}

//��� ѯ���û�����ְ���ķ�ʽ
void Print::printUserFindOfficeWay() {
	cout << "��ѡ����ҷ�ʽ��";
}

//��� ���ҷ�ʽ
void Print::printAllFindWay() {
	cout << "1��ͨ�� ID ����" << endl;
	cout << "2��ͨ����������" << endl;
}

//��� ѯ���û�����ְ���� ID
void Print::printUserFindOfficeId() {
	cout << "���������ְ���� ID��";
}

//��� ѯ���û�����ְ���� ����
void Print::printUserFindOfficeName() {
	cout << "���������ְ���� ������";
}

//��� ѯ���û��Ƿ�ȷ���������ְ��
void Print::printUserIsClearAllOffice() {
	cout << "�Ƿ�ɾ��ȫ��ְ����Ϣ��(y/n)��";
}

//��� ��ʾ�û�������󲢵ȴ�
void Print::printUserInputErrorWiat() {
	//��� ��ʾ�û��������
	cout << "������������" << endl;
	//�ȴ��û��������
	system("pause");
}
