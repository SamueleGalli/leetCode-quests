WITH RECURSIVE Total_Level AS(
    SELECT 1 AS Level, E.employee_id
    FROM Employees AS E
    WHERE E.manager_id IS NULL

    UNION ALL

    SELECT TL.Level + 1 AS Level, E.employee_id
    FROM Employees AS E
    JOIN Total_Level AS TL ON TL.employee_id = E.manager_id
),
Gerarchy AS(
    SELECT E.employee_id, E.manager_id
    FROM Employees AS E

    UNION ALL

    SELECT E.employee_id, G.manager_id
    FROM Employees AS E
    JOIN Gerarchy AS G ON G.employee_id = E.manager_id
),
Budget_Size AS(
    SELECT COUNT(*) AS Teams, SUM(E.salary) AS Budget, G.manager_id AS manager_id
    FROM Gerarchy AS G
    JOIN Employees AS E ON G.employee_id = E.employee_id
    GROUP BY G.manager_id
)

SELECT  E.employee_id AS employee_id, E.employee_name AS employee_name,
        TL.Level AS level,
        COALESCE(BS.Teams, 0) AS team_size,
        E.salary + COALESCE(BS.Budget, 0) AS budget
FROM Employees AS E
JOIN Total_Level AS TL ON E.employee_id = TL.employee_id
LEFT JOIN Budget_Size AS BS ON E.employee_id = BS.manager_id
ORDER BY level , budget DESC, employee_name