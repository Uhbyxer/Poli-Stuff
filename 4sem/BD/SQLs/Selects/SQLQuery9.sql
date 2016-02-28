--Вивести реєстр всіх документів, по видах та працівниках, посортованих по даті створення
(select 'Прийомка' as 'Вид документа', AcceptHead.ID as '№', AcceptHead.DocDate as 'Дата документа', Users.Name as 'Працівник'
from AcceptHead
join Users on Users.ID = AcceptHead.UserID

union
 
select 'Розміщення' as 'Вид документа', PlaceHead.ID as '№', PlaceHead.DocDate as 'Дата документа', Users.Name as 'Працівник'
from PlaceHead
join Users on Users.ID = PlaceHead.UserID
)
order by 'Дата документа'
