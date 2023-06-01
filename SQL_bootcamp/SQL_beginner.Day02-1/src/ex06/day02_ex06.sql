select pizza_name, pizzeria.name as pizzeria_name
from ((select *
	from person_order
	join person on person_order.person_id = person.id
	where name = 'Denis' or name = 'Anna') as po
	join menu on po.menu_id = menu.id) as po1
join pizzeria on po1.pizzeria_id = pizzeria.id
order by pizza_name, pizzeria_name;
