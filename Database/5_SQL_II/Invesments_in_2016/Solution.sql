SELECT ROUND(
        SUM(result.tiv_2016), 2) AS tiv_2016
FROM (
    SELECT *
    FROM Insurance
    GROUP BY lat,lon
    HAVING COUNT(*) = 1
    ) AS result
WHERE (
    SELECT COUNT(*)
    FROM Insurance AS investment
    WHERE investment.tiv_2015 = result.tiv_2015) > 1