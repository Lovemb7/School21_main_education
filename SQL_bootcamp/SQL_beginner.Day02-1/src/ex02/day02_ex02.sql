SELECT COALESCE(person.name, '-')                             person_name,
       COALESCE(To_char(pv.visit_date, 'YYYY-MM-DD'), 'null') AS visit_date,
       COALESCE(pl.name, '-')                                 pizzeria_name
FROM   person
       FULL JOIN (SELECT *
                  FROM   person_visits
                  WHERE  visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS pv
              ON person.id = pv.person_id
       FULL JOIN (SELECT id,
                         name
                  FROM   pizzeria) AS pl
              ON pv.pizzeria_id = pl.id
ORDER  BY person_name,
          visit_date,
          pizzeria_name; 
