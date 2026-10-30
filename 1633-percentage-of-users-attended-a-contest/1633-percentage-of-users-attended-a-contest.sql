# Write your MySQL query statement below
select t2.contest_id,round((count(t2.user_id)*100/(select count(*) from users)),2) as percentage
from Users t1 join Register t2 on t1.user_id=t2.user_id
group by t2.contest_id order by percentage desc, t2.contest_id asc;