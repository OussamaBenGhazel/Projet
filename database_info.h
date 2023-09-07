#ifndef DATABASE_INFO_H
#define DATABASE_INFO_H
#include <QString>
#include <QMap>
typedef const QMap<QString, QString> my_map;


my_map student_table ={
    {"id_col","id"},
    {"name_col","name"},
    {"surname_col","surname"},
    { "password_col","password"},
    {"age_col","age"},
    {"class_col","class"},
    {"grade_col","grade"},

};



my_map subjects_table ={
    {"id_col","id"},
    {"subject_col","subject"},
    {"time_col","time"},
    { "level_col","level"},
    {"classroom_col","classroom"},


    };


my_map teacher_table ={
    {"id_col","id"},
    {"name_col","name"},
    {"surname_col","surname"},
    { "password_col","password"},
    {"level_col","level"},
    {"subject","subject"},


    };




#endif // DATABASE_INFO_H
