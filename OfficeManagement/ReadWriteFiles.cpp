#include"ReadWriteFiles.h"

//无参构造函数
ReadWriteFiles::ReadWriteFiles() {
	this->ifs = new ifstream;
	this->ofs = new ofstream;
}

//读取文件
void ReadWriteFiles::readFile(string filePath, vector<Office>& officeList) {
	//读取文件
	ifs->open(filePath,  ios::in);

	//判断是否读取成功
	if (!ifs->is_open())
	{
		return ;
	}

	//创建 ID 变量，存储读取的 ID
	int id;
	//创建 Name 变量，存储读取的 Name
	char name[64];
	//创建 rank 变量，存储读取的 Rank
	int rank;
	//创建 line 变量，存储读取到的文件中的内容
	char data[65];
	//创建 flag 变量，存储应该存入到什么数据
	int flag = 1;
	//创建临时 Office 变量
	Office office;


	while (*ifs >> data)
	{
		//判断是否是传入 id
		if (flag % 3 == 1)
		{
			id = *data - '0';
			flag++;
		}
		//判断是否是传入 name
		else if (flag % 3 == 2)
		{
			name[strlen(data)] = '\0';
			strcpy_s(name, sizeof(name), data);
			flag++;
		}
		//判断是否是传入 职位
		else if (flag % 3 == 0)
		{
			rank = *data - '0';
			flag++;

			//将该职工的数据传递到临时的 office 对象中
			office.setId(id);
			office.setName(name);
			office.setRank(rank);

			//使用 push_back 添加一个对象
			officeList.push_back(office);
		}
	}

	ifs->close();
}

//写入文件
void ReadWriteFiles::writeFile(string filePath, vector<Office>& officeList) {
	ofs->open(filePath, ios::out |ios::trunc);

	for (int i = 0; i < officeList.size(); i++)
	{
		*ofs << to_string(officeList[i].getId()) << ' '
			<< officeList[i].getName() << ' '
			<< to_string(officeList[i].getRank()) << '\n';
	}

	ofs->close();
}