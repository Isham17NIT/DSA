

with
    cte1 as (
        select p1.product_id, p1.new_price as price
        from products as p1
        where change_date = (select max(p2.change_date) from products as p2
                             where change_date<='2019-08-16' and p1.product_id = p2.product_id)
    ),
    cte2 as (
        select distinct product_id, 10 as price
        from products where product_id not in (select product_id from cte1)
    )
    select * from cte1
    union
    select * from cte2;