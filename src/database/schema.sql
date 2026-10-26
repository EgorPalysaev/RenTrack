DROP TABLE IF EXISTS `user_name`;
DROP TABLE IF EXISTS `role_name`;
DROP TABLE IF EXISTS `premise`;
DROP TABLE IF EXISTS `user_rent`;
DROP TABLE IF EXISTS `status`;

CREATE TABLE role_name(
	RoleID INTEGER PRIMARY KEY AUTOINCREMENT,
	Role TEXT NOT NULL UNIQUE
);

CREATE TABLE status(
	StatusID INTEGER PRIMARY KEY AUTOINCREMENT,
	Status TEXT NOT NULL UNIQUE

);

INSERT INTO `role_name` (Role) VALUES ('Tenant'), ('Landlord');
INSERT INTO `status` (Status) VALUES ('Active'), ('Inactive'), ('In rent');

CREATE TABLE user_name(	
	UserID INTEGER PRIMARY KEY AUTOINCREMENT,			
	RoleID INTEGER NOT NULL,
	login TEXT NOT NULL UNIQUE CHECK (length(login) <= 32),
	password TEXT NOT NULL CHECK (length(password) <= 32),
	Name TEXT NOT NULL CHECK (length(Name) <= 32),			 --VARCHAR() can encode under 256 symdols
	Surname TEXT NOT NULL CHECK (length(Surname) <= 32),			 --TEXT can encode under 2^16 symbols
	Patronymic TEXT DEFAULT NULL CHECK (Patronymic IS NULL OR length(Patronymic) <= 32),
	FOREIGN KEY(RoleID) REFERENCES role_name(RoleID)
);

CREATE TABLE premise(
	PremiseID INTEGER PRIMARY KEY AUTOINCREMENT,
	Address TEXT NOT NULL UNIQUE,
	Area REAL NOT NULL CHECK (Area > 0),
	Comment TEXT DEFAULT NULL,
	StatusID INTEGER NOT NULL,
	FOREIGN KEY(StatusID) REFERENCES status(StatusID)
);
CREATE TABLE user_rent(
	RentID INTEGER PRIMARY KEY AUTOINCREMENT,
	UserID INTEGER NOT NULL,
	PremiseID INTEGER NOT NULL,
	Start_rent TEXT DEFAULT CURRENT_TIMESTAMP,
	End_rent TEXT DEFAULT NULL,
	CHECK(End_rent IS NULL OR End_rent >= Start_rent),
	FOREIGN KEY(PremiseID) REFERENCES premise(PremiseID),
	FOREIGN KEY(UserID) REFERENCES user_name(UserID)
);

CREATE INDEX idx_user_rent_user
    ON user_rent (UserID);

CREATE INDEX idx_user_rent_premise
    ON user_rent (PremiseID);
