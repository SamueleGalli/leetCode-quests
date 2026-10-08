DROP TABLE IF EXISTS Cinema;

CREATE TABLE Cinema(
    id INTEGER PRIMARY KEY,
    movie TEXT,
    description TEXT,
    rating REAL
);

INSERT INTO Cinema
VALUES(1,'War','great 3D',8.9);

INSERT INTO Cinema
VALUES(2,'Science','fiction',8.5);

INSERT INTO Cinema
VALUES(3,'irish','boring',6.2);

INSERT INTO Cinema
VALUES(4,'Ice song','Fantacy',8.6);

INSERT INTO Cinema
VALUES(5,'House card','Interesting',9.1);

SELECT *
FROM Cinema;