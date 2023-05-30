SELECT person_order.person_id
FROM   person_order
WHERE  order_date = '2022-01-07'
EXCEPT ALL
SELECT person_visits.person_id
FROM   person_visits
WHERE  visit_date = '2022-01-07'; 
