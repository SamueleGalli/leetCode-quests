SELECT results
FROM
(
    SELECT Users.name AS results
    FROM MovieRating
    JOIN Users ON Users.user_id = MovieRating.user_id
    GROUP BY Users.name
    ORDER BY COUNT(*) DESC, Users.name
    LIMIT 1
) AS user

UNION ALL

SELECT results
FROM 
(
    SELECT Movies.title AS results
    FROM MovieRating
    JOIN Movies ON Movies.movie_id = MovieRating.movie_id
    WHERE created_at >= '2020-02-01' AND created_at < '2020-03-01'
    GROUP BY Movies.title
    ORDER BY AVG(MovieRating.rating) DESC, Movies.title
    LIMIT 1
) AS movie