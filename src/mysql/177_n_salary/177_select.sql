


-- SELECT
-- (SELECT distinct salary  
--     FROM Employee
--     ORDER BY salary DESC LIMIT 1 offset 1) as SecondHighestSalary ;



CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N := N-1;
  RETURN (
      SELECT 
            salary
      FROM 
            Employee
      GROUP BY 
            salary
      ORDER BY 
            salary DESC
      LIMIT N, 1
  );
END



