
--всі ворота, на як може відбуватися Прийомка товару
select Cells.Name 
from Cells 
where TypeID in
(
select ID from CellTypes where Name = 'Прийомка'
)