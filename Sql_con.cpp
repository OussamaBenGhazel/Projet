#include "Sql_con.h"


SQL_con::SQL_con  (QString db_type , QString hostname,QString username , QString passwd,QString db_name )
{
    this->db_type= db_type ;
    this->hostname= hostname ;
    this->db_name= db_name;
    this->username= username ;
    this->passwd=passwd ;
}

bool  SQL_con ::  connect (){
    if (is_connected){
        return false ;
    }
    db = QSqlDatabase::addDatabase(this->db_type);
//    db.setHostName(hostname);
    db.setUserName(username);
    db.setPassword(passwd);
    db.setDatabaseName(db_name);
    if(db.open())
    {
        qDebug()<< "connected to database:"<<db_name ;
        is_connected = true ;
        return true ;
    }
    else
    {
        qDebug()<<"unable to connect error: "<<db.lastError().text();
    }
    return false ;
}
SQL_con::~SQL_con()
{
    disconnect();
}

void SQL_con :: disconnect (){
    if (is_connected)
    {
        db.close();
        is_connected =false ;
    qDebug()<<"Colsing db now ";
    }
}

bool SQL_con::isConnected() const
{
    return is_connected;
}

bool SQL_con::check_user_exist(QString table_name, QString name, QString surname)
{
    QSqlQuery qry;

    QString cmd = QString("select * from %1 WHERE NAME =:name AND SURNAME=:surname").arg(table_name);
    //    str
    qry.prepare(cmd);
    qry.bindValue(":name",name);

    qry.bindValue(":surname",surname);

    if (qry.exec())
    {
    int qcnt = 0; // num of querry
    while (qry.next()){
        qcnt ++ ;
    }
    if (qcnt >= 1){
        //            id = qry.value(0).toString(); // Access the result column by index (0 in this case)

        qDebug()<< "usraname and passwd correct";
        return true;// users found
    }
    else {
        qDebug()<< "wrong username or passwd ";
    return false ;     // no  user found
    }


    }
//    return false ;
}

bool SQL_con::update_user(QString table_name, QVariantList &items)
{
    if (items.size()!= 6){
    qDebug()<<"size don't match: "<<items.size();
    return false ;
    }
    QString cmd = QString("UPDATE %1 SET PASSWORD = ?, AGE = ?, CLASS = ?, GRADE = ? where NAME = ? and SURNAME =?" ).arg(table_name);
    QSqlQuery qry;

    qry.prepare(cmd);
    for (int i=0; i<items.size();++i){
    qry.addBindValue(items.at(i));
    }
    if (qry.exec())
    {
    qDebug()<<"update executed with success";

    }
    else {
    qDebug()<<"ERROR: "<<qry.lastError().text();

    }
    return false ;
}

bool SQL_con::insert_user(QString table_name, QVariantList &items)
{
    if (items.size()!= 7){
    qDebug()<<"size don't match: "<<items.size();
    return false ;
    }
    QSqlQuery qry ;
    QString cmd = QString("INSERT INTO %1 (ID, NAME, SURNAME, PASSWORD, AGE, CLASS, GRADE) VALUES (?, ?, ?, ?, ?, ?, ?)").arg(table_name);
    qry.prepare(cmd);
    for (int i=0; i<items.size();++i){
    qry.addBindValue(items.at(i));
    }
    if (qry.exec())
    {
    qDebug()<<"insert executed with success";
    }
    else {
    qDebug()<<"ERROR: "<<qry.lastError().text();
    }
    return false ;
}

QList<QString> SQL_con::select_user(QString cmd)
{
    QList<QString> items ;
    QSqlQuery qry;
    qry.prepare(cmd);
    if (qry.exec())
    {
    while (qry.next()) {
        for (int i = 0; i < qry.record().count(); ++i) {
            items.append(qry.value(i).toString());
            //            qDebug() << qry.value(i).toString();
        }
        qDebug()<<items;
        qDebug()<<"-------------------------------------";
        //items.clear();
    }
    }
    else{
    qDebug()<<"ERROR: "<<qry.lastError().text();

    }
    return items ;
}

bool SQL_con::user_connection(QString table_name, QList<QString> &credentials)
{
    QSqlQuery qry;

    QString cmd = QString("select * from %1 WHERE NAME =? AND SURNAME=? AND PASSWORD=?").arg(table_name);
    //    str
    qry.prepare(cmd);
    for (int i=0; i<credentials.size();++i){
    qry.addBindValue(credentials.at(i));
    }
    if (qry.exec())
    {
    int qcnt = 0; // num of querry
    while (qry.next()){
        qcnt ++ ;
    }
    if (qcnt == 1){
        //            id = qry.value(0).toString(); // Access the result column by index (0 in this case)

        qDebug()<< "usraname and passwd correct";
        return true;
    }
    else {
        qDebug()<< "wrong username or passwd ";
    }

    }
    return false ;
}

bool SQL_con::remove_user(QString table_name, QList<QString> &list)
{
    QString cmd =QString("DELETE FROM %1 WHERE NAME = ? and SURNAME= ?").arg(table_name);
    QSqlQuery qry;
    qry.prepare(cmd);
    for (int i=0; i<list.size();++i){
    qry.addBindValue(list.at(i));

    }
    if (qry.exec())
    {
    qDebug()<<"remove executed with success";
    return true;
    }
    else {
    qDebug()<<"ERROR: "<<qry.lastError().text();

    }
    return false  ;
}


QSqlQueryModel* SQL_con::load_all_table_data(QString table_name)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery *qry= new  QSqlQuery (db);
     QString cmd = QString("select * from %1").arg(table_name);
    qry->prepare(cmd);
    qry->exec();
    model->setQuery(*qry);
    return model;
}
