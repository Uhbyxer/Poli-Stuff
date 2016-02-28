
--create table Departments
--(

--ID int primary key identity,
--Name nvarchar(50),
--Location nvarchar(50)

--)
--go


--create table Employees
--(

--ID int primary key identity,
--FirstName nvarchar(50),
--LastName nvarchar(50),
--Gender nvarchar(50),
--Salary int,
--DepartmentId int foreign key references Departments(Id)


--)
--go


--insert into Departments values ('IT', 'New York')
--insert into Departments values ('HR', 'London')
--insert into Departments values ('Payrol', 'Sydney')
--go

Insert into Employees values ('Mark', 'Hastings', 'Male', 60000, 1)
Insert into Employees values ('Steve', 'Pound', 'Male', 45000, 1)
Insert into Employees values ('Ben', 'Hoskinz', 'Male', 70000, 1)
Insert into Employees values ('Philip', 'Hastings', 'Male', 45000, 2)
Insert into Employees values ('Mary', 'Lambeth', 'Female', 30000, 2)
Insert into Employees values ('Valarie', 'Vikings', 'Female', 35000, 3)
Insert into Employees values ('John', 'Stanmore', 'Male', 80000, 1)
go