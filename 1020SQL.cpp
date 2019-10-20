create database s1831050012_HRM

go
use s1831050012_HRM;

go

create table Department
(
	DepartmentID char(3) not NULL primary key,
	DepartmentName char(20) not NULL,
	Note Text
);

create table Employee
(
	EmployeeID char(6)primary key not NULL,
	Name char(10) not NULL,
	Birthday Datetime not NULL,
	Sex Bit not NULL,
	Address char(20),
	Zip char(6),
	PhoneNumber char(12),
	EmailAddress char(30),
	DepartmentID char(3) not NULL,
	foreign key(DepartmentID)references Department(DepartmentID)
);

create table Salary
(
	EmployeeID char(6) not NULL,
	Income float(8) not NULL,
	OutCome float(8) not NULL,
	foreign key(EmployeeID)references Employee(EmployeeID)
);

insert into Department
values('1', '财务部', '财务部'),
	  ('2', '研发部', '研发部'),
	  ('3', '人力资源部', '人力资源部');

insert into Employee
values('1001', '李勇', '78-3-12', '0', '河南', '475001', '3880378', 'ly@henu.edu.cn', '1'),
      ('1002', '王敏', '80-11-2', '1', '河南', '475002', '0378311', 'wm@henu.edu.cn', '1'),
	  ('1003', '刘晨', '78-6-22', '0', '河南', '475003', '0378322', 'lc@henu.edu.cn', '1'),
      ('1004', '周宏', '83-10-3', '1', '河北', '475004', '7865987', 'zh@henu.edu.cn', '1'),
      ('2001', '张立', '78-8-1',  '0', '河南', '475005', '0378333', 'zl@henu.edu.cn', '2'),
      ('2002', '刘毅', '82-1-23', '0', '河南', '475006', '0378344', 'ly@henu.edu.cn', '2'),
      ('2003', '张玫', '81-3-15', '1', '河南', '475007', '0378355',	'zm@henu.edu.cn', '2'),
      ('2004', '王军', '79-5-12', '0', '山东', '475008', '5687967',	'wj@henu.edu.cn', '2'),
      ('3001', '徐静', '76-8-12', '1', '河南', '475009', '0378366',	'xj@henu.edu.cn', '3'),
      ('3002', '赵军', '79-2-19', '0', '河南', '475010', '0378377',	'zj@henu.edu.cn', '3'),
      ('3003', '王霞', '82-8-18', '1', '湖南', '475011', '7556677',	'wx@henu.edu.cn', '3');

insert into salary
values('1001', '3600', '1500'),
      ('1002', '3300', '1000'),
	  ('1003', '3700', '1200'),
	  ('1004', '4500', '1600'),
	  ('2001', '4000', '1600');
