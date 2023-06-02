WITH visit_pz
     AS (SELECT pizzeria.NAME AS pizzeria_name
         FROM   person
                JOIN person_visits
                  ON person.id = person_visits.person_id
                JOIN pizzeria
                  ON person_visits.pizzeria_id = pizzeria.id
         WHERE  person.name = 'Andrey'),
     order_pz
     AS (SELECT pizzeria.name AS pizzeria_name
         FROM   person
                JOIN person_order
                  ON person.id = person_order.person_id
                JOIN menu
                  ON person_order.menu_id = menu.id
                JOIN pizzeria
                  ON menu.pizzeria_id = pizzeria.id
         WHERE  person.name = 'Andrey'),
     v_o
     AS (SELECT *
         FROM   visit_pz
         EXCEPT
         SELECT *
         FROM   order_pz),
     o_v
     AS (SELECT *
         FROM   order_pz
         EXCEPT
         SELECT *
         FROM   visit_pz) SELECT pizzeria_name
FROM   v_o
UNION
SELECT pizzeria_name
FROM   o_v
ORDER  BY pizzeria_name;
