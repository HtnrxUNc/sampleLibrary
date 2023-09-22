#pragma once
#include <vector>
#include "Office.h"

#include <iostream>
using namespace std;

// 打印输出的类
class Print {
public:
	//输出 主菜单
	void printMain();

	//输出 提示用户输入编号
	void printUserInput();

	//输出 询问用户增加职工的数量
	void printUserAddOfficeSum();

	//输出 询问用户添加职工的 ID
	void printUserAddOfficeId();

	//输出 询问用户添加职工的 姓名
	void printUserAddOfficeName();

	//输出 询问用户添加职工的 职位
	void printUserAddOfficeRank();

	//输出 所有可设置的 职位
	void printAllAddRank();

	//输出 显示单名职工的信息
	void printOffice(Office office);

	//输出 显示所有职工的信息
	void printAllOffice(vector<Office>& officeList);

	//输出 职工的岗位（str类型）
	string printOfficeStringRank(int rank);

	//输出 询问用户删除职工的 ID 或者 姓名
	void printUserDeleteOfficeIdOrName();

	//输出 删除失败
	void printUserDeleteOfficeFail();

	//输出 询问用户修改职工的 ID
	void printUserReviseOfficeId();

	//输出 询问用户修改职工新的 ID
	void printUserReviseOfiiceNewId();

	//输出 询问用户查找职工的方式
	void printUserFindOfficeWay();

	//输出 查找方式
	void printAllFindWay();

	//输出 询问用户查找职工的 ID
	void printUserFindOfficeId();

	//输出 询问用户查找职工的 姓名
	void printUserFindOfficeName();

	//输出 询问用户是否确认清空所有职工
	void printUserIsClearAllOffice();

	//输出 提示用户输入错误并等待
	void printUserInputErrorWiat();
};
