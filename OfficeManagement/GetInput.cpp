#include "GetInput.h"

//获取 用户在主菜单的输入
//返回 -1 代表输入错误
int GetInput::getUserMainInput() {
	//创建 userInput 变量，用于存储用户输入
	int userInput;
	//将用户的输入传入到 userInput
	GetInput::getUserInput(userInput);

	//判断 用户输入的是否是数字，
	//判断 用户输入的数字 是否大于等于0，
	//判断 用户输入的数字 是否小于8，
	//如果不是，则返回 -1
	if (GetInput::ifInputIsInt(cin) 
		&& GetInput::ifInputMoreThanEqualZero(userInput) 
		&& userInput < 8)
	{
			//如果 用户输入的数字合法，则返回用户的输入
			return userInput;

	}

	//如果 用户输入的不是数字，或者输入不合法，则返回 -1
	return -1;
}

//获取 用户在添加职工时，需要添加的数量
int GetInput::getUserAddOfficeSumInput() {
	//创建 userInput 变量，用于存储用户输入
	int userInput;

	//将用户的输入传入到 userInput
	GetInput::getUserInput(userInput);

	//判断 用户输入的是否是数字，
	//判断 用户输入的数字 是否大于等于0，
	//如果不是，则返回 -1
	if (ifInputIsInt(cin) 
		&& ifInputMoreThanEqualZero(userInput))
	{
		//如果 用户输入的数字合法，则返回用户的输入
		return userInput;
	}

	//如果 用户输入的不是数字，或者用户输入不合法，则返回 -1
	return -1;
}

//获取 用户添加职工的ID
int GetInput::getUserAddOfficeIdInput() {
	//创建 userInput 变量，用于存储用户输入
	int userInput;

	//将用户的输入传入到 userInput
	GetInput::getUserInput(userInput);

	if (ifInputIsInt(cin) 
		&& ifInputMoreThanZero(userInput))
	{
		//如果 用户输入的数字合法，则返回用户的输入
		return userInput;
	}

	//如果 用户输入的不是数字，或者用户输入不合法，则返回 -1
	return -1;
}

//获取 用户添加职工的 姓名
void GetInput::getUserAddOfficeNameInput(char (& name) [64]) {
	cin >> name;
}

//获取 用户添加职工的 职位
int GetInput::getUserAddOfficeRankInput() {
	//创建 userInput 变量，用于存储用户输入
	int userInput;

	//将用户的输入传入到 userInput
	GetInput::getUserInput(userInput);

	//判断用户输入的是否是数字，并且是否合法
	if (ifInputIsInt(cin)
		&& ifInputMoreThanZero(userInput)
		&& userInput < 4)
	{
		//如果 用户输入的数字合法，则返回用户的输入
		return userInput;
	}

	//如果 用户输入的不是数字，或者用户输入不合法，则返回 -1
	return -1;
}

//获取 用户删除职工的 ID 或者 姓名
//如果用户输入的是数字，则返回 true ，如果用户输入的不是数字，则返回 false
bool GetInput::getUserDeleteOfficeIdOrName(int& deleteId, char(&deleteName)[64]) {
	//创建 userInputInt 变量，用于存储用户输入的 int 类型数据
	int userInputInt;

	//将用户输入的内容传入 userInput
	getUserInput(userInputInt);

	//判断用户输入的内容是否是数字
	if (ifInputIsInt(cin))
	{
		//判断用户输入的数字是否合法
		if (ifInputMoreThanZero(userInputInt))
		{
			//如果用户输入合法，则返回 true 并且将用户的输入存储到 deleteId 中
			deleteId = userInputInt;
			return true;
		}
	}
	else
	{
		//如果用户输入的不是数字，则直接返回 false ，并将用户的输入存储到 deleteName
		getUserInput(deleteName);
		return false;
	}
}

//获取 用户修改职工的 id
int GetInput::getUserReviseOfficeId() {
	//创建 userInput 变量存储用户输入
	int userInput;

	getUserInput(userInput);

	if (ifInputIsInt(cin)
		&& ifInputMoreThanZero(userInput))
	{
		return userInput;
	}

	return -1;
}

//获取 用户查找职工时的查找方式
int GetInput::getUserFindOfficeWayInput() {
	//创建 userInput 变量存储用户输入
	int userInput;
	
	//获取用户输入并存储到 userInput
	getUserInput(userInput);

	//判断用户输入是否是数字并且是否合法
	if (ifInputIsInt(cin) 
		&& ifInputMoreThanZero(userInput))
	{
		return userInput;
	}

	return -1;
}

//获取 用户查找职工的 ID
int GetInput::getUserFindOfficeId() {
	//创建变量，存储用户的输入
	int userInput;

	//获取用户的输入
	getUserInput(userInput);

	//判断用户的输入是否合法
	if (ifInputIsInt(cin)
		&& ifInputMoreThanZero(userInput))
	{
		return userInput;
	}

	return -1;
}

//获取 用户查找职工的 姓名
void GetInput::getUserFindOfficeName(char(&name)[64]) {
	getUserInput(name);
}

//获取 用户是否清空所有职工信息
bool GetInput::getUserIsClearAllOffice() {
	//创建变量存储用户是否清空
	char userIsClear;

	getUserInput(userIsClear);
	
	return userIsClear == 'y' ? true : false;
}

//重置 cin 状态，清除 cin 输入
void GetInput::reCinClearCin() {
	//重置 cin 错误状态
	cin.clear();
	//清除输入流中的数据
	cin.ignore(1000, '\n');
}




//将用户的输入传递给传入的参数
void GetInput::getUserInput(int& userInput) {
	cin >> userInput;
}
//将用户的输入传递给传入的参数  
//char[64] 参数的 getUserInput 函数重载
void GetInput::getUserInput(char(&userInput)[64]) {
	cin >> userInput;
}
//将用户的输入传递给传入的参数  
//char 参数的 getUserInput 函数重载
void GetInput::getUserInput(char& userInput) {
	cin >> userInput;
}


//判断 用户的输入是否为数字
bool GetInput::ifInputIsInt(std:: istream& input) {
	return !input.fail();
}

//判断 用户的输入是否大于 0
bool GetInput::ifInputMoreThanZero(int userInput) {
	return userInput > 0;
}

//判断 用户的输入是否等于 0
bool GetInput::ifInputEqualZero(int userInput) {
	return userInput == 0;
}

//判断 用户的输入是否 大于等于 0
bool GetInput::ifInputMoreThanEqualZero(int userInput) {
	return ifInputMoreThanZero(userInput) || ifInputEqualZero(userInput);
}

//判断 用户的输入是否 小于数组的成员数
bool ifInputLessThanListLength(const std::vector<Office>) {
	return false;
}