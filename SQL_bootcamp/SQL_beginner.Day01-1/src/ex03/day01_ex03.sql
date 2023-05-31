SELECT order_date AS action_date,
       person_id
FROM   person_order
UNION
SELECT visit_date,
       person_id
FROM   person_visits
ORDER  BY action_date,
          person_id DESC; 
