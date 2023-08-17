# Write your MySQL query statement below
SELECT product_name, sum(unit) as unit
FROM products 
INNER JOIN orders using (product_id)
where order_date LIKE "%2020-02%"
group by product_name
having unit>=100;