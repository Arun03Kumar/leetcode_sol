# Write your MySQL query statement below
select e.name as Employee from Employee as e join Employee as o on e.managerId = o.id where e.salary > o.salary 