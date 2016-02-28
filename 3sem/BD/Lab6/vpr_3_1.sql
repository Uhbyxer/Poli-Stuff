CREATE VIEW [dbo].[vNewSalersCustomers]
AS
	SELECT
		cus.cname as Customer, 
		cus.city CustomerCity,
		cus.rating,
		sal.sname as Saler,
		sal.comm as SalerProfit,
		sal.city as SalerCity
	FROM dbo.Customers cus
	JOIN Salers sal
		ON cus.snum = sal.snum
	WHERE
		cus.cnum in (
			SELECT
				cnum
			FROM Relations
			WHERE
				sname = SUSER_SNAME()
				/*sname = 'Serres'*/
		) 
union -- якщо користувач кер≥вник - додаЇмо вс≥ записи
	SELECT
		cus.cname as Customer, 
		cus.city CustomerCity,
		cus.rating,
		sal.sname as Saler,
		sal.comm as SalerProfit,
		sal.city as SalerCity
	FROM dbo.Customers cus
	JOIN Salers sal
		ON cus.snum = sal.snum
	WHERE
		 SUSER_SNAME() in (
			SELECT
				sname
			FROM ChiefSalers
		) 