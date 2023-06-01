select name
from (select pizza_name, Dm_vs.pizzeria_id
	from (select pizzeria_id
		from (select id
			from person
			where name = 'Dmitriy') as Dm_id
			join person_visits on dm_id.id = person_visits.person_id
			where visit_date = '2022-01-08') as Dm_vs
		join menu on Dm_vs.pizzeria_id = menu.pizzeria_id
		where prize < 800) as Dm_pz
join pizzeria on Dm_pz.pizzeria_id = pizzeria.id;

select pizzeria.name
from person as ps
join person_visits on ps.id = person_visits.person_id
join pizzeria on person_visits.pizzeria_id = pizzeria.id
join menu on pizzeria.id = menu.pizzeria_id
where ps.name = 'Dmitriy' and person_visits.visit_date = '2022-01-08' and menu.price < 800;
