SELECT Orders.customer_number
FROM Orders
GROUP BY Orders.customer_number
HAVING COUNT(*) = (
    SELECT COUNT(*)
    FROM Orders
    GROUP BY Orders.customer_number
    ORDER BY COUNT(*) DESC
    LIMIT 1
);