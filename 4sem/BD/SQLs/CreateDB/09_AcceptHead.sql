--таблиц€ шапки документа ѕрийомка
create table AcceptHead
(
ID int,
DocDate datetime,

ClientID int not null,
WarehouseID int not null,
CellID int not null,
UserID int not null,

constraint PK_AcceptHead primary key(ID),

--ссилка на кл≥Їнта
constraint FK_AcceptHead_Client foreign key(ClientID) 
references Clients(ID),

--ссилка на склад
constraint FK_AcceptHead_Warehouses foreign key(WarehouseID) 
references Warehouses(ID),

--ссилка на ком≥рку (ворота)
constraint FK_AcceptHead_Cells foreign key(CellID) 
references Cells(ID),

--ссилка на користувача (прац≥вника)
constraint FK_AcceptHead_Users foreign key(UserID) 
references Users(ID),


)