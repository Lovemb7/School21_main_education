WITH new_table AS (
    SELECT name, COUNT(*) AS count_of_visits
    FROM person_visits
    JOIN person ON person_visits.person_id = person.id
    GROUP BY name)
SELECT person.name, count_of_visits
FROM person
JOIN new_table ON person.name = new_table.name AND count_of_visits > 3;
