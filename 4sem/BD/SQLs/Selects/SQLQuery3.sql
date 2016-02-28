--Назви клієнтів та їх товари, вага яких перевищує 50 кг
select Clients.Name, Products.Name, Products.Amount 
from Clients join Products on Clients.ID = Products.ClientID 
where  Products.Amount > 50 
