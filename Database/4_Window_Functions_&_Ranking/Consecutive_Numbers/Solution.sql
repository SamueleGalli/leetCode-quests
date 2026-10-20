SELECT DISTINCT result AS ConsecutiveNums 
FROM(
    SELECT
        CASE
            WHEN    num = LEAD(num, 1) OVER(ORDER BY id) AND
                    num = LEAD(num, 2) OVER(ORDER BY id)
            THEN num
        END AS result
    FROM Logs
    ) AS temp_table
WHERE result IS NOT NULL