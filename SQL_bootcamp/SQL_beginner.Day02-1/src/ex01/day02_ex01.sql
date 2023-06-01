SELECT    missing_date::                                                date
FROM      generate_series('2022-01-01', '2022-01-10', interval '1 day') AS missing_date
LEFT JOIN
          (
                 SELECT visit_date
                 FROM   person_visits
                 WHERE  person_id = 1
                 OR     person_id = 2) AS vd
ON        missing_date.missing_date = vd.visit_date
WHERE     visit_date isnull
ORDER BY  missing_date;
