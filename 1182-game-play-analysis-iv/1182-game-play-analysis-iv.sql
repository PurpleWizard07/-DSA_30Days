# Write your MySQL query statement below
# Write your MySQL query statement below
with cte as
(select *,
lead(event_date) over (partition by player_id order by event_date) next,
dense_rank() over (partition by player_id order by event_date) rn
from activity)

select round(sum(case when datediff(next,event_date) = 1 then 1 else 0 end)/count(distinct player_id),2) fraction
from cte
where rn = 1