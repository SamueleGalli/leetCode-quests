SELECT Department.name AS Department,
       E.name AS Employee,
       salary AS Salary
FROM Employee AS E
JOIN Department ON E.departmentId = Department.id
WHERE (Department.id, E.salary) IN (SELECT departmentId, MAX(salary)
    FROM Employee
    GROUP BY departmentId)