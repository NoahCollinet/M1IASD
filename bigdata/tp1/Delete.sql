prompt -------------------------------------------;
prompt ------    Suppression de la base     ------;
prompt -------------------------------------------;

DELETE FROM Photographie;
DELETE FROM AppareilPhoto;
DELETE FROM Licence_Distri;
DELETE FROM UtilisateurP;
DELETE FROM ConfigPh;

BEGIN
EXECUTE IMMEDIATE 'DROP TABLE Photographie';
EXCEPTION
 WHEN OTHERS THEN
	IF SQLCODE != -942 THEN
	RAISE;
	END IF;
END;
/

BEGIN
EXECUTE IMMEDIATE 'DROP TABLE AppareilPhoto';
EXCEPTION
 WHEN OTHERS THEN
	IF SQLCODE != -942 THEN
	RAISE;
	END IF;
END;
/

BEGIN
EXECUTE IMMEDIATE 'DROP TABLE Licence_Distri';
EXCEPTION
 WHEN OTHERS THEN
	IF SQLCODE != -942 THEN
	RAISE;
	END IF;
END;
/

BEGIN
EXECUTE IMMEDIATE 'DROP TABLE UtilisateurP';
EXCEPTION
 WHEN OTHERS THEN
	IF SQLCODE != -942 THEN
	RAISE;
	END IF;
END;
/

BEGIN
EXECUTE IMMEDIATE 'DROP TABLE ConfigPh';
EXCEPTION
 WHEN OTHERS THEN
	IF SQLCODE != -942 THEN
	RAISE;
	END IF;
END;
/
