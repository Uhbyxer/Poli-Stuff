SELECT
	snum,
	cname,
	COUNT(cnum) as N
FROM Customers	
GROUP BY
	snum,
	cname
	
	


	
