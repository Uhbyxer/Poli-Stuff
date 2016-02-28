--������� ������
create table Products
(
ID int,
Name nvarchar(50),
--������ ������
Width numeric(18,3),  
Height numeric(18,3),
Depth numeric(18,3),
--����
Amount numeric(18,3),

RegionID int not null,
ClientID int not null,
constraint PK_Products primary key(ID),

--������ �� ��� ���������
constraint FK_Products_Regions foreign key(RegionID) 
references Regions(ID),

--������ �� �볺���
constraint FK_Products_Clients foreign key(ClientID) 
references Clients(ID)

)