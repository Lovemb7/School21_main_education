WITH femail
     AS (SELECT pizzeria.name AS pizzeria_name
         FROM   person
                JOIN person_order
                  ON person.id = person_order.person_id
                JOIN menu
                  ON person_order.menu_id = menu.id
                JOIN pizzeria
                  ON menu.pizzeria_id = pizzeria.id
         WHERE  gender = 'female'),
     male
     AS (SELECT pizzeria.NAME AS pizzeria_name
         FROM   person
                JOIN person_order
                  ON person.id = person_order.person_id
                JOIN menu
                  ON person_order.menu_id = menu.id
                JOIN pizzeria
                  ON menu.pizzeria_id = pizzeria.id
         WHERE  gender = 'male'),
     only_female
     AS (SELECT *
         FROM   femail
         EXCEPT
         SELECT *
         FROM   male),
     only_male
     AS (SELECT *
         FROM   male
         EXCEPT
         SELECT *
         FROM   femail) SELECT pizzeria_name
FROM   only_female
UNION
SELECT pizzeria_name
FROM   only_male; 
