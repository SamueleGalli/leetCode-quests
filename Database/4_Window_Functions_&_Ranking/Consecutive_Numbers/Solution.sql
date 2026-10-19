SELECT DISTINCT num = LEAD(num, 1) OVER(ORDER BY id) AND
                num = LEAD(num, 2) OVER(ORDER BY id) AS ConsecutiveNums 
FROM Logs