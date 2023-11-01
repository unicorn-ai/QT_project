#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QFileDialog>
#include <QAxObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(10);
    //ui->tableWidget->setItem(1, 0, new QTableWidgetItem("jhj11"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mergeCells(const QString& cell)
{
    QAxObject *range = sheet->querySubObject("Range(const QString&)", cell);
    range->setProperty("VerticalAlignment", -4108);//xlCenter
    range->setProperty("WrapText", true);
    range->setProperty("MergeCells", true);
}
//导出明细
void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Excle file"),QString("./paper_list.xlsx"),tr("Excel Files(*.xlsx)"));    //设置保存的文件名
    if(fileName != "")
    {

        QAxObject *excel = new QAxObject;
        if(excel->setControl("Excel.Application"))
        {
            excel->dynamicCall("SetVisible (bool Visible)",false);
            excel->setProperty("DisplayAlerts",false);
            QAxObject *workbooks = excel->querySubObject("WorkBooks");            //获取工作簿集合
            workbooks->dynamicCall("Add");                                        //新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");        //获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
            QAxObject *cell_RW,*cell0,*cell1,*cell2,*cell3,*cell4,*cell5,*cell6,*cell7,*cell8,*cell9,
                      *cell10,*cell11,*cell12,*cell13,*cell14,*cell15,*cell16,*cell17,*cell18,
                      *cell19,*cell20,*cell21,*cell22,*cell23,*cell24,*cell25,*cell26,*cell27,*cell28,*cell29,
                      *cell30,*cell31;
            QAxObject *merge_range0,*merge_range1,*merge_range2,*merge_range3,*merge_range4,*merge_range5,*merge_range6,
                      *merge_range7,*merge_range8,*merge_range9,*merge_range10,*merge_range11,*merge_range12,*merge_range13,*merge_range14;
            QString RD,merge_cell0,merge_cell1,merge_cell2,merge_cell3,merge_cell4,merge_cell5,merge_cell6,merge_cell7,
                    merge_cell8,merge_cell9,merge_cell10,merge_cell11,merge_cell12,merge_cell13,merge_cell14;
            const QString qtw0="仪器编号";
            const QString qtw1="仪器名称";
            const QString qtw2="规格";
            const QString qtw3="单位";
            const QString qtw4="存放位置";
            const QString qtw5="柜";
            const QString qtw6="层";
            const QString qtw7="进货时间";
            const QString qtw8="凭证号";
            const QString qtw9="摘要";
            const QString qtw10="产地";
            const QString qtw11="总账";
            const QString qtw12="账页";
            const QString qtw13="收（增加）入";
            const QString qtw14="付（减少）出";
            const QString qtw15="结余";
            const QString qtw16="年";
            const QString qtw17="月";
            const QString qtw18="日";
            const QString qtw19="备注";
            const QString qtw20="本账页数";
            const QString qtw21="本户页数";
            const QString qtw22="明细分类账\n\r（2022学年）";
            const QString qtw23="数量";
            const QString qtw24="单价";
            const QString qtw25="金额";
            //生成一定格式的表格
            int kind_number=(ui->tableWidget->item(1,0)->text()).toInt();
            int start_year=(ui->tableWidget->item(1,1)->text()).toInt();
            int year_number=(ui->tableWidget->item(1,2)->text()).toInt();
            for(int op=0;op<kind_number;op++)
            {
                cell0=worksheet->querySubObject("Cells(int,int)", 5+16*op,1);
                cell1=worksheet->querySubObject("Cells(int,int)", 5+16*op,4);
                cell2=worksheet->querySubObject("Cells(int,int)", 5+16*op,7);
                cell3=worksheet->querySubObject("Cells(int,int)", 5+16*op,10);
                cell4=worksheet->querySubObject("Cells(int,int)", 5+16*op,12);
                cell5=worksheet->querySubObject("Cells(int,int)", 5+16*op,15);
                cell6=worksheet->querySubObject("Cells(int,int)", 5+16*op,17);
                cell7=worksheet->querySubObject("Cells(int,int)", 6+16*op,1);
                cell8=worksheet->querySubObject("Cells(int,int)", 6+16*op,4);
                cell9=worksheet->querySubObject("Cells(int,int)", 6+16*op,5);
                cell10=worksheet->querySubObject("Cells(int,int)", 6+16*op,6);
                cell11=worksheet->querySubObject("Cells(int,int)", 6+16*op,7);
                cell12=worksheet->querySubObject("Cells(int,int)", 7+16*op,7);
                cell13=worksheet->querySubObject("Cells(int,int)", 6+16*op,8);
                cell14=worksheet->querySubObject("Cells(int,int)", 6+16*op,11);
                cell15=worksheet->querySubObject("Cells(int,int)", 6+16*op,14);
                cell16=worksheet->querySubObject("Cells(int,int)", 7+16*op,1);
                cell17=worksheet->querySubObject("Cells(int,int)", 7+16*op,2);
                cell18=worksheet->querySubObject("Cells(int,int)", 7+16*op,3);
                cell19=worksheet->querySubObject("Cells(int,int)", 7+16*op,17);//备注
                cell20=worksheet->querySubObject("Cells(int,int)", 3+16*op,15);
                cell21=worksheet->querySubObject("Cells(int,int)", 4+16*op,15);
                cell22=worksheet->querySubObject("Cells(int,int)", 3+16*op,1);
                cell23=worksheet->querySubObject("Cells(int,int)", 7+16*op,8);
                cell24=worksheet->querySubObject("Cells(int,int)", 7+16*op,9);
                cell25=worksheet->querySubObject("Cells(int,int)", 7+16*op,10);
                cell26=worksheet->querySubObject("Cells(int,int)", 7+16*op,11);
                cell27=worksheet->querySubObject("Cells(int,int)", 7+16*op,12);
                cell28=worksheet->querySubObject("Cells(int,int)", 7+16*op,13);
                cell29=worksheet->querySubObject("Cells(int,int)", 7+16*op,14);
                cell30=worksheet->querySubObject("Cells(int,int)", 7+16*op,15);
                cell31=worksheet->querySubObject("Cells(int,int)", 7+16*op,16);
                cell0->dynamicCall("SetValue(const QString&)",qtw0);
                cell1->dynamicCall("SetValue(const QString&)",qtw1);
                cell2->dynamicCall("SetValue(const QString&)",qtw2);
                cell3->dynamicCall("SetValue(const QString&)",qtw3);
                cell4->dynamicCall("SetValue(const QString&)",qtw4);
                cell5->dynamicCall("SetValue(const QString&)",qtw5);
                cell6->dynamicCall("SetValue(const QString&)",qtw6);
                cell7->dynamicCall("SetValue(const QString&)",qtw7);
                cell8->dynamicCall("SetValue(const QString&)",qtw8);
                cell9->dynamicCall("SetValue(const QString&)",qtw9);
                cell10->dynamicCall("SetValue(const QString&)",qtw10);
                cell11->dynamicCall("SetValue(const QString&)",qtw11);
                cell12->dynamicCall("SetValue(const QString&)",qtw12);
                cell13->dynamicCall("SetValue(const QString&)",qtw13);
                cell14->dynamicCall("SetValue(const QString&)",qtw14);
                cell15->dynamicCall("SetValue(const QString&)",qtw15);
                cell16->dynamicCall("SetValue(const QString&)",qtw16);
                cell17->dynamicCall("SetValue(const QString&)",qtw17);
                cell18->dynamicCall("SetValue(const QString&)",qtw18);
                cell19->dynamicCall("SetValue(const QString&)",qtw19);
                cell20->dynamicCall("SetValue(const QString&)",qtw20);
                cell21->dynamicCall("SetValue(const QString&)",qtw21);
                cell22->dynamicCall("SetValue(const QString&)",qtw22);
                cell23->dynamicCall("SetValue(const QString&)",qtw23);
                cell24->dynamicCall("SetValue(const QString&)",qtw24);
                cell25->dynamicCall("SetValue(const QString&)",qtw25);
                cell26->dynamicCall("SetValue(const QString&)",qtw23);
                cell27->dynamicCall("SetValue(const QString&)",qtw24);
                cell28->dynamicCall("SetValue(const QString&)",qtw25);
                cell29->dynamicCall("SetValue(const QString&)",qtw23);
                cell30->dynamicCall("SetValue(const QString&)",qtw24);
                cell31->dynamicCall("SetValue(const QString&)",qtw25);
                //cell10->dynamicCall("SetValue(const QString&)",qtw11);
                merge_cell0.append(QChar(1 + 'A'));  //初始列
                merge_cell0.append(QString::number(5+16*op));  //初始行
                merge_cell0.append(":");
                merge_cell0.append(QChar(2 + 'A'));  //终止列
                merge_cell0.append(QString::number(5+16*op));  //终止行
                merge_cell1.append(QChar(4 + 'A'));  //初始列
                merge_cell1.append(QString::number(5+16*op));  //初始行
                merge_cell1.append(":");
                merge_cell1.append(QChar(5 + 'A'));  //终止列
                merge_cell1.append(QString::number(5+16*op));  //终止行
                merge_cell2.append(QChar(7 + 'A'));  //初始列
                merge_cell2.append(QString::number(5+16*op));  //初始行
                merge_cell2.append(":");
                merge_cell2.append(QChar(8 + 'A'));  //终止列
                merge_cell2.append(QString::number(5+16*op));  //终止行
                merge_cell3.append(QChar(11 + 'A'));  //初始列
                merge_cell3.append(QString::number(5+16*op));  //初始行
                merge_cell3.append(":");
                merge_cell3.append(QChar(12 + 'A'));  //终止列
                merge_cell3.append(QString::number(5+16*op));  //终止行
                merge_cell4.append(QChar(0 + 'A'));  //初始列
                merge_cell4.append(QString::number(6+16*op));  //初始行
                merge_cell4.append(":");
                merge_cell4.append(QChar(2 + 'A'));  //终止列
                merge_cell4.append(QString::number(6+16*op));
                //收（增加）入
                merge_cell5.append(QChar(7 + 'A'));  //初始列
                merge_cell5.append(QString::number(6+16*op));  //初始行
                merge_cell5.append(":");
                merge_cell5.append(QChar(9 + 'A'));  //终止列
                merge_cell5.append(QString::number(6+16*op));  //终止行
                //付（减少）出
                merge_cell6.append(QChar(10 + 'A'));  //初始列
                merge_cell6.append(QString::number(6+16*op));  //初始行
                merge_cell6.append(":");
                merge_cell6.append(QChar(12 + 'A'));  //终止列
                merge_cell6.append(QString::number(6+16*op));
                //结余
                merge_cell7.append(QChar(13 + 'A'));  //初始列
                merge_cell7.append(QString::number(6+16*op));  //初始行
                merge_cell7.append(":");
                merge_cell7.append(QChar(15 + 'A'));  //终止列
                merge_cell7.append(QString::number(6+16*op));  //终止行
                //备注
                merge_cell8.append(QChar(16 + 'A'));  //初始列
                merge_cell8.append(QString::number(6+16*op));  //初始行
                merge_cell8.append(":");
                merge_cell8.append(QChar(16 + 'A'));  //终止列
                merge_cell8.append(QString::number(7+16*op));

                //凭证号
                merge_cell9.append(QChar(3 + 'A'));  //初始列
                merge_cell9.append(QString::number(6+16*op));  //初始行
                merge_cell9.append(":");
                merge_cell9.append(QChar(3 + 'A'));  //终止列
                merge_cell9.append(QString::number(7+16*op));  //终止行
                //摘要
                merge_cell10.append(QChar(4 + 'A'));  //初始列
                merge_cell10.append(QString::number(6+16*op));  //初始行
                merge_cell10.append(":");
                merge_cell10.append(QChar(4 + 'A'));  //终止列
                merge_cell10.append(QString::number(7+16*op));  //终止行
                //产地
                merge_cell11.append(QChar(5 + 'A'));  //初始列
                merge_cell11.append(QString::number(6+16*op));  //初始行
                merge_cell11.append(":");
                merge_cell11.append(QChar(5 + 'A'));  //终止列
                merge_cell11.append(QString::number(7+16*op));  //终止行
                //本账页数
                merge_cell12.append(QChar(14 + 'A'));  //初始列
                merge_cell12.append(QString::number(3+16*op));  //初始行
                merge_cell12.append(":");
                merge_cell12.append(QChar(15 + 'A'));  //终止列
                merge_cell12.append(QString::number(3+16*op));  //终止行
                //本户页数
                merge_cell13.append(QChar(14 + 'A'));  //初始列
                merge_cell13.append(QString::number(4+16*op));  //初始行
                merge_cell13.append(":");
                merge_cell13.append(QChar(15 + 'A'));  //终止列
                merge_cell13.append(QString::number(4+16*op));  //终止行
                //标题
                merge_cell14.append(QChar(0 + 'A'));  //初始列
                merge_cell14.append(QString::number(3+16*op));  //初始行
                merge_cell14.append(":");
                merge_cell14.append(QChar(13 + 'A'));  //终止列
                merge_cell14.append(QString::number(4+16*op));
                merge_range0= worksheet->querySubObject("Range(const QString&)", merge_cell0);
                merge_range1 = worksheet->querySubObject("Range(const QString&)", merge_cell1);
                merge_range2 = worksheet->querySubObject("Range(const QString&)", merge_cell2);
                merge_range3 = worksheet->querySubObject("Range(const QString&)", merge_cell3);
                merge_range4 = worksheet->querySubObject("Range(const QString&)", merge_cell4);
                merge_range5= worksheet->querySubObject("Range(const QString&)", merge_cell5);
                merge_range6 = worksheet->querySubObject("Range(const QString&)", merge_cell6);
                merge_range7 = worksheet->querySubObject("Range(const QString&)", merge_cell7);
                merge_range8 = worksheet->querySubObject("Range(const QString&)", merge_cell8);
                merge_range9 = worksheet->querySubObject("Range(const QString&)", merge_cell9);
                merge_range10= worksheet->querySubObject("Range(const QString&)", merge_cell10);
                merge_range11 = worksheet->querySubObject("Range(const QString&)", merge_cell11);
                merge_range12 = worksheet->querySubObject("Range(const QString&)", merge_cell12);
                merge_range13 = worksheet->querySubObject("Range(const QString&)", merge_cell13);
                merge_range14 = worksheet->querySubObject("Range(const QString&)", merge_cell14);
                merge_range0->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range0->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range0->setProperty("WrapText", true);
                merge_range0->setProperty("MergeCells", true);
                merge_range0->clear();
                merge_range1->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range1->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range1->setProperty("WrapText", true);
                merge_range1->setProperty("MergeCells", true);
                merge_range1->clear();
                merge_range2->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range2->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range2->setProperty("WrapText", true);
                merge_range2->setProperty("MergeCells", true);
                merge_range2->clear();
                merge_range3->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range3->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range3->setProperty("WrapText", true);
                merge_range3->setProperty("MergeCells", true);
                merge_range3->clear();
                merge_range4->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range4->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range4->setProperty("WrapText", true);
                merge_range4->setProperty("MergeCells", true);
                merge_range4->clear();
                merge_range5->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range5->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range5->setProperty("WrapText", true);
                merge_range5->setProperty("MergeCells", true);
                merge_range5->clear();
                merge_range6->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range6->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range6->setProperty("WrapText", true);
                merge_range6->setProperty("MergeCells", true);
                merge_range6->clear();
                merge_range7->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range7->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range7->setProperty("WrapText", true);
                merge_range7->setProperty("MergeCells", true);
                merge_range7->clear();
                merge_range8->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range8->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range8->setProperty("WrapText", true);
                merge_range8->setProperty("MergeCells", true);
                merge_range9->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range9->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range9->setProperty("WrapText", true);
                merge_range9->setProperty("MergeCells", true);
                merge_range9->clear();
                merge_range10->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range10->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range10->setProperty("WrapText", true);
                merge_range10->setProperty("MergeCells", true);
                merge_range10->clear();
                merge_range11->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range11->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range11->setProperty("WrapText", true);
                merge_range11->setProperty("MergeCells", true);
                merge_range11->clear();
                merge_range12->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range12->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range12->setProperty("WrapText", true);
                merge_range12->setProperty("MergeCells", true);
                merge_range12->clear();
                merge_range13->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range13->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range13->setProperty("WrapText", true);
                merge_range13->setProperty("MergeCells", true);
                merge_range13->clear();
                merge_range14->setProperty("VerticalAlignment", -4108);     // 水平居中
                merge_range14->setProperty("HorizontalAlignment", -4108);   // 垂直居中
                merge_range14->setProperty("WrapText", true);
                merge_range14->setProperty("MergeCells", true);
                merge_range14->clear();
                merge_cell0.clear();
                merge_cell1.clear();
                merge_cell2.clear();
                merge_cell3.clear();
                merge_cell4.clear();
                merge_cell5.clear();
                merge_cell6.clear();
                merge_cell7.clear();
                merge_cell8.clear();
                merge_cell9.clear();
                merge_cell10.clear();
                merge_cell11.clear();
                merge_cell12.clear();
                merge_cell13.clear();
                merge_cell14.clear();

            }
            //向明细表格填充仪器编号，名称，位置等数据

            for(int k=0;k<kind_number;k++)
            {
                for(int i=0;i<11;i++)
                {
                    if(i==0)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 2);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==1)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 5);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==2)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 8);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==3)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 11);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==4)
                    {
//                        cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*k, 15);
//                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==5)
                    {
                        //                           cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*k, 14);
                        //                           cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==6)
                    {
                        //                           cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*k, 16);
                        //                           cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    }
                    if(i==7)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 4+16*k, 17);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i+8)->text());
                    }
                    if(i==8)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 14);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i+8)->text());
                    }
                    if(i==9)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 16);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i+8)->text());
                    }
                    if(i==10)
                    {
                        cell_RW=worksheet->querySubObject("Cells(int,int)", 3+16*k, 17);
                        cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(1,0)->text());
                    }

                    cell_RW->clear();
                }
//                cell_RW=worksheet->querySubObject("Cells(int,int)", 3+16*k, 17);
//                cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(1,0)->text());
//                cell_RW->clear();
            }
            //填充数量，金额，年份等
            for(int year=0;year<year_number;year++)
            {
                for(int mon=0;mon<kind_number;mon++)
                {
                    //单价
    //                int start_year=(ui->tableWidget->item(1,1)->text()).toInt();
    //                int year_number=(ui->tableWidget->item(1,2)->text()).toInt();
                    cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*mon+year, 15);
                    cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+mon,4)->text());
                    cell_RW->clear();
                    //数量
                    cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*mon+year, 14);
                    cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+mon,5+2*year)->text());
                    cell_RW->clear();
                    //金额
                    cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*mon+year, 16);
                    cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+mon,6+2*year)->text());
                    cell_RW->clear();
                    //年
                    cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*mon+year, 1);
                    cell_RW->dynamicCall("SetValue(const QString&)",start_year+year);
                    cell_RW->clear();
                    //账页
                    //cell_RW=worksheet->querySubObject("Cells(int,int)", 5+16*k, 2);
                    //cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+k,i)->text());
                    cell_RW=worksheet->querySubObject("Cells(int,int)", 8+16*mon+year, 7);
                    cell_RW->dynamicCall("SetValue(const QString&)",ui->tableWidget->item(2+mon,18)->text());
                    cell_RW->clear();
                }

            }



            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName)); //保存至fileName
            workbook->dynamicCall("Close()");                                                   //关闭工作簿
            excel->dynamicCall("Quit()");                                                       //关闭excel
            delete excel;
            excel=NULL;
        }
    }

}
//导入
void MainWindow::on_pushButton_5_clicked()
{
    //导入时从第二行导入，第一行不导入

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
//            ui->progressBar->show();    //进度条需要在ui文件中加个progressBar控件
//            ui->progressBar->setValue(10);
            QAxObject *excel = new QAxObject(this);//建立excel操作对象
            excel->setControl("Excel.Application");//连接Excel控件
            excel->setProperty("Visible", false);//不显示窗体看效果
            excel->setProperty("DisplayAlerts", false);//不显示警告看效果
            /*********获取COM文件的一种方式************/
            QAxObject *workbooks = excel->querySubObject("WorkBooks");
            //获取工作簿(excel文件)集合
            workbooks->dynamicCall("open(const QString&)", path);//path至关重要，获取excel文件的路径
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
            int a,b,i,j;
//            tablewidget_row=intRow;
//            tablewidget_column=intCol;
            a=intRow-intRowStart+1,b=intCol-intColStart+1;
            ui->tableWidget->setColumnCount(a);
            ui->tableWidget->setRowCount(b);

            QByteArray text[a][b];
            QString exceldata[a][b];
            int coerow=0,coecol=0;

            for ( i = intRowStart; i < intRowStart + intRow; i++,coerow++)
            {
                coecol=0;//务必是要恢复初值的
                for (int j = intColStart; j < intColStart + intCol; j++,coecol++)
                {
                    auto cell = excel->querySubObject("Cells(Int, Int)", i, j );
                    QVariant cellValue = cell->dynamicCall("value");
                    text[coerow][coecol]=cellValue.toByteArray();//QVariant转换为QByteArray
                    exceldata[coerow][coecol]=QString(text[coerow][coecol]);//QByteArray转换为QString
//                    if(ui->progressBar->value()<=60)
//                    {
//                        ui->progressBar->setValue(10+i*5);
//                    }

                    //qDebug()<<exceldata[coerow][coecol]<<coerow<<" "<<coecol;
                }
            }
            ui->tableWidget->setRowCount(a-1);
            for( i=1;i<a;++i)
                for(j=0;j<b;++j)
                {
                    ui->tableWidget->setItem(i-1, j, new QTableWidgetItem(exceldata[i][j]));
//                    if(ui->progressBar->value()<=80)
//                    {
//                        ui->progressBar->setValue(60+i*5);
//                    }
                }

            ui->tableWidget->setItem(1, 0, new QTableWidgetItem("在此输入仪器总数"));
            ui->tableWidget->setItem(1, 1, new QTableWidgetItem("起始年份"));
            ui->tableWidget->setItem(1, 2, new QTableWidgetItem("共有几年"));
            workbook->dynamicCall( "Close(Boolean)", false );
            excel->dynamicCall( "Quit(void)" );
            delete excel;
//            ui->progressBar->setValue(100);
//            ui->progressBar->hide();
//            ui->progressBar->setValue(0);

            // QMessageBox::warning(this,tr("读取情况"),tr("读取完成！"),QMessageBox::Yes);

        }
        file.close();
    }
}

//退出
void MainWindow::on_pushButton_2_clicked()
{
    close();
}
