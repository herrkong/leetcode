


-- CREATE TABLE  Customers 
--     (Id INT NOT NULL PRIMARY KEY,
--     Name VARCHAR(50) NOT NULL )

CREATE TABLE  Orders 
    (Id INT NOT NULL PRIMARY KEY,
    CustomerId INT NOT NULL )

-- Customers 表：

-- +----+-------+
-- | Id | Name  |
-- +----+-------+
-- | 1  | Joe   |
-- | 2  | Henry |
-- | 3  | Sam   |
-- | 4  | Max   |
-- +----+-------+
-- Orders 表：

-- +----+------------+
-- | Id | CustomerId |
-- +----+------------+
-- | 1  | 3          |
-- | 2  | 1          |
-- +----+------------+
-- 例如给定上述表格，你的查询应返回：

-- +-----------+
-- | Customers |
-- +-----------+
-- | Henry     |
-- | Max       |