--ex1 
CREATE TABLE Ta (
    idA INT PRIMARY KEY,
    a2 INT UNIQUE,
    a3 INT
);
 
CREATE TABLE Tb (
    idB INT PRIMARY KEY,
    b2 INT,
    b3 INT
);
 
CREATE TABLE Tc (
    idC INT PRIMARY KEY,
    idA INT,
    idB INT,
    FOREIGN KEY (idA) REFERENCES Ta(idA),
    FOREIGN KEY (idB) REFERENCES Tb(idB)
);
 

CREATE PROCEDURE PopulareTabele
AS
BEGIN
    SET NOCOUNT ON;
 
    -- Golirea tabelelor folosind DELETE
    DELETE FROM Tc;
    DELETE FROM Tb;
    DELETE FROM Ta;
 
    DECLARE @i INT = 1; -- contor pt bucle
  --variabila pt stocarea valorilor generate aleator
    DECLARE @randA INT, @randB INT;
 
    -- Populare Ta cu 10.000 de randuri
    WHILE @i <= 10000
    BEGIN
        -- Generam un nr aleator pt a3 si valoare unica pt a2
        SET @randA = FLOOR(RAND() * 10000); 
        INSERT INTO Ta (idA, a2, a3)
        VALUES (@i, @i * 10, FLOOR(RAND() * 10000));-- a2 este unic prin formula `@i * 10'
        SET @i = @i + 1; -- incrementam contorul
    END;
 
    -- Resetare contor
    SET @i = 1;
 
    -- Populare Tb cu 3.000 de randuri
    WHILE @i <= 3000
    BEGIN
    -- generam un nr aleator pt 'b2'
        SET @randB = FLOOR(RAND() * 10000); -- Generare nr aleator pentru b2
        INSERT INTO Tb (idB, b2, b3)
        -- Valorile sunt generate aleator pentru b2 si b3
    VALUES (@i, @randB, FLOOR(RAND() * 10000));
        SET @i = @i + 1; -- incrementam contorul
  END;
 
    -- Resetare contor
    SET @i = 1;
 
    -- Populare Tc cu 30.000 de randuri
    WHILE @i <= 30000
    BEGIN
    -- Generam chei externe aleatoare care refera Ta si Tb
        INSERT INTO Tc (idC, idA, idB)
        VALUES (
            @i,
            FLOOR(RAND() * 10000) + 1, -- idA este un nr intre 1 si 10.000
            FLOOR(RAND() * 3000) + 1   -- idB este un nr intre 1 si 3.000
        );
        SET @i = @i + 1; -- incrementam contorul
    END;
 
    SET NOCOUNT OFF;
END;
 
 
EXEC PopulareTabele;
 
 
SELECT COUNT(*) FROM Ta;
SELECT COUNT(*) FROM Tb;
SELECT COUNT(*) FROM Tc;
 
 
--a
-- Index la tabela TA
SELECT * 
FROM sys.indexes
WHERE object_id = OBJECT_ID('Ta');
 
--Clustered Index Scan
SELECT * 
FROM Ta
WHERE a3 > 9990;
 
--Clustered Index Seek
SELECT * 
FROM Ta
WHERE idA = 5000;
 
--Nonclustered Index Scan
SELECT * 
FROM Ta
WHERE a2 BETWEEN 1000 AND 2000;
 
--Nonclustered Index Seek
SELECT * 
FROM Ta
WHERE a2 = 10000;
 
--b
SELECT idA, a2
FROM Ta
WHERE a3 = 500;
 
--c 
SELECT * 
FROM Tb
WHERE b2 = 40;
 
CREATE NONCLUSTERED INDEX idx_b2 ON Tb (b2);
 
DROP INDEX idx_b2 ON Tb;
 
SELECT * 
FROM Tb
WHERE b2 = 40;
 
--d
SELECT Tc.idC, Ta.a2 
FROM Tc
INNER JOIN Ta ON Tc.idA = Ta.idA
WHERE Tc.idA = 1000;
 
SELECT Tc.idC, Tb.b2
FROM Tc
INNER JOIN Tb ON Tc.idB = Tb.idB
WHERE Tc.idB = 2000;
 
 
CREATE NONCLUSTERED INDEX idx_idA ON Tc (idA);
CREATE NONCLUSTERED INDEX idx_idB ON Tc (idB);