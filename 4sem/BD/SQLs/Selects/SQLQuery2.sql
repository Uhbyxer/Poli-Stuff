--всі товари, що розміщаються в зоні "Електротовари", з об'ємом не білишим 1 куб. м.
select Name, Width * Height * Depth as Capacity 
from Products
where  (Width * Height * Depth <= 1) and 
RegionID in
(
select ID from Regions where Name = 'Електротехніка'
)