--Прихід товару, щоб було вказано назви клієнтів, товарів, складу
select Clients.Name, AcceptHead.*, AcceptBody.*, Warehouses.Name, Products.Name
from AcceptBody join AcceptHead on AcceptBody.HeadID = AcceptHead.ID
join Clients on  AcceptHead.ClientID = Clients.ID
join Warehouses on Warehouses.ID = AcceptHead.WarehouseID
join Products on Products.ID = AcceptBody.ProductID