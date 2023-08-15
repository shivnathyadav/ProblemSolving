# Write your MySQL query statement below
#LEFT TABLE COMPLETE USED IN LEFT OUTER JOIN
select unique_id,name from Employees LEFT OUTER JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id ;