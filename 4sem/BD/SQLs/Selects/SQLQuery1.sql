
--�� ������, �� �� ���� ���������� �������� ������
select Cells.Name 
from Cells 
where TypeID in
(
select ID from CellTypes where Name = '��������'
)