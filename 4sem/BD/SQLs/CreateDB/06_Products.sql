--таблиц€ “овари
create table Products
(
ID int,
Name nvarchar(50),
--розм≥ри товару
Width numeric(18,3),  
Height numeric(18,3),
Depth numeric(18,3),
--вага
Amount numeric(18,3),

RegionID int not null,
ClientID int not null,
constraint PK_Products primary key(ID),

--ссилка до зон розм≥щенн€
constraint FK_Products_Regions foreign key(RegionID) 
references Regions(ID),

--ссилка на кл≥Їнта
constraint FK_Products_Clients foreign key(ClientID) 
references Clients(ID)

)