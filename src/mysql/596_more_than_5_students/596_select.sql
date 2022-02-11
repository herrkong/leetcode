
SELECT class    
FROM 
    (SELECT class ,COUNT(DISTINCT student) AS NUM 
        FROM courses
    GROUP BY class)AS temp_table 
WHERE 
    NUM >= 5;
