SELECT name
FROM   (SELECT *
        FROM   (SELECT name,
                       id
                FROM   person
                WHERE  ( address = 'Moscow'
                          OR address = 'Samara' )
                       AND gender = 'male') AS p
               JOIN person_order
                 ON p.id = person_order.person_id) AS p_ord
       JOIN menu
         ON p_ord.menu_id = menu.id
WHERE  pizza_name = 'pepperoni pizza'
        OR pizza_name = 'mushroom pizza'
ORDER  BY name DESC;

SELECT name
FROM   person
       JOIN person_order
         ON person.id = person_order.person_id
       JOIN menu
         ON menu.id = person_order.menu_id
WHERE  person.gender = 'male'
       AND ( person.address = 'Moscow'
              OR person.address = 'Samara' )
       AND ( menu.pizza_name = 'mushroom pizza'
              OR menu.pizza_name = 'pepperoni pizza' )
ORDER  BY name DESC; 
