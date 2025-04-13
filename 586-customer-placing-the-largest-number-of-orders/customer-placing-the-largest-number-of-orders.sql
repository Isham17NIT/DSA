# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(*) = (SELECT MAX(a.cnt) FROM (SELECT COUNT(*) AS cnt
FROM Orders
GROUP BY customer_number
ORDER BY cnt DESC) AS a);