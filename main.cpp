#include "LoginDialog.h"
#include"mainwindow.h"
#include <QtWidgets/QApplication>
#include<qmainwindow.h>
#include<QMessageBox>
#include<Windows.h>
#pragma execution_character_set("utf-8")
int main(int argc, char* argv[])
{

    QApplication a(argc, argv);
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        mainwindow* main = new mainwindow(dlg.getusr(), dlg.getpwd());//��¼ʱ���û��������봫�����˵�
        main->setWindowTitle("����Ԥ��ϵͳ");
        main->show();
        return a.exec();
    }
    return 0;
}