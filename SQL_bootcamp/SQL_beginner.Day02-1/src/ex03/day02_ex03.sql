with period as (
	select cast(pv as date) as missing_date
	from generate_series('2022-01-01'::timestamp, '2022-01-10', '1 day') as pv), 
	dates as (
		select visit_date
		from person_visits
		where person_id = 1 or person_id = 2)
	select missing_date
	from period
	left join dates on visit_date = missing_date
	where visit_date isnull
	order by visit_date;
