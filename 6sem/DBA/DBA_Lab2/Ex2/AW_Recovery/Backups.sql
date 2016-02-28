USE [master]
GO
ALTER DATABASE [AW_Marketing] SET RECOVERY FULL WITH NO_WAIT
GO


USE [master]
GO
EXEC master.dbo.sp_addumpdevice  @devtype = N'disk', @logicalname = N'BackupFull', @physicalname = N'C:\AWBackups\BackupFull.bak'
GO

USE [master]
GO
EXEC master.dbo.sp_addumpdevice  @devtype = N'disk', @logicalname = N'BackupLogs', @physicalname = N'C:\AWBackups\BackupLogs.bak'
GO


USE [master]
GO
EXEC master.dbo.sp_addumpdevice  @devtype = N'disk', @logicalname = N'BackupDiff', @physicalname = N'C:\AWBackups\BackupDiff.bak'
GO

BACKUP DATABASE [AW_Marketing] TO  [BackupFull] WITH NOFORMAT, INIT,  NAME = N'AW_Marketing-Full Database Backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO

BACKUP LOG [AW_Marketing] TO  [BackupLogs] WITH NOFORMAT, INIT,  NAME = N'AW_Marketing-Transaction Log  Backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
BACKUP DATABASE [AW_Marketing] TO  [BackupDiff] WITH NOFORMAT, INIT,  NAME = N'AW_Marketing-Full Database Backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO


BACKUP LOG [AW_Marketing] TO  [BackupLogs] WITH NOFORMAT, INIT,  NAME = N'AdventureWorks2008 – Transaction Log 2', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
