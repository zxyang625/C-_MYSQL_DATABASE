#include"mainwindow.h"
#pragma execution_character_set("utf-8")
mainwindow::mainwindow(string usr,string pwd,QWidget* parent):QMainWindow(parent)
{
	this->setAttribute(Qt::WA_DeleteOnClose);
	conn=mysql.mysql_connect("yzx","123456");
	strcpy(mysql.user,usr.c_str());//���յ�¼������˺ź�����
	strcpy(mysql.password, pwd.c_str());
	char tmp1[50];//��ӭ��ʾ
	strcpy(tmp1, usr.c_str());
	tiplbl = new QLabel(strcat(tmp1,",��ӭ��¼���й���ϵͳ"), this);
	tiplbl->move(100, 5);
	tiplbl->resize(300, 50);
	QFont ft;//��������
	ft.setPointSize(14);
	tiplbl->setFont(ft);
	this->resize(480, 390);

	flight_show_btn = new QPushButton("�����ѯ",this);
	flight_show_btn->move(180, 50);
	hotel_show_btn = new QPushButton("�õ��ѯ", this);
	hotel_show_btn->move(180, 100);
	bus_show_btn = new QPushButton("������ѯ", this);
	bus_show_btn->move(180, 150);
	resv_show_btn = new QPushButton("������ѯ", this);
	resv_show_btn->move(180, 200);
	cust_show_btn = new QPushButton("�˿Ͳ�ѯ", this);
	cust_show_btn->move(180, 250);
	option_btn = new QPushButton("ϵͳ����", this);
	option_btn->move(180, 300);
	resv_btn = new QPushButton("Ԥ��ͨ��", this);
	resv_btn->move(180,250);
	exit_btn = new QPushButton("�˳�", this);
	exit_btn->move(180, 350);
	string tmp2 = mysql.user;
	if (tmp2 == "yzx")//���ڹ���Ա�����ض���Ԥ���İ�ť,��ʾ�˿Ͳ�ѯ��ϵͳ����
	{
		resv_btn->hide();
		cust_show_btn->show();
		option_btn->show();
	}
	else//�����û�����ʾ���������������س˿Ͳ�ѯ��ϵͳ����
	{
		option_btn->hide();
		cust_show_btn->hide();
		resv_btn->show();
	}

	this->setObjectName("mainWindow");
	this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix1/11.jpg);}");

	connect(flight_show_btn, &QPushButton::clicked, this, &mainwindow::slot_flight_show);
	connect(hotel_show_btn, &QPushButton::clicked, this, &mainwindow::slot_hotel_show);
	connect(bus_show_btn, &QPushButton::clicked, this, &mainwindow::slot_bus_show);
	connect(resv_show_btn, &QPushButton::clicked, this, &mainwindow::slot_resv_show);
	connect(cust_show_btn, &QPushButton::clicked, this, &mainwindow::slot_cust_show);
	connect(option_btn, &QPushButton::clicked, this, &mainwindow::slot_option);
	connect(resv_btn, &QPushButton::clicked, this, &mainwindow::slot_resv);
	connect(exit_btn, &QPushButton::clicked, this, &mainwindow::close);

}
mainwindow::~mainwindow()
{
	mysql_close(conn);
}

void mainwindow::tomain() {
	this->show();
}
void mainwindow::slot_flight_show()//��ѯ���ӽ������ɣ������ùݣ��������˿�����
{
	res=mysql.show(conn, "flights",res);// �����ݿ�õ��Ľ�������ӽ���
	unsigned int column = mysql_num_fields(res);//������
	this->hide();//����������
	childwin* chwin = new childwin(column , 1 , res ,this);//����Ϊ�������Ӵ���ѡ��Ϊ1
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("�����ѯ");
	chwin->show();//��ʾ�ӽ���
}
void mainwindow::slot_hotel_show()
{
	res = mysql.show(conn, "hotels", res);
	unsigned int column = mysql_num_fields(res);
	this->hide();
	childwin* chwin = new childwin(column, 2 , res, this);
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("�ùݲ�ѯ");
	chwin->show();
}
void mainwindow::slot_bus_show()
{
	res = mysql.show(conn, "buses", res);
	unsigned int column = mysql_num_fields(res);
	this->hide();
	childwin* chwin = new childwin(column, 3, res, this);
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("������ѯ");
	chwin->show();
}
void mainwindow::slot_resv_show()//�����û����û�ֻ�ܲ鿴�Լ��Ķ���������Ա���Բ鿴���г˿͵Ķ���
{
	string tmp = mysql.user;
	if (tmp == "yzx")
		res = mysql.select_all(conn, "reservations", res);
	else
		res = mysql.select(conn, mysql.user, res);
	unsigned int column = mysql_num_fields(res);
	childwin* chwin = new childwin(column, 4, res, this);
	this->hide();
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("������ѯ");
	chwin->show();
}
void mainwindow::slot_cust_show()
{
	res = mysql.select_all(conn, "customers", res);
	unsigned int column = mysql_num_fields(res);
	this->hide();
	childwin* chwin = new childwin(column, 5, res, this);
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("�˿Ͳ�ѯ");
	chwin->show();
}
void mainwindow::slot_resv()
{
	childwin* chwin = new childwin(conn, 1, mysql.user, this);
	this->hide();
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("��������");
	chwin->show();
}
void mainwindow::slot_option()
{
	childwin* chwin = new childwin(conn, 2, mysql.user, this);
	this->hide();
	connect(chwin, &childwin::sendsignal, this, &mainwindow::tomain);
	chwin->setWindowTitle("ϵͳ����");
	chwin->show();
}

