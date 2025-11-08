-- select sell_date,count(product) as num_sold,product as Products from Activities Group By sell_date

SELECT 
    sell_date, 
    COUNT(Distinct product) AS num_sold, 
    GROUP_CONCAT(Distinct product ORDER BY product) AS Products 
FROM Activities 
GROUP BY sell_date;