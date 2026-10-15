SELECT customer_id
FROM Customer
GROUP BY Customer.customer_id
HAVING COUNT(DISTINCT product_key) =
(
    SELECT COUNT(*)
    FROM Product
)