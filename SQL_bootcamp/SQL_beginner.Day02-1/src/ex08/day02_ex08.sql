select name
from (select *
	from (select name, id
		from person
		where (address = 'Moskow' or address = 'Samara') and gender = 'male') as p
	join person_order on p.id = person_order.person_id) as p_ord
join menu on p_ord.menu_id = menu.id
where pizza_name = 'pepperoni pizza' or pizza_name = 'mushroom pizza'
order by name desc;

select name
from person
join person_order on person.id = person_order.person_id
join menu on menu.id = person_order.menu_id
where person.gender = 'male' and (person.address = 'Moskow' or person.address = 'Samara') and (menu.pizza_name = 'mushroom pizza' or menu.pizza_name = 'pepperoni pizza')
order by name desc;
