SELECT
	cname,
	city,
	rating
FROM Customers
WHERE
	snum NOT IN (
		SELECT
			snum
		FROM Salers
		WHERE
			sname = 'Peel' or comm > 0.13
	)
union

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