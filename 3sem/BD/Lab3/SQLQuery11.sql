SELECT
	odate,
	COUNT(odate) as N
FROM Orders	
WHERE snum in
	(
	SELECT snum
	FROM Salers
	WHERE comm >= 0.12	
	)
GROUP BY
	odate