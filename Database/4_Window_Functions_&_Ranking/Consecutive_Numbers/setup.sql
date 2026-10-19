/*
Table: Logs
    +-------------+---------+
    | Column Name | Type    |
    +-------------+---------+
    | id          | int     |
    | num         | varchar |
    +-------------+---------+

In SQL, id is the primary key for this table.
id is an autoincrement column starting from 1.
Find all numbers that appear at least three times consecutively.
Return the result table in any order.
The result format is in the following example.

Example 1:

Input: 
    Logs table:
        +----+-----+
        | id | num |
        +----+-----+
        | 1  | 1   |
        | 2  | 1   |
        | 3  | 1   |
        | 4  | 2   |
        | 5  | 1   |
        | 6  | 2   |
        | 7  | 2   |
        +----+-----+
Output: 
    +-----------------+
    | ConsecutiveNums |
    +-----------------+
    | 1               |
    +-----------------+
    Explanation:
        1 is the only number that appears consecutively for at least three times.
*/

DROP TABLE IF EXISTS Logs;

CREATE TABLE Logs
(
    id INTEGER PRIMARY KEY,
    num TEXT
);

INSERT INTO Logs
VALUES(1, 1);

INSERT INTO Logs
VALUES(2, 1);

INSERT INTO Logs
VALUES(3, 1);

INSERT INTO Logs
VALUES(4, 2);

INSERT INTO Logs
VALUES(5, 1);

INSERT INTO Logs
VALUES(6, 2);

INSERT INTO Logs
VALUES(7, 2);

SELECT *
FROM Logs;