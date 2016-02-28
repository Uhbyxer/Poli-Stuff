SELECT
	rating,
	COUNT(cnum) AS N
FROM Customers	
GROUP BY
	rating
HAVING (rating) > 200

