#include<fstream>
#include<iostream>
#include<windows.h>
int main(){
	if(system(NULL)==0){
		std::cout<<char(7);
		MessageBox(NULL,TEXT("The operating system cannot call the cmd program\n(0x1)"),TEXT("error message"),MB_OK);
		exit(1);
	}
	system("md \"D:\\yz\"");
	system("cls");
	system("attrib +h D:\\yz");
	std::fstream r1;
	r1.open("D:\\yz\\���ڴ��ļ��е�˵��.txt",std::ios::out);
	r1<<"����yz�Ĵ洢���ݣ����κ�Σ���ԣ��벻Ҫɾ����";
	r1.close();
	r1.clear();
	r1.open("D:\\yz\\happen.data",std::ios::out);
	r1.close();
	r1.clear();
	r1.open("D:\\yz\\data1.data",std::ios::out);
	r1<<"3\n10\n2\n0\n0\n5 5 0 1 0 0 0 0 0 50 0 1 1\n5 0 0 0 1 0 0 0 0 50 0 1 1\n0 5 0 0 1 0 0 0 0 50 0 1 1\n";
	r1.close();
	r1.clear();
	r1.open("D:\\yz\\data2.data",std::ios::out);
	r1<<"2\n20\n5\n0\n0\n5 10 0 2 1 0 0 0 0 50 0 1 1\n15 10 0 1 2 0 0 0 0 50 0 1 -1";
	r1.close();
	r1.clear();
	r1.open("D:\\yz\\donate.html",std::ios::out);
	r1<<"<b>����</b>\n<p></p>\n<img src=\"�տ���·��\" alt=\"\">";
	r1.close();
	r1.clear(); 
	r1.open("D:\\yz\\help.html",std::ios::out);
	r1<<"<body><a class=\"lg-fg-orange lg-bold\" href=\"https://www.luogu.com.cn/paste/8zm8qvvm\" target=\"_blank\">������־</a>\n<details>\n	����\n<summary>��ʾ��������ʧ��</summary>\n�����������\n</details>\n<details>\n<summary>ʹ��happen����ʱ��ʾ�ļ�������</summary>\n�ļ����ô�������һ�����ó���\n</details>\n<details>\n<summary>��ȡ����ʱ��ʾû���ҵ��ļ�</summary>\n�ļ����ô�������һ�����ó���\n</details>\n�������������⣬����\n<a class=\"lg-fg-orange lg-bold\" href=\"https://www.luogu.com.cn/chat?uid=745903\" target=\"_blank\">hjsxhst2022</a><html>��ϵ<html>";
	std::cout<<"����׼�����";
}

