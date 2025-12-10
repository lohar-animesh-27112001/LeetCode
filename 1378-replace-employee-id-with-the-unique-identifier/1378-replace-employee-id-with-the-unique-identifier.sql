# Write your MySQL query statement below
SELECT eUNI.unique_id, e.name
FROM Employees AS e LEFT JOIN EmployeeUNI as eUNI
ON e.id = eUNI.id;