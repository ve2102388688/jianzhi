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
-- 先计算部门的平均薪水
-- 选取大于结果值
select
	e.deptno, e.ename, e.sal, t.avgsal 
from
	emp e
join
	(select deptno, avg(sal) avgsal from emp group by deptno) t  -- 部门的平均薪水
on
	e.deptno=t.deptno and e.sal>t.avgsal;


-- 3、取得部门中（所有人的）平均薪水的等级
-- 先计算部门的平均薪水
-- 部门的平均薪水等级
select
	t.deptno, s.grade
from
	salgrade s
join
	(select deptno, avg(sal) avgsal from emp group by deptno) t
on
	t.avgsal between s.losal and s.hisal; 


-- 4、取得部门中（所有人的）平均的薪水等级
-- 先计算每个人的薪水等级
-- 按部门求平均值
select
	t.deptno, avg(t.grade) avggrade
from
	(select e.deptno, s.grade from emp e join salgrade s on e.sal between s.losal and s.hisal) t
group by
	t.deptno;


-- 5、不准用组函数（Max），取得最高薪水
select 
	ename, sal
from
	emp
order by
	sal desc
limit 1;


-- 6、取得平均薪水最高的部门的部门编号
-- 部门的平均薪水
-- 降序取第一个
select 
	deptno, avg(sal) avgsal 
from
	emp 
group by
	deptno
order by
	avgsal desc
limit 1;


-- 7、求平均薪水的等级最低的部门的部门名称
select
	d.dname, avgsal
from
	dept d
join
	(select deptno, avg(sal) avgsal from emp group by deptno order by avgsal limit 1) t
on
	t.deptno=d.deptno;


-- 8、取得比普通员工(员工代码没有在mgr字段上出现的) 的最高薪水还要高的领导人姓名




-- 9、取得薪水最高的前五名员工
SELECT 
	ename, sal
FROM
	emp
ORDER BY
	sal DESC
limit 5;




-- 10、取得薪水最高的第六到第十名员工
SELECT 
	ename, sal
FROM 
	emp
ORDER BY 
	sal DESC 
LIMIT 5,5;								-- 取5个数据，从0开始


-- 11、取得最后入职的 5 名员工
SELECT 
	ename, hiredate
FROM 
	emp
ORDER BY 
	hiredate DESC  
LIMIT 5;


-- 12、取得每个薪水等级有多少员工
SELECT 
	s.grade, count(*) 
FROM 
	emp e 
JOIN 
	salgrade s 
ON 
	e.sal BETWEEN s.losal AND s.hisal 
GROUP BY 
	s.grade;


-- 13、面试题：




-- 14、列出所有员工及领导的姓名
SELECT 
	e.ename '员工', mag.ename '领导'
FROM 
	emp e
JOIN 
	emp mag
ON 
	e.mgr=mag.empno;


-- 15、列出受雇日期早于其直接上级的所有员工的编号,姓名,部门名称
SELECT 
	 e.empno, e.ename '员工', e.hiredate, d.dname, mag.ename '领导', mag.hiredate
FROM 
	emp e
JOIN 
	emp mag
ON  
	e.mgr=mag.empno
JOIN 
	dept d
ON	
	d.deptno=e.deptno		-- 需要求取部门名称
WHERE 
	e.hiredate<mag.hiredate;

	 
-- 16、列出部门名称和这些部门的员工信息, 同时列出那些没有员工的部门
SELECT 
	d.deptno, e.*
FROM 
	dept d
LEFT JOIN 
	emp e
ON 
	d.deptno=e.deptno;


-- 17、列出至少有 5 个员工的所有部门
SELECT 
	deptno,count(*) totalNum
FROM
	emp
GROUP BY 
	deptno
HAVING 
	totalNum>=5;


-- 18、列出薪金比"SMITH" 多的所有员工信息
SELECT 
	e.*
FROM 
	emp e
WHERE 
	e.sal > (SELECT sal FROM emp WHERE ename='SMITH');


-- 19、列出所有"CLERK"( 办事员) 的姓名及其部门名称, 部门的人数
-- 连接查询要放在where之前
SELECT 
	e.ename, e.job, d.dname
FROM 
	emp e
JOIN 
	dept d
ON 
	e.deptno=d.deptno
WHERE 
	job='CLERK';


-- 20、列出最低薪金大于 1500 的各种工作及从事此工作的全部雇员人数。
SELECT 
	job, count(*)
FROM
	emp
GROUP BY 
	job
HAVING 
	min(sal)>1500;								-- 最低薪金大于1500


-- 21、列出在部门"SALES"< 销售部> 工作的员工的姓名
SELECT 
	ename
FROM 
	emp
WHERE 
	deptno=(SELECT deptno FROM dept WHERE dname='SALES');		-- SALES的部门编号


-- 22、列出薪金高于公司平均薪金的所有员工, 所在部门名称, 上级领导, 雇员的工资等级.
SELECT 
	e.ename '员工', d.dname, s.grade, mag.ename '领导'
FROM 
	emp e
INNER JOIN 
	dept d
ON 
	e.deptno=d.deptno									-- 部门名称
LEFT JOIN 
	emp mag
ON 
	e.mgr=mag.empno										-- 上级领导（左连接，KING没有上级也是员工）
INNER JOIN 
	salgrade s
ON
	e.sal BETWEEN s.losal AND s.hisal					-- 工资等级
WHERE 
	e.sal > (SELECT avg(sal) FROM emp);					-- 高于公司平均薪金


-- 23、列出与"SCOTT" 从事相同工作的所有员工及部门名称
SELECT 
	e.ename, t.dname
FROM 
	emp e
JOIN 
	dept t
ON	
	e.deptno=t.deptno									-- 部门名称
WHERE 
	e.job=(SELECT job FROM emp WHERE ename='SCOTT') AND e.ename != 'SCOTT';


-- 24、列出薪金等于部门 30 中员工的薪金的其他员工的姓名和薪金.
SELECT 
	ename, sal
FROM 
	emp
WHERE 
	sal in(SELECT DISTINCT sal FROM emp WHERE deptno=30) AND deptno!=30;		-- 等于部门30的工资


-- 25、列出薪金高于在部门 30 工作的所有员工的薪金的员工姓名和薪金. 部门名称
SELECT 
	e.ename, e.sal, t.dname
FROM 
	emp e
JOIN 
	dept t
ON 
	e.deptno=t.deptno
WHERE 
	e.sal>(SELECT max(sal) FROM emp WHERE deptno=30);					-- 30部门的最高工资


-- 26、列出在每个部门工作的员工数量, 平均工资和平均服务期限
-- ifnull(xxx, 0) : xxx为空就设置该字段值为0
-- 两个日期的“年差”，差了多少年？ TimeStampDiff(间隔类型, 前一个日期, 后一个日期) timestampdiff(YEAR, e.hiredate, now())
SELECT 
	t.deptno, count(e.ename) totalNum, ifnull(avg(e.sal),0) avgsal, ifnull(avg(timestampdiff(YEAR, e.hiredate, now())), 0) avgservicetime
FROM 
	emp e
RIGHT JOIN 																-- 右连接，有些部门没有人
	dept t
ON 
	e.deptno=t.deptno
GROUP BY 
	t.deptno;


-- 27、列出所有员工的姓名、部门名称和工资。
SELECT 
	e.ename, e.sal, d.dname
FROM 
	emp e
JOIN 
	dept d
ON	
	e.deptno=d.deptno;


-- 28、列出所有部门的详细信息和人数
SELECT 
	d.*, count(e.ename) totalNum			-- 使用分组函数一定要使用分组GROUP BY
FROM
	emp e
RIGHT JOIN 
	dept d
ON
	e.deptno=d.deptno						-- 右连接。部门表必须查出来
GROUP BY 
	d.deptno;


-- 29、列出各种工作的最低工资及从事此工作的雇员姓名
SELECT 
	e.ename, t.job, t.minsal
FROM 
	(SELECT job,min(sal) minsal FROM emp GROUP BY job) t		-- 找出每个工作岗位最低薪资
LEFT JOIN 
	emp e
ON 
	e.job=t.job AND e.sal=t.minsal;


-- 30、列出各个部门的 MANAGER(领导) 的最低薪金
SELECT 
	deptno, min(sal)
FROM
	emp
WHERE 
	job='MANAGER'
GROUP BY 
	deptno;


-- 31、列出所有员工的年工资, 按年薪从低到高排序
SELECT 
	ename, (sal+ifnull(comm,0))*12 yearsal
FROM
	emp
ORDER BY 
	yearsal ASC;


-- 32、求出员工领导的薪水超过3000的员工名称与领导
SELECT 
	e.ename '员工', mag.ename '领导'
FROM 
	emp e
JOIN 
	emp mag
ON 
	e.mgr=mag.empno
WHERE	
	mag.sal>3000;										-- 领导的薪水超过3000


-- 33、求出部门名称中, 带'S'字符的部门员工的工资合计、部门人数
SELECT 
	d.deptno, d.dname, d.loc, ifnull(sum(e.sal),0) sumsal, count(e.ename)
FROM 
	emp e
RIGHT JOIN 
	dept d
ON
	e.deptno=d.deptno
WHERE
	d.dname like '%S%'									-- 带'S'字符
GROUP BY 
	d.deptno, d.dname, d.loc;


-- 34、给任职日期超过 30 年的员工加薪 10%.
UPDATE 
	emp
SET 
	sal = sal*1.1
WHERE 
	timestampdiff(YEAR, hiredate, now())>30;