#include "student_con.h"
#include "ui_student_con.h"
#include <QSortFilterProxyModel>
#include <QTableView>
#include <std_info.h>

student::student(QWidget *parent, SQL_con *db) :
    QWidget(parent),
    ui(new Ui::student),mysql_db(db)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->connect_wid);
 ui->stackedWidget->show();

}

student::~student()
{
    delete ui;

}


void student::on_connect_clicked()
{
    if (mysql_db && mysql_db->isConnected())
    {
        this->name = ui->name_edit->text();
        this->surname = ui->surname_edit->text();
        QString pass= ui->pass_edit->text();
        qDebug()<< name ;
        qDebug()<< pass ;
        qDebug() << "MySQL DB is connected.";
        QList <QString> list ;
        list<<name<<surname <<pass;
        bool state = mysql_db->user_connection("STUDENT_TABLE",list);
        if (state){

            ui->stackedWidget->setCurrentWidget(ui->main_std_wid);
            ui->stackedWidget->show();
//            Qstring str =;
            ui->welcome_label->setText("Welcome "+name+" "+surname );

        // Use the mysql_db object here
    }
    else
    {
        qDebug() << "MySQL DB is not connected.";
    }

}
}

//void student::on_pushButton_clicked()
//{    if (mysql_db && mysql_db->isConnected())
//{
//    mysql_db->md = mysql_db->load_data();
//    proxyModel = new QSortFilterProxyModel(this);
////    *ui->tableView->setModel(mysql_db->md);
//    proxyModel->setSourceModel(mysql_db->md);  // Set your MySQL data model as the source
//    //*proxyModel->setSortColumn(2, Qt::AscendingOrder);  // Replace columnIndex with the desired column index
//    //*proxyModel->setS
//    ui->tableView->setSortingEnabled(true);
//    ui->tableView->setModel(proxyModel);
//    qDebug()<<mysql_db->md->rowCount();

//}


//}

void student::on_logout_btn_clicked()
{
if (mysql_db->md)
{
    mysql_db->md->removeRows(0, mysql_db->md->rowCount());
    delete mysql_db->md;
    mysql_db->md = nullptr;
    delete proxyModel;
    proxyModel =nullptr;
}

//ui->tableView->reset();
ui->main_std_wid->close();
ui->stackedWidget->setCurrentWidget(ui->connect_wid);
ui->stackedWidget->show();


}




void student::on_info_btn_clicked()
{
std_info* info_diag= new std_info(nullptr,"Alter", mysql_db);
;
info_diag->show_user_info(name,surname);
//info_diag->update_user_info(items) ;
info_diag->show();

}




void student::create_new_user_btn()//create a new user
{
if (mysql_db && mysql_db->isConnected()){
    std_info* info_diag= new std_info();
    info_diag->show();
//    info_diag->l
}
}


void student::on_time_table_btn_clicked()
{
TimeTable* table = new TimeTable();
table->show();
}


void student::on_classmates_btn_clicked()
{

}


void student::on_teachers_btn_clicked()
{

}

