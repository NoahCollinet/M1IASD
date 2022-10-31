/* CREATION */



prompt -- Appareil photo

CREATE TABLE AppareilPhoto (
    AppareilId INT NOT NULL,  
    CONSTRAINT PK_AppId PRIMARY KEY(AppareilId)
);

prompt -- Licence de Distribution

CREATE TABLE Licence_Distri (
    LicenceId INT NOT NULL,
    Droits number(1),
    utilisationC number(1),
    ModifA number(1), 
    CONSTRAINT PK_Licence PRIMARY KEY(LicenceId) 
);


prompt -- Utilisateur 

CREATE TABLE UtilisateurP (
    numID INT NOT NULL,
    Age INT NOT NULL, 
    CONSTRAINT PK_Utilisa PRIMARY KEY(numID)
);


prompt -- Configurations

CREATE TABLE ConfigPh (
    ConfigID INT NOT NULL,
    OuvertureF INT NOT NULL, 
    TempsE INT NOT NULL, 
    Flash number(1), 
    DistanceF INT NOT NULL,
    CONSTRAINT PK_Config PRIMARY KEY(ConfigID)
);
    

prompt -- Photographie


CREATE TABLE Photographie (
    PhotoID INT NOT NULL,
    LIEU VARCHAR(50),
    DateP Date, 
    IdAppa INT NOT NULL,
    LicId INT NOT NULL, 
    ConId INT NOT NULL,
    numeroId INT NOT NULL,
    CONSTRAINT PK_Photo PRIMARY KEY(PhotoID),
    CONSTRAINT FK_AppaID FOREIGN KEY(IdAppa) REFERENCES AppareilPhoto(AppareilId) ON DELETE CASCADE,
    CONSTRAINT FK_Licence FOREIGN KEY(LicId) REFERENCES Licence_Distri(LicenceId) ON DELETE CASCADE,
    CONSTRAINT FK_ConID FOREIGN KEY(ConId) REFERENCES ConfigPh(ConfigID) ON DELETE CASCADE,
    CONSTRAINT FK_numeroId FOREIGN KEY(numeroId) REFERENCES UtilisateurP(numID) ON DELETE CASCADE
);