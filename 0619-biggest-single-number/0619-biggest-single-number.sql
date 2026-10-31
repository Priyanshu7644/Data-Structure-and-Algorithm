# Write your MySQL query statement below
select max(t1.num) as num
from mynumbers t1 join (select num,count(num) as count_num from mynumbers group by num) t2 on t1.num=t2.num
where t2.count_num=1;