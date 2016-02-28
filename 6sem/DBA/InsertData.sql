USE AW_Marketing
GO

DECLARE @c int
SET @c = 1
WHILE  @c < 250
BEGIN
  INSERT INTO PastPromotions.ProductDiscounts
  SELECT ProductID, '10', 'Price Reduction'
  FROM AdventureWorks2008.Production.Product

  INSERT INTO PastSponsorship.SponsorshipDeals
  SELECT ProductID, 'Sponsorship Deal'
  FROM AdventureWorks2008.Production.ProductInventory
  SET @c = @c + 1
END
