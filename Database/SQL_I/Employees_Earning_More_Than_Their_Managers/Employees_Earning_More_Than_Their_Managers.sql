SELECT Employee.name AS Employee
FROM Employee
INNER JOIN Employee as manager
ON Employee.managerId = manager.id
WHERE Employee.salary > manager.salary