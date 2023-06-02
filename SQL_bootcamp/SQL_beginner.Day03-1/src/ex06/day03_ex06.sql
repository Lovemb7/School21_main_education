WITH p1
     AS (SELECT pizza_name,
                pizzeria.name AS pizzeria_name_1,
                price,
                pizzeria.id
         FROM   pizzeria
                JOIN menu
                  ON pizzeria.id = menu.pizzeria_id),
     p2
     AS (SELECT pizza_name,
                pizzeria.name AS pizzeria_name_2,
                price,
                pizzeria.id
         FROM   pizzeria
                JOIN menu
                  ON pizzeria.id = menu.pizzeria_id)
SELECT p1.pizza_name,
       pizzeria_name_1,
       pizzeria_name_2,
       p1.price
FROM   p1,
       p2
WHERE  p1.pizza_name = p2.pizza_name
       AND p1.price = p2.price
       AND p1.id > p2.id
ORDER  BY pizza_name; 
