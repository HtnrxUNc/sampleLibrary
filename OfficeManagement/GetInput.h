#pragma once

#include <iostream>
using namespace std;
#include <vector>
#include "Office.h"

class GetInput {
public:
	//获取 用户在主菜单的输入
	int getUserMainInput();

	//获取 用户在添加职工时，需要添加的数量
	int getUserAddOfficeSumInput();

	//获取 用户添加职工的 ID
	int getUserAddOfficeIdInput();

	//获取 用户添加职工的 姓名
	void getUserAddOfficeNameInput(char (& name) [64]);

	//获取 用户添加职工的 职位
	int getUserAddOfficeRankInput();

	//获取 用户删除职工的 ID 或者 姓名
	//如果用户输入的是数字，则返回 true ，如果用户输入的不是数字，则返回 false
	bool getUserDeleteOfficeIdOrName(int& deleteId,char (&deleteName) [64]);

	//获取 用户修改职工的 id
	int getUserReviseOfficeId();

	//获取 用户查找职工时的查找方式
	int getUserFindOfficeWayInput();

	//获取 用户查找职工的 ID
	int getUserFindOfficeId();

	//获取 用户查找职工的 姓名
	void getUserFindOfficeName(char(&name)[64]);

	//获取 用户是否清空所有职工信息
	bool getUserIsClearAllOffice();

	//重置 cin 状态，清除 cin 输入
	void reCinClearCin();


private:
	//判断 用户输入的是否是数字
	bool ifInputIsInt(std::istream& cin);

	//判断 用户输入的数字是否大于 0
	bool ifInputMoreThanZero(int userInput);

	//获取 用户的输入 并传递给传入的参数
	void getUserInput(int& userInput);
	//将用户的输入传递给传入的参数  
	//char[64] 参数的 getUserInput 函数重载
	void getUserInput(char(&userInput)[64]);
	//将用户的输入传递给传入的参数  
	//char 参数的 getUserInput 函数重载
	void getUserInput(char& userInput);

	//判断 用户输入的数字是否等于 0
	bool ifInputEqualZero(int userInput);

	//判断 用户的输入是否 大于等于 0
	bool ifInputMoreThanEqualZero(int userInput);

	//判断 用户的输入是否 小于数组的成员数
	bool ifInputLessThanListLength(const std::vector<Office>);
};