--таблична частина документа Розміщення
create table PlaceBody
(
ID int,
RowNum int,
ProductID int not null,
Number numeric(18,3),
CellID int not null,

HeadID int not null,

constraint PK_PlaceBody primary key(ID),

--ссилка на товар
constraint FK_PlaceBody_Product foreign key(ProductID) 
references Products(ID),

--ссилка на комірку
constraint FK_PlaceBody_Cells foreign key(CellID) 
references Cells(ID),

--ссилка на шапку документа
constraint FK_Place_Body_Head foreign key(HeadID) 
references PlaceHead(ID),
)