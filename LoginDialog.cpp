#include "LoginDialog.h"
#pragma execution_character_set("utf-8")
LoginDialog::LoginDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("��¼����");
    usrLabel = new QLabel(this);
    usrLabel->move(70, 85);
    usrLabel->setText("�û���:");
    usrLineEdit = new QLineEdit(this);
    usrLineEdit->move(140, 80);
    usrLineEdit->setPlaceholderText("�������û���:");
    usrLineEdit->setClearButtonEnabled(1);

    pwdLabel = new QLabel(this);
    pwdLabel->move(70, 135);
    pwdLabel->setText("����:");
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140, 130);
    pwdLineEdit->setPlaceholderText("����������:");
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    pwdLineEdit->setClearButtonEnabled(1);

    loginBtn = new QPushButton(this);
    loginBtn->move(50, 200);
    loginBtn->setText("��¼");
    exitBtn = new QPushButton(this);
    exitBtn->move(210, 200);
    exitBtn->setText("�˳�");
    connect(loginBtn,&QPushButton::clicked, this, &LoginDialog::login);
    connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);

    group = new QButtonGroup(this);//���û�ѡ��͹���Աѡ�����һ��Group��
    user = new QRadioButton(tr("�û���¼"), this);
    admin = new QRadioButton(tr("����Ա��¼"), this);
    group->addButton(user, 1);
    group->addButton(admin, 2);
    user->move(30, 30);
    admin->move(200, 30);

    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/new/prefix1/44.jpg);}");//���ñ���ͼƬ
}
void LoginDialog::login()//�ۺ���������¼
{
    if ((sql_tmp.identify(usrLineEdit->text().trimmed(),pwdLineEdit->text().trimmed()) && group->checkedId() == 1)||(usrLineEdit->text().trimmed() == "yzx" && pwdLineEdit->text().trimmed() == "123456" && group->checkedId() == 2))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, "����!", "�û������������!", QMessageBox::Yes);
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}

LoginDialog::~LoginDialog()
{
}
string LoginDialog::getusr()//����������û���
{
    string usr = usrLineEdit->text().toStdString();
    return usr;
}
string LoginDialog::getpwd()//�������������
{
    string pwd = pwdLineEdit->text().toStdString();
    return pwd;
}
