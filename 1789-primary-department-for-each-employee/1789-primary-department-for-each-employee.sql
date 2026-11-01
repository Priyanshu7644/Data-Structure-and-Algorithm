# Write your MySQL query statement below
select t1.employee_id,t1.department_id
from employee t1 join employee t2 on t1.employee_id=t2.employee_id 
group by employee_id
having count(*)=1

union

select t1.employee_id,t1.department_id
from employee t1
where t1.primary_flag='Y';