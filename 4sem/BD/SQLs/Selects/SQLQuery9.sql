--������� ����� ��� ���������, �� ����� �� �����������, ������������ �� ��� ���������
(select '��������' as '��� ���������', AcceptHead.ID as '�', AcceptHead.DocDate as '���� ���������', Users.Name as '���������'
from AcceptHead
join Users on Users.ID = AcceptHead.UserID

union
 
select '���������' as '��� ���������', PlaceHead.ID as '�', PlaceHead.DocDate as '���� ���������', Users.Name as '���������'
from PlaceHead
join Users on Users.ID = PlaceHead.UserID
)
order by '���� ���������'
