SELECT
	cname,
	city,
	rating
FROM Customers
WHERE
	cnum NOT IN (
		SELECT
			cnum
		FROM Orders
		WHERE
			odate > '2013-09-04'
	)