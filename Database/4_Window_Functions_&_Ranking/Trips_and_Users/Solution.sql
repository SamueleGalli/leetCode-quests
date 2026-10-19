SELECT  request_at AS Day,
        ROUND (
            1.0 * COUNT(
                CASE WHEN status != 'completed'
                    THEN 1
                END
            ) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
JOIN Users AS Client ON client_id = Client.users_id
JOIN Users AS Driver ON driver_id = Driver.users_id
WHERE   request_at >= '2013-10-01' AND request_at <= '2013-10-03'
        AND Client.banned = 'No' AND Driver.banned = 'No'
GROUP BY day
