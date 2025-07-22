# Write your MySQL query statement below
SELECT p.product_id, IFNULL(ROUND(SUM(p.price * u.units)/(SUM(u.units)),2),0) AS average_price FROM Prices p
LEFT JOIN unitssold u ON p.product_id = u.product_id
WHERE u.purchase_date BETWEEN p.start_date AND p.end_date OR u.purchase_date is null
GROUP BY p.product_id;