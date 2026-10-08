DROP TABLE IF EXISTS Person;
DROP TABLE IF EXISTS Address;

CREATE TABLE Person (
    personId INTEGER PRIMARY KEY,
    lastName TEXT,
    firstName TEXT
);


CREATE TABLE Address (
    AddressId INTEGER PRIMARY KEY,
    personId INTEGER,
    city TEXT,
    state TEXT
);


INSERT INTO Person
VALUES (1,'Wang','Allen');
INSERT INTO Person
VALUES (2,'Alice','Bob');



INSERT INTO Address
VALUES (1,2,'New York City','New York');
INSERT INTO Address
VALUES (2,3,'Leetcode', 'California');



SELECT * FROM Person;
.print ''
SELECT * FROM Address;
