# Write your MySQL query statement below

-- select round(sum(if(order_date = customer_pref_delivery_date, 1, 0))*100 / count(*), 2) as immediate percentage
-- from delivery 
-- where (customer_id, order_date) in (
--     select customer_id, min(order_date)
--     from delivery
--     group by customer_id
-- )

-- CTE

-- with firstOrders as (
--     select customer_id, min(order_date) as first_order from deivery group by customer_id
-- ) select ROUND(SUM(order_date = customer_pref_delivery_date) * 100.0 / COUNT(*), 2) AS immediate_percentage
-- FROM Delivery d
-- JOIN FirstOrders f
-- ON d.customer_id = f.customer_id AND d.order_date = f.first_order;

-- USING WINDOW FUNCTION

WITH RankedOrders AS (
  SELECT *,
    ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS rn
  FROM Delivery
)
SELECT 
  ROUND(
    SUM(order_date = customer_pref_delivery_date) * 100.0 / COUNT(*), 2
  ) AS immediate_percentage
FROM RankedOrders
WHERE rn = 1;

