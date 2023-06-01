SELECT name
FROM   (SELECT pizza_name,
               Dm_vs.pizzeria_id
        FROM   (SELECT pizzeria_id
                FROM   (SELECT id
                        FROM   person
                        WHERE  name = 'Dmitriy') AS Dm_id
                       JOIN person_visits
                         ON dm_id.id = person_visits.person_id
                WHERE  visit_date = '2022-01-08') AS Dm_vs
               JOIN menu
                 ON Dm_vs.pizzeria_id = menu.pizzeria_id
        WHERE  price < 800) AS Dm_pz
       JOIN pizzeria
         ON Dm_pz.pizzeria_id = pizzeria.id;

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
