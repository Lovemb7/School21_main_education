CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
SELECT pizzeria.name
FROM   person AS ps
       JOIN person_visits
         ON ps.id = person_visits.person_id
       JOIN pizzeria
         ON person_visits.pizzeria_id = pizzeria.id
       JOIN menu
         ON pizzeria.id = menu.pizzeria_id
WHERE  ps.name = 'Dmitriy'
       AND person_visits.visit_date = '2022-01-08'
       AND menu.price < 800;
