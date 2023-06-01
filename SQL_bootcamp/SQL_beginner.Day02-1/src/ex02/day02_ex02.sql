select coalesce(person.name, '-') person_name,
	coalesce(to_char(pv.visit_date, 'YYYY-MM-DD'), 'null') as visit_date,
	coalesce(pl.name, '-') pizzeria_name
from person
full join (select * from person_visits
	where visit_date between '2022-01-01' and '2022-01-03') as pv
	on person.id = pv.person_id
full join (select id, name
	from pizzeria) as pl
	on pv.pizzeria_id = pl.id
order by person_name, visit_date, pizzeria_name;
