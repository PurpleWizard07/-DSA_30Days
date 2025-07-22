# Write your MySQL query statement below
select * from cinema
group by id
having id%2 <> 0 and description <> 'boring'
order by rating desc;