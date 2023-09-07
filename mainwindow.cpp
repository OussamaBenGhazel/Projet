#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow),mysql_db ("QODBC" ,"","oussama","oussama", "gestion_garderie")
{
    ui->setupUi(this);
    bool state =mysql_db.connect();
    std = new student(this, &mysql_db);
    ui->stackedWidget->addWidget(std);
    QList<QString> list;
    list = mysql_db.select_user("select * from STUDENT_TABLE");
}
void MainWindow::on_student_btn_clicked(){

    ui->stackedWidget->setCurrentWidget(std);
    ui->stackedWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_home_btn_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->p1);
    ui->stackedWidget->show();

}

void MainWindow::on_teacher_btn_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->p3);

    ui->stackedWidget->show();


}


void MainWindow::on_close_btn_clicked()
{
    this->close();
}


void MainWindow::on_minimize_btn_clicked()
{
//    this->resize(800,600);
    this->showNormal();

}


void MainWindow::on_resizebtn_clicked()
{
    this->showFullScreen();
}

