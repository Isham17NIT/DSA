# Write your MySQL query statement below
SELECT p.product_id,p.product_name
FROM Product AS p
INNER JOIN(
SELECT product_id, MIN(sale_date) AS start, MAX(sale_date) AS end
FROM Sales
GROUP BY product_id) AS t1
ON p.product_id = t1.product_id
WHERE t1.start>='2019-01-01' AND t1.end<='2019-03-31';