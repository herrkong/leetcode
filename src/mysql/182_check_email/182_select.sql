

SELECT Email 
FROM
    (SELECT Email,COUNT(Email) AS Num FROM Person GROUP BY Email) AS temp_table
WHERE 
    Num > 1;