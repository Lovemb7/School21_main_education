CREATE UNIQUE INDEX idx_menu_unique ON menu USING btree(pizzeria_id, pizza_name);

EXPLAIN ANALYZE
SELECT pizzeria_id, pizza_name FROM menu;
