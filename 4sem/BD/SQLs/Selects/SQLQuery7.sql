--Комірки в яких розміщено більше 2-х різних товарних позицій 
select  Cells.Name, Count(PlaceBody.ProductID) as 'К-сть різних товарів' 
from PlaceBody
join Cells on Cells.ID = PlaceBody.CellID
group by Cells.Name having Count(PlaceBody.ProductID) > 2
