SELECT
	cus.cname,
	cus.city,
	ord.amt,
	ord.odate
FROM Customers cus, Orders ord
WHERE
	ord.amt > 1000
	AND cus.cnum = ord.cnum
