--CREATE DATABASE data;
--PRAGMA foreign_keys = ON;

DROP TABLE IF EXISTS `user_name`;
DROP TABLE IF EXISTS `role_name`;
DROP TABLE IF EXISTS `premise`;
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

CREATE TABLE user_name(					 --DROP TABLE <name> means delete table
	userID INTEGER PRIMARY KEY AUTOINCREMENT,		 --AUTO_INCREMENT means id++, AUTOINCREMENT means unique id also after deleting
	Role INTEGER NOT NULL,
	login varchar(32) NOT NULL,
	password varchar(32) NOT NULL,
	Name varchar(32) NOT NULL,			 --VARCHAR() can encode under 256 symdols
	Surname varchar(32) NOT NULL,			 --TEXT can encode under 2^16 symbols
	Patronymic varchar(32) NOT NULL,
	FOREIGN KEY(Role) REFERENCES role_name(RoleID)
);

--INSERT INTO user_name (Role, Name, surname, patronymic) VALUES (2, 'Egor', 'Palysaev', 'Aleksandrovich');
--INSERT INTO user_role(Role, `User`) VALUES ((SELECT Role FROM role_name WHERE RoleID = 1), (SELECT user_name.Name WHERE userID = 1));

CREATE TABLE premise(
	PermiseID INTEGER PRIMARY KEY AUTOINCREMENT,
	Permise_Adress VARCHAR(128),
	Specification TEXT DEFAULT NULL,
	Start_rent DATE DEFAULT CURRENT_TIMESTAMP,
	Send_rent DATE DEFAULT NULL,
	Tenant INTEGER NOT NULL,
	Status INTEGER NOT NULL,

	FOREIGN KEY(Status) REFERENCES status(StatusID),
	FOREIGN KEY(Tenant) REFERENCES user_name(userID)
);
