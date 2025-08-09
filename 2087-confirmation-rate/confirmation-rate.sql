# Write your MySQL query statement below

select user_id, round(confirmed_req/total_req, 2) as confirmation_rate
from (
    select s.user_id, 
    sum(case when c.action='confirmed' then 1 else 0 end) AS confirmed_req,
    count(*) as total_req
    from signups as s
    left join confirmations as c
    on s.user_id = c.user_id
    group by s.user_id) as f;