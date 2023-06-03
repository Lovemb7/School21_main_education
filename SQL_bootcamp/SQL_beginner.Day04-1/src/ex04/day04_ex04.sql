CREATE VIEW v_symmetric_union AS
WITH
R AS (SELECT person_id FROM person_visits WHERE visit_date = '2022-01-02'),
S AS (SELECT person_id FROM person_visits WHERE visit_date = '2022-01-06')
SELECT person_id FROM (
SELECT * FROM R EXCEPT SELECT * FROM S) as table1
UNION
SELECT person_id FROM (
SELECT * FROM S EXCEPT SELECT * FROM R) as table2
ORDER BY person_id;
