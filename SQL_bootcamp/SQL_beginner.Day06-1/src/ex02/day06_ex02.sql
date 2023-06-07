SELECT person.name AS name, pizza_name, price, (price - price * discount / 100) AS discount_price, pizzeria.name AS pizzeria_name
FROM person
JOIN person_discounts ON person.id = person_discounts.person_id
JOIN pizzeria ON person_discounts.pizzeria_id = pizzeria.id
JOIN menu ON pizzeria.id = menu.pizzeria_id
JOIN person_order ON menu.id = person_order.menu_id
WHERE person.id = person_order.person_id
ORDER BY name, pizza_name;
