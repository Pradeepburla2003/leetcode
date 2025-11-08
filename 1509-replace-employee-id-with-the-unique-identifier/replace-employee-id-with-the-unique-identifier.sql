select u.unique_id, e.name from employees as e left join EmployeeUNI as u on  e.id=u.id;
-- select * from employees;