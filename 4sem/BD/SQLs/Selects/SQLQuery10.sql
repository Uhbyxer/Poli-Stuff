--���������, ��� ����. ���� (� �����) ���� ������ � ��� ����� ���� ������ ���� ���������
select Cells.Tier, sum(Cells.Amount)/1000 as '����. ����, �' 
from Cells
where Cells.TypeID in
(
select CellTypes.ID from CellTypes where CellTypes.Name = '���������'
)
group by Cells.Tier