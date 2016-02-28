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
