CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      # we will take one salary and compare it with all the salary if there will be N-1 salary which are greater than selected salary then that will be our Nth highest salary.

select distinct(e1.salary) from employee e1 where N-1=(select count(distinct salary) from employee e2 where e2.salary>e1.salary)
      
  );
END