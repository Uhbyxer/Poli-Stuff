--Розміщення товару в розрізі Назв клієнтів, Комірок 
select  Clients.Name, Cells.Name, Products.Name, PlaceBody.Number  
from PlaceBody
join Cells on Cells.ID = PlaceBody.CellID
join Products on Products.ID = PlaceBody.ProductID
join PlaceHead on PlaceHead.ID = PlaceBody.HeadID
join AcceptHead on AcceptHead.ID = PlaceHead.AcceptID
join Clients on Clients.ID = AcceptHead.ClientID