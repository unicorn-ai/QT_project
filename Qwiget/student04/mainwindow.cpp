#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAxObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::qTableWidget2Excel(QTableWidget *table)
{

    //导入
    //ui->progressBar->setValue(0);   //设置进度条的值为0
     QString path = QFileDialog::getOpenFileName(this,"open","../","execl(*.xlsx)");
    //指定父对象（this），“open”具体操作，打开，“../”默认，之后可以添加要打开文件的格式
    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file(path);
        //打开文件,默认为utf8变量，
        bool flag = file.open(QIODevice::ReadOnly);
        if(flag == true)//打开成功
        {

            QAxObject *excel = new QAxObject(this);//建立excel操作对象
            excel->setControl("Excel.Application");//连接Excel控件
            excel->setProperty("Visible", false);//不显示窗体看效果
            excel->setProperty("DisplayAlerts", false);//不显示警告看效果
            /*********获取COM文件的一种方式************/
            QAxObject *workbooks = excel->querySubObject("WorkBooks");
            //获取工作簿(excel文件)集合
            workbooks->dynamicCall("Open(const QString&)", path);//path至关重要，获取excel文件的路径
            //打开一个excel文件
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
            QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)",1);//访问excel中的工作表中第一个单元格
            QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet的范围
            /*********获取COM文件的一种方式************/
            //获取打开excel的起始行数和列数和总共的行数和列数
            int intRowStart = usedRange->property("Row").toInt();//起始行数
            int intColStart = usedRange->property("Column").toInt(); //起始列数
            QAxObject *rows, *columns;
            rows = usedRange->querySubObject("Rows");//行
            columns = usedRange->querySubObject("Columns");//列
            int intRow = rows->property("Count").toInt();//行数
            int intCol = columns->property("Count").toInt();//列数
            //起始行列号
            //qDebug()<<intRowStart;
            //qDebug()<<intColStart;
            //行数和列数
            //qDebug()<<intRow;
            //qDebug()<<intCol;
            int a,b;
            a=intRow-intRowStart+1,b=intCol-intColStart+1;
            QByteArray text[a][b];
            QString exceldata[a][b];
            int coerow=0,coecol=0;

            for (int i = intRowStart; i < intRowStart + intRow; i++,coerow++)
                {
                    coecol=0;//务必是要恢复初值的
                    for (int j = intColStart; j < intColStart + intCol; j++,coecol++)
                    {
                        auto cell = excel->querySubObject("Cells(Int, Int)", i, j );
                        QVariant cellValue = cell->dynamicCall("value");
                        text[coerow][coecol]=cellValue.toByteArray();//QVariant转换为QByteArray
                        exceldata[coerow][coecol]=QString(text[coerow][coecol]);//QByteArray转换为QString

                        //qDebug()<<exceldata[coerow][coecol]<<coerow<<" "<<coecol;
                    }
                }
            ui->tableWidget->setRowCount(a-1);
            for(int i=1;i<a;++i)
                for(int j=0;j<b;++j)
                {
                    ui->tableWidget->setItem(i-1, j, new QTableWidgetItem(exceldata[i][j]));

                }


            workbook->dynamicCall( "Close(Boolean)", false );
            excel->dynamicCall( "Quit(void)" );
            delete excel;

           // QMessageBox::warning(this,tr("读取情况"),tr("读取完成！"),QMessageBox::Yes);

        }
        file.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_00clicked()
{
    qTableWidget2Excel(ui->tableWidget);
}

void MainWindow::on_pushButton_clicked()
{
    //导入
    //ui->progressBar->setValue(0);   //设置进度条的值为0
     QString path = QFileDialog::getOpenFileName(this,"open","../","execl(*.xlsx)");
    //指定父对象（this），“open”具体操作，打开，“../”默认，之后可以添加要打开文件的格式
    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file(path);
        //打开文件,默认为utf8变量，
        bool flag = file.open(QIODevice::ReadOnly);
        if(flag == true)//打开成功
        {

            QAxObject *excel = new QAxObject(this);//建立excel操作对象
            excel->setControl("Excel.Application");//连接Excel控件
            excel->setProperty("Visible", false);//不显示窗体看效果
            excel->setProperty("DisplayAlerts", false);//不显示警告看效果
            /*********获取COM文件的一种方式************/
            QAxObject *workbooks = excel->querySubObject("WorkBooks");
            //获取工作簿(excel文件)集合
            workbooks->dynamicCall("Open(const QString&)", path);//path至关重要，获取excel文件的路径
            //打开一个excel文件
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
            QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)",1);//访问excel中的工作表中第一个单元格
            QAxObject *usedRange = worksheet->querySubObject("UsedRange");//sheet的范围
            /*********获取COM文件的一种方式************/
            //获取打开excel的起始行数和列数和总共的行数和列数
            int intRowStart = usedRange->property("Row").toInt();//起始行数
            int intColStart = usedRange->property("Column").toInt(); //起始列数
            QAxObject *rows, *columns;
            rows = usedRange->querySubObject("Rows");//行
            columns = usedRange->querySubObject("Columns");//列
            int intRow = rows->property("Count").toInt();//行数
            int intCol = columns->property("Count").toInt();//列数
            //起始行列号
            //qDebug()<<intRowStart;
            //qDebug()<<intColStart;
            //行数和列数
            //qDebug()<<intRow;
            //qDebug()<<intCol;
            int a,b;
            a=intRow-intRowStart+1,b=intCol-intColStart+1;
            QByteArray text[a][b];
            QString exceldata[a][b];
            int coerow=0,coecol=0;

            for (int i = intRowStart; i < intRowStart + intRow; i++,coerow++)
                {
                    coecol=0;//务必是要恢复初值的
                    for (int j = intColStart; j < intColStart + intCol; j++,coecol++)
                    {
                        auto cell = excel->querySubObject("Cells(Int, Int)", i, j );
                        QVariant cellValue = cell->dynamicCall("value");
                        text[coerow][coecol]=cellValue.toByteArray();//QVariant转换为QByteArray
                        exceldata[coerow][coecol]=QString(text[coerow][coecol]);//QByteArray转换为QString

                        //qDebug()<<exceldata[coerow][coecol]<<coerow<<" "<<coecol;
                    }
                }
            ui->tableWidget->setRowCount(a-1);
            for(int i=1;i<a;++i)
                for(int j=0;j<b;++j)
                {
                    ui->tableWidget->setItem(i-1, j, new QTableWidgetItem(exceldata[i][j]));

                }


            workbook->dynamicCall( "Close(Boolean)", false );
            excel->dynamicCall( "Quit(void)" );
            delete excel;

           // QMessageBox::warning(this,tr("读取情况"),tr("读取完成！"),QMessageBox::Yes);

        }
        file.close();
    }
}
