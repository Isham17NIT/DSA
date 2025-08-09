
select p1.product_id, COALESCE(p2.latest_price,10) as price
from (select distinct product_id from products) as p1
left join (
    select p3.product_id, p3.new_price as latest_price
    from products as p3
    where p3.change_date = (select max(p4.change_date) from products as p4
                            where p4.change_date<='2019-08-16' and p4.product_id=p3.product_id)
) as p2
on p1.product_id = p2.product_id;
