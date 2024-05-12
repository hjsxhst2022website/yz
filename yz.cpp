#pragma GCC optimize(3)
#include<bits/stdc++.h>

#include<unistd.h>
#include<windows.h>
#include<wininet.h>
#include<bitset>
#include<graphics.h>
#include<thread>
#define INF LONG_LONG_MAX
#define pi 3.14159265358979323846264338
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define ull unsigned long long
#define int unsigned long long
using namespace std;

bool pause=0;
double inf=numeric_limits<double>::infinity();;
double sdx=0,sdy=0,sdz=0;//视点x，视点y，视点z
ull xsfw=20;//显示范围
double jsbc=1;//计算步长
ull gs=2;//光速
double ylcl=0.0000000000667259;//引力常数
ull yzdx=60;//宇宙大小
double expand=0;
const ull yzs=1000000;
double time_speed=0;
double sxpl=0.05;
ull lzs=0;
double expansivity=0;
bool expansivity_=0; 
string cmdpassword="114514hhh";
bool cmdlogin=1;
bool time_=0;//时间方向(正0负1)
vector<bool> zfwz(yzs + 5);//正反物质(正0反1)
vector<double> bj(yzs + 5);//看做一个球体，存半径(米)
vector<double> x(yzs + 5);//米
vector<double> y(yzs + 5);//米
vector<double> z(yzs + 5);//米
vector<double> xsd(yzs + 5);//米/秒
vector<double> ysd(yzs + 5);//米/秒
vector<double> zsd(yzs + 5);//米/秒
vector<double> xjsd(yzs + 5);//米/秒^2
vector<double> yjsd(yzs + 5);//米/秒^2
vector<double> zjsd(yzs + 5); // 米/秒^2
vector<double> zl(yzs + 5); // 千克
vector<double> nl(yzs + 5); // 能量
vector<double> dl(yzs + 5); // 动量
vector<double> dh(yzs + 5); // 电荷
void clean_() {
	int all=0;
	vector<double> x_;
	vector<double> y_;
	vector<double> z_;
	vector<double> xsd_;
	vector<double> ysd_;
	vector<double> zsd_;
	vector<double> xjsd_;
	vector<double> yjsd_;
	vector<double> zjsd_;
	vector<double> zl_;
	vector<double> nl_;
	vector<double> dl_;
	vector<double> dh_;
	
	vector<bool> zfwz_;
	for(int i = 1; i <= x.size(); i++) {
		// 如果 zl[i] 的值为 -1，则跳过当前循环，不执行后续操作
		if(zl[i] == -1) {
			continue;
		}
		// 将不为 -1 的元素对应的数据存入临时向量中
		x_.push_back(x[i]);
		y_.push_back(y[i]);
		z_.push_back(z[i]);
		xsd_.push_back(xsd[i]);
		ysd_.push_back(ysd[i]);
		zsd_.push_back(zsd[i]);
		xjsd_.push_back(xjsd[i]);
		yjsd_.push_back(yjsd[i]);
		zjsd_.push_back(zjsd[i]);
		zl_.push_back(zl[i]);
		nl_.push_back(nl[i]);
		dl_.push_back(dl[i]);
		dh_.push_back(dh[i]);
		zfwz_.push_back(zfwz[i]);
		all++;
	}
	lzs=all;
	// 清空原有向量数据
	x.clear();
	y.clear();
	z.clear();
	xsd.clear();
	ysd.clear();
	zsd.clear();
	xjsd.clear();
	yjsd.clear();
	zjsd.clear();
	zl.clear();
	nl.clear();
	dl.clear();
	dh.clear();
	zfwz.clear();
	// 将临时向量中的数据重新赋值给原有向量
	x = x_;
	y = y_;
	z = z_;
	xsd = xsd_;
	ysd = ysd_;
	zsd = zsd_;
	xjsd = xjsd_;
	yjsd = yjsd_;
	zjsd = zjsd_;
	zl = zl_;
	nl = nl_;
	dl = dl_;
	dh = dh_;
	zfwz = zfwz_;
}

bool tcxs;//正反物质突出显示
ull time_speed_=1;//计算速度，1毫秒一次
ull times=0;//时间
long double expandadd=0;//膨胀加速度
//功能函数
//检查网络是否通畅的函数
bool wifi(const string& host,int port){
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0)
		return 0;
	SOCKET sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==INVALID_SOCKET){
		WSACleanup();
		return 0;
	}
	sockaddr_in serverAddr;
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(port);
	serverAddr.sin_addr.s_addr=inet_addr(host.c_str());
	int connectionResult=connect(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	closesocket(sockfd);
	WSACleanup();
	if(connectionResult==0)
		return 1;
	else
		return 0;
}
//string转换为longlong
long long string_to_longlong(string s){
	long long b=0;
	bool fs=0;
	for(int a=0;a<=s.length()-1;++a){
		if(s[a]=='-')
			fs=1;
		b=b*10+(s[a]-48);
	}
	if(fs)
		return -b;
	return b; 
}
double cv(double c,double v){//cv转换
	return (c*c)/sqrt(1-((v*v)/(c*c)));
}
//计算引力
double ag(double mass,double distance){
	const double constg=6.67430e-11;
	return (constg*mass)/(distance*distance);
}
//计算电磁力
double ac(double charge,double distance){
	const double constc=8.987551e9;
	return (constc*charge)/(distance*distance);
}
//保存发生的事件
void save_happen(string a){
	fstream r1;
	r1.open("D:\\yz\\happen.data",ios::app);
	r1<<a<<'\n';
	r1.close();
	r1.clear(); 
	return;
}
//毫秒换秒
double clocks(){
	return clock()*1.0/CLOCKS_PER_SEC;
}
//cmd登录(默认登录)
void cmdlogin_(){
	system("cls");
	if(cmdlogin){
		printf("已登录");
		Sleep(2000);
		return;
	}
	printf("请输入管理员密码:");
	string password;
	getline(cin,password);
	if(password==cmdpassword){
		printf("登陆成功");
		cmdlogin=1;
	}else{
		printf("登录失败");
		Sleep(2000);
	}
	return;
}
//cmd未登录
void not_have_cmd(){
	printf("此为管理员权限，您还没有登录\n");
	Sleep(2000);
	return; 
}
void E_to_M(ull yzw1){//能量转换为质量，根据爱因斯坦的公式，传参原子位
	zl[yzw1]=nl[yzw1]*1.0/pow(gs,2);
}

void M_to_E(ull yzw1){//质量转换为能量，根据爱因斯坦的公式
	nl[yzw1]=zl[yzw1]*(gs*gs);
}
//over

void add(ull i){//输入，传参粒子位
	if(i<=lzs&&i!=0){
		if(lzs<i){
			for(int a=1;a<=i-lzs+5;a++){
				zfwz.push_back(0);
				bj.push_back(0);
				x.push_back(0);
				y.push_back(0);
				z.push_back(0);
				xsd.push_back(0);
				ysd.push_back(0);
				zsd.push_back(0);
				xjsd.push_back(0);
				yjsd.push_back(0);
				zjsd.push_back(0);
				zl.push_back(0);
				nl.push_back(0);
				dl.push_back(0);
				dh.push_back(0);
			}
		}
		printf("请输入x(0~%lld%s",yzdx,"):");
		cin>>x[i];
		printf("请输入y(0~%lld%s",yzdx,"):");
		cin>>y[i];
		printf("请输入z(0~%lld%s",yzdx,"):");
		cin>>z[i];
		printf("请输入x速度(0~%lld%s",gs,"):");
		cin>>xsd[i];
		printf("请输入y速度(0~%lld%s",gs,"):");
		cin>>ysd[i];
		printf("请输入z速度(0~%lld%s",gs,"):");
		cin>>zsd[i];
		printf("请输入x加速度(0~%lld%s",gs,"):");
		cin>>xjsd[i];
		printf("请输入y加速度(0~%lld%s",gs,"):");;
		cin>>yjsd[i];
		printf("请输入z加速度(0~%lld%s",gs,"):");
		cin>>zjsd[i];
		printf("请输入质量(kg):");
		cin>>zl[i];
		M_to_E(i);
		printf("请输入电荷量(C):");
		cin>>dh[i];
		printf("请输入正反物质类型(正0反1):");
		int x;
		cin>>x;
		if(x!=0&&x!=1){
			cout<<char(7);
			MessageBox(NULL,"正反物质类型数据错误","error message",MB_OK);
			add(i);
		}
		zfwz[i]=x;
		printf("请输入粒子半径(米):");
		cin>>bj[i];
		return;
	}else
		printf("不存在此粒子\n");
}

void savedata(){//保存数据，一般用于准备关闭程序时使用
	system("cls");
	printf("准备保存\n");
	fstream save;
	save.open("D:\\yz\\save.data",ios::out);
	save.close();
	save.clear();
	save.open("D:\\yz\\save.data");
	save<<setprecision(15)<<lzs<<'\n'<<yzdx<<'\n'<<gs<<'\n'<<expand<<'\n'<<expandadd<<'\n';
	for(int i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		save<<setprecision(15)<<(x[i]==inf?0:x[i])<<" "<<(y[i]==inf?0:y[i])<<" "<<(z[i]==inf?0:z[i])<<" "<<(xsd[i]==inf?0:xsd[i])<<" "<<(ysd[i]==inf?0:ysd[i])<<" "<<(zsd[i]==inf?0:zsd[i])<<" "<<(xjsd[i]==inf?0:xjsd[i])<<" "<<(yjsd[i]==inf?0:yjsd[i])<<" "<<(zjsd[i]==inf?0:zjsd[i])<<" "<<(zl[i]==inf?0:zl[i])<<" "<<zfwz[i]<<" "<<(bj[i]==inf?0:bj[i])<<" "<<(dh[i]==inf?0:dh[i])<<endl;//x-y-z-x速度-y速度-z速度-x加速度-y加速度-z加速度-质量-正反物质-半径-电荷
		cout<<"已完成"<<i*1.0/lzs*100<<"%"<<endl;
	}
	save.close();
	save.clear();
	printf("完成\n");
	Sleep(1000);
	system("cls");
	return;
}
void cmd(void){//管理员
	system("cls");
	cout<<"进入命令模式"<<endl;
	printf("done:退出命令模式\nclean:清理缓存\nxdd+数字:所有粒子在x方向移动\nydd+数字:所有粒子在y方向移动\nzdd+数字:所有粒子在z方向移动\nspeed:改变刷新速度\ntime speed:改变计算速度\ntime:调整时间流逝方向\ndata:查看可使用粒子数和已使用粒子数和宇宙大小和膨胀速度（已消失的不算）\nlook:查看粒子数据\nrange add:移动区域中的粒子\nalter:修改粒子参数\nlook all:显示所有存在的正反物质的数量\nall:显示所有存在的粒子数据\nmove eye:移动视点位置（未完成）\nexpand:改变膨胀率\ndisplay change:显示范围更改(未完成)\nexit:正常退出\nexpand add:改变膨胀速度加速度\nchange size:改变宇宙大小\nadd:添加粒子\ndel+数字:删除输入编号的粒子\nrange del:删除区域内的粒子\nexpansivity:根据现在的大小按一定的比率改变膨胀速度\nhappen:查看最新的10个事件\nhappen all:查看所有发生事件\nhelp:帮助\nupdate log:查看更新日志\npause:暂停运算\n");
	while(1){
		printf("operator<<");
		string n;
		getline(cin,n);
		if(n=="done"){
			system("cls");
			return;
		}else if(n=="clean"){
			fstream r1;
			r1.open("D:\\yz\\happen.data",ios::out);
			r1.close();
			r1.clear();
			r1.open("D:\\yz\\saves.data",ios::out);
			r1.close();
			r1.clear();
			r1.open("D:\\yz\\save.data",ios::out);
			r1.close();
			r1.clear();
		}else if(n[0]=='x'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				x[i]+=add;
			}
		}else if(n[0]=='y'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				y[i]+=add;
			}
		}else if(n[0]=='z'&&n[1]=='d'&&n[2]=='d'){
			double add=string_to_longlong(n);
			for(unsigned long long i=1;i<=yzs;++i){
				if(zl[i]==-1)
					continue;
				z[i]+=add;
			}
		}else if(n=="speed"){
			printf("请输入每帧刷新速度(秒):");
			cin>>sxpl;
		}else if(n=="time"){
			printf("请输入正（0）负（1）:");
			short a;
			cin>>a;
			if(a!=0&&a!=1)
				printf("error\n");
			else{
				time_=a;
				for(int i=1;i<=yzs;i++){
					xsd[i]=-xsd[i];
					ysd[i]=-ysd[i];
					zsd[i]=-zsd[i];
					xjsd[i]=-xjsd[i];
					yjsd[i]=-yjsd[i];
					zjsd[i]=-zjsd[i];
				}
			}
		}else if(n=="data"){
			ull a=0;
			for(ull i=1;i<=yzs;i++){
				if(zl[i]!=-1)
					a++;
			}
			printf("可使用粒子数:%lld\n使用粒子数:%lld\n",yzs,a); 
			cout<<"宇宙大小:";
			if(yzdx==INF)
				cout<<"inf";
			else
				cout<<yzdx;
			cout<<'\n';
			printf("膨胀速度:%lf\n光速:%lld\n",expand,gs);
		}else if(n=="look"){
			if(cmdlogin){
				printf("请输入查看的粒子编号：");
				ull a;
				cin>>a;
				if(a<=lzs&&a!=0){
					printf("x:%lf\ny:%lf\nz:%lf\nx速度:%lf\ny速度:%lf\nz速度:%lf\nx加速度:%lf\ny加速度:%lf\nz加速度:%lf\n质量:%lf\n能量:%lf\n半径:%lf\n正反物质类型:%s\n电荷量:%lf\n",x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"反物质":"正物质",dh[a]);
				}else
					printf("不存在此粒子\n");
			}else{
				not_have_cmd();
			}
		}else if(n=="time speed"){
			printf("请输入每次计算速度(秒):");
			cin>>time_speed;
			time_speed*=1000;
		}else if(n=="alter"){
			printf("请输入修改粒子:");
			ull i;
			cin>>i;
			add(i);
		}else if(n=="range add"){
			double x1,x2,y1,y2,z1,z2;
			printf("请按x1,x2,y1,y2,z1,z2的顺序输入:");
			cin>>x1>>x2>>y1>>y2>>z1>>z2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			if(z1>z2)
				swap(z1,z2);
			double xadd,yadd,zadd;
			printf("请输入x方向移动距离:");
			cin>>xadd;
			printf("请输入y方向移动距离:");
			cin>>yadd;
			printf("请输入z方向移动距离:");
			cin>>zadd;
			printf("正在执行......\n");
			for(ull i=1;i<=yzs;i++){
				if(zl[i]==-1)
					continue;
				if(x[i]>=x1&&x[i]<=x2&&y[i]>=y1&&y[i]<=y2&&z[i]>=z1&&z[i]<=z2)
					x[i]+=xadd;
				y[i]+=yadd;
				z[i]+=zadd;
			}
		}else if(n=="look all"){
			ull zheng=0,fan=0,have=0;
			for(ull i=1;i<=yzs;i++){
				if(zfwz[i]==0&&zl[i]!=-1)
					zheng++;
				else if(zfwz[i]==1&&zl[i]!=-1)
					fan++;
				if(zl[i]!=-1)
					have++;
			}
			printf("正物质%lld个，反物质%lld个，存在%lld个\n",zheng,fan,have);
		}else if(n=="all"){
			for(ull a=1;a<=yzs;a++){
				if(zl[a]==-1)
					continue;
				printf("编号:%lld\nx:%lf\ny:%lf\nz:%lf\nx速度:%lf\ny速度:%lf\nz速度:%lf\nx加速度:%lf\ny加速度:%lf\nz加速度:%lf\n质量:%lf\n能量:%lf\n半径:%lf\n正反物质类型:%s\n电荷量:%lf\n\n",a,x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"反物质":"正物质",dh[a]);
			}
		}else if(n=="move eye"){
			printf("请输入视点x所在位置:");
			cin>>sdx;
			printf("请输入视点y所在位置:");
			cin>>sdy;
		}else if(n=="expand"){
			printf("请输入膨胀速度:");
			cin>>expand;
		}else if(n=="display change"){
			printf("请输入显示范围:");
			cin>>xsfw;
		}else if(n=="exit"){
			savedata();
			exit(0);
		}else if(n=="expand add"){
			printf("请输入膨胀速度加速度:");
			cin>>expandadd;
		}else if(n=="change size"){
			printf("请输入宇宙大小:");
			cin>>yzdx;
			closegraph();
			initgraph(signed(yzdx*10),signed(yzdx*10));//打开一个窗口
			setcaption("Your universe");//设置标题
		}else if(n=="add"){
			lzs++;
			add(lzs);
		}else if(n[0]=='d'&&n[1]=='e'&&n[2]=='l'){
			int yzw=string_to_longlong(n);
			zl[yzw]=-1;
		}else if(n=="range del"){
			double x1,x2,y1,y2,z1,z2;
			printf("请按x1,x2,y1,y2,z1,z2的顺序输入:");
			cin>>x1>>x2>>y1>>y2>>z1>>z2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			if(z1>z2)
				swap(z1,z2);
			printf("正在执行......\n");
			for(ull i=1;i<=yzs;i++){
				if(zl[i]==-1)
					continue;
				if(x[i]>=x1&&x[i]<=x2&&y[i]>=y1&&y[i]<=y2&&z[i]>=z1&&z[i]<=z2)
					zl[i]=-1;
			}
		}else if(n=="expansivity"){
			if(expansivity==0){
				printf("请输入膨胀率:(单位:%%):");
				cin>>expansivity;
				if(expansivity>100||expansivity<-100)
					printf("数据错误\n");
				else{
					expansivity/=100;
					expansivity_=1;
				}
				printf("\n");
			}else{
				printf("已经停用膨胀率\n");
				expansivity=0;
			}
		}else if(n=="happen"){
			fstream r1;
			r1.open("D:\\yz\\happen.data");
			if(!r1.is_open()){
				printf("文件不存在\n");
				system("pause");
			}
			for(int i=1;i<=10&&!r1.eof();i++){
				ull a;
				r1>>a;
				if(a==1){
					ull i,j,time;
					r1>>i>>j>>time;
					printf("发生碰撞at%lld号粒子&%lld号粒子，在第%lld次更新时碰撞\n",i,j,time);
				}else if(a==2){
					int i,j,time;
					r1>>i>>j>>time;
					printf("发生正反湮灭at%lld号粒子&%lld号粒子，在第%lld次更新时湮灭\n",i,j,time);
				}
			}
			r1.close();
			r1.clear();
		}else if(n=="del"){
			int s=0;
			cout<<"请输入删除粒子：";
			cin>>s;
			zl[s]=-1;
			cout<<"\n命令完成\n";
		}
		else if(n=="happen all"){
			fstream r1;
			r1.open("D:\\yz\\happen.data",ios::in);
			if(!r1.is_open()){
				printf("文件不存在\n");
				system("pause");
			}
			while(!r1.eof()){
				ull a;
				r1>>a;
				if(a==1){
					ull i,j,time;
					r1>>i>>j>>time;
					printf("发生碰撞at%lld号粒子&%lld号粒子，在第%lld次更新时碰撞\n",i,j,time);
				}else if(a==2){
					int i,j,time;
					r1>>i>>j>>time;
					printf("发生正反湮灭at%lld号粒子&%lld号粒子，在第%lld次更新时湮灭\n",i,j,time);
				}
			}
			r1.close();
			r1.clear();
		}else if(n=="help"){
			system("start D:\\yz\\help.html");
		}else if(n=="pause"){
			if(pause==0){
				pause=1;
				cout<<"已暂停运算\n";
			}else{
				pause=0;
				cout<<"已重启运算\n";
			}
		}else if(n=="update log"){
			system("start https://www.luogu.com.cn/paste/hglsje64");
		}
		else if(n!=""){
			printf("\"%s\"不是可执行的命令\n",&n[0]);
		}
		cout<<"命令完成"<<endl;
	}
	system("cls");
}
bool scandata(){//读取数据，一般用于程序开始
	system("cls");
	fstream qwq;
	qwq.open("D:\\yz\\save.data");
	if(qwq.is_open()){
		qwq>>lzs>>yzdx>>gs>>expand>>expandadd;
		if(lzs>yzs){
			for(int i = 1; i <= lzs - yzs + 5; i++){
				zfwz.push_back(0);
				bj.push_back(0);
				x.push_back(0);
				y.push_back(0);
				z.push_back(0);
				xsd.push_back(0);
				ysd.push_back(0);
				zsd.push_back(0);
				xjsd.push_back(0);
				yjsd.push_back(0);
				zjsd.push_back(0);
				zl.push_back(0);
				nl.push_back(0);
				dl.push_back(0);
				dh.push_back(0);
			}
		}
		for(ull i=1;i<=lzs;i++){
			int dh_=0;
			int zfwz_=0;
			qwq>>x[i]>>y[i]>>z[i]>>xsd[i]>>ysd[i]>>zsd[i]>>xjsd[i]>>yjsd[i]>>zjsd[i]>>zl[i]>>zfwz_>>bj[i]>>dh_;
			dh[i]=dh_;
			zfwz[i]=zfwz_;
			M_to_E(i);
			cout<<"已完成"<<i*1.0/lzs*100<<"%"<<endl;
		}
		qwq.close();
		qwq.clear();
		system("cls");
		return 1;
	}else{
		cout<<char(7);
		printf("没有找到数据\n");
		qwq.close();
		qwq.clear();
		Sleep(2000);
		system("cls");
		return 0;
	}
}

bool zdsj(){
	cout<<char(7);
	int a=MessageBox(NULL,TEXT("是否自定义数据？"),"",MB_YESNO);//自定义数据
	if(a==IDYES){
		system("cls");
		printf("认真输入，不然很麻烦哦\n");
		printf("请输入宇宙大小:");
		cin>>yzdx;
		printf("请输入原子数(1~");
		printf("%lld%s",yzs,"):");
		cin>>lzs;
		if(lzs>yzs){
			cout<<char(7);
			MessageBox(NULL,TEXT("Excessive particle count(0x1)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(1); 
		}else if(lzs<1){
			cout<<char(7);
			MessageBox(NULL,TEXT("The particle number is too small(0x2)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(2);
		}
		printf("请输入光速:");
		cin>>gs;
		if(gs<=0){
			cout<<char(7);
			MessageBox(NULL,TEXT("The speed of light is too small(0x3)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(3);
		}
		if(yzdx<=0){
			cout<<char(7);
			MessageBox(NULL,TEXT("The universe is too small(0x5)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
			exit(5);
		}
		for(int i=1;i<=lzs;i++){
			add(i);
			printf("已完成%lf%%\n",i*1.0/lzs*100);
		}
		cout<<"over"<<endl;
		system("cls");
		return 1;
	}
	return 0;
}

void qidong(){
	system("cls");
	printf("请输入粒子数(0~%lld):",yzs);
	cin>>lzs;
	if(lzs>yzs){
		for(int i = 1; i <= lzs - yzs + 5; i++){
			zfwz.push_back(0);
			bj.push_back(0);
			x.push_back(0);
			y.push_back(0);
			z.push_back(0);
			xsd.push_back(0);
			ysd.push_back(0);
			zsd.push_back(0);
			xjsd.push_back(0);
			yjsd.push_back(0);
			zjsd.push_back(0);
			zl.push_back(0);
			nl.push_back(0);
			dl.push_back(0);
			dh.push_back(0);
		}
	}
	printf("请输入光速:");
	cin>>gs;
	if(gs<=0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The speed of light is too small(0x3)"),TEXT("error message"),MB_OK);
		exit(3);
	}
	printf("请输入宇宙大小:");
	cin>>yzdx;
	if(yzdx<=0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The universe is too small(0x5)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
		exit(5);
	}
	srand(time(0));
	for(int i=1;i<=lzs;i++){//初始化
		x[i]=rand()%yzdx;
		y[i]=rand()%yzdx;
		z[i]=rand()%yzdx;
		bool zf=rand()%2;//正负 
		if(zf==0)
			xsd[i]=rand()%gs+1;
		else
			xsd[i]=-rand()%gs-1;
		zf=rand()%2;
		if(zf==0)
			ysd[i]=rand()%gs+1;
		else
			ysd[i]=-rand()%gs-1;
		zf=rand()%2;
		if(zf==0)
			zsd[i]=rand()%gs+1;
		else
			zsd[i]=-rand()%gs-1;
		zf=rand()%2;
		if(zf==0)
			xjsd[i]=rand()%gs;
		else
			xjsd[i]=-rand()%gs;
		zf=rand()%2;
		if(zf==0)
			yjsd[i]=rand()%gs;
		else
			yjsd[i]=-rand()%gs;
		zf=rand()%2;
		if(zf==0)
			zjsd[i]=rand()%gs;
		else
			zjsd[i]=-rand()%gs;
//		zfwz[i]=0;
		zfwz[i]=rand()%2;
		do{
			zl[i]=rand()%10000;
		}while(zl[i]<0);
		M_to_E(i);
		while(bj[i]<=0)
			bj[i]=rand()%(yzdx/2);
		dh[i]=(rand()*10)%10/10;
		cout<<"已完成"<<i*1.0/lzs*100<<"%"<<endl;
	}
	cout<<"over"<<endl;
//	Sleep(1000);
	system("cls");
	return;
}
#define MIN_DISTANCE 1.0
#define G 6.67e-11
void updateParticles() {
	for (int i = 1; i <=lzs; ++i) {
		if(zl[i]==-1)
			continue;
		double ax = 0, ay = 0, az = 0; // 加速度初始化为0
		for (int j = 0; j < lzs; ++j) {
			if(zl[j]==-1)
				continue;
			if (i != j) {
				double dx = fabs(x[j] - x[i]);
				double dy = fabs(y[j]- y[i]);
				double dz = fabs(z[j] - z[i]);
				double r = sqrt(dx * dx + dy * dy + dz * dz); // 计算粒子之间的距离
				// 限制粒子之间的距离
				if (r < MIN_DISTANCE) {
					r = MIN_DISTANCE;
				}
				// 计算引力
				double F = (G * zl[j] * zl[j]) / (r * r);
				ax += F * (dx / r);
				ay += F * (dy / r);
				az += F * (dz / r);
			}
		}
		
		// 更新速度和位置
		xsd[i] += ax;
		ysd[i] += ay;
		zsd[i] += az;
	}
}

void save_alldata(){
	fstream save;
	save.open("D:\\yz\\saves.data",ios::app);
	save<<setprecision(15)<<lzs<<'\n'<<yzdx<<'\n'<<gs<<'\n'<<expand<<'\n'<<expandadd<<'\n'<<times<<'\n';
	for(int i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		save<<setprecision(15)<<(x[i]==inf?0:x[i])<<" "<<(y[i]==inf?0:y[i])<<" "<<(z[i]==inf?0:z[i])<<" "<<(xsd[i]==inf?0:xsd[i])<<" "<<(ysd[i]==inf?0:ysd[i])<<" "<<(zsd[i]==inf?0:zsd[i])<<" "<<(xjsd[i]==inf?0:xjsd[i])<<" "<<(yjsd[i]==inf?0:yjsd[i])<<" "<<(zjsd[i]==inf?0:zjsd[i])<<" "<<(zl[i]==inf?0:zl[i])<<" "<<zfwz[i]<<" "<<(bj[i]==inf?0:bj[i])<<" "<<(dh[i]==inf?0:dh[i])<<endl;//x-y-z-x速度-y速度-z速度-x加速度-y加速度-z加速度-质量-正反物质-半径-电荷
	}
	save.close();
	save.clear();
	return;
}
bool scandatas(){
	cout<<char(7);
	int a=MessageBox(NULL,"是否使用数据库?","",MB_YESNO);
	if(a==IDYES){
		string a;
		system("cls");
		printf("请输入数据库编号：");
		getline(cin,a);
		fstream r1;
		r1.open(&("D:\\yz\\data"+a+".data")[0]);
		if(!r1.is_open()){
			printf("数据库信息不存在\n");
			system("pause");
			return 0; 
		}
		r1>>lzs>>yzdx>>gs>>expand>>expandadd;
		for(ull i=1;i<=lzs||!r1.eof();i++){
			int dh_=0;
			int zfwz_=0;
			r1>>x[i]>>y[i]>>z[i]>>xsd[i]>>ysd[i]>>zsd[i]>>xjsd[i]>>yjsd[i]>>zjsd[i]>>zl[i]>>zfwz_>>bj[i]>>dh_;
			dh[i]=dh_;
			zfwz[i]=zfwz_;
			M_to_E(i);
			cout<<"已完成"<<i*1.0/yzs*100<<"%"<<endl;
		}
		system("cls");
		return 1;
	}else
		return 0;
}

void chushihua(){//初始化随机
	if(scandatas());
	else
		if(zdsj());
	else qidong();
	return; 
}

void weizhigengxin(){//位置更新与禁止超光速与无缝世界
	for(int i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		xsd[i]+=xjsd[i];
		ysd[i]+=yjsd[i];
		zsd[i]+=zjsd[i];
//		if(xsd[i]>=gs)
//			xsd[i]=gs-0.0001;
//		if(ysd[i]>=gs)
//			ysd[i]=gs-0.0001;
//		if(zsd[i]>=gs)
//			zsd[i]=gs-0.0001;
//		if(xsd[i]<=-gs)
//			xsd[i]=-gs+0.0001;
//		if(ysd[i]<=-gs)
//			ysd[i]=-gs+0.0001;
//		if(zsd[i]<=-gs)
//			zsd[i]=-gs+0.0001;
		x[i]+=xsd[i]/jsbc;
		y[i]+=ysd[i]/jsbc;
		z[i]+=zsd[i]/jsbc;
		if(x[i]+bj[i]>yzdx)
			x[i]=bj[i];
		else if(x[i]-bj[i]<0)
			x[i]=yzdx-bj[i];
		if(y[i]+bj[i]>yzdx)
			y[i]=bj[i];
		else if(y[i]-bj[i]<0)
			y[i]=yzdx-bj[i];
		if(z[i]+bj[i]>yzdx)
			z[i]=bj[i];
		else if(z[i]-bj[i]<0)
			z[i]=yzdx-bj[i];
	}
	if(yzs==INF)
		return;
}
double lasttime=0;
struct out_z{
	ull z;//z轴
	ull bh;//编号
};
bool z_cmp(out_z a,out_z b){
	return a.z>b.z;
}
void mouse_window(int &x,int &y){//获取鼠标相对于窗口的位置
	HWND hwnd = GetForegroundWindow(); // 获取当前窗口句柄
	POINT pt;
	GetCursorPos(&pt); // 获取相对于屏幕的鼠标位置
	ScreenToClient(hwnd, &pt); // 将屏幕坐标转换为窗口内的客户区坐标
	x = pt.x;
	y = pt.y;
}
void output(){//输出
	double nowtime=times;
	if(lasttime==nowtime)
		return;
	out_z lz[lzs+1];
	for(int i=1;i<=lzs;i++){
		lz[i].z=z[i];
		lz[i].bh=i;
	}
	sort(lz+1,lz+lzs+1,z_cmp);
	cleardevice();
	bool xuanzhong=0;
	int xuanzhong_=0;
	for(ull i=1;i<=lzs;i++){
		int now_=lz[i].bh;
		if(zl[now_]==-1)
			continue;
		setfillcolor(BLACK);
		if(tcxs){
			if(zfwz[now_]==0)
				setfillcolor(BLUE);
			else
				setfillcolor(RED);
		}
		if(!xuanzhong){
			int x_,y_;
			mouse_window(x_,y_);
			x_/=10;
			y_/=10;
			if(sqrt(pow(x[now_]-x_,2)+pow(y[now_]-y_,2))<bj[now_]){
				setfillcolor(YELLOW);
				xuanzhong=1;
				xuanzhong_=now_;
				printf("\nx:%lf\ny:%lf\nz:%lf\nx速度:%lf\ny速度:%lf\nz速度:%lf\nx加速度:%lf\ny加速度:%lf\nz加速度:%lf\n质量:%lf\n能量:%lf\n半径:%lf\n正反物质类型:%s\n电荷量:%lf\n",x[now_],y[now_],z[now_],xsd[now_],ysd[now_],zsd[now_],xjsd[now_],yjsd[now_],zjsd[now_],zl[now_],nl[now_],bj[now_],zfwz[now_]?"反物质":"正物质",dh[now_]);
			}
		}
		fillcircle(x[now_]*10,y[now_]*10,bj[now_]*10/z[now_]);
	}
	delay_fps(60);
	lasttime=times;
	if(xuanzhong){
		while(1){
			int x_,y_;
			mouse_window(x_,y_);
			x_/=10;
			y_/=10;
			if(!(sqrt(pow(x[xuanzhong_]-x_,2)+pow(y[xuanzhong_]-y_,2))<bj[xuanzhong_])){
				break;
			}
			Sleep(50);
		}
	}
}
// 碰撞检查与响应函数
bool check_collision(ull p1, ull p2) {
	double dx = fabs(x[p1] - x[p2]);
	double dy = fabs(y[p1] - y[p2]);
	double dz = fabs(z[p1] - z[p2]);
	double dist = sqrt(dx * dx + dy * dy + dz * dz);
	
	// 碰撞判定
	if (dist <= bj[p1] + bj[p2]) {
		// 计算单位法向量
		double nx = dx / dist;
		double ny = dy / dist;
		double nz = dz / dist;
		
		// 计算切向量
		double tx = -ny;
		double ty = nx;
		double tz = 0; // 切向量在Z方向的分量应为0，根据前提描述
		
		// p1和p2在法向和切向上的速度分量
		double v1n = xsd[p1] * nx + ysd[p1] * ny + zsd[p1] * nz;
		double v1t = xsd[p1] * tx + ysd[p1] * ty + zsd[p1] * tz;
		double v2n = xsd[p2] * nx + ysd[p2] * ny + zsd[p2] * nz;
		double v2t = xsd[p2] * tx + ysd[p2] * ty + zsd[p2] * tz;
		
		// 使用一维弹性碰撞公式计算法向速度分量的结果
		double v1nAfter = (v1n * (zl[p1] - zl[p2]) + 2 * zl[p2] * v2n) / (zl[p1] + zl[p2]);
		double v2nAfter = (v2n * (zl[p2] - zl[p1]) + 2 * zl[p1] * v1n) / (zl[p1] + zl[p2]);
		
		// 更新速度
		xsd[p1] = v1nAfter * nx + v1t * tx;
		ysd[p1] = v1nAfter * ny + v1t * ty;
		zsd[p1] = v1nAfter * nz + v1t * tz;
		
		xsd[p2] = v2nAfter * nx + v2t * tx;
		ysd[p2] = v2nAfter * ny + v2t * ty;
		zsd[p2] = v2nAfter * nz + v2t * tz;
		return 1;
	}
	return 0;
}

void pengzhuang(){
	fstream r1;
	r1.open("D:\\yz\\happen.data",ios::app);
	for(ull i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		for(ull j=i+1;j<=lzs;j++){
			if(zl[j]==-1)
				continue;
			if(check_collision(i,j))
				r1<<"1 "<<i<<" "<<j<<" "<<times<<"\n";
		}
	}
	r1.close();
	r1.clear();
}
void dongliang(){
	for(ull i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		double sd=sqrt(x[i]*x[i]+y[i]*y[i]+z[i]*z[i]);
		dl[i]=zl[i]*cv(gs,sd)-zl[i]*gs*gs;
	}
}
void all_E_M(){
	for(int i=1;i<=lzs;i++)
		E_to_M(i);
}
void jiasudugengxin(){
	updateParticles();
	/*
	for(ull i=1;i<=lzs;i++){
	if(zl[i]==-1)
	continue;
	for(ull j=1;j<=lzs;j++){
	if(zl[j]==-1)
	continue;
	if(i==j)
	continue;
	double xjl=fabs(x[i]-x[j]);//x距离 
	double yjl=fabs(y[i]-y[j]);//y距离 
	double zjl=fabs(z[i]-z[j]);//z距离 
	double jl=sqrt(pow(xjl,2)+pow(yjl,2)+pow(zjl,2));
	double sum=xjl+yjl+zjl;
	double yl=ag(jl,zl[j]);
	double G = 6.67430e-11; // 引力常数
	double F = G * (zl[i] * zl[j]) / (jl * jl); // 计算引力
	if (sum != 0) { // 确保分母非零
	xjsd[i] = (xjl / sum) * (F ); // x方向上的加速度
	yjsd[i] = (yjl / sum) * (F); // y方向上的加速度
	zjsd[i] = (zjl / sum) * (F) ; // z方向上的加速度
	}
	else{
	zl[i]=zl[i]+zl[j];
	bj[i]=bj[i]+bj[j];
	zl[j]=-1;
	}
	if(dh[i]*dh[j]<0){ // 异性相吸
	double cl=ac(jl,dh[j]);
	xjsd[i]+=(xjl/sum)*cl/zl[i]; // x加速度 
	yjsd[i]+=(yjl/sum)*cl/zl[i]; // y加速度 
	zjsd[i]+=(zjl/sum)*cl/zl[i]; // z加速度 
	} else if (dh[i]*dh[j]>0){ // 同性相斥
	double cl=ac(jl,zl[j]);
	xjsd[i]-=(xjl/sum)*cl/zl[i]; // x加速度 
	yjsd[i]-=(yjl/sum)*cl/zl[i]; // y加速度 
	zjsd[i]-=(zjl/sum)*cl/zl[i]; // z加速度 
	}
	
	}
	}*/
}
void zhengfanyanmie(){
	bool is=0;
	for(ull i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		for(ull j=1;j<=lzs;j++){
			if(i==j||zl[j]==-1)
				continue;
			if(zfwz[i]==zfwz[j])
				continue;
			double jl=sqrt(pow(fabs(x[i]-x[j]),2)+pow(fabs(y[i]-y[j]),2)+pow(fabs(z[i]-z[j]),2));
			if(jl<=bj[i]+bj[j]){
				is=1;
				double tj1=1.333333333333333333333333333333333333333/*4/3*/*pi*pow(bj[i],3);
				double tj2=1.333333333333333333333333333333333333333*pi*pow(bj[j],3);
				if(tj1>tj2){//体积保留 
					zl[j]=-1;
					bj[i]=pow(tj1-tj2,1/3);
				}
				else if(tj1<tj2){
					zl[i]=-1;
					bj[j]=pow(tj2-tj1,1/3);
				}
				else{
					zl[i]=-1,zl[j]=-1;
				}
				fstream happen;
				happen.open("D:\\yz\\happen.data",ios::app);
				happen<<"2 "<<i<<" "<<j<<" "<<times<<"\n";//未完成
				happen.close();
				happen.clear();
				break;
			}
		}
	}
	if(is==1){
		clean_();
	}
}
int jisuan(){
	int begin=clock();
//	while(1){
	if(expansivity_==1)
		expand=yzdx*expansivity;
	expand+=expandadd;
	yzdx+=expand;
	zhengfanyanmie();
	jiasudugengxin();
	weizhigengxin();
//		pengzhuang();
	if(time_)
		times--;
	else
		times++;
//	}
	
	int over=clock();
	return begin-over;
}
void xunhuanjisuan(){
	while(1){
		while(pause==1){
			Sleep(500);
		}
		jisuan();
	}
}
signed main(){
	system("title 模拟宇宙");
	printf("loading......\n");
	ios::sync_with_stdio(0);
	cin.tie(0);
//	if(!wifi("39.156.66.10",80)){
//		MessageBox(NULL,"网络未连接(0xC)","error message",MB_OK);
//		exit(12);
//	}
	srand(time(0));
	MEMORYSTATUSEX statex;
	statex.dwLength=sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	ull i=statex.ullAvailPhys/1048576/*1024*1024*/;
	if(i<256){
		printf("内存不足，剩余%lldMB的物理内存，普通运行情况下须保持至少256MB的物理内存才能基本保持流畅运行。\n",i);
		system("pause");
		exit(10);
	}
	printf("遇到问题请与kkksc003@126.com联系处理\n");
	printf("不要乱输!不要乱输!!不要乱输!!!乱输后果很严重!\n");
	printf("按下Q键进入命令模式，按下S键保存数据，按下C键登录\n");
	for(ull i=1;i<=yzs;i++)//初始化
		zl[i]=-1;
	bool allscan=0;
	{	fstream a;
		a.open("D:\\yz\\happen.data",ios::out);
		a.close();
		a.clear();
		a.open("D:\\yz\\saves.data");
		if(a.is_open()){
			cout<<char(7);
			if(MessageBox(NULL,"发现全程保存的数据，是否还原？","",MB_YESNO|MB_ICONQUESTION)==IDYES)
				allscan=1;
		}
		if(!allscan){
			a.close();
			a.clear();
			a.open("D:\\yz\\save.data");
			if(a.is_open()){
				cout<<char(7);
				if(MessageBox(NULL,"发现保存数据，是否使用?","",MB_YESNO|MB_ICONQUESTION)==IDYES)
					scandata();
				else
					chushihua();
			}else
				chushihua();
			a.close();
			a.clear();
		}
	}
	cout<<char(7);
	if(MessageBox(NULL,"是否取消宇宙大小限制？","",MB_YESNO)==IDYES)
		yzdx=INF;
	if(MessageBox(NULL,"是否分开显示正反物质？正物质用蓝色表示，反物质用红色表示，但是输出速度会减慢","",MB_YESNO)==IDYES)
		tcxs=1;
	cout<<"请输入模拟精度（精度越高，模拟越准确，但是速度越慢）"<<endl;
	cin>>jsbc;
	system("cls");
	fstream qwq;
	qwq.open("D:\\yz\\saves.data");
	if(!allscan){
		qwq.close();
		qwq.clear();
	}
	if(!qwq.is_open()&&allscan){
		cout<<char(7);
		MessageBox(NULL,"找不到数据(0xD)","error message",MB_OK);
		exit(13);
	}
//	thread jisuans(xunhuanjisuan);
//	jisuans.detach();
	initgraph(signed(yzdx*10),signed(yzdx*10));//打开一个窗口
	setcaption("Your universe");//设置标题
	while(1){
		if(KEY_DOWN('Q'))
			cmd();
		if(KEY_DOWN('S'))
			savedata();
		if(KEY_DOWN('C'))
			cmdlogin_();
		int fps=jisuan();
		output();
		system("cls");
		if(fps==0)
			cout<<"fps:>1000"<<endl;
		else
			cout<<"fps:"<<setprecision(8)<<1000.0/fps<<endl;
		printf("时间:%lld",times);
	}
}
