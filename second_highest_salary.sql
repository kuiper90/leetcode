-- https://leetcode.com/problems/second-highest-salary/description/

SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary NOT IN (SELECT MAX(Salary) FROM Employee)
ORDER BY SecondHighestSalary DESC

SELECT MAX(Salary) AS SecondHighestSalary FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee)