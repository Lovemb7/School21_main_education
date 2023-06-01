select name
from person
join person_order on person.id = person_order.person_id
join menu on person_order.menu_id = menu.id
where gender = 'female' and (pizza_name = 'pepperoni pizza' or pizza_name = 'cheese pizza')
group by name
having count(*) > 1
order by name;
