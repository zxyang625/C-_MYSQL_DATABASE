#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDialog>
#include<QMainWindow>
#include<QLabel>
#include <QTextEdit>
#include<QPushButton>
#include"childwin.h"
#include"mymysql.h"
#include"LoginDialog.h"
using namespace std;
class mainwindow :public QMainWindow//������
{
	Q_OBJECT;
public:
	explicit mainwindow(string,string,QWidget* parent = 0);
	~mainwindow();
	void tomain();//�ۺ������������ӽ�����źŷ���������
	void slot_flight_show();//�ۺ�������չʾ����
	void slot_hotel_show();//�ۺ�������չʾ�ù�
	void slot_bus_show();//�ۺ�������չʾ����
	void slot_resv_show();//�ۺ�������չʾ����
	void slot_cust_show();//�ۺ�������չʾ�˿�
	void slot_resv();//�ۺ�������Ԥ������
	void slot_option();//�ۺ�������ϵͳ����
	QPushButton* exit_btn;

private:
	QLabel* tiplbl;
	QPushButton* flight_show_btn;
	QPushButton* hotel_show_btn;
	QPushButton* bus_show_btn;
	QPushButton* resv_show_btn;
	QPushButton* cust_show_btn;
	QPushButton* option_btn;
	QPushButton* resv_btn;

	MYSQL* conn;
	Mysql mysql;
	MYSQL_RES* res = NULL;
};

#endif // !MAINWINDOW_H