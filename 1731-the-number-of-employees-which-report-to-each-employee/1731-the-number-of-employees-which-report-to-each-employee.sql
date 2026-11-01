# Write your MySQL query statement below
select t1.employee_id,t1.name,count(t2.employee_id) as reports_count,round(avg(t2.age)) as average_age
from employees t1 join employees t2 on t1.employee_id=t2.reports_to 
group by t1.employee_id
order by employee_id asc;