SELECT
	cus.cname,
	cus.city,
	ord.amt,
	ord.odate
FROM Customers cus
JOIN Orders ord
	ON cus.cnum = ord.cnum
WHERE
	ord.amt > 1000
