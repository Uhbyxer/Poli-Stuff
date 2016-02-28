SELECT
	cname,
	city,
	rating
FROM Customers
WHERE
	city <> 'London' and rating > 200