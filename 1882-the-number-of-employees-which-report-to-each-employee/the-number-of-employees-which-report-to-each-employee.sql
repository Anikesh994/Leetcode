# Write your MySQL query statement below
SELECT manager.employee_id , manager.name , COUNT(emp.reports_to) AS reports_count , ROUND(AVG(emp.age)) AS average_age
FROM Employees emp join Employees manager
ON emp.reports_to = manager.employee_id
GROUP BY employee_id
ORDER BY employee_id
