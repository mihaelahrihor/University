CREATE TABLE Ta (
    idA INT IDENTITY(1,1) PRIMARY KEY,
    a2 INT UNIQUE,
    a3 INT
);

CREATE TABLE Tb (
    idB INT IDENTITY(1,1) PRIMARY KEY,
    b2 INT,
    b3 INT
);

CREATE TABLE Tc (
    idC INT IDENTITY(1,1) PRIMARY KEY,
    idA INT,
    idB INT,
    FOREIGN KEY (idA) REFERENCES Ta(idA),
    FOREIGN KEY (idB) REFERENCES Tb(idB)
);

CREATE PROCEDURE InsertData
AS
BEGIN
    SET NOCOUNT ON;

    -- 
    DECLARE @i INT = 1;
    WHILE @i <= 10000
    BEGIN
        INSERT INTO Ta (a2, a3) VALUES (@i * 10, ABS(CHECKSUM(NEWID())) % 1000);
        SET @i = @i + 1;
    END;

    -- 
    DECLARE @j INT = 1;
    WHILE @j <= 3000
    BEGIN
        INSERT INTO Tb (b2, b3) VALUES (@j * 5, ABS(CHECKSUM(NEWID())) % 500);
        SET @j = @j + 1;
    END;

    --
    DECLARE @k INT = 1;
    WHILE @k <= 30000
    BEGIN
        INSERT INTO Tc (idA, idB) VALUES (
            1 + ABS(CHECKSUM(NEWID())) % 10000, 
            1 + ABS(CHECKSUM(NEWID())) % 3000  
        );
        SET @k = @k + 1;
    END;
END;

EXEC InsertData;

--ex2
-- a
SELECT 
    t.name AS TableName,
    i.name AS IndexName,
    i.type_desc AS IndexType,
    c.name AS ColumnName
FROM 
    sys.indexes i
INNER JOIN 
    sys.index_columns ic ON i.object_id = ic.object_id AND i.index_id = ic.index_id
INNER JOIN 
    sys.columns c ON ic.object_id = c.object_id AND ic.column_id = c.column_id
INNER JOIN 
    sys.tables t ON i.object_id = t.object_id
WHERE 
    t.name = 'Ta';


CREATE NONCLUSTERED INDEX idx_a3 ON Ta(a3);


--scan clustered
SELECT * FROM Ta;

--seek clustered
SELECT * FROM Ta WHERE idA = 500;

--nonclustered scan
SELECT a3 FROM Ta WHERE a3 < 50;

--nonclustered seek
SELECT a3 FROM Ta WHERE a3 = 100;

--b
CREATE NONCLUSTERED INDEX idx_a2 ON Ta(a2);

SELECT idA, a3 
FROM Ta 
WHERE a2 = 50;

--c
SELECT * 
FROM Tb 
WHERE b2 = 100;

CREATE NONCLUSTERED INDEX idx_b2 ON Tb(b2);

--d
SELECT Tc.idC, Ta.a2, Ta.a3
FROM Tc
INNER JOIN Ta ON Tc.idA = Ta.idA
WHERE Ta.a2 = 100;

SELECT Tc.idC, Tb.b2, Tb.b3
FROM Tc
INNER JOIN Tb ON Tc.idB = Tb.idB
WHERE Tb.b2 = 50;

CREATE NONCLUSTERED INDEX idx_idA ON Tc(idA);

CREATE NONCLUSTERED INDEX idx_idB ON Tc(idB);


SELECT Tc.idC, Ta.a2, Ta.a3
FROM Tc
INNER JOIN Ta ON Tc.idA = Ta.idA
WHERE Ta.a2 = 100;

SELECT Tc.idC, Tb.b2, Tb.b3
FROM Tc
INNER JOIN Tb ON Tc.idB = Tb.idB
WHERE Tb.b2 = 50;













