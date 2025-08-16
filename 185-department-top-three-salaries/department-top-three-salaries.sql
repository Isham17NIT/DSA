# Write your MySQL query statement below
with 
    cte1 as (
        select departmentId, max(salary) as sal_1 
        from employee
        group by departmentId
    ),
    cte2 as (
        select e.departmentId, max(e.salary) as sal_2 
        from employee as e
        where salary < (select sal_1 from cte1 where cte1.departmentId = e.departmentId)
        group by e.departmentId
    ),
    cte3 as (
        select e.departmentId, max(e.salary) as sal_3 
        from employee as e
        where salary < (select sal_2 from cte2 where cte2.departmentId = e.departmentId)
        group by e.departmentId
    ),
    cte4 as (
        select cte1.departmentId, d.name, sal_1, sal_2, sal_3
        from cte1
        left join cte2 on cte1.departmentId = cte2.departmentId
        left join cte3 on cte2.departmentId = cte3.departmentId
        inner join department as d on cte1.departmentId=d.id
    )
    select cte4.name as Department, e.name as Employee, e.salary
    from employee as e
    inner join cte4 on e.departmentId=cte4.departmentId
    inner join department as d on e.departmentId=d.id
    where salary=sal_1 or (sal_2 is not null and salary=sal_2) or (sal_3 is not null and salary=sal_3);
    