SELECT Activity.activity_date AS day,
       COUNT(DISTINCT Activity.user_id) AS active_users
FROM Activity
WHERE Activity.activity_date >= '2019-06-28' AND Activity.activity_date <= '2019-07-27'
     AND Activity.activity_type IS NOT NULL
GROUP BY day