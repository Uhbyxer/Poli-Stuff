--Прихід товарів від клієнта з назвою: ПАТ "ДЖЕЙ ТІ ІНТЕРНЕШНЛ КОМПАНІ  Україна"
select AcceptBody.RowNum, Products.Name, AcceptBody.Number
from AcceptBody join AcceptHead on AcceptBody.HeadID = AcceptHead.ID
join Clients on  AcceptHead.ClientID = Clients.ID
join Products on Products.ID = AcceptBody.ProductID
where Clients.Name = 'ПАТ "ДЖЕЙ ТІ ІНТЕРНЕШНЛ КОМПАНІ  Україна"'