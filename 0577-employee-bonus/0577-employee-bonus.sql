# Write your MySQL query statement below
select t1.name,t2.bonus
from employee t1 left join bonus t2 on t1.empid=t2.empid
where t2.bonus<1000 or t2.bonus is NULL;