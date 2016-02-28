SELECT
	cname,
	city,
	rating
FROM Customers
WHERE
	city = 'London' or city = 'Rome'
