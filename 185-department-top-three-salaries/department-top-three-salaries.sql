# Write your MySQL query statement below
with 
    ranks as (select e.*, 
              dense_rank() over(partition by e.departmentId order by salary desc) as rnk
              from employee as e)
select d.name as Department, r.name as Employee, r.salary
from ranks as r
inner join department as d on r.departmentId=d.id
where r.rnk < 4;