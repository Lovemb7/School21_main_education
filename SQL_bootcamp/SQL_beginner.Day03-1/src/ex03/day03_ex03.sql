WITH male
     AS (SELECT pizzeria.name AS pizzeria_name
         FROM   person
                JOIN person_visits
                  ON person.id = person_visits.person_id
                JOIN pizzeria
                  ON person_visits.pizzeria_id = pizzeria.id
         WHERE  gender = 'male'),
     female
     AS (SELECT pizzeria.NAME AS pizzeria_name
         FROM   person
                JOIN person_visits
                  ON person.id = person_visits.person_id
                JOIN pizzeria
                  ON person_visits.pizzeria_id = pizzeria.id
         WHERE  gender = 'female'),
     only_male
     AS (SELECT *
         FROM   male
         EXCEPT ALL
         SELECT *
         FROM   female),
     only_female
     AS (SELECT *
         FROM   female
         EXCEPT ALL
         SELECT *
         FROM   male) SELECT pizzeria_name
FROM   only_male
UNION ALL
SELECT pizzeria_name
FROM   only_female
ORDER  BY pizzeria_name;
