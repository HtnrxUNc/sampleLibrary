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
	//实例化 打印输出 的类
	Print print;
	//创建一个 bool 变量用于检测是否退出系统
	bool flag = true;
	//实例化 获取用户输入 的类
	GetInput getInput;
	//创建一个 int 变量用于获取用户的输入
	int userInput;
	//创建一个 vector 存储 office
	vector<Office> officeList;
	//创建一个 ReadWriteFiles 用于文件操作
	ReadWriteFiles readWriteFiles;

	//尝试读取文件
	readWriteFiles.readFile("Office.txt", officeList);

	test01(officeList);

	while (flag)
	{
		//输出 主菜单
		print.printMain();
		//输出 提示用户输入编号
		print.printUserInput();
		//获取 用户在主菜单的输入
		userInput = getInput.getUserMainInput();

		
		//判断 用户输入的编号是多少，调用对应的功能
		//判断 用户是否想要退出程序
		if (userInput == 0)
		{
			flag = false;
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//判断 用户是否想要添加职工
		else if (userInput == 1)
		{
			//输出 询问用户添加职工的数量
			print.printUserAddOfficeSum();
			//获取 用户需要添加的职工数量
			userInput = getInput.getUserAddOfficeSumInput();

			//判断 用户的输入是否合法
			if (userInput != -1)
			{
				//如果输入合法，则创建变量，存储创建职工需要的数据
				int id;
				char name[64];
				int rank;

				//循环用户输入的添加职工数量
				for (int i = 0; i < userInput; i++)
				{
					//输出 提示用户输入添加职工的 ID
					print.printUserAddOfficeId();
					//获取 用户添加职工的ID
					id = getInput.getUserAddOfficeIdInput();

					//判断用户输入的 ID 如果不合法则提示并重置 cin
					if (id == -1)
					{
						print.printUserInputErrorWiat();
						getInput.reCinClearCin();
						break;
					}

					//输出 提示用户输入添加职工的 姓名
					print.printUserAddOfficeName();
					//获取 用户添加职工的姓名
					getInput.getUserAddOfficeNameInput(name);
					
					//输出 提示用户输入添加职工的 职位
					print.printUserAddOfficeRank();
					//输出 所有可设置的 职位
					print.printAllAddRank();
					//获取 用户添加职工的职位
					rank = getInput.getUserAddOfficeRankInput();

					//判断用户输入的 职位 如果不合法则提示并重置 cin
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
		//判断 用户是否想要显示所有职工
		else if (userInput == 2)
		{
			print.printAllOffice(officeList);
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//判断 用户是否想要删除职工
		else if (userInput == 3)
		{
			//用于存储用户删除职工的 ID
			int deleteOfficeId;
			//用于存储用户删除职工的 姓名
			char deleteOfficeName[64];

			//输出全部员工
			print.printAllOffice(officeList);
			//输出 询问用户删除职工的 ID 或者 姓名
			print.printUserDeleteOfficeIdOrName();
			
			bool deleteOfficeSuccess = false;

			//获取 用户删除职工的输入
			if (getInput.getUserDeleteOfficeIdOrName(deleteOfficeId, deleteOfficeName))
			{
				//从后往前循环
				for (int i = officeList.size() - 1; i >= 0; i--)
				{
					//判断是否是需要删除的职工
					if (officeList[i].getId() == deleteOfficeId)
					{
						//如果是，则删除
						officeList.erase(officeList.begin() + i);

						//确认删除
						deleteOfficeSuccess = true;

						readWriteFiles.writeFile("Office.txt", officeList);
					}
					
				}
				if (!deleteOfficeSuccess)
				{
					//判断如果用户的输入错误
					//输出 用户输入错误
					print.printUserDeleteOfficeFail();
					//重置 cin 等待用户确认清除屏幕
					getInput.reCinClearCin();

					break;
				}
			}
			else
			{
				//从后往前循环
				for (int i = officeList.size() - 1; i >= 0; i--)
				{
					//判断是否是需要删除的职工
					if (strcmp(officeList[i].getName(),deleteOfficeName) == 0)
					{
						//如果是，则删除
						officeList.erase(officeList.begin() + i);

						//确认删除
						deleteOfficeSuccess = true;
					}
				}

				if (!deleteOfficeSuccess)
				{
					//判断如果用户的输入错误
					//输出 用户输入错误
					print.printUserDeleteOfficeFail();
					//重置 cin 等待用户确认清除屏幕
					getInput.reCinClearCin();

					break;
				}
			}

		}
		//===========================================================================================================================
		//===========================================================================================================================
		//判断 用户是否想要修改职工信息
		else if (userInput == 4)
		{
			//创建变量，存储修改职工的新的信息
			int id;
			char name[64];
			int rank;

			//输出 全部员工
			print.printAllOffice(officeList);

			//输出 询问用户需要修改的职工ID
			print.printUserReviseOfficeId();

			//获取 用户需要修改职工的 ID
			userInput = getInput.getUserReviseOfficeId();

			//判断用户输入的 ID 是否合法
			if (userInput != -1
				&& userInput <officeList.size())
			{
				//输出 询问用户修改职工的新 ID
				print.printUserReviseOfiiceNewId();
				//调用 用户添加职工时，获取用户输入的 ID 函数
				id = getInput.getUserAddOfficeIdInput();

				//判断用户输入的 ID 如果不合法则提示并重置 cin
				if (id == -1)
				{
					print.printUserInputErrorWiat();
					getInput.reCinClearCin();
					break;
				}

				//输出 询问用户修改职工的新 姓名
				print.printUserAddOfficeName();
				//调用 用户添加职工时，获取用户输入的 姓名 函数
				getInput.getUserAddOfficeNameInput(name);

				//输出 询问用户修改职工的新 职位
				print.printUserAddOfficeRank();
				//输出 所有可设置的 职位
				print.printAllAddRank();
				//调用 用户添加职工时，获取用户输入的 职位 函数
				rank = getInput.getUserAddOfficeRankInput();

				//判断用户输入的 职位 如果不合法则提示并重置 cin
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
		//判断 用户是否想要查找职工信息
		else if (userInput == 5)
		{
			//输出 所有查找职工的方式
			print.printAllFindWay();

			//输出 询问用户想要查找职工的方式
			print.printUserFindOfficeWay();

			//获取 用户想要什么方式查找职工，并存储到 userInput
			userInput = getInput.getUserFindOfficeWayInput();

			//判断 用户的输入是否合法
			if (userInput != -1
				&& userInput <= 2)
			{
				//判断 用户是否想要通过 ID 方式查找职工
				if (userInput == 1)
				{
					//输出 询问用户查找职工的ID
					print.printUserFindOfficeId();

					//获取用户的输入，并存储到 userInput
					userInput = getInput.getUserFindOfficeId();

					//判断 用户的输入是否合法
					if (userInput < officeList.size()
						&& userInput != -1)
					{
						//输出 该名职工的信息
						print.printOffice(officeList[userInput - 1]);
					}
					else
					{
						print.printUserInputErrorWiat();
						getInput.reCinClearCin();
					}
				}
				//判断 用户是否想要通过姓名方式查找
				else if (userInput == 2)
				{
					//创建 findName 变量，存储用户查找职工时输入的名字
					char findName[64];

					//输出 询问用户查找职工的 姓名
					print.printUserFindOfficeName();

					//获取用户的输入
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
		//判断 用户是否想要按照编号排序职工
		else if (userInput == 6)
		{
			//创建一个临时变量 temp 用于存储移动
			Office temp;
			//创建变量 officeListCorrectOrder 用于确认列表顺序是否正确
			bool officeListCorrectOrder = true;

			//冒泡排序
			for (int i = 0; i < officeList.size(); i++)
			{
				for (int j = 0; j < officeList.size() - 1; j++)
				{
					
					if (!(officeList[j].getId() < officeList[j + 1].getId()))
					{
						temp = officeList[j + 1];
						officeList[j + 1] = officeList[j];
						officeList[j] = temp;

						//如果调换过顺序，则将 officeListCoorectOrder 改为 false
						officeListCorrectOrder = false;
					}
				}

				//判断 是否调整过顺序，没有调整过的话，直接退出循环
				if (officeListCorrectOrder)
				{
					break;
				}
			}
		}
		//===========================================================================================================================
		//===========================================================================================================================
		//判断 用户是否想要清空所有职工
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