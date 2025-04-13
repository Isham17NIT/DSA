# Write your MySQL query statement below
SELECT name
FROM Salesperson 
WHERE sales_id NOT IN (
    SELECT sales_id 
    FROM Orders
    WHERE com_id = (SELECT c.com_id FROM Company AS c WHERE c.name = "RED")
    GROUP BY sales_id
    HAVING COUNT(order_id) > 0);