#pragma once

#include <iostream>
using namespace std;
#include <fstream>
#include<string>
#include<vector>
#include"Office.h"

class ReadWriteFiles {
public:
	//有参构造函数
	ReadWriteFiles();

	//读取文件
	void readFile(string filePath, vector<Office>& officeList);

	//写入文件
	void writeFile(string filePath, vector<Office>& officeList);

private:
	//读取文件对象
	ifstream* ifs;
	//写入文件对象
	ofstream* ofs;
};