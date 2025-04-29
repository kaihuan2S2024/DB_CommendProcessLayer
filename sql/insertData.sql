CREATE TABLE users (
                       UserID INTEGER,
                       name VARCHAR(255),
                       email VARCHAR(255) primary key
);

CREATE TABLE test3 (
                        UserID INTEGER primary key,
                        name VARCHAR(255),
                        email VARCHAR(255)
);

CREATE TABLE user2 (
                        UserID INTEGER references test3(UserID),
                        name VARCHAR(255),
                        email VARCHAR(255)
);
INSERT INTO user2 (UserID, name, email) VALUES (0, 'Richard','richard@gmail.com');
INSERT INTO user2 (UserID, name, email) VALUES (1, 'Max','max@gmail.com');
INSERT INTO users (UserID, name, email) VALUES (2, 'Ming','Ming@gmail.com');
INSERT INTO users (UserID, name, email) VALUES (3, 'Mike','Mike@gmail.com');
INSERT INTO users (UserID, name, email) VALUES (4, 'Molly','Molly@andrew.cmu.edu');
INSERT INTO test3 (UserID, name, email) VALUES (4, 'Molly','Molly@andrew.cmu.edu');
DELETE FROM users
WHERE UserID = 1;
UPDATE users
SET email = 'test1232345@145.com'
WHERE UserID = 3;
exit;