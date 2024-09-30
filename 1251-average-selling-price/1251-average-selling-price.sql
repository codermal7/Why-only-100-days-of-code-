# Write your MySQL query statement below
select p.product_id, 
    coalesce(round(sum(us.units * p.price) / sum(us.units), 2), 0) as average_price 
from Prices as p 
left join UnitsSold as us 
    on p.product_id = us.product_id 
    and us.purchase_date between p.start_date and p.end_date 
group by p.product_id;