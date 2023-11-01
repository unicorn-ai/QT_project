#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    if(ui->comboBox_3->currentText()=="0"){max_temper_alarm=14;}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
//    if(ui->comboBox_3->currentText()=="0"){}
    f=new MainWindow;
    connect(this,SIGNAL(send_data(int)),f,SLOT(get_data(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

//void Dialog::on_buttonBox_clicked(QAbstractButton *button)
//{
//    QString mes="sendddd";
//    int SD[9];
//    SD[0]=ui->comboBox_3->currentText().toInt();
//    SD[1]=ui->comboBox_13->currentText().toInt();
//    SD[2]=ui->comboBox_2->currentText().toInt();
//    SD[3]=ui->comboBox_12->currentText().toInt();
//    SD[4]=ui->comboBox_7->currentText().toInt();
//    SD[5]=ui->comboBox_11->currentText().toInt();
//    SD[6]=ui->comboBox_8->currentText().toInt();
//    SD[7]=ui->comboBox_9->currentText().toInt();

//for(int i = 0; i < 8; i++)
//{
//emit send_data(SD[i]);
//}
//    memset(SD,'\0',sizeof(SD));
//    num+=1;
//}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog::on_pushButton_clicked()
{
    QString mes="sendddd";
    int c=12;
    int SD[9];
    SD[0]=ui->comboBox_3->currentText().toInt();
    SD[1]=ui->comboBox_13->currentText().toInt();
    SD[2]=ui->comboBox_2->currentText().toInt();
    SD[3]=ui->comboBox_12->currentText().toInt();
    SD[4]=ui->comboBox_7->currentText().toInt();
    SD[5]=ui->comboBox_11->currentText().toInt();
    SD[6]=ui->comboBox_8->currentText().toInt();
    SD[7]=ui->comboBox_9->currentText().toInt();

for(int i = 0; i < 8; i++)
{
emit send_data(SD[i]);
}
    memset(SD,'\0',sizeof(SD));
    num+=1;
//   emit send_data(c);
    this->close();
}
