#include <iostream>
#include <string>
using namespace std;
#include "Print.h"
#include "GetInput.h"
#include "ReadWriteFiles.h"

void test01(vector<Office> &officeList) {
	char name1[64] = {0};
	char name2[64] = {0};
	char name3[64] = {0};

	name1[0] = 'z';
	name2[0] = 'x';
	name3[0] = 'c';


	Office office1(1 ,name1,1);
	Office office2(2 ,name2,2);
	Office office3(3 ,name3,3);

	officeList.emplace_back(office1);
	officeList.emplace_back(office2);
	officeList.emplace_back(office3);
}

void run() {
	//ʵ���� ��ӡ��� ����
	Print print;
	//����һ�� bool �������ڼ���Ƿ��˳�ϵͳ
	bool flag = true;
	//ʵ���� ��ȡ�û����� ����
	GetInput getInput;
	//����һ�� int �������ڻ�ȡ�û�������
	int userInput;
	//����һ�� vector �洢 office
	vector<Office> officeList;
	//����һ�� ReadWriteFiles �����ļ�����
	ReadWriteFiles readWriteFiles;

	//���Զ�ȡ�ļ�
	readWriteFiles.readFile("Office.txt", officeList);

	test01(officeList);

	while (flag)
	{
		//��� ���˵�
		print.printMain();
		//��� ��ʾ�û�������
		print.printUserInput();
		//��ȡ �û������˵�������
		userInput = getInput.getUserMainInput();

		
		//�ж� �û�����ı���Ƕ��٣����ö�Ӧ�Ĺ���
		//�ж� �û��Ƿ���Ҫ�˳�����
		if (userInput == 0)
		{
			flag = false;
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫ���ְ��
		else if (userInput == 1)
		{
			//��� ѯ���û����ְ��������
			print.printUserAddOfficeSum();
			//��ȡ �û���Ҫ��ӵ�ְ������
			userInput = getInput.getUserAddOfficeSumInput();

			//�ж� �û��������Ƿ�Ϸ�
			if (userInput != -1)
			{
				//�������Ϸ����򴴽��������洢����ְ����Ҫ������
				int id;
				char name[64];
				int rank;

				//ѭ���û���������ְ������
				for (int i = 0; i < userInput; i++)
				{
					//��� ��ʾ�û��������ְ���� ID
					print.printUserAddOfficeId();
					//��ȡ �û����ְ����ID
					id = getInput.getUserAddOfficeIdInput();

					//�ж��û������ ID ������Ϸ�����ʾ������ cin
					if (id == -1)
					{
						print.printUserInputErrorWiat();
						getInput.reCinClearCin();
						break;
					}

					//��� ��ʾ�û��������ְ���� ����
					print.printUserAddOfficeName();
					//��ȡ �û����ְ��������
					getInput.getUserAddOfficeNameInput(name);
					
					//��� ��ʾ�û��������ְ���� ְλ
					print.printUserAddOfficeRank();
					//��� ���п����õ� ְλ
					print.printAllAddRank();
					//��ȡ �û����ְ����ְλ
					rank = getInput.getUserAddOfficeRankInput();

					//�ж��û������ ְλ ������Ϸ�����ʾ������ cin
					if (rank == -1)
					{
						print.printUserInputErrorWiat();
						getInput.reCinClearCin();
						break;
					}

					Office office(id,name,rank);
					officeList.emplace_back(office);

					readWriteFiles.writeFile("Office.txt", officeList);
				}
			}
			else
			{
				print.printUserInputErrorWiat();
				getInput.reCinClearCin();
			}
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫ��ʾ����ְ��
		else if (userInput == 2)
		{
			print.printAllOffice(officeList);
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫɾ��ְ��
		else if (userInput == 3)
		{
			//���ڴ洢�û�ɾ��ְ���� ID
			int deleteOfficeId;
			//���ڴ洢�û�ɾ��ְ���� ����
			char deleteOfficeName[64];

			//���ȫ��Ա��
			print.printAllOffice(officeList);
			//��� ѯ���û�ɾ��ְ���� ID ���� ����
			print.printUserDeleteOfficeIdOrName();
			
			bool deleteOfficeSuccess = false;

			//��ȡ �û�ɾ��ְ��������
			if (getInput.getUserDeleteOfficeIdOrName(deleteOfficeId, deleteOfficeName))
			{
				//�Ӻ���ǰѭ��
				for (int i = officeList.size() - 1; i >= 0; i--)
				{
					//�ж��Ƿ�����Ҫɾ����ְ��
					if (officeList[i].getId() == deleteOfficeId)
					{
						//����ǣ���ɾ��
						officeList.erase(officeList.begin() + i);

						//ȷ��ɾ��
						deleteOfficeSuccess = true;

						readWriteFiles.writeFile("Office.txt", officeList);
					}
					
				}
				if (!deleteOfficeSuccess)
				{
					//�ж�����û����������
					//��� �û��������
					print.printUserDeleteOfficeFail();
					//���� cin �ȴ��û�ȷ�������Ļ
					getInput.reCinClearCin();

					break;
				}
			}
			else
			{
				//�Ӻ���ǰѭ��
				for (int i = officeList.size() - 1; i >= 0; i--)
				{
					//�ж��Ƿ�����Ҫɾ����ְ��
					if (strcmp(officeList[i].getName(),deleteOfficeName) == 0)
					{
						//����ǣ���ɾ��
						officeList.erase(officeList.begin() + i);

						//ȷ��ɾ��
						deleteOfficeSuccess = true;
					}
				}

				if (!deleteOfficeSuccess)
				{
					//�ж�����û����������
					//��� �û��������
					print.printUserDeleteOfficeFail();
					//���� cin �ȴ��û�ȷ�������Ļ
					getInput.reCinClearCin();

					break;
				}
			}

		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫ�޸�ְ����Ϣ
		else if (userInput == 4)
		{
			//�����������洢�޸�ְ�����µ���Ϣ
			int id;
			char name[64];
			int rank;

			//��� ȫ��Ա��
			print.printAllOffice(officeList);

			//��� ѯ���û���Ҫ�޸ĵ�ְ��ID
			print.printUserReviseOfficeId();

			//��ȡ �û���Ҫ�޸�ְ���� ID
			userInput = getInput.getUserReviseOfficeId();

			//�ж��û������ ID �Ƿ�Ϸ�
			if (userInput != -1
				&& userInput <officeList.size())
			{
				//��� ѯ���û��޸�ְ������ ID
				print.printUserReviseOfiiceNewId();
				//���� �û����ְ��ʱ����ȡ�û������ ID ����
				id = getInput.getUserAddOfficeIdInput();

				//�ж��û������ ID ������Ϸ�����ʾ������ cin
				if (id == -1)
				{
					print.printUserInputErrorWiat();
					getInput.reCinClearCin();
					break;
				}

				//��� ѯ���û��޸�ְ������ ����
				print.printUserAddOfficeName();
				//���� �û����ְ��ʱ����ȡ�û������ ���� ����
				getInput.getUserAddOfficeNameInput(name);

				//��� ѯ���û��޸�ְ������ ְλ
				print.printUserAddOfficeRank();
				//��� ���п����õ� ְλ
				print.printAllAddRank();
				//���� �û����ְ��ʱ����ȡ�û������ ְλ ����
				rank = getInput.getUserAddOfficeRankInput();

				//�ж��û������ ְλ ������Ϸ�����ʾ������ cin
				if (rank == -1)
				{
					print.printUserInputErrorWiat();
					getInput.reCinClearCin();
					break;
				}

				Office office(id,name,rank);
				officeList[userInput - 1] = office;

				readWriteFiles.writeFile("Office.txt", officeList);
			}
			else
			{
				print.printUserInputErrorWiat();
				getInput.reCinClearCin();
			}
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫ����ְ����Ϣ
		else if (userInput == 5)
		{
			//��� ���в���ְ���ķ�ʽ
			print.printAllFindWay();

			//��� ѯ���û���Ҫ����ְ���ķ�ʽ
			print.printUserFindOfficeWay();

			//��ȡ �û���Ҫʲô��ʽ����ְ�������洢�� userInput
			userInput = getInput.getUserFindOfficeWayInput();

			//�ж� �û��������Ƿ�Ϸ�
			if (userInput != -1
				&& userInput <= 2)
			{
				//�ж� �û��Ƿ���Ҫͨ�� ID ��ʽ����ְ��
				if (userInput == 1)
				{
					//��� ѯ���û�����ְ����ID
					print.printUserFindOfficeId();

					//��ȡ�û������룬���洢�� userInput
					userInput = getInput.getUserFindOfficeId();

					//�ж� �û��������Ƿ�Ϸ�
					if (userInput < officeList.size()
						&& userInput != -1)
					{
						//��� ����ְ������Ϣ
						print.printOffice(officeList[userInput - 1]);
					}
					else
					{
						print.printUserInputErrorWiat();
						getInput.reCinClearCin();
					}
				}
				//�ж� �û��Ƿ���Ҫͨ��������ʽ����
				else if (userInput == 2)
				{
					//���� findName �������洢�û�����ְ��ʱ���������
					char findName[64];

					//��� ѯ���û�����ְ���� ����
					print.printUserFindOfficeName();

					//��ȡ�û�������
					getInput.getUserFindOfficeName(findName);

					for (int i = 0; i < officeList.size(); i++)
					{
						if (strcmp(officeList[i].getName(), findName) == 0)
						{
							print.printOffice(officeList[i]);
						}
					}
				}
			}
			else
			{
				print.printUserInputErrorWiat();
				getInput.reCinClearCin();
			}
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫ���ձ������ְ��
		else if (userInput == 6)
		{
			//����һ����ʱ���� temp ���ڴ洢�ƶ�
			Office temp;
			//�������� officeListCorrectOrder ����ȷ���б�˳���Ƿ���ȷ
			bool officeListCorrectOrder = true;

			//ð������
			for (int i = 0; i < officeList.size(); i++)
			{
				for (int j = 0; j < officeList.size() - 1; j++)
				{
					
					if (!(officeList[j].getId() < officeList[j + 1].getId()))
					{
						temp = officeList[j + 1];
						officeList[j + 1] = officeList[j];
						officeList[j] = temp;

						//���������˳���� officeListCoorectOrder ��Ϊ false
						officeListCorrectOrder = false;
					}
				}

				//�ж� �Ƿ������˳��û�е������Ļ���ֱ���˳�ѭ��
				if (officeListCorrectOrder)
				{
					break;
				}
			}
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//�ж� �û��Ƿ���Ҫ�������ְ��
		else if (userInput == 7)
		{
			print.printUserIsClearAllOffice();

			if (getInput.getUserIsClearAllOffice())
			{
				officeList.clear();

				readWriteFiles.writeFile("Office.txt", officeList);
			}
		}
		else
		{
			print.printUserInputErrorWiat();
			getInput.reCinClearCin();
		}
	}

	readWriteFiles.writeFile("Office.txt", officeList);
}

int main() {
	run();

	system("pause");

	return 0;
}