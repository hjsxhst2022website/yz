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
double sdx=0,sdy=0,sdz=0;//�ӵ�x���ӵ�y���ӵ�z
ull xsfw=20;//��ʾ��Χ
double jsbc=1;//���㲽��
ull gs=2;//����
double ylcl=0.0000000000667259;//��������
ull yzdx=60;//�����С
double expand=0;
const ull yzs=1000000;
double time_speed=0;
double sxpl=0.05;
ull lzs=0;
double expansivity=0;
bool expansivity_=0; 
string cmdpassword="114514hhh";
bool cmdlogin=1;
bool time_=0;//ʱ�䷽��(��0��1)
vector<bool> zfwz(yzs + 5);//��������(��0��1)
vector<double> bj(yzs + 5);//����һ�����壬��뾶(��)
vector<double> x(yzs + 5);//��
vector<double> y(yzs + 5);//��
vector<double> z(yzs + 5);//��
vector<double> xsd(yzs + 5);//��/��
vector<double> ysd(yzs + 5);//��/��
vector<double> zsd(yzs + 5);//��/��
vector<double> xjsd(yzs + 5);//��/��^2
vector<double> yjsd(yzs + 5);//��/��^2
vector<double> zjsd(yzs + 5); // ��/��^2
vector<double> zl(yzs + 5); // ǧ��
vector<double> nl(yzs + 5); // ����
vector<double> dl(yzs + 5); // ����
vector<double> dh(yzs + 5); // ���
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
		// ��� zl[i] ��ֵΪ -1����������ǰѭ������ִ�к�������
		if(zl[i] == -1) {
			continue;
		}
		// ����Ϊ -1 ��Ԫ�ض�Ӧ�����ݴ�����ʱ������
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
	// ���ԭ����������
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
	// ����ʱ�����е��������¸�ֵ��ԭ������
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

bool tcxs;//��������ͻ����ʾ
ull time_speed_=1;//�����ٶȣ�1����һ��
ull times=0;//ʱ��
long double expandadd=0;//���ͼ��ٶ�
//���ܺ���
//��������Ƿ�ͨ���ĺ���
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
//stringת��Ϊlonglong
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
double cv(double c,double v){//cvת��
	return (c*c)/sqrt(1-((v*v)/(c*c)));
}
//��������
double ag(double mass,double distance){
	const double constg=6.67430e-11;
	return (constg*mass)/(distance*distance);
}
//��������
double ac(double charge,double distance){
	const double constc=8.987551e9;
	return (constc*charge)/(distance*distance);
}
//���淢�����¼�
void save_happen(string a){
	fstream r1;
	r1.open("D:\\yz\\happen.data",ios::app);
	r1<<a<<'\n';
	r1.close();
	r1.clear(); 
	return;
}
//���뻻��
double clocks(){
	return clock()*1.0/CLOCKS_PER_SEC;
}
//cmd��¼(Ĭ�ϵ�¼)
void cmdlogin_(){
	system("cls");
	if(cmdlogin){
		printf("�ѵ�¼");
		Sleep(2000);
		return;
	}
	printf("���������Ա����:");
	string password;
	getline(cin,password);
	if(password==cmdpassword){
		printf("��½�ɹ�");
		cmdlogin=1;
	}else{
		printf("��¼ʧ��");
		Sleep(2000);
	}
	return;
}
//cmdδ��¼
void not_have_cmd(){
	printf("��Ϊ����ԱȨ�ޣ�����û�е�¼\n");
	Sleep(2000);
	return; 
}
void E_to_M(ull yzw1){//����ת��Ϊ���������ݰ���˹̹�Ĺ�ʽ������ԭ��λ
	zl[yzw1]=nl[yzw1]*1.0/pow(gs,2);
}

void M_to_E(ull yzw1){//����ת��Ϊ���������ݰ���˹̹�Ĺ�ʽ
	nl[yzw1]=zl[yzw1]*(gs*gs);
}
//over

void add(ull i){//���룬��������λ
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
		printf("������x(0~%lld%s",yzdx,"):");
		cin>>x[i];
		printf("������y(0~%lld%s",yzdx,"):");
		cin>>y[i];
		printf("������z(0~%lld%s",yzdx,"):");
		cin>>z[i];
		printf("������x�ٶ�(0~%lld%s",gs,"):");
		cin>>xsd[i];
		printf("������y�ٶ�(0~%lld%s",gs,"):");
		cin>>ysd[i];
		printf("������z�ٶ�(0~%lld%s",gs,"):");
		cin>>zsd[i];
		printf("������x���ٶ�(0~%lld%s",gs,"):");
		cin>>xjsd[i];
		printf("������y���ٶ�(0~%lld%s",gs,"):");;
		cin>>yjsd[i];
		printf("������z���ٶ�(0~%lld%s",gs,"):");
		cin>>zjsd[i];
		printf("����������(kg):");
		cin>>zl[i];
		M_to_E(i);
		printf("����������(C):");
		cin>>dh[i];
		printf("������������������(��0��1):");
		int x;
		cin>>x;
		if(x!=0&&x!=1){
			cout<<char(7);
			MessageBox(NULL,"���������������ݴ���","error message",MB_OK);
			add(i);
		}
		zfwz[i]=x;
		printf("���������Ӱ뾶(��):");
		cin>>bj[i];
		return;
	}else
		printf("�����ڴ�����\n");
}

void savedata(){//�������ݣ�һ������׼���رճ���ʱʹ��
	system("cls");
	printf("׼������\n");
	fstream save;
	save.open("D:\\yz\\save.data",ios::out);
	save.close();
	save.clear();
	save.open("D:\\yz\\save.data");
	save<<setprecision(15)<<lzs<<'\n'<<yzdx<<'\n'<<gs<<'\n'<<expand<<'\n'<<expandadd<<'\n';
	for(int i=1;i<=lzs;i++){
		if(zl[i]==-1)
			continue;
		save<<setprecision(15)<<(x[i]==inf?0:x[i])<<" "<<(y[i]==inf?0:y[i])<<" "<<(z[i]==inf?0:z[i])<<" "<<(xsd[i]==inf?0:xsd[i])<<" "<<(ysd[i]==inf?0:ysd[i])<<" "<<(zsd[i]==inf?0:zsd[i])<<" "<<(xjsd[i]==inf?0:xjsd[i])<<" "<<(yjsd[i]==inf?0:yjsd[i])<<" "<<(zjsd[i]==inf?0:zjsd[i])<<" "<<(zl[i]==inf?0:zl[i])<<" "<<zfwz[i]<<" "<<(bj[i]==inf?0:bj[i])<<" "<<(dh[i]==inf?0:dh[i])<<endl;//x-y-z-x�ٶ�-y�ٶ�-z�ٶ�-x���ٶ�-y���ٶ�-z���ٶ�-����-��������-�뾶-���
		cout<<"�����"<<i*1.0/lzs*100<<"%"<<endl;
	}
	save.close();
	save.clear();
	printf("���\n");
	Sleep(1000);
	system("cls");
	return;
}
void cmd(void){//����Ա
	system("cls");
	cout<<"��������ģʽ"<<endl;
	printf("done:�˳�����ģʽ\nclean:������\nxdd+����:����������x�����ƶ�\nydd+����:����������y�����ƶ�\nzdd+����:����������z�����ƶ�\nspeed:�ı�ˢ���ٶ�\ntime speed:�ı�����ٶ�\ntime:����ʱ�����ŷ���\ndata:�鿴��ʹ������������ʹ���������������С�������ٶȣ�����ʧ�Ĳ��㣩\nlook:�鿴��������\nrange add:�ƶ������е�����\nalter:�޸����Ӳ���\nlook all:��ʾ���д��ڵ��������ʵ�����\nall:��ʾ���д��ڵ���������\nmove eye:�ƶ��ӵ�λ�ã�δ��ɣ�\nexpand:�ı�������\ndisplay change:��ʾ��Χ����(δ���)\nexit:�����˳�\nexpand add:�ı������ٶȼ��ٶ�\nchange size:�ı������С\nadd:�������\ndel+����:ɾ�������ŵ�����\nrange del:ɾ�������ڵ�����\nexpansivity:�������ڵĴ�С��һ���ı��ʸı������ٶ�\nhappen:�鿴���µ�10���¼�\nhappen all:�鿴���з����¼�\nhelp:����\nupdate log:�鿴������־\npause:��ͣ����\n");
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
			printf("������ÿ֡ˢ���ٶ�(��):");
			cin>>sxpl;
		}else if(n=="time"){
			printf("����������0������1��:");
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
			printf("��ʹ��������:%lld\nʹ��������:%lld\n",yzs,a); 
			cout<<"�����С:";
			if(yzdx==INF)
				cout<<"inf";
			else
				cout<<yzdx;
			cout<<'\n';
			printf("�����ٶ�:%lf\n����:%lld\n",expand,gs);
		}else if(n=="look"){
			if(cmdlogin){
				printf("������鿴�����ӱ�ţ�");
				ull a;
				cin>>a;
				if(a<=lzs&&a!=0){
					printf("x:%lf\ny:%lf\nz:%lf\nx�ٶ�:%lf\ny�ٶ�:%lf\nz�ٶ�:%lf\nx���ٶ�:%lf\ny���ٶ�:%lf\nz���ٶ�:%lf\n����:%lf\n����:%lf\n�뾶:%lf\n������������:%s\n�����:%lf\n",x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"������":"������",dh[a]);
				}else
					printf("�����ڴ�����\n");
			}else{
				not_have_cmd();
			}
		}else if(n=="time speed"){
			printf("������ÿ�μ����ٶ�(��):");
			cin>>time_speed;
			time_speed*=1000;
		}else if(n=="alter"){
			printf("�������޸�����:");
			ull i;
			cin>>i;
			add(i);
		}else if(n=="range add"){
			double x1,x2,y1,y2,z1,z2;
			printf("�밴x1,x2,y1,y2,z1,z2��˳������:");
			cin>>x1>>x2>>y1>>y2>>z1>>z2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			if(z1>z2)
				swap(z1,z2);
			double xadd,yadd,zadd;
			printf("������x�����ƶ�����:");
			cin>>xadd;
			printf("������y�����ƶ�����:");
			cin>>yadd;
			printf("������z�����ƶ�����:");
			cin>>zadd;
			printf("����ִ��......\n");
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
			printf("������%lld����������%lld��������%lld��\n",zheng,fan,have);
		}else if(n=="all"){
			for(ull a=1;a<=yzs;a++){
				if(zl[a]==-1)
					continue;
				printf("���:%lld\nx:%lf\ny:%lf\nz:%lf\nx�ٶ�:%lf\ny�ٶ�:%lf\nz�ٶ�:%lf\nx���ٶ�:%lf\ny���ٶ�:%lf\nz���ٶ�:%lf\n����:%lf\n����:%lf\n�뾶:%lf\n������������:%s\n�����:%lf\n\n",a,x[a],y[a],z[a],xsd[a],ysd[a],zsd[a],xjsd[a],yjsd[a],zjsd[a],zl[a],nl[a],bj[a],zfwz[a]?"������":"������",dh[a]);
			}
		}else if(n=="move eye"){
			printf("�������ӵ�x����λ��:");
			cin>>sdx;
			printf("�������ӵ�y����λ��:");
			cin>>sdy;
		}else if(n=="expand"){
			printf("�����������ٶ�:");
			cin>>expand;
		}else if(n=="display change"){
			printf("��������ʾ��Χ:");
			cin>>xsfw;
		}else if(n=="exit"){
			savedata();
			exit(0);
		}else if(n=="expand add"){
			printf("�����������ٶȼ��ٶ�:");
			cin>>expandadd;
		}else if(n=="change size"){
			printf("�����������С:");
			cin>>yzdx;
			closegraph();
			initgraph(signed(yzdx*10),signed(yzdx*10));//��һ������
			setcaption("Your universe");//���ñ���
		}else if(n=="add"){
			lzs++;
			add(lzs);
		}else if(n[0]=='d'&&n[1]=='e'&&n[2]=='l'){
			int yzw=string_to_longlong(n);
			zl[yzw]=-1;
		}else if(n=="range del"){
			double x1,x2,y1,y2,z1,z2;
			printf("�밴x1,x2,y1,y2,z1,z2��˳������:");
			cin>>x1>>x2>>y1>>y2>>z1>>z2;
			if(x1>x2)
				swap(x1,x2);
			if(y1>y2)
				swap(y1,y2);
			if(z1>z2)
				swap(z1,z2);
			printf("����ִ��......\n");
			for(ull i=1;i<=yzs;i++){
				if(zl[i]==-1)
					continue;
				if(x[i]>=x1&&x[i]<=x2&&y[i]>=y1&&y[i]<=y2&&z[i]>=z1&&z[i]<=z2)
					zl[i]=-1;
			}
		}else if(n=="expansivity"){
			if(expansivity==0){
				printf("������������:(��λ:%%):");
				cin>>expansivity;
				if(expansivity>100||expansivity<-100)
					printf("���ݴ���\n");
				else{
					expansivity/=100;
					expansivity_=1;
				}
				printf("\n");
			}else{
				printf("�Ѿ�ͣ��������\n");
				expansivity=0;
			}
		}else if(n=="happen"){
			fstream r1;
			r1.open("D:\\yz\\happen.data");
			if(!r1.is_open()){
				printf("�ļ�������\n");
				system("pause");
			}
			for(int i=1;i<=10&&!r1.eof();i++){
				ull a;
				r1>>a;
				if(a==1){
					ull i,j,time;
					r1>>i>>j>>time;
					printf("������ײat%lld������&%lld�����ӣ��ڵ�%lld�θ���ʱ��ײ\n",i,j,time);
				}else if(a==2){
					int i,j,time;
					r1>>i>>j>>time;
					printf("������������at%lld������&%lld�����ӣ��ڵ�%lld�θ���ʱ����\n",i,j,time);
				}
			}
			r1.close();
			r1.clear();
		}else if(n=="del"){
			int s=0;
			cout<<"������ɾ�����ӣ�";
			cin>>s;
			zl[s]=-1;
			cout<<"\n�������\n";
		}
		else if(n=="happen all"){
			fstream r1;
			r1.open("D:\\yz\\happen.data",ios::in);
			if(!r1.is_open()){
				printf("�ļ�������\n");
				system("pause");
			}
			while(!r1.eof()){
				ull a;
				r1>>a;
				if(a==1){
					ull i,j,time;
					r1>>i>>j>>time;
					printf("������ײat%lld������&%lld�����ӣ��ڵ�%lld�θ���ʱ��ײ\n",i,j,time);
				}else if(a==2){
					int i,j,time;
					r1>>i>>j>>time;
					printf("������������at%lld������&%lld�����ӣ��ڵ�%lld�θ���ʱ����\n",i,j,time);
				}
			}
			r1.close();
			r1.clear();
		}else if(n=="help"){
			system("start D:\\yz\\help.html");
		}else if(n=="pause"){
			if(pause==0){
				pause=1;
				cout<<"����ͣ����\n";
			}else{
				pause=0;
				cout<<"����������\n";
			}
		}else if(n=="update log"){
			system("start https://www.luogu.com.cn/paste/hglsje64");
		}
		else if(n!=""){
			printf("\"%s\"���ǿ�ִ�е�����\n",&n[0]);
		}
		cout<<"�������"<<endl;
	}
	system("cls");
}
bool scandata(){//��ȡ���ݣ�һ�����ڳ���ʼ
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
			cout<<"�����"<<i*1.0/lzs*100<<"%"<<endl;
		}
		qwq.close();
		qwq.clear();
		system("cls");
		return 1;
	}else{
		cout<<char(7);
		printf("û���ҵ�����\n");
		qwq.close();
		qwq.clear();
		Sleep(2000);
		system("cls");
		return 0;
	}
}

bool zdsj(){
	cout<<char(7);
	int a=MessageBox(NULL,TEXT("�Ƿ��Զ������ݣ�"),"",MB_YESNO);//�Զ�������
	if(a==IDYES){
		system("cls");
		printf("�������룬��Ȼ���鷳Ŷ\n");
		printf("�����������С:");
		cin>>yzdx;
		printf("������ԭ����(1~");
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
		printf("���������:");
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
			printf("�����%lf%%\n",i*1.0/lzs*100);
		}
		cout<<"over"<<endl;
		system("cls");
		return 1;
	}
	return 0;
}

void qidong(){
	system("cls");
	printf("������������(0~%lld):",yzs);
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
	printf("���������:");
	cin>>gs;
	if(gs<=0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The speed of light is too small(0x3)"),TEXT("error message"),MB_OK);
		exit(3);
	}
	printf("�����������С:");
	cin>>yzdx;
	if(yzdx<=0){
		cout<<char(7);
		MessageBox(NULL,TEXT("The universe is too small(0x5)"),TEXT("error message"),MB_OK|MB_ICONSTOP);
		exit(5);
	}
	srand(time(0));
	for(int i=1;i<=lzs;i++){//��ʼ��
		x[i]=rand()%yzdx;
		y[i]=rand()%yzdx;
		z[i]=rand()%yzdx;
		bool zf=rand()%2;//���� 
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
		cout<<"�����"<<i*1.0/lzs*100<<"%"<<endl;
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
		double ax = 0, ay = 0, az = 0; // ���ٶȳ�ʼ��Ϊ0
		for (int j = 0; j < lzs; ++j) {
			if(zl[j]==-1)
				continue;
			if (i != j) {
				double dx = fabs(x[j] - x[i]);
				double dy = fabs(y[j]- y[i]);
				double dz = fabs(z[j] - z[i]);
				double r = sqrt(dx * dx + dy * dy + dz * dz); // ��������֮��ľ���
				// ��������֮��ľ���
				if (r < MIN_DISTANCE) {
					r = MIN_DISTANCE;
				}
				// ��������
				double F = (G * zl[j] * zl[j]) / (r * r);
				ax += F * (dx / r);
				ay += F * (dy / r);
				az += F * (dz / r);
			}
		}
		
		// �����ٶȺ�λ��
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
		save<<setprecision(15)<<(x[i]==inf?0:x[i])<<" "<<(y[i]==inf?0:y[i])<<" "<<(z[i]==inf?0:z[i])<<" "<<(xsd[i]==inf?0:xsd[i])<<" "<<(ysd[i]==inf?0:ysd[i])<<" "<<(zsd[i]==inf?0:zsd[i])<<" "<<(xjsd[i]==inf?0:xjsd[i])<<" "<<(yjsd[i]==inf?0:yjsd[i])<<" "<<(zjsd[i]==inf?0:zjsd[i])<<" "<<(zl[i]==inf?0:zl[i])<<" "<<zfwz[i]<<" "<<(bj[i]==inf?0:bj[i])<<" "<<(dh[i]==inf?0:dh[i])<<endl;//x-y-z-x�ٶ�-y�ٶ�-z�ٶ�-x���ٶ�-y���ٶ�-z���ٶ�-����-��������-�뾶-���
	}
	save.close();
	save.clear();
	return;
}
bool scandatas(){
	cout<<char(7);
	int a=MessageBox(NULL,"�Ƿ�ʹ�����ݿ�?","",MB_YESNO);
	if(a==IDYES){
		string a;
		system("cls");
		printf("���������ݿ��ţ�");
		getline(cin,a);
		fstream r1;
		r1.open(&("D:\\yz\\data"+a+".data")[0]);
		if(!r1.is_open()){
			printf("���ݿ���Ϣ������\n");
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
			cout<<"�����"<<i*1.0/yzs*100<<"%"<<endl;
		}
		system("cls");
		return 1;
	}else
		return 0;
}

void chushihua(){//��ʼ�����
	if(scandatas());
	else
		if(zdsj());
	else qidong();
	return; 
}

void weizhigengxin(){//λ�ø������ֹ���������޷�����
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
	ull z;//z��
	ull bh;//���
};
bool z_cmp(out_z a,out_z b){
	return a.z>b.z;
}
void mouse_window(int &x,int &y){//��ȡ�������ڴ��ڵ�λ��
	HWND hwnd = GetForegroundWindow(); // ��ȡ��ǰ���ھ��
	POINT pt;
	GetCursorPos(&pt); // ��ȡ�������Ļ�����λ��
	ScreenToClient(hwnd, &pt); // ����Ļ����ת��Ϊ�����ڵĿͻ�������
	x = pt.x;
	y = pt.y;
}
void output(){//���
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
				printf("\nx:%lf\ny:%lf\nz:%lf\nx�ٶ�:%lf\ny�ٶ�:%lf\nz�ٶ�:%lf\nx���ٶ�:%lf\ny���ٶ�:%lf\nz���ٶ�:%lf\n����:%lf\n����:%lf\n�뾶:%lf\n������������:%s\n�����:%lf\n",x[now_],y[now_],z[now_],xsd[now_],ysd[now_],zsd[now_],xjsd[now_],yjsd[now_],zjsd[now_],zl[now_],nl[now_],bj[now_],zfwz[now_]?"������":"������",dh[now_]);
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
// ��ײ�������Ӧ����
bool check_collision(ull p1, ull p2) {
	double dx = fabs(x[p1] - x[p2]);
	double dy = fabs(y[p1] - y[p2]);
	double dz = fabs(z[p1] - z[p2]);
	double dist = sqrt(dx * dx + dy * dy + dz * dz);
	
	// ��ײ�ж�
	if (dist <= bj[p1] + bj[p2]) {
		// ���㵥λ������
		double nx = dx / dist;
		double ny = dy / dist;
		double nz = dz / dist;
		
		// ����������
		double tx = -ny;
		double ty = nx;
		double tz = 0; // ��������Z����ķ���ӦΪ0������ǰ������
		
		// p1��p2�ڷ���������ϵ��ٶȷ���
		double v1n = xsd[p1] * nx + ysd[p1] * ny + zsd[p1] * nz;
		double v1t = xsd[p1] * tx + ysd[p1] * ty + zsd[p1] * tz;
		double v2n = xsd[p2] * nx + ysd[p2] * ny + zsd[p2] * nz;
		double v2t = xsd[p2] * tx + ysd[p2] * ty + zsd[p2] * tz;
		
		// ʹ��һά������ײ��ʽ���㷨���ٶȷ����Ľ��
		double v1nAfter = (v1n * (zl[p1] - zl[p2]) + 2 * zl[p2] * v2n) / (zl[p1] + zl[p2]);
		double v2nAfter = (v2n * (zl[p2] - zl[p1]) + 2 * zl[p1] * v1n) / (zl[p1] + zl[p2]);
		
		// �����ٶ�
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
	double xjl=fabs(x[i]-x[j]);//x���� 
	double yjl=fabs(y[i]-y[j]);//y���� 
	double zjl=fabs(z[i]-z[j]);//z���� 
	double jl=sqrt(pow(xjl,2)+pow(yjl,2)+pow(zjl,2));
	double sum=xjl+yjl+zjl;
	double yl=ag(jl,zl[j]);
	double G = 6.67430e-11; // ��������
	double F = G * (zl[i] * zl[j]) / (jl * jl); // ��������
	if (sum != 0) { // ȷ����ĸ����
	xjsd[i] = (xjl / sum) * (F ); // x�����ϵļ��ٶ�
	yjsd[i] = (yjl / sum) * (F); // y�����ϵļ��ٶ�
	zjsd[i] = (zjl / sum) * (F) ; // z�����ϵļ��ٶ�
	}
	else{
	zl[i]=zl[i]+zl[j];
	bj[i]=bj[i]+bj[j];
	zl[j]=-1;
	}
	if(dh[i]*dh[j]<0){ // ��������
	double cl=ac(jl,dh[j]);
	xjsd[i]+=(xjl/sum)*cl/zl[i]; // x���ٶ� 
	yjsd[i]+=(yjl/sum)*cl/zl[i]; // y���ٶ� 
	zjsd[i]+=(zjl/sum)*cl/zl[i]; // z���ٶ� 
	} else if (dh[i]*dh[j]>0){ // ͬ�����
	double cl=ac(jl,zl[j]);
	xjsd[i]-=(xjl/sum)*cl/zl[i]; // x���ٶ� 
	yjsd[i]-=(yjl/sum)*cl/zl[i]; // y���ٶ� 
	zjsd[i]-=(zjl/sum)*cl/zl[i]; // z���ٶ� 
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
				if(tj1>tj2){//������� 
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
				happen<<"2 "<<i<<" "<<j<<" "<<times<<"\n";//δ���
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
	system("title ģ������");
	printf("loading......\n");
	ios::sync_with_stdio(0);
	cin.tie(0);
//	if(!wifi("39.156.66.10",80)){
//		MessageBox(NULL,"����δ����(0xC)","error message",MB_OK);
//		exit(12);
//	}
	srand(time(0));
	MEMORYSTATUSEX statex;
	statex.dwLength=sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	ull i=statex.ullAvailPhys/1048576/*1024*1024*/;
	if(i<256){
		printf("�ڴ治�㣬ʣ��%lldMB�������ڴ棬��ͨ����������뱣������256MB�������ڴ���ܻ��������������С�\n",i);
		system("pause");
		exit(10);
	}
	printf("������������kkksc003@126.com��ϵ����\n");
	printf("��Ҫ����!��Ҫ����!!��Ҫ����!!!������������!\n");
	printf("����Q����������ģʽ������S���������ݣ�����C����¼\n");
	for(ull i=1;i<=yzs;i++)//��ʼ��
		zl[i]=-1;
	bool allscan=0;
	{	fstream a;
		a.open("D:\\yz\\happen.data",ios::out);
		a.close();
		a.clear();
		a.open("D:\\yz\\saves.data");
		if(a.is_open()){
			cout<<char(7);
			if(MessageBox(NULL,"����ȫ�̱�������ݣ��Ƿ�ԭ��","",MB_YESNO|MB_ICONQUESTION)==IDYES)
				allscan=1;
		}
		if(!allscan){
			a.close();
			a.clear();
			a.open("D:\\yz\\save.data");
			if(a.is_open()){
				cout<<char(7);
				if(MessageBox(NULL,"���ֱ������ݣ��Ƿ�ʹ��?","",MB_YESNO|MB_ICONQUESTION)==IDYES)
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
	if(MessageBox(NULL,"�Ƿ�ȡ�������С���ƣ�","",MB_YESNO)==IDYES)
		yzdx=INF;
	if(MessageBox(NULL,"�Ƿ�ֿ���ʾ�������ʣ�����������ɫ��ʾ���������ú�ɫ��ʾ����������ٶȻ����","",MB_YESNO)==IDYES)
		tcxs=1;
	cout<<"������ģ�⾫�ȣ�����Խ�ߣ�ģ��Խ׼ȷ�������ٶ�Խ����"<<endl;
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
		MessageBox(NULL,"�Ҳ�������(0xD)","error message",MB_OK);
		exit(13);
	}
//	thread jisuans(xunhuanjisuan);
//	jisuans.detach();
	initgraph(signed(yzdx*10),signed(yzdx*10));//��һ������
	setcaption("Your universe");//���ñ���
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
		printf("ʱ��:%lld",times);
	}
}
