SELECT *
FROM cinema
WHERE cinema.id % 2 != 0 AND description != 'boring'
ORDER BY cinema.rating DESC;