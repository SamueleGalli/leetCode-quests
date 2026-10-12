SELECT Employees.employee_id
FROM Employees
LEFT JOIN Employees AS gone
ON Employees.manager_id = gone.employee_id
WHERE gone.employee_id IS NULL AND Employees.salary < 30000 && Employees.manager_id IS NOT NULL
ORDER BY Employees.employee_id