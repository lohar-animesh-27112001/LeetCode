# Write your MySQL query statement below
SELECT product_name, year, price
FROM Sales AS S JOIN Product AS P
WHERE S.product_id = P.product_id;