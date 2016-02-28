create View ProductsView as
select Products.*, Regions.Name as RegionName, Clients.Name as ClientName
from Products 
left join Regions on Products.RegionID = RegionID
left join Clients on Products.ClientID = ClientID