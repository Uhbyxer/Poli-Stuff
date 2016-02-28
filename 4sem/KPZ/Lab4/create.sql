--CREATE DATABASE SampleDB

create table Cars
(
CarID int,
Brand nvarchar(150) not null,
Model nvarchar(150) not null,
constraint PK_Cars primary key(CarID),
)
