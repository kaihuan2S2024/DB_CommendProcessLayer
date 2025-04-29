-- before Testing, you need to ensure that you have change to a clean db file in main

-- it will fail because the table developers is not created yet.
CREATE TABLE users (
                       UserID INTEGER,
                       name VARCHAR(255),
                       email VARCHAR(255) references developers(email)
);

-- This will successfully create the table users because the table developers is created before the table users.
CREATE TABLE developers (
                       UserID INTEGER not null,
                       name VARCHAR(255) unique,
                       email VARCHAR(255) primary key
);

CREATE TABLE users (
                       UserID INTEGER,
                       name VARCHAR(255),
                       email VARCHAR(255) references developers(email)
);

-- This will fail because the The reference column UserID in the table users is not a primary key.
CREATE TABLE dummy (
                       UserID INTEGER references users(UserID),
                       name VARCHAR(255),
                       email VARCHAR(255)
);

-- This will fail because email richard@gmail.com is not in the developers table.
INSERT INTO users (UserID, name, email) VALUES (0, 'Richard','richard@gmail.com');

-- This will success because the email richard@gmail.com is in the developers table.
INSERT INTO developers (UserID, name, email) VALUES (0, 'Richard','richard@gmail.com');
INSERT INTO users (UserID, name, email) VALUES (0, 'Richard','richard@gmail.com');
select * from developers;
select * from users;

-- This will fail because the userID can not be null
INSERT INTO developers (UserID, name, email) VALUES (null, 'max','max@gmail.com');
INSERT INTO developers (name, email) VALUES ('max','max@gmail.com');

-- This will fail because the name is unique which can not be duplicated.
INSERT INTO developers (UserID, name, email) VALUES (0, 'Richard','max@gmail.com');

-- This will fail because the email is primary key which can not be duplicated.
INSERT INTO developers (UserID, name, email) VALUES (0, 'max','richard@gmail.com');
select * from developers;

-- This will success
INSERT INTO developers (UserID, name, email) VALUES (1, 'Max','max@gmail.com');
select * from developers;

-- This will fail because the email is primary key which can not be null
INSERT INTO developers (UserID, name, email) VALUES (2, 'leo',null);
INSERT INTO developers (UserID, name) VALUES (2, 'leo');
select * from developers;



