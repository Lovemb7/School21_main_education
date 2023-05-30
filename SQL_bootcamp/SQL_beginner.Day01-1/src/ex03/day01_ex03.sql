SELECT order_date,
       person_id
FROM   person_order
UNION
SELECT visit_date,
       person_id
FROM   person_visits
ORDER  BY order_date,
          person_id DESC; 
