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
	r1.open("D:\\yz\\关于此文件夹的说明.txt",std::ios::out);
	r1<<"这是yz的存储数据，无任何危害性，请不要删除。";
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
	r1<<"<b>捐赠</b>\n<p></p>\n<img src=\"收款码路径\" alt=\"\">";
	r1.close();
	r1.clear(); 
	r1.open("D:\\yz\\help.html",std::ios::out);
	r1<<"<body><a class=\"lg-fg-orange lg-bold\" href=\"https://www.luogu.com.cn/paste/8zm8qvvm\" target=\"_blank\">更新日志</a>\n<details>\n	帮助\n<summary>显示网络连接失败</summary>\n请检查电脑网络\n</details>\n<details>\n<summary>使用happen命令时提示文件不存在</summary>\n文件配置错误，运行一遍配置程序\n</details>\n<details>\n<summary>读取数据时显示没有找到文件</summary>\n文件配置错误，运行一遍配置程序\n</details>\n如果解决不了问题，请与\n<a class=\"lg-fg-orange lg-bold\" href=\"https://www.luogu.com.cn/chat?uid=745903\" target=\"_blank\">hjsxhst2022</a><html>联系<html>";
	std::cout<<"数据准备完毕";
}

