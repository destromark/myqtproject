#include <QMessageBox>
#include <QSignalMapper>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculator");
    mapper();
    connect(ui->pushButton_c,SIGNAL(clicked()),this,SLOT(slotClear() ) );
    connect(signalMapper, SIGNAL(mapped(int)), this,SLOT(slotButton(int)));
    connect(ui->pushButton_ce,SIGNAL(clicked()),this,SLOT(slotClearAll()) );
    connect(ui->pushButton_eq,SIGNAL(clicked()),this,SLOT(slotEqul()));
    connect(signalMapper_str, SIGNAL(mapped(int)),this,SLOT(slotLogik(int)));
}

void MainWindow::slotClear() //очистка текущего значения
{
   ui->lcdNumber->display(0);
    currnumb=0;
}

void MainWindow::slotButton(int bNum) //ввод числа
{
    currnumb=currnumb*10+bNum;
    ui->lcdNumber->display(currnumb);
}

void MainWindow::Math(int num) //обрабока запросов
{
    switch (num) {
    case 10:
            lastnumb=lastnumb+currnumb;
        break;
    case 11:

            lastnumb=lastnumb-currnumb;
        break;
    case 12:
            lastnumb=lastnumb*currnumb;
        break;
    case 13:
            lastnumb=lastnumb/currnumb;
        break;
    default:
        abort();
        break;
    }
}

void MainWindow::slotLogik(int oper) //обработка поступающих значений сигналов 10-сумма 11-вычитание 12-умножение 13-деление
{
    switch (oper) {
    case 10:
        CurrOper="+";
        if(lastnumb!=0)
        {
            if(oper!=lastoper)
            {
                Math(lastoper);
                lastoper=oper;
                hist=QString::number(lastnumb);
                break;
            }
            Math(oper);
            hist=QString::number(lastnumb);
            lastoper=oper;
        } else
            {
            hist=QString::number(currnumb);
            lastnumb=currnumb;
            lastoper=oper;
            }
        break;
    case 11:
        CurrOper="-";
        if(lastnumb!=0)
        {
            if(oper!=lastoper)
            {
                Math(lastoper);
                lastoper=oper;
                hist=QString::number(lastnumb);
                break;
            }
            Math(oper);
            hist=QString::number(lastnumb);
            lastoper=oper;
        } else
            {
            hist=QString::number(currnumb);
            lastnumb=currnumb;
            lastoper=oper;
            }
        break;
    case 12:
        CurrOper="*";
        if(lastnumb!=0)
        {
            if(oper!=lastoper)
            {
                Math(lastoper);
                lastoper=oper;
                hist=QString::number(lastnumb);
                break;
            }
            Math(oper);
            hist=QString::number(lastnumb);
            lastoper=oper;
        } else
            {
            hist=QString::number(currnumb);
            lastnumb=currnumb;
            lastoper=oper;
            }
        break;
    case 13:
        CurrOper="/";
        if(lastnumb!=0)
        {
            if(lastoper!=0)
            {
                Math(lastoper);
                lastoper=oper;
                hist=QString::number(lastnumb);
                break;
            }
            Math(oper);
            hist=QString::number(lastnumb);
            lastoper=13;
        } else
            {
            hist=QString::number(currnumb);
            lastnumb=currnumb;
            lastoper=oper;
            }
        break;
    default:
        abort();
        break;
    }

   hist=hist+" "+CurrOper;
   ui->lcdNumber->display(0);
   ui->lineEdit->setText(hist);
   currnumb=0;

}

void MainWindow::slotEqul() //Выполнение расчетов
{
    if(CurrOper=="+")
    {
      slotLogik(10);
    }
    else if(CurrOper=="-")
    {
      slotLogik(11);
    }
    else if(CurrOper=="*")
    {
      slotLogik(12);
    }
    else if(CurrOper=="/")
    {
      slotLogik(13);
    }

    ui->lineEdit->setText("");
    ui->lcdNumber->display(lastnumb);
}

void MainWindow::slotClearAll() //очистка
{
    ui->lcdNumber->display(0);
    currnumb=0;
    lastnumb=0;
    CurrOper="";
    lastoper=0;
    hist="";
    ui->lineEdit->setText("");

}


void MainWindow::mapper() //присвоения значения сигналам
{
    signalMapper=new QSignalMapper(this);
    signalMapper_str=new QSignalMapper(this);

    connect(ui->pushButton_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_9, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->pushButton_sum, SIGNAL(clicked()), signalMapper_str, SLOT(map()));
    connect(ui->pushButton_min, SIGNAL(clicked()), signalMapper_str, SLOT(map()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), signalMapper_str, SLOT(map()));
    connect(ui->pushButton_div, SIGNAL(clicked()), signalMapper_str, SLOT(map()));

    signalMapper->setMapping(ui->pushButton_0, 0);
    signalMapper->setMapping(ui->pushButton_1, 1);
    signalMapper->setMapping(ui->pushButton_2, 2);
    signalMapper->setMapping(ui->pushButton_3, 3);
    signalMapper->setMapping(ui->pushButton_4, 4);
    signalMapper->setMapping(ui->pushButton_5, 5);
    signalMapper->setMapping(ui->pushButton_6, 6);
    signalMapper->setMapping(ui->pushButton_7, 7);
    signalMapper->setMapping(ui->pushButton_8, 8);
    signalMapper->setMapping(ui->pushButton_9, 9);
    signalMapper_str->setMapping(ui->pushButton_sum, 10);
    signalMapper_str->setMapping(ui->pushButton_min, 11);
    signalMapper_str->setMapping(ui->pushButton_mult, 12);
    signalMapper_str->setMapping(ui->pushButton_div, 13);

}

MainWindow::~MainWindow()
{
    delete ui;
}
