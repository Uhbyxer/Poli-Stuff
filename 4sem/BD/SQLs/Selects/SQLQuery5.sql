--Сумарна вага приходу по кожних воротах
select Cells.Name, sum(Products.Amount) as Amount 
from AcceptBody
join Products on Products.ID = AcceptBody.ProductID
join AcceptHead on AcceptHead.ID = AcceptBody.HeadID
join Cells on Cells.ID = AcceptHead.CellID
group by Cells.Name