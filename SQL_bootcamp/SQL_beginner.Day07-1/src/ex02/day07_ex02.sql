SELECT name, count, action_type
FROM ((SELECT pizzeria_id, COUNT(*) AS count, 'visit' AS action_type
       FROM person_visits
       GROUP BY pizzeria_id
       ORDER BY count DESC
       LIMIT 3)
       UNION
      (SELECT pizzeria_id, COUNT(*) AS count, 'order' AS action_type
       FROM person_order
       JOIN menu ON person_order.menu_id = menu.id
       GROUP BY pizzeria_id
       ORDER BY count DESC
       LIMIT 3)) AS new_table
JOIN pizzeria ON new_table.pizzeria_id = pizzeria.id
ORDER BY action_type ASC, count DESC;
