#pragma once

#include <iostream>
using namespace std;
#include <fstream>
#include<string>
#include<vector>
#include"Office.h"

class ReadWriteFiles {
public:
	//�вι��캯��
	ReadWriteFiles();

	//��ȡ�ļ�
	void readFile(string filePath, vector<Office>& officeList);

	//д���ļ�
	void writeFile(string filePath, vector<Office>& officeList);

private:
	//��ȡ�ļ�����
	ifstream* ifs;
	//д���ļ�����
	ofstream* ofs;
};