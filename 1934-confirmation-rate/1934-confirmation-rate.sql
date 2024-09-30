select 
    s.user_id as user_id,
    Round( COALESCE(sum(case when action = "confirmed" then 1 else 0 end)/count(action), 0) , 2) as confirmation_rate 
from Signups s
left join confirmations c
on s.user_id = c.user_id
group by s.user_id