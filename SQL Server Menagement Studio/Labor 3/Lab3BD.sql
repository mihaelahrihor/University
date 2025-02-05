--Teil 1

--MODIFY COLUMN TYPE PROCEDURE
CREATE PROCEDURE ModifyColumnType
    @TableName NVARCHAR(50),
    @ColumnName NVARCHAR(50),
    @NewDataType NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + ' ALTER COLUMN ' + QUOTENAME(@ColumnName) + ' ' + @NewDataType;
    EXEC sp_executesql @SQL;
END;
GO
-- Example: Modify the data type of 'salary' column in 'Employee' to 'DECIMAL(10, 2)'
EXEC ModifyColumnType 'Employee', 'salary', 'DECIMAL(10, 2)';
 
 go
 --Rollback Modify Column Type
 CREATE PROCEDURE RollbackModifyColumnType
    @TableName NVARCHAR(50),
    @ColumnName NVARCHAR(50),
    @OldDataType NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + ' ALTER COLUMN ' + QUOTENAME(@ColumnName) + ' ' + @OldDataType;
    EXEC sp_executesql @SQL;
END;
GO
-- Example: Revert 'salary' column in 'Employee' back to 'FLOAT'
EXEC RollbackModifyColumnType 'Employee', 'salary', 'FLOAT';
go

--ADD DEFAULT CONSTRAINT
CREATE PROCEDURE AddDefaultConstraint
    @TableName NVARCHAR(50),
    @ColumnName NVARCHAR(50),
    @DefaultValue NVARCHAR(50),
    @ConstraintName NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + 
                 ' ADD CONSTRAINT ' + QUOTENAME(@ConstraintName) + 
                 ' DEFAULT ' + @DefaultValue + 
                 ' FOR ' + QUOTENAME(@ColumnName);
    EXEC sp_executesql @SQL;
END;
GO
-- Example: Add default value of 0 for 'inventory_id' in 'Employee'
EXEC AddDefaultConstraint 'Employee', 'inventory_id', '0', 'DF_Employee_InventoryID';
go
--Rollback
CREATE PROCEDURE RollbackAddDefaultConstraint
    @TableName NVARCHAR(50),
    @ConstraintName NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + ' DROP CONSTRAINT ' + QUOTENAME(@ConstraintName);
    EXEC sp_executesql @SQL;
END;
GO
-- Example: Remove default constraint from 'inventory_id' in 'Employee'
EXEC RollbackAddDefaultConstraint 'Employee', 'DF_Employee_InventoryID';
go

--CREATE NEW TABLE
CREATE PROCEDURE CreateNewTable
    @TableName NVARCHAR(50),
    @Columns NVARCHAR(MAX)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'CREATE TABLE ' + QUOTENAME(@TableName) + ' (' + @Columns + ')';
    EXEC sp_executesql @SQL;
END;
GO

-- Example: Create a new table for suppliers
EXEC CreateNewTable 'Supplier', 'supplier_id INT PRIMARY KEY, name VARCHAR(50)';

--Rollback
CREATE PROCEDURE RollbackCreateNewTable
    @TableName NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'DROP TABLE ' + QUOTENAME(@TableName);
    EXEC sp_executesql @SQL;
END;
GO

-- Example: Remove the 'Supplier' table
EXEC RollbackCreateNewTable 'Supplier';


--ADD COLUMN TO TABLE
CREATE PROCEDURE AddColumnToTable
    @TableName NVARCHAR(50),
    @ColumnDefinition NVARCHAR(100)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + ' ADD ' + @ColumnDefinition;
    EXEC sp_executesql @SQL;
END;
GO
-- Example: Add a column 'phone_number' to 'Employee'
EXEC AddColumnToTable 'Employee', 'phone_number VARCHAR(15)';

--Rollback
CREATE PROCEDURE RollbackAddColumnToTable
    @TableName NVARCHAR(50),
    @ColumnName NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + ' DROP COLUMN ' + QUOTENAME(@ColumnName);
    EXEC sp_executesql @SQL;
END;
GO

-- Example: Remove the 'phone_number' column from 'Employee'
EXEC RollbackAddColumnToTable 'Employee', 'phone_number';


--ADD FOREIGN KEY CONSTRAINT
CREATE PROCEDURE AddForeignKeyConstraint
    @TableName NVARCHAR(50),
    @ColumnName NVARCHAR(50),
    @ReferencedTable NVARCHAR(50),
    @ReferencedColumn NVARCHAR(50),
    @ConstraintName NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + 
               ' ADD CONSTRAINT ' + QUOTENAME(@ConstraintName) + 
               ' FOREIGN KEY (' + QUOTENAME(@ColumnName) + ') ' +
               'REFERENCES ' + QUOTENAME(@ReferencedTable) + ' (' + QUOTENAME(@ReferencedColumn) + ')';
    EXEC sp_executesql @SQL;
END;
GO

-- Example: Add a foreign key on 'departament_id' in 'Employee' referencing 'Departament'
EXEC AddForeignKeyConstraint 'Employee', 'departament_id', 'Departament', 'departament_id', 'FK_Employee_Departament';

--Rollback
CREATE PROCEDURE RollbackAddForeignKeyConstraint
    @TableName NVARCHAR(50),
    @ConstraintName NVARCHAR(50)
AS
BEGIN
    DECLARE @SQL NVARCHAR(MAX);
    SET @SQL = 'ALTER TABLE ' + QUOTENAME(@TableName) + ' DROP CONSTRAINT ' + QUOTENAME(@ConstraintName);
    EXEC sp_executesql @SQL;
END;
GO

-- Example: Remove foreign key constraint 'FK_Employee_Departament'
EXEC RollbackAddForeignKeyConstraint 'Employee', 'FK_Employee_Departament';



--TEIL 2
-- TABLE FOR DATABASE VERSION CONTROL
CREATE TABLE CurrentVersion (
    VersionNumber INT NOT NULL
);

-- Inițializarea versiunii curente la 0 (sau orice valoare de început preferi)
INSERT INTO CurrentVersion (VersionNumber) VALUES (0);

CREATE TABLE DatabaseVersion (
    CurrentVersion INT PRIMARY KEY
);


INSERT INTO DatabaseVersion (CurrentVersion) VALUES (0);



CREATE TABLE VersionHistory (
    VersionNumber INT PRIMARY KEY, 
    ProcedureExecuted NVARCHAR(100),
    Parameters NVARCHAR(MAX), 
    Timestamp DATETIME DEFAULT GETDATE(), 
);


CREATE PROCEDURE AddNewVersionn
    @ProcedureName NVARCHAR(100),
    @Parameters NVARCHAR(MAX)
AS
BEGIN
    DECLARE @NewVersion INT;
    -- Obține versiunea curentă
    SELECT @NewVersion = VersionNumber FROM CurrentVersion;

    -- Crește versiunea pentru a o incrementa
    SET @NewVersion = @NewVersion + 1;

    -- Introduce un nou rând în tabelul VersionHistory
    INSERT INTO VersionHistory (VersionNumber, ProcedureExecuted, Parameters)
    VALUES (@NewVersion, @ProcedureName, @Parameters);

    -- Actualizează tabelul CurrentVersion cu noua versiune
    UPDATE CurrentVersion
    SET VersionNumber = @NewVersion;
END;
GO


--
CREATE OR ALTER PROCEDURE RollbackToVersionnn
    @TargetVersion INT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @CurrentVersion INT;
    DECLARE @ProcedureName NVARCHAR(100);
    DECLARE @Parameters NVARCHAR(MAX);

    -- Obține versiunea curentă din tabela CurrentVersion
    SELECT @CurrentVersion = VersionNumber FROM CurrentVersion;

    -- Execută rollback până când versiunea curentă corespunde versiunii țintă
    WHILE @CurrentVersion > @TargetVersion
    BEGIN
        -- Obține ultima procedură executată și parametrii
        SELECT TOP 1 
            @ProcedureName = ProcedureName, 
            @Parameters = Parameters
        FROM VersionHistory
        WHERE VersionNumber = @CurrentVersion
        ORDER BY VersionNumber DESC;

        -- Execută rollback pe baza numelui procedurii
        IF @ProcedureName = 'ModifyColumnType'
        BEGIN
            DECLARE @TableName NVARCHAR(50), @ColumnName NVARCHAR(50), @OldDataType NVARCHAR(50);
            -- Descompune parametrii pentru a obține valorile necesare
            SELECT 
                @TableName = PARSENAME(@Parameters, 3),
                @ColumnName = PARSENAME(@Parameters, 2),
                @OldDataType = PARSENAME(@Parameters, 1);

            EXEC RollbackModifyColumnType @TableName, @ColumnName, @OldDataType;
        END
        ELSE IF @ProcedureName = 'AddDefaultConstraint'
        BEGIN
            DECLARE @TableName2 NVARCHAR(50), @ConstraintName NVARCHAR(50);
            SELECT 
                @TableName2 = PARSENAME(@Parameters, 2),
                @ConstraintName = PARSENAME(@Parameters, 1);

            EXEC RollbackAddDefaultConstraint @TableName2, @ConstraintName;
        END
        ELSE IF @ProcedureName = 'CreateNewTable'
        BEGIN
            DECLARE @TableName3 NVARCHAR(50);
            SELECT @TableName3 = @Parameters;

            EXEC RollbackCreateNewTable @TableName3;
        END
        ELSE IF @ProcedureName = 'AddColumnToTable'
        BEGIN
            DECLARE @TableName4 NVARCHAR(50), @ColumnName2 NVARCHAR(50);
            SELECT 
                @TableName4 = PARSENAME(@Parameters, 2),
                @ColumnName2 = PARSENAME(@Parameters, 1);

            EXEC RollbackAddColumnToTable @TableName4, @ColumnName2;
        END
        ELSE IF @ProcedureName = 'AddForeignKeyConstraint'
        BEGIN
            DECLARE @TableName5 NVARCHAR(50), @ConstraintName2 NVARCHAR(50);
            SELECT 
                @TableName5 = PARSENAME(@Parameters, 2),
                @ConstraintName2 = PARSENAME(@Parameters, 1);

            EXEC RollbackAddForeignKeyConstraint @TableName5, @ConstraintName2;
        END

        -- Scade versiunea curentă
        SET @CurrentVersion = @CurrentVersion - 1;

        -- Actualizează tabela CurrentVersion
        UPDATE CurrentVersion
        SET VersionNumber = @CurrentVersion;
    END
END;
GO






-- EXAMPLE USAGE
-- Adding new version entries
EXEC AddNewVersion 'ModifyColumnType', 'Employee, salary, DECIMAL(10, 2)';
EXEC AddNewVersion 'AddDefaultConstraint', 'Employee, inventory_id, 0, DF_Employee_InventoryID';
EXEC AddNewVersion 'CreateNewTable', 'Supplier, supplier_id INT PRIMARY KEY, name VARCHAR(50)';
EXEC AddNewVersion 'AddColumnToTable','Employee, phone_number VARCHAR(15)';
EXEC AddNewVersion 'AddForeignKeyConstraint', 'Employee, departament_id, Departament, departament_id, FK_Employee_Departament';

SELECT * FROM VersionHistory;
SELECT * FROM DatabaseVersion;


-- Rolling back to version 2
EXEC RollbackToVersionnn @TargetVersion = 12;


ALTER TABLE VersionHistory
ADD ProcedureName NVARCHAR(100);

SELECT TOP 1 @ProcedureName = ProcedureName, @Parameters = Parameters
FROM VersionHistory
WHERE VersionNumber = @CurrentVersion
ORDER BY VersionNumber DESC;

