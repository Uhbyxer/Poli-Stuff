--������ � ���� �������� ����� 2-� ����� �������� ������� 
select  Cells.Name, Count(PlaceBody.ProductID) as '�-��� ����� ������' 
from PlaceBody
join Cells on Cells.ID = PlaceBody.CellID
group by Cells.Name having Count(PlaceBody.ProductID) > 2
