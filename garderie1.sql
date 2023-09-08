/*==============================================================*/
/* Nom de SGBD :  ORACLE Version 11g                            */
/* Date de création :  9/6/2023 8:03:36 PM                      */
/*==============================================================*/


/*==============================================================*/
/* Table : APPARTENIR                                           */
/*==============================================================*/
create table APPARTENIR 
(
   ID_SUBJECT           INTEGER              not null,
   ID_LEVEL             INTEGER              not null
);

alter table APPARTENIR
   add constraint PK_APPARTENIR primary key (ID_SUBJECT, ID_LEVEL);

/*==============================================================*/
/* Table : ENSEIGNE                                             */
/*==============================================================*/
create table ENSEIGNE 
(
   ID_TEACHER           INTEGER              not null,
   ID_LEVEL             INTEGER              not null
);

alter table ENSEIGNE
   add constraint PK_ENSEIGNE primary key (ID_TEACHER, ID_LEVEL);

/*==============================================================*/
/* Table : LEVELS_TABLE                                         */
/*==============================================================*/
create table LEVELS_TABLE 
(
   ID_LEVEL             INTEGER              not null,
   LEVEL_NAME           VARCHAR(30)
);

alter table LEVELS_TABLE
   add constraint PK_LEVELS_TABLE primary key (ID_LEVEL);

/*==============================================================*/
/* Table : STUDENT_TABLE                                        */
/*==============================================================*/
create table STUDENT_TABLE 
(
   ID_STUDENT           INTEGER              not null,
   ID_LEVEL             INTEGER              not null,
   NAME                 VARCHAR(30)          not null,
   SURNAME              VARCHAR(30)          not null,
   PASSWORD             VARCHAR(30)          not null,
   AGE                  INTEGER              not null,
   CLASS                INTEGER              not null,
   GRADE                INTEGER              not null
);

alter table STUDENT_TABLE
   add constraint PK_STUDENT_TABLE primary key (ID_STUDENT);

/*==============================================================*/
/* Table : SUBJECTS_TABLE                                       */
/*==============================================================*/
create table SUBJECTS_TABLE 
(
   ID_SUBJECT           INTEGER              not null,
   SUBJECT              VARCHAR(30)          not null,
   TIME                 INTEGER              not null,
   "LEVEL"              INTEGER,
   CLASSROOM            VARCHAR(30)
);

alter table SUBJECTS_TABLE
   add constraint PK_SUBJECTS_TABLE primary key (ID_SUBJECT);

/*==============================================================*/
/* Table : TEACHER_TABLE                                        */
/*==============================================================*/
create table TEACHER_TABLE 
(
   ID_TEACHER           INTEGER              not null,
   NAME                 VARCHAR(30)          not null,
   SURNAME              VARCHAR(30)          not null,
   PASSWORD             VARCHAR(30)          not null,
   "LEVEL"              INTEGER              not null,
   SUBJECT              VARCHAR(30)          not null
);

alter table TEACHER_TABLE
   add constraint PK_TEACHER_TABLE primary key (ID_TEACHER);

alter table APPARTENIR
   add constraint FK_APPARTEN_APPARTENI_SUBJECTS foreign key (ID_SUBJECT)
      references SUBJECTS_TABLE (ID_SUBJECT);

alter table APPARTENIR
   add constraint FK_APPARTEN_APPARTENI_LEVELS_T foreign key (ID_LEVEL)
      references LEVELS_TABLE (ID_LEVEL);

alter table ENSEIGNE
   add constraint FK_ENSEIGNE_ENSEIGNE_TEACHER_ foreign key (ID_TEACHER)
      references TEACHER_TABLE (ID_TEACHER);

alter table ENSEIGNE
   add constraint FK_ENSEIGNE_ENSEIGNE2_LEVELS_T foreign key (ID_LEVEL)
      references LEVELS_TABLE (ID_LEVEL);

alter table STUDENT_TABLE
   add constraint FK_STUDENT__INSCRIT_LEVELS_T foreign key (ID_LEVEL)
      references LEVELS_TABLE (ID_LEVEL);

