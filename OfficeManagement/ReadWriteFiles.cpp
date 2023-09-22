#include"ReadWriteFiles.h"

//�޲ι��캯��
ReadWriteFiles::ReadWriteFiles() {
	this->ifs = new ifstream;
	this->ofs = new ofstream;
}

//��ȡ�ļ�
void ReadWriteFiles::readFile(string filePath, vector<Office>& officeList) {
	//��ȡ�ļ�
	ifs->open(filePath,  ios::in);

	//�ж��Ƿ��ȡ�ɹ�
	if (!ifs->is_open())
	{
		return ;
	}

	//���� ID �������洢��ȡ�� ID
	int id;
	//���� Name �������洢��ȡ�� Name
	char name[64];
	//���� rank �������洢��ȡ�� Rank
	int rank;
	//���� line �������洢��ȡ�����ļ��е�����
	char data[65];
	//���� flag �������洢Ӧ�ô��뵽ʲô����
	int flag = 1;
	//������ʱ Office ����
	Office office;


	while (*ifs >> data)
	{
		//�ж��Ƿ��Ǵ��� id
		if (flag % 3 == 1)
		{
			id = *data - '0';
			flag++;
		}
		//�ж��Ƿ��Ǵ��� name
		else if (flag % 3 == 2)
		{
			name[strlen(data)] = '\0';
			strcpy_s(name, sizeof(name), data);
			flag++;
		}
		//�ж��Ƿ��Ǵ��� ְλ
		else if (flag % 3 == 0)
		{
			rank = *data - '0';
			flag++;

			//����ְ�������ݴ��ݵ���ʱ�� office ������
			office.setId(id);
			office.setName(name);
			office.setRank(rank);

			//ʹ�� push_back ���һ������
			officeList.push_back(office);
		}
	}

	ifs->close();
}

//д���ļ�
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