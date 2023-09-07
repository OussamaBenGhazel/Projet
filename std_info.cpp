#include "std_info.h"
#include "ui_std_info.h"
#include<QList>
std_info::std_info(QWidget *parent,QString type,SQL_con* db) :
    QDialog(parent),
    ui(new Ui::std_info),my_db(db)
{
    this->type = type;
    ui->setupUi(this);
    if (type=="Create"){
        ui->diag_title->setText("Creating new USER");
    }
    else if ("Alter"==type){
        ui->diag_title->setText("My Information");
        ui->save_diag_btn->setText("Save changes");
        ui->name_edit->setDisabled(false);
        ui->surname_edit->setDisabled(false);
    }
}

std_info::~std_info()
{
    delete ui;
    qDebug()<<"std_info windo deleted";
}

void std_info::on_close_diag_btn_clicked()
{
    this->close();
}

bool std_info::create_new_user(){
    QString name = ui->name_edit->text();
    QString surname = ui->surname_edit->text();
    QString pass = ui->passwd_edit->text() ;
    QString age = ui->age_edit->text() ;
    QString std_class = ui->class_edit->text() ;
    QString grade = ui->grade_edit->text() ;
    //    ui->gra
    qDebug()<< name <<surname << pass<<age<<std_class<<grade;
    if (name.trimmed().isEmpty() || surname.trimmed().isEmpty() || pass.trimmed().isEmpty()  ){
        qDebug()<<"name or username or passord can't be a white space";

        return false;
    }

     bool state = my_db->check_user_exist("student",name,surname);
//                 make_querry("select * from student WHERE name ='"+name+"' AND surname='"+surname+"'");
    if (!state){
        QVariantList items ;
        items << QVariant()<< name <<surname << pass<<age<<std_class<<grade;

        my_db->insert_user("student",items);
        return true; ;
    }
    else {
        qDebug()<<"name and surname "<< name << surname<< "already exist";

    }

    return false ;
}
bool std_info::show_user_info(QString name,QString surname){

    QList<QString> list = my_db->select_user(QString("select * from STUDENT_TABLE WHERE NAME= '%1' and SURNAME= '%2'").arg(name).arg(surname));
    for (int i= 0; i<list.size();++i)
    {
        qDebug()<<list.at(i);
    }
    ui->name_edit->setText(list.at(2));
    ui->surname_edit->setText(list.at(3));
    ui->passwd_edit->setText(list.at(4)) ;
    ui->age_edit->setText(list.at(5)) ;
    ui->class_edit->setDisplayIntegerBase(list.at(6).toInt())  ;//setText()
    ui->grade_edit->setText(list.at(7)) ;
    return false;
}

bool std_info::update_user_data(){

    QString name = ui->name_edit->text();
    QString surname = ui->surname_edit->text();
    QString pass = ui->passwd_edit->text() ;
    QString age = ui->age_edit->text() ;
    QString std_class = ui->class_edit->text() ;
    QString grade = ui->grade_edit->text() ;
    //    ui->gra
    //    QString t = QString("gggmal %1").arg(50);
    qDebug() << pass<<age<<std_class<<grade;
    if ( pass.trimmed().isEmpty()  ){
        qDebug()<<"passord can't be a white space";

                return false;
    }
//    bool state = my_db->make_querry(QString("select * from student WHERE name ='%1' AND surname='%2'").arg(name).arg(surname));

        QVariantList list ;
    list << pass<<age<<std_class<<grade<<name <<surname ;
        my_db->update_user("STUDENT_TABLE",list);
        //        my_db->insert_to_db(list);
        //        UPDATE `student` SET `password` = '555', `age` = '22', `class` = '2', `grade` = '12.0' WHERE name and suranme





    return true;
}
void std_info::on_save_diag_btn_clicked()
{
    if (type=="Create"){
                create_new_user();
    }
    else if ("Alter"==type){
                update_user_data();
    }//    QString name = ui->name_edit->text();
//    QString surname = ui->surname_edit->text();
//    QString pass = ui->passwd_edit->text() ;
//    QString age = ui->age_edit->text() ;
//    QString std_class = ui->class_edit->text() ;
//    QString grade = ui->grade_edit->text() ;

//    qDebug() << pass<<age<<std_class<<grade;
//    if ( pass.trimmed().isEmpty()  ){
//        qDebug()<<"passord can't be a white space";

//    }
//    bool state = my_db->check_user_exist("student",name,surname);
//    if (!state){
//        QVariantList list ;
//        list << QVariant()<< name <<surname << pass<<age<<std_class<<grade;
//    }
//    else {
//        qDebug()<<"name and surname "<< name << surname<< "already exist";

//    }


}


void std_info::on_passwd_edit_editingFinished()
{    qDebug()<< "testt !!";
    ui->save_diag_btn->setEnabled(true);
}


