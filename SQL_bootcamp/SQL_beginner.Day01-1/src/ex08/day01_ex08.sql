SELECT order_date,
       CONCAT(name, ' (age:', age, ')') AS person_information
FROM   person_order
       natural JOIN (SELECT id AS person_id,
                            NAME,
                            age
                     FROM   person) AS person_new
ORDER  BY order_date,
          person_information; 
