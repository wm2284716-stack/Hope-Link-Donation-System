#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "donation.h" // عشان نربط الملف اللي لسه كاتبينه

QT_BEGIN_NAMESPACE
namespace Ui { class HopeLink; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked(); // دي دالة الزرار اللي برمجناها في الـ UI

private:
    Ui::HopeLink *ui;
};
#endif // MAINWINDOW_H