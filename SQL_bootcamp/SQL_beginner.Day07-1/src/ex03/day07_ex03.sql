SELECT name, SUM(count) AS total_count
FROM ((SELECT pizzeria_id, COUNT(*) AS count
       FROM person_visits
       GROUP BY pizzeria_id)
       UNION ALL
      (SELECT pizzeria_id, COUNT(*) AS count
       FROM person_order
       JOIN menu ON person_order.menu_id = menu.id
       GROUP BY pizzeria_id)) AS new_table
JOIN pizzeria ON new_table.pizzeria_id = pizzeria.id
GROUP BY name
ORDER BY total_count DESC, name ASC;
