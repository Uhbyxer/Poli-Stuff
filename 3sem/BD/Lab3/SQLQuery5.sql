SELECT
	cname,
	city,
	rating
FROM Customers
WHERE
	LEN(cname) > 5