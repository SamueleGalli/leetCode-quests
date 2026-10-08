DROP TABLE IF EXISTS Employee;

CREATE TABLE Employee
(
    id INTEGER PRIMARY KEY,
    name TEXT,
    salary INTEGER,
    managerId INTEGER
);

INSERT INTO Employee
VALUES(1,'joe',70000,3);

INSERT INTO Employee
VALUES(2,'Henry',80000,4);

INSERT INTO Employee
VALUES(3,'Sam',60000,NULL);

INSERT INTO Employee
VALUES(4,'Max',90000,NULL);


SELECT * FROM Employee;