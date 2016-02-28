BACKUP LOG [AW_Marketing] TO  [BackupLogs] WITH  NO_TRUNCATE , NOFORMAT, NOINIT,  NAME = N'AW_Marketing-Transaction Log  Backup', SKIP, NOREWIND, NOUNLOAD,  NORECOVERY ,  STATS = 10
GO


RESTORE DATABASE [AW_Marketing] FROM  DISK = N'C:\AWBackups\BackupDiff.bak' WITH  FILE = 1,  NORECOVERY,  NOUNLOAD,  STATS = 10
GO
RESTORE DATABASE [AW_Marketing] FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL10.MSSQLSERVER\MSSQL\Backup\AW_Marketing\AW_Marketing_backup_2015_05_02_170015_4141067.bak' WITH  FILE = 1,  NORECOVERY,  NOUNLOAD,  STATS = 10
GO
RESTORE LOG [AW_Marketing] FROM  DISK = N'C:\AWBackups\BackupLogs.bak' WITH  FILE = 2,  NOUNLOAD,  STATS = 10
GO