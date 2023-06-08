WITH new_table AS (
    SELECT address, round((MAX(CAST(age AS numeric(7,2))) -
                           ((MIN(CAST(age AS numeric(7,2)))) / MAX(CAST(age AS numeric(7,2))))), 2) AS formula,
           round(AVG(age), 2) AS average
    FROM person
    GROUP BY address)
SELECT address, formula, average, (formula > average) AS comparison
FROM new_table
ORDER BY address;
