SELECT
	sal.sname,
	ord.amt,
	cus.cname
FROM Salers sal
JOIN Orders ord 
	ON sal.snum = ord.snum
JOIN Customers cus
ON ord.cnum = cus.cnum
