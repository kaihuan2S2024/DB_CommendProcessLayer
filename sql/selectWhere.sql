select * from users;

select name from users
where name='Richard' AND UserID=0;

select UserID,name from users
where name='Max' AND UserID=1;

select * from users
where name='Ming' AND email='Ming@gmail.com';

select * from users
where name='Mike' OR name='Richard';

select * from users
where email LIKE '%@gmail.com';

exit;