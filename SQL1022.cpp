--salary表少录入一些数据,下面录入缺录的数据
insert into Salary
values('2002','3800','1800'),
      ('2003','3800','1500'),
      ('2004','5100','1800'),
      ('3001','4200','2000'),
      ('3002','4100','1800'),
      ('3003','4600','1400');

select *
from Salary

--a) 查询每个雇员的所有信息
select *
from Employee

--b) 查询每个雇员的地址和电话
select name,address,phonenumber
from Employee

--c) 查询EmployeeID为2001的雇员的地址和电话。
select address,phonenumber
from Employee
where EmployeeID='2001'

--d) 查询女雇员地址和电话，并用AS子句将结果中各列的标题分别指定为“地址”和“电话”。
select name, address as 地址,phonenumber as 电话
from Employee
where sex='1'

--e) 计算每个雇员的实际收入。
select EmployeeID,Income-OutCome as 实际收入
from Salary

--f) 找出所有姓王的雇员的部门号。
select zip
from Employee
where name like '王%'

--思考：找出所有地址中含有“河南”的雇员的号码和部门号。
select EmployeeID,zip
from Employee
where address='河南'

--a)查询每个雇员的情况及工资情况（工资=Income - Outcome）
select Employee.EmployeeID,name,income-outcome as 工资
from Employee,Salary
where Employee.EmployeeID=Salary.EmployeeID

--b)查询财务部工资在2200元以上的雇员姓名及工资情况
select name,income-outcome as 工资
from Employee,Salary,Department
where Department.DepartmentID=Employee.DepartmentID and
      Employee.EmployeeID=Salary.EmployeeID and
	    DepartmentName='财务部' and
	   (Income-OutCome)>2200

--c)查询研发部在1980年以前出生的雇员姓名及其工资详情
select name,Income,OutCome
from Employee,Salary,Department
where Department.DepartmentID=Employee.DepartmentID and
      Employee.EmployeeID=Salary.EmployeeID and
	    DepartmentName='研发部' and
	    Birthday<'1980-1-1';

--d)查询人力资源部雇员的最高和最低工资
select max(Income-OutCome) as mas,min(Income-OutCome) as min
from Salary
where EmployeeID
      in(select EmployeeID
	     from Employee
	     where DepartmentID
		 in(select DepartmentID
		    from Department
			where DepartmentName='人力资源部'
			)
		)

--e)将各雇员的情况按工资由低到高排列
select name,income-outcome as 工资
from Salary,Employee
where Employee.EmployeeID=Salary.EmployeeID
order by income-outcome ASC

--f)求各部门的雇员数
select DepartmentName,count(Employee.DepartmentID) as 雇员数
from Employee,Department
where Employee.DepartmentID=Department.DepartmentID
group by Employee.DepartmentID,DepartmentName

--g)找出所有在财务部和人力资源部工作的雇员的编号
select EmployeeID
from Employee,Department
where Department.DepartmentID=Employee.DepartmentID and
	  DepartmentName='财务部'
union
select EmployeeID
from Employee,Department
where Department.DepartmentID=Employee.DepartmentID and
      DepartmentName='人力资源部'

--h)统计人力资源部工资在2500以上雇员的人数
select count(EmployeeID)
from Employee,Department
where EmployeeID
      in(select EmployeeID
	     from Salary
		 where (income-outcome)>2500
		 )
	  and Department.DepartmentID=Employee.DepartmentID
	  and DepartmentName='人力资源部'

--i)求财务部雇员的总人数
select count(EmployeeID) as 总人数
from Employee
where DepartmentID
      in(select DepartmentID
	     from Department
		 where DepartmentName='财务部'
	     )

--j)求财务部雇员的平均工资
select avg(income-outcome) as 平均工资
from Salary
where EmployeeID
      in(select EmployeeID
	     from Employee
		 where DepartmentID
		       in(select DepartmentID
			      from Department
				  where DepartmentName='财务部'
				  )
		 )

--k)查找比所有财务部的雇员工资都高的雇员的姓名
select name
from Employee,Salary
where Employee.EmployeeID=Salary.EmployeeID and
      (income-outcome)>all(select Income-OutCome
						   from Salary,Employee,Department
						   where Department.DepartmentID=Employee.DepartmentID and
						         Employee.EmployeeID=Salary.EmployeeID and
					       	     DepartmentName='财务部'
						   )

--l)查找财务部年龄不低于研发部所有雇员年龄的雇员的姓名
select name
from Employee,Department
where Department.DepartmentID=Employee.DepartmentID and
	  DepartmentName='财务部' and
	  Birthday<=any(select min(Birthday)
	                from Employee,Department
                    where Department.DepartmentID=Employee.DepartmentID and
						  DepartmentName='研发部'
					)

--m)查找在财务部工作的雇员的情况
select Employee.EmployeeID,name,Birthday,sex,Address,Zip,PhoneNumber,
       EmailAddress,Employee.DepartmentID,DepartmentName,Note,Income,OutCome
from Employee,Salary,Department
where Department.DepartmentID=Employee.DepartmentID and
      Employee.EmployeeID=Salary.EmployeeID and
	  DepartmentName='财务部'
