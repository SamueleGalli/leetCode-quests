SELECT 
    strftime('%Y-%m', trans_date) AS month,
    Transactions.country,
     AS trans_count,
    SUM(state = 'approved') AS approved_count,
     AS trans_total_amount,
    Transactions.amount AS approved_total_amount
FROM Transactions
GROUP BY Transactions.trans_date, Transactions.country
