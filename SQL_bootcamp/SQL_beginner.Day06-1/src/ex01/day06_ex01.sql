INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
SELECT row_number() over () AS id,
		po.person_id,
		m.pizzeria_id,
		(CASE WHEN COUNT(*) = 1 THEN 10.5
			WHEN COUNT(*) = 2 THEN 22
			ELSE 30 END) AS discount
FROM person_order AS po
JOIN menu AS  m ON po.menu_id = m.id
GROUP BY po.person_id, m.pizzeria_id;
