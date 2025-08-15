# Write your MySQL query statement below
with 
    cte1 as (
        select person_name, sum(weight) over(
            order by turn asc
        ) as cum_sum
        from queue
    )
    select person_name
    from cte1 
    where cum_sum = (select max(cum_sum)
                     from cte1 
                     where cum_sum<=1000);
