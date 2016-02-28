SELECT
	sal.sname,
	sal.comm,
	ord.amt,
	ord.odate
FROM Salers sal
LEFT JOIN Orders ord
	ON sal.snum = ord.snum
