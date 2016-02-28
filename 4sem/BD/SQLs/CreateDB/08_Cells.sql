--таблиц€  ом≥рки
create table Cells
(
ID int,
Name nvarchar(50),


--розм≥ри товару
Width numeric(18,3),--ширина  
Height numeric(18,3),--висота
Depth numeric(18,3),--глубина
SizeControl int, -- чи контролювати по розм≥ру
--вага
Amount numeric(18,3), 
AmountControl int, -- чи контролювати по ваз≥

Stillage int, --стелаж
Tier int, --€рус 
Position int, --позиц≥€

TypeID int not null,
WarehouseID int not null,
RegionID int not null,

constraint PK_Cells primary key(ID),

--ссилка на типи ком≥рок
constraint FK_Cells_CellsTypes foreign key(TypeID) 
references CellTypes(ID),

--ссилка на склад
constraint FK_Cells_Warehouses foreign key(WarehouseID) 
references Warehouses(ID),

--ссилка до зон розм≥щенн€
constraint FK_Cells_Regions foreign key(RegionID) 
references Regions(ID),

)