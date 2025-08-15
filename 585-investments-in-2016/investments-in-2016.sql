# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016
from insurance 
where pid in (
            select distinct i.pid
            from insurance as i
            inner join insurance as j on i.pid!=j.pid and i.tiv_2015=j.tiv_2015
            where (i.lat, i.lon) in (select lat, lon
                                    from insurance 
                                    group by lat,lon
                                    having count(pid)=1)); 

