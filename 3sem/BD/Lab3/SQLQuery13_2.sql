SELECT
	odate,
	snum,
	SUM(amt) as SumOfSales
FROM Orders	
WHERE amt > 100
GROUP BY
	odate,
	snum
HAVING SUM(amt) > 3000
	