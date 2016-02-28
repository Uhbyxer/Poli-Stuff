SELECT
	odate,
	COUNT(odate) as N
FROM Orders	

GROUP BY
	odate
