#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper;
    QSignalMapper *signalMapper_str;
    void mapper();
    void Math(int num);
private slots:
   void slotClear();
   void slotClearAll();
   void slotButton(int bNum);   
   void slotLogik(int oper);
   void slotEqul();

private:
int currnumb;
int lastnumb;
QString hist;
int lastoper;
QString CurrOper;


};

#endif // MAINWINDOW_H
