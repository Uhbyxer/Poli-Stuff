--таблична частина документа Прийомка
create table AcceptBody
(
ID int,
RowNum int,
ProductID int not null,
Number numeric(18,3),

HeadID int not null,

constraint PK_AcceptBody primary key(ID),

--ссилка на товар
constraint FK_AcceptBody_Product foreign key(ProductID) 
references Products(ID),

--ссилка на шапку документа
constraint FK_Body_Head foreign key(HeadID) 
references AcceptHead(ID),
)