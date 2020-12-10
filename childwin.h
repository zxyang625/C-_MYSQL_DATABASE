#ifndef CHILDWIN_H
#define CHILDWIN_H
#include <ctime>
#include<QPushButton>
#include<QTextEdit>
#include<QMainWindow>
#include<QMessageBox>
#include <QTableWidget>
#include<QHeaderView>
#include <QTableWidgetItem>
#include<QButtonGroup>
#include<QRadioButton>
#include<mysql.h>
#include"mymysql.h"
class childwin : public QMainWindow
{
	Q_OBJECT

public:
	explicit childwin(int column,int option,MYSQL_RES* res,QWidget *parent = nullptr);//��ѯ�����ӽ���
	explicit childwin(MYSQL* conn, int option ,const char* custname,QWidget* parent = nullptr);//�������ӽ���
	~childwin();
signals:
	void sendsignal();//������������ź�
private:
	Mysql mysql;//������Mysql
	void slot_back_to_main();//�ۺ�����������������
	void slot_resv();//�ۺ�����������
	void slot_delete();//�ۺ�������ɾ������
	void slot_system_option();//�ۺ�������ϵͳ����

	QPushButton* submit_btn;
	QPushButton* delete_btn;
	QButtonGroup* group;
	QRadioButton* flight;
	QRadioButton* hotel;
	QRadioButton* bus;
	QRadioButton* customer;
	QLineEdit* line;
	QPushButton* back_btn;
	QStringList header;
	QTableWidget* tableWidget;

	QTextEdit* output_text;
	QLineEdit* admin_line;
	
	char customer_name[50];
	MYSQL_RES* res = NULL;
	MYSQL* tmp_mysql =NULL;
	//MYSQL* tmp_mysql=NULL;
	MYSQL_RES* tmp_res = NULL;
	MYSQL_ROW tmp_row=NULL;
	MYSQL_ROW rows=NULL;
};


#endif