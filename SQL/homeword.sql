use bjpowernode;
-- select * from dept;
-- select * from emp;
-- select * from salgrade;


-- use prictice;
-- select * from customers;
-- select * from orderitems;
-- select * from orders;
-- select * from productnotes;
-- select * from vendors;
-- select * from customers;



-- 注意下面的写法是错的，有分组前面的select只能是分组函数或者分组变量deptno，不能是ename
select
	ename, deptno, max(sal)
from
	emp
group by
	deptno;


-- 1、取得每个部门最高薪水的人员名称
select
	e.ename, t.*
from 
	emp e
join
	(select deptno, max(sal) maxsal from emp group by deptno) t  -- 部门最高薪水
on
	t.deptno=e.deptno and t.maxsal=e.sal;

-- 2、哪些人的薪水在部门的平均薪水之上
select
	e.deptno, e.ename, e.sal, t.avgsal 
from
	emp e
join
	(select deptno, avg(sal) avgsal from emp group by deptno) t  -- 部门的平均薪水
on
	e.deptno=t.deptno and e.sal>t.avgsal;






