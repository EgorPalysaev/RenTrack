DROP TABLE IF EXISTS `user_name`;
DROP TABLE IF EXISTS `role_name`;
DROP TABLE IF EXISTS `premise`;
DROP TABLE IF EXISTS `user_rent`;
DROP TABLE IF EXISTS `status`;

CREATE TABLE role_name(
	RoleID INTEGER PRIMARY KEY NOT NULL,
	Role VARCHAR(16) NOT NULL
);

CREATE TABLE status(
	StatusID INTEGER PRIMARY KEY AUTOINCREMENT,
	Status VARCHAR(16) NOT NULL

);

INSERT INTO `role_name` VALUES (1, 'Tenant');
INSERT INTO `role_name` VALUES (2, 'Landlord');

INSERT INTO `status` (Status) VALUES ('Active'), ('Inactive'), ('In rent');

CREATE TABLE user_name(	
	UserID INTEGER PRIMARY KEY AUTOINCREMENT,			
	RoleID INTEGER NOT NULL,
	login varchar(32) NOT NULL,
	password varchar(32) NOT NULL,
	Name varchar(32) NOT NULL,			 --VARCHAR() can encode under 256 symdols
	Surname varchar(32) NOT NULL,			 --TEXT can encode under 2^16 symbols
	Patronymic varchar(32) NOT NULL,
	FOREIGN KEY(RoleID) REFERENCES role_name(RoleID)
);

CREATE TABLE premise(
	PremiseID INTEGER PRIMARY KEY AUTOINCREMENT,
	Premise_Address TEXT NOT NULL,
	Specification TEXT DEFAULT NULL,
	Status INTEGER NOT NULL,
	FOREIGN KEY(Status) REFERENCES status(StatusID)
);
CREATE TABLE user_rent(
	RentID INTEGER PRIMARY KEY AUTOINCREMENT,
	UserID INTEGER NOT NULL,
	PremiseID INTEGER NOT NULL,
	Start_rent DATE DEFAULT CURRENT_TIMESTAMP,
	End_rent DATE DEFAULT NULL,
	FOREIGN KEY(PremiseID) REFERENCES premise(PremiseID),
	FOREIGN KEY(UserID) REFERENCES user_name(UserID)
);
