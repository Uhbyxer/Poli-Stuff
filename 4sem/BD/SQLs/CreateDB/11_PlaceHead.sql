--таблиця шапки документа Розміщення
create table PlaceHead
(
ID int,
DocDate datetime,

UserID int not null,
AcceptID int not null,

constraint PK_PlaceHead primary key(ID),

--ссилка на користувача (працівника)
constraint FK_Place_Users foreign key(UserID) 
references Users(ID),

--ссилка на документ Прийомка
constraint FK_Place_Accept foreign key(AcceptID) 
references AcceptHead(ID),


)