--����� �볺��� �� �� ������, ���� ���� �������� 50 ��
select Clients.Name, Products.Name, Products.Amount 
from Clients join Products on Clients.ID = Products.ClientID 
where  Products.Amount > 50 
