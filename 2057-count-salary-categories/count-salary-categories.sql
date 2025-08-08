# Write your MySQL query statement below
with
    low_sal as (select 'Low Salary' as category,count(income) as accounts_count
                from accounts
                where income<20000),
    avg_sal as (select 'Average Salary' as category,count(income) as accounts_count
                from accounts
                where income between 20000 and 50000),
    high_sal as (select 'High Salary' as category,count(income) as accounts_count
                from accounts
                where income>50000)
    select * from low_sal
    union
    select * from avg_sal
    union
    select * from high_sal;
