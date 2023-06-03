CREATE VIEW v_symmetric_union AS
WITH
R AS (SELECT * FROM person_visits AS R WHERE visit_date = '2022-01-02'),
S AS (SELECT * FROM person_visits AS S WHERE visit_date = '2022-01-06')
SELECT * FROM R EXCEPT SELECT * FROM S
UNION ALL
SELECT * FROM S EXCEPT SELECT * FROM R
ORDER BY person_id;
