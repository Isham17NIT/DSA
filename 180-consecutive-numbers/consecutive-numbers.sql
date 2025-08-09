# Write your MySQL query statement below

select distinct l1.num as ConsecutiveNums
from logs as l1
inner join logs as l2 on l1.num=l2.num and l2.id = 1 + l1.id
inner join logs as l3 on l2.num=l3.num and l3.id = 1 + l2.id;