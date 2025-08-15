# Write your MySQL query statement below
select person_name
from (
    select person_name, sum(weight) over(
        order by turn asc
    ) as cum_sum
    from queue) as t
    where cum_sum<=1000
    order by cum_sum desc
    limit 1;