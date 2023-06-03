INSERT INTO person_visits
(
	id,
	person_id,
	pizzeria_id,
	visit_date
)
VALUES
(
	22,
	9,
	5,
	'2022-01-08'
);
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
