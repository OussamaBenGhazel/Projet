#include "timetable.h"
#include "ui_timetable.h"

TimeTable::TimeTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeTable)
{
    ui->setupUi(this);
    this->show_time_table();
}

TimeTable::~TimeTable()
{
    delete ui;
}

void TimeTable::show_time_table()
{
    QStringList daysOfWeek = {"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"};
    QStringList subjects = {"Advanced Math", "Economics", "Literature", "Computer Science"};

//    QString a;
//    a.toU
//    for (int i = 0; i < subjects.size(); ++i)
//        subjects[i].toUpper();
//    for (int i = 0; i < daysOfWeek.size(); ++i)
//        daysOfWeek[i].toUpper();
//    QDebug()<<
    ui->tableWidget->setRowCount(daysOfWeek.size());
    ui->tableWidget->setVerticalHeaderLabels(daysOfWeek);
    ui->tableWidget->setColumnCount(subjects.size());
    ui->tableWidget->setHorizontalHeaderLabels(subjects);

    QSqlQuery query;

    if (query.exec("SELECT SUBJECT ,  TIME,CLASSROOM,DAYS FROM SUBJECTS_TABLE WHERE LEVELS ='1'")) // Adjust the query as needed
    {
        // Populate the timetable grid based on the SQL query results
        int i = 0 ;
        while (query.next()) {
            for (int i = 0; i < query.record().count(); ++i) {
//                items.append(qry.value(i).toString());
                qDebug() << i<<query.value(i).toString();
            }
//            qDebug()<<"aaaaa";
            QString subjectName = query.value(0).toString();
            QString days = query.value(3).toString();
            QString classroom = query.value(2).toString();
            int duration = query.value(1).toInt();


            // Split the 'days' string to get individual days
            QStringList daysList = days.split(",");
//            qDebug()<<daysList;
//            qDebug()<<subjectName,days,classroom,duration;
            qDebug()<<"--------------------------------";
            for (const QString &day : daysList) {
                int row = daysOfWeek.indexOf(day.trimmed());
                int col = subjects.indexOf(subjectName);
                qDebug()<<row<<col;
                if (row != -1 && col != -1) {
                    QString cellValue = QString::number(duration) + "(h)"+"\class:"+classroom;
                    qDebug()<<cellValue ;
                    ui->tableWidget->setItem(row, col, new QTableWidgetItem(cellValue));
                }
            }
        }
    }
    else {
        qDebug()<<query.lastError().text();
    }
}
