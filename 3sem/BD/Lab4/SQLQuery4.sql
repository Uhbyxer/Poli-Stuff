SELECT
	cus.cname,
	ord.amt,
	ord.odate
FROM Customers cus
JOIN Orders ord
	ON cus.cnum = ord.cnum
 AND cus.snum != ord.snum  
