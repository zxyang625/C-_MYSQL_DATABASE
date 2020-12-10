#pragma once
#include<mysql.h>
#include<iostream>
#include<Qstring.h>
#include<QMessageBox>
#pragma execution_character_set("utf-8")
using namespace std;
class Mysql:public QWidget
{
	Q_OBJECT;
public:
		char* host = "localhost";//�������ݿ����Ϣ
		char user[20];
		char password[20];
		char* db="travel_system";

public:
	MYSQL* mysql_connect(const char* usr,const char* pwd); //�������ݿ�
	MYSQL_RES* show(MYSQL* mysql, const char* op, MYSQL_RES* res);//չʾ���ݿ�
	MYSQL_RES* select(MYSQL* mysql, const char* op, MYSQL_RES* res);//ͨ��op����ѡ��
	MYSQL_RES* select_all(MYSQL* mysql, const char* op, MYSQL_RES* res);//ͨ��op��������ѡ��
	bool resv_sql(MYSQL* mysql,const char* custname,int type ,const char* resvname);//��������
	bool delete_sql(MYSQL* mysql, const char* custname, int type, const char* resvname);//����ɾ��
	bool identify(QString,QString);//���ݿ������֤
	int sum(MYSQL* mysql, int type, const char* resvname);//�����ж����۸��ܺ�
private:
	MYSQL_RES* res = NULL;
	MYSQL_RES* tmp_res = NULL;
	MYSQL_ROW row=NULL;
	string customer[9][2] = {//��������ݿ��û�
		{"Ǯһ", "123456"},
		{"����", "123456"},
		{"����", "123456"},
		{"����", "123456"},
		{"����", "123456"},
		{"����", "123456"},
	    {"����", "123456"},
		{"����", "123456"},
		{"���", "123456"}	};
};

