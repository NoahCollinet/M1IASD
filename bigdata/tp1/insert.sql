prompt -------------------------------------------;
prompt --- Insertion des nouveaux tuples ---------;
prompt -------------------------------------------;

prompt ------------------------------------------;
prompt ---     insertion Appareil Photo    ------;
prompt ------------------------------------------;

INSERT INTO AppareilPhoto VALUES (1);
INSERT INTO AppareilPhoto VALUES (2);
INSERT INTO AppareilPhoto VALUES (3);
INSERT INTO AppareilPhoto VALUES (4);
INSERT INTO AppareilPhoto VALUES (5);

prompt ---------------------------------------------;
prompt ---   insertion Licence de Distribution   ---;
prompt ---------------------------------------------;

INSERT INTO Licence_Distri VALUES (10,1,0,0);
INSERT INTO Licence_Distri VALUES (11,1,1,0);
INSERT INTO Licence_Distri VALUES (12,0,0,0);
INSERT INTO Licence_Distri VALUES (13,1,1,0);
INSERT INTO Licence_Distri VALUES (14,1,1,1);

prompt ------------------------------------------;
prompt -----     insertion Utilisateur    -------;
prompt ------------------------------------------;

INSERT INTO UtilisateurP VALUES (20,32);
INSERT INTO UtilisateurP VALUES (21,45);
INSERT INTO UtilisateurP VALUES (22,17);
INSERT INTO UtilisateurP VALUES (23,17);
INSERT INTO UtilisateurP VALUES (24,19);
INSERT INTO UtilisateurP VALUES (25,31);

prompt ------------------------------------------;
prompt -----    insertion Configurations   ------;
prompt ------------------------------------------;

INSERT INTO ConfigPh VALUES (30,5,125,0,100);
INSERT INTO ConfigPh VALUES (31,6,75,1,100);
INSERT INTO ConfigPh VALUES (32,5,125,1,100);
INSERT INTO ConfigPh VALUES (33,2,100,1,55);
INSERT INTO ConfigPh VALUES (34,1,1000,0,35);


prompt ------------------------------------------;
prompt ------    insertion Photographie   -------;
prompt ------------------------------------------;

INSERT INTO Photographie VALUES(40,'Japan Expo Thailand','03/02/2022',1,10,30,20);
INSERT INTO Photographie VALUES(41,'Japan Expo Düsseldorf','12/09/2022',2,11,31,21);
INSERT INTO Photographie VALUES(42,'Los Angeles Cosplay Convention','29/11/2021',3,12,32,22);
INSERT INTO Photographie VALUES(43,'Los Angeles Cosplay Convention','29/11/2021',3,12,33,22);
INSERT INTO Photographie VALUES(44,'Los Angeles Cosplay Convention','29/11/2021',3,13,32,22);
INSERT INTO Photographie VALUES(45,'Versailles','11/03/2022',4,12,34,23);
INSERT INTO Photographie VALUES(46,'Versailles','11/03/2022',4,12,34,24);
INSERT INTO Photographie VALUES(47,'Versailles','11/12/2021',5,14,34,25);