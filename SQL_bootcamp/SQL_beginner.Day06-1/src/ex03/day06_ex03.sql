CREATE UNIQUE INDEX idx_person_discounts_unique ON person_discounts(person_id, pizzeria_id);
SET enable_seqscan = off;
SET enable_bitmapscan = off;

EXPLAIN ANALYZE
SELECT person_id, pizzeria_id
FROM person_discounts;
