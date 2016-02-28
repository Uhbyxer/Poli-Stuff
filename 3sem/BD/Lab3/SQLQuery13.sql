
SELECT
	odate,
	snum,
	SUM(amt) as SumOfSales
FROM Orders	
WHERE odate in 
	(
		/* Дати з сумарними продажами  > 3000*/
		SELECT
			odate,
			SUM(amt)
		FROM Orders	
		WHERE amt > 100
		GROUP BY
			odate 
		HAVING SUM(amt) > 3000
	) 
	AND amt > 100
GROUP BY
	odate,
	snum
	
