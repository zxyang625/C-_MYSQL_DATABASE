#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include"mymysql.h"
#include <QDialog>
#include<Qstring.h>
#include<QButtonGroup>
#include<QRadioButton>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QMessageBox>
#pragma execution_character_set("utf-8")
class QLabel;    
class QLineEdit;
class QPushButton;

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    LoginDialog(QWidget* parent = 0);
    ~LoginDialog();
private:
    Mysql sql_tmp;
    QLineEdit* usrLineEdit;//�û���
    QLineEdit* pwdLineEdit;//����
    QButtonGroup* group;
    QLabel* usrLabel;
    QLabel* pwdLabel;
    QPushButton* loginBtn;//��¼��ť
    QPushButton* exitBtn;//�˳���ť
    QRadioButton* user;//�û�ѡ��
    QRadioButton* admin;//����Աѡ��

public:
    string getusr();//����������û���
    string getpwd();//�������������
    void login();//�ۺ���������¼
};
#endif // LOGINDIALOG_H