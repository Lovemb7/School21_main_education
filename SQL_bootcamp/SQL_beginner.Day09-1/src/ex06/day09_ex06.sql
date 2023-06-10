CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(IN pperson varchar DEFAULT 'Dmitriy',
      IN pprice numeric DEFAULT 500, IN pdate date DEFAULT '2022-01-08') RETURNS SETOF varchar AS $$
        BEGIN
        RETURN QUERY (SELECT DISTINCT pizzeria.name
        FROM person
        JOIN person_visits ON person.id = person_visits.person_id
        JOIN person_order ON person.id = person_order.person_id
        JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
        JOIN menu ON person_order.menu_id = menu.id
        WHERE person.name = pperson AND price < pprice AND person_order.order_date = pdate AND
            person_visits.visit_date = pdate AND person_visits.pizzeria_id = menu.pizzeria_id);
        END;
$$ LANGUAGE plpgsql;


SELECT *
FROM fnc_person_visits_and_eats_on_date(pprice := 800);

SELECT *
FROM fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');
