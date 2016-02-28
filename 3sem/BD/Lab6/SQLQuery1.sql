CREATE VIEW [dbo].[vCustomers]
AS
	SELECT
		cus.cname as Customer, 
		cus.city CustomerCity,
		cus.rating,
		sal.comm as SalerProfit,
		sal.city as SalerCity
	FROM dbo.Customers cus
	JOIN Salers sal
		ON cus.snum = sal.snum
	WHERE
		sal.sname = SUSER_SNAME()