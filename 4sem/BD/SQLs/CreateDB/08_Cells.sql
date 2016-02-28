--������� ������
create table Cells
(
ID int,
Name nvarchar(50),


--������ ������
Width numeric(18,3),--������  
Height numeric(18,3),--������
Depth numeric(18,3),--�������
SizeControl int, -- �� ������������ �� ������
--����
Amount numeric(18,3), 
AmountControl int, -- �� ������������ �� ���

Stillage int, --������
Tier int, --���� 
Position int, --�������

TypeID int not null,
WarehouseID int not null,
RegionID int not null,

constraint PK_Cells primary key(ID),

--������ �� ���� ������
constraint FK_Cells_CellsTypes foreign key(TypeID) 
references CellTypes(ID),

--������ �� �����
constraint FK_Cells_Warehouses foreign key(WarehouseID) 
references Warehouses(ID),

--������ �� ��� ���������
constraint FK_Cells_Regions foreign key(RegionID) 
references Regions(ID),

)