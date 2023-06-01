SELECT pizza_name,
       pizzeria.name AS pizzeria_name
FROM   ((SELECT *
        FROM   person_order
               JOIN person
                 ON person_order.person_id = person.id
        WHERE  name = 'Denis'
                OR name = 'Anna') AS po
        JOIN menu
          ON po.menu_id = menu.id) AS po1
       JOIN pizzeria
         ON po1.pizzeria_id = pizzeria.id
ORDER  BY pizza_name,
          pizzeria_name; 
