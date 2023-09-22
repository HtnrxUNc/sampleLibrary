#include "Print.h"

//输出 主菜单
void Print::printMain() {
	cout << "********************************************************" << endl;
	cout << "***************   欢迎使用职工管理系统   ***************" << endl;
	cout << "******************   0.退出管理系统   ******************" << endl;
	cout << "******************   1.增加职工信息   ******************" << endl;
	cout << "******************   2.显示职工信息   ******************" << endl;
	cout << "******************   3.删除离职职工   ******************" << endl;
	cout << "******************   4.修改职工信息   ******************" << endl;
	cout << "******************   5.查找职工信息   ******************" << endl;
	cout << "******************   6.按照编号排序   ******************" << endl;
	cout << "******************   7.清空所有文档   ******************" << endl;
	cout << "********************************************************" << endl;
}

//输出 提示用户输入编号
void Print::printUserInput() {
	cout << "请输入您的选择：";
}

//输出 询问用户增加职工的数量
void Print::printUserAddOfficeSum() {
	cout << "请输入增加职工的数量：";
}


//输出 询问用户添加职工的 ID
void Print::printUserAddOfficeId() {
	cout << "请输入添加职工的ID：";
}

//输出 询问用户添加职工的 姓名
void Print::printUserAddOfficeName() {
	cout << "请输入添加职工的姓名：";
}

//输出 询问用户添加职工的 姓名
void Print::printUserAddOfficeRank() {
	cout << "请输入添加职工的职位：" << endl;
}

//输出 所有可设置的 职位
void Print::printAllAddRank() {
	cout << "1、老板" << endl;
	cout << "2、经理" << endl;
	cout << "3、职工" << endl;
}

//输出 显示单名职工的信息
void Print::printOffice(Office office) {
	cout << office.getId() << "、"
		<< office.getName() << '\t'
		<< "职位：" << printOfficeStringRank(office.getRank()) << endl;
}

//输出 显示所有职工
void Print::printAllOffice(vector<Office>& officeList) {
	for (int i = 0; i < officeList.size(); i++)
	{
		printOffice(officeList[i]);
	}
}

//输出 职工的岗位（str类型）
string Print::printOfficeStringRank(int rank) {
	if (rank == 1)
	{
		return "老板";
	}
	else if (rank == 2)
	{
		return "经理";
	}
	else if (rank == 3)
	{
		return "员工";
	}
}

//输出 询问用户删除职工的 ID 或者 姓名
void Print::printUserDeleteOfficeIdOrName() {
	cout << "请输入需要删除职工的 ID 或者 姓名：";
}

//输出 删除失败
void Print::printUserDeleteOfficeFail() {
	cout << "没有找到该职工信息";
}

//输出 询问用户修改职工的 ID
void Print::printUserReviseOfficeId() {
	cout << "请输入需要修改职工的 ID：";
}

//输出 询问用户修改职工新的 ID
void Print::printUserReviseOfiiceNewId() {
	cout << "请输入职工的新 ID：";
}

//输出 询问用户查找职工的方式
void Print::printUserFindOfficeWay() {
	cout << "请选择查找方式：";
}

//输出 查找方式
void Print::printAllFindWay() {
	cout << "1、通过 ID 查找" << endl;
	cout << "2、通过姓名查找" << endl;
}

//输出 询问用户查找职工的 ID
void Print::printUserFindOfficeId() {
	cout << "请输入查找职工的 ID：";
}

//输出 询问用户查找职工的 姓名
void Print::printUserFindOfficeName() {
	cout << "请输入查找职工的 姓名：";
}

//输出 询问用户是否确认清空所有职工
void Print::printUserIsClearAllOffice() {
	cout << "是否删除全部职工信息？(y/n)：";
}

//输出 提示用户输入错误并等待
void Print::printUserInputErrorWiat() {
	//输出 提示用户输入错误
	cout << "您的输入有误" << endl;
	//等待用户按任意键
	system("pause");
}
