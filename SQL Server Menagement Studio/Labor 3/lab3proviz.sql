--Modify column type
CREATE PROCEDURE ModifyColumnType
    @TableName VARCHAR(50),
    @ColumnName VARCHAR(50),
    @NewDataType VARCHAR(50)
AS
BEGIN
    DECLARE @SqlQuery VARCHAR(MAX)
    
    -- SQL-Anweisung, um den Datentyp zu andern
    SET @SqlQuery = 'ALTER TABLE ' + @TableName + 
                    ' ALTER COLUMN ' + @ColumnName + ' ' + @NewDataType;
    
    EXEC(@SqlQuery);
END
GO
EXEC ModifyColumnType 'Inventory', 'quantity', 'DECIMAL(10, 2)';

--Rollback
CREATE PROCEDURE RollbackModifyColumnType
    @TableName VARCHAR(50),
    @ColumnName VARCHAR(50),
    @OldDataType VARCHAR(50)
AS
BEGIN
    DECLARE @SqlQuery VARCHAR(MAX)
    
    -- 1. Salvam valorile coloanei într-o tabela temporara
    SET @SqlQuery = 'SELECT ' + @ColumnName + ' INTO #Temp_' + @TableName + 
                    ' FROM ' + @TableName;
    EXEC(@SqlQuery);

    -- 2. Modificam coloana la tipul vechi
    SET @SqlQuery = 'ALTER TABLE ' + @TableName + 
                    ' ALTER COLUMN ' + @ColumnName + ' ' + @OldDataType;
    EXEC(@SqlQuery);

    -- 3. Restauram valorile din tabelul temporar
    SET @SqlQuery = 'UPDATE ' + @TableName + 
                    ' SET ' + @ColumnName + ' = t.' + @ColumnName +
                    ' FROM ' + @TableName + ' AS t ' +
                    ' INNER JOIN #Temp_' + @TableName + ' AS tmp ON t.' + @ColumnName + ' = tmp.' + @ColumnName;
    EXEC(@SqlQuery);

    -- 4. stergem tabelul temporar
    SET @SqlQuery = 'DROP TABLE #Temp_' + @TableName;
    EXEC(@SqlQuery);
END
GO
EXEC RollbackModifyColumnType 'Inventory', 'quantity', 'int';

--default constraint