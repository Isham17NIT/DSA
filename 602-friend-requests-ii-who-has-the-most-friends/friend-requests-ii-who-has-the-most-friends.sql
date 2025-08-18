# Write your MySQL query statement below
with 
    cte1 as (
        select accepter_id, count(*) as cnt1
        from RequestAccepted
        group by accepter_id 
    ),
    cte2 as (
        select requester_id, count(*) as cnt2
        from RequestAccepted
        group by requester_id
    )
    select accepter_id as id, (cnt1+cnt2) as num
    from cte1
    inner join cte2 on cte1.accepter_id=cte2.requester_id

    union 

    select accepter_id as id, cnt1 as num
    from cte1
    left join cte2 on cte1.accepter_id=cte2.requester_id
    where cte2.requester_id is null

    union 

    select requester_id as id, cnt2 as num
    from cte1
    right join cte2 on cte1.accepter_id=cte2.requester_id
    where cte1.accepter_id is null

    order by num desc
    limit 1;