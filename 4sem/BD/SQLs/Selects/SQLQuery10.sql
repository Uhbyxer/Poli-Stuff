--визначити, яку макс. вагу (в тонах) може містити в собі кожен ярус складу зони зберігання
select Cells.Tier, sum(Cells.Amount)/1000 as 'Макс. вага, т' 
from Cells
where Cells.TypeID in
(
select CellTypes.ID from CellTypes where CellTypes.Name = 'Зберігання'
)
group by Cells.Tier