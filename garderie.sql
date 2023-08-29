/*==============================================================*/
/* Nom de SGBD :  ORACLE Version 11g                            */
/* Date de création :  8/26/2023 6:34:01 PM                     */
/*==============================================================*/


/*==============================================================*/
/* Table : ELEVE                                                */
/*==============================================================*/
create table ELEVE 
(
   NOM                  VARCHAR(20)          not null,
   PRENOM               VARCHAR(20)          not null,
   CLASSE               INTEGER              not null,
   ANNEE_SCOLAIRE       INTEGER              not null,
   MOT_DE_PASSE         VARCHAR(20)          not null,
   GENDER               CHAR(1)              not null,
   ENSEIGNANT_PREF      VARCHAR(20)          not null,
   ID_ELEVE             VARCHAR(20)          not null
);

alter table ELEVE
   add constraint PK_ELEVE primary key (ID_ELEVE);

/*==============================================================*/
/* Table : ENSEIGNANT                                           */
/*==============================================================*/
create table ENSEIGNANT 
(
   NOM                  VARCHAR(20)          not null,
   PRENOM               VARCHAR(20)          not null,
   CLASS_A_ENSEIGNER    INTEGER              not null,
   MATIERE_A_ENSEIGNER  VARCHAR(20)          not null,
   NB_CLASSE            INTEGER              not null,
   ELEVE_PREFERE        VARCHAR(20)          not null,
   ID_ENSEIGNANT        INTEGER              not null
);

alter table ENSEIGNANT
   add constraint PK_ENSEIGNANT primary key (ID_ENSEIGNANT);

/*==============================================================*/
/* Table : ENSEIGNER                                            */
/*==============================================================*/
create table ENSEIGNER 
(
   ID_ENSEIGNANT        CLOB                 not null,
   ID_ELEVE             CLOB                 not null
);

alter table ENSEIGNER
   add constraint PK_ENSEIGNER primary key (ID_ENSEIGNANT, ID_ELEVE);

alter table ENSEIGNER
   add constraint FK_ENSEIGNE_ENSEIGNER_ENSEIGNA foreign key (ID_ENSEIGNANT)
      references ENSEIGNANT (ID_ENSEIGNANT);

alter table ENSEIGNER
   add constraint FK_ENSEIGNE_ESTENSEIG_ELEVE foreign key (ID_ELEVE)
      references ELEVE (ID_ELEVE);

