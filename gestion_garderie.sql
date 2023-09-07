/*==============================================================*/
/* Nom de SGBD :  ORACLE Version 11g                            */
/* Date de création :  9/5/2023 7:09:14 PM                      */
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
/* Table : ELEVE                                                */
/*==============================================================*/
create table ELEVE 
(
   NOM                  CLOB                 not null,
   PRENOM               CLOB                 not null,
   CLASSE               INTEGER              not null,
   ANNEE_SCOLAIRE       TIMESTAMP            not null,
   MOT_DE_PASSE         CHAR(10)             not null,
   TIME                 DATE                 not null,
   GENDER               CHAR(1)              not null,
   ENSEIGNANT_PREF      CLOB                 not null,
   ID_ELEVE             CLOB                 not null,
   ID_LEVEL             INTEGER              not null
);

alter table ELEVE
   add constraint PK_ELEVE primary key (ID_ELEVE);

/*==============================================================*/
/* Table : ENSEIGNANT                                           */
/*==============================================================*/
create table ENSEIGNANT 
(
   NOM                  CLOB                 not null,
   PRENOM               CLOB                 not null,
   CLASS_A_ENSEIGNER    INTEGER              not null,
   SUJET_A_ENSEIGNER    CLOB                 not null,
   NB_CLASSE            INTEGER              not null,
   TIME                 DATE                 not null,
   ELEVE_PREFERE        CLOB                 not null,
   ID_ENSEIGNANT        CLOB                 not null
);

alter table ENSEIGNANT
   add constraint PK_ENSEIGNANT primary key (ID_ENSEIGNANT);

/*==============================================================*/
/* Table : ENSEIGNE                                             */
/*==============================================================*/
create table ENSEIGNE 
(
   ID_ENSEIGNANT        CLOB                 not null,
   ID_LEVEL             INTEGER              not null
);

alter table ENSEIGNE
   add constraint PK_ENSEIGNE primary key (ID_ENSEIGNANT, ID_LEVEL);

/*==============================================================*/
/* Table : LEVELS_TABLE                                         */
/*==============================================================*/
create table LEVELS_TABLE 
(
   ID_LEVEL             INTEGER              not null,
   LEVEL_NAME           CLOB
);

alter table LEVELS_TABLE
   add constraint PK_LEVELS_TABLE primary key (ID_LEVEL);

/*==============================================================*/
/* Table : SUBJECTS_TABLE                                       */
/*==============================================================*/
create table SUBJECTS_TABLE 
(
   ID_SUBJECT           INTEGER              not null,
   SUBJECT              CLOB                 not null,
   DURATION             INTEGER              not null,
   CLASSROOM            CLOB                 not null,
   "LEVEL"              INTEGER              not null,
   DAYS                 CLOB                 not null
);

alter table SUBJECTS_TABLE
   add constraint PK_SUBJECTS_TABLE primary key (ID_SUBJECT);

alter table APPARTENIR
   add constraint FK_APPARTEN_APPARTENI_LEVELS_T foreign key (ID_LEVEL)
      references LEVELS_TABLE (ID_LEVEL);

alter table APPARTENIR
   add constraint FK_APPARTEN_APPARTENI_SUBJECTS foreign key (ID_SUBJECT)
      references SUBJECTS_TABLE (ID_SUBJECT);

alter table ELEVE
   add constraint FK_ELEVE_INSCRIT_LEVELS_T foreign key (ID_LEVEL)
      references LEVELS_TABLE (ID_LEVEL);

alter table ENSEIGNE
   add constraint FK_ENSEIGNE_ENSEIGNE_LEVELS_T foreign key (ID_LEVEL)
      references LEVELS_TABLE (ID_LEVEL);

alter table ENSEIGNE
   add constraint FK_ENSEIGNE_ENSEIGNE2_ENSEIGNA foreign key (ID_ENSEIGNANT)
      references ENSEIGNANT (ID_ENSEIGNANT);

