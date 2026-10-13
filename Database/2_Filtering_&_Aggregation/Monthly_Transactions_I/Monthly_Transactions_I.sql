SELECT 
    strftime('%Y-%m', trans_date) AS month,-- in mysql -> DATE_FORMAT(trans_date, '%Y-%m') AS month
    Transactions.country,
    COUNT(*) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(Transactions.amount) AS trans_total_amount,
    SUM(
        CASE WHEN state = 'approved' THEN Transactions.amount
        ELSE 0
    END) AS approved_total_amount
FROM Transactions
GROUP BY month, Transactions.country
