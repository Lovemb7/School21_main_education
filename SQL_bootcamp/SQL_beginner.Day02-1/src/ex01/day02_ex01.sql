select missing_date::date
from generate_series('2022-01-01', '2022-01-10', interval '1 day') as missing_date
left join (select visit_date from person_visits
	where person_id = 1 or person_id = 2) as vd on missing_date.missing_date = vd.visit_date
where visit_date isnull
order by missing_date;
