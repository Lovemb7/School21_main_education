CREATE INDEX idx_person_name ON person USING btree(UPPER(name));
SET unable_seqscan = off;

EXPLAIN ANALYZE
SELECT name
FROM person
WHERE UPPER(name) IS NOT NULL;
