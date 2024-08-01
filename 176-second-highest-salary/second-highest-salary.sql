SELECT 
    CASE 
        WHEN COUNT(distinct salary) < 2 THEN NULL
        ELSE (
            SELECT distinct salary
            FROM employee
            ORDER BY salary DESC
            LIMIT 1,1
        )
    END AS SecondHighestSalary
FROM employee;
