CREATE OR REPLACE FUNCTION check_past_date(cur_date timestamp, cur_id integer)
RETURNS TABLE (curr_name varchar, rate_to_usd_my numeric) AS $$
    BEGIN
        RETURN QUERY
            SELECT name, rate_to_usd
            FROM (SELECT MAX(currency.updated) AS max_dt
                  FROM currency
                  WHERE cur_id = currency.id AND currency.updated <= cur_date
                  GROUP BY name) AS max_date
           JOIN currency ON max_date.max_dt = currency.updated;
    END;
    $$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION check_future_date(cur_date timestamp, cur_id integer)
RETURNS TABLE (curr_name varchar, rate_to_usd_my numeric) AS $$
    BEGIN
        RETURN QUERY
            SELECT name, rate_to_usd
            FROM (SELECT MIN(currency.updated) AS min_dt, name AS min_name
                  FROM currency
                  WHERE cur_id = currency.id AND currency.updated > cur_date
                  GROUP BY name) AS min_date
           JOIN currency ON min_date.min_dt = currency.updated AND min_date.min_name = currency.name;
    END;
    $$ LANGUAGE plpgsql;

SELECT COALESCE(name, 'not defined') AS name, COALESCE(lastname, 'not defined') AS lastname,
       (CASE WHEN (SELECT COUNT(*) FROM check_past_date(updated, currency_id)) = 1
        THEN (SELECT curr_name FROM check_past_date(updated, currency_id))
        ELSE (SELECT curr_name FROM check_future_date(updated, currency_id)) END) AS currency_name,
       ((CASE WHEN (SELECT COUNT(*) FROM check_past_date(updated, currency_id)) = 1
         THEN (SELECT rate_to_usd_my FROM check_past_date(updated, currency_id))
         ELSE (SELECT rate_to_usd_my FROM check_future_date(updated, currency_id)) END) *
                   balance.money) AS currency_in_usd
FROM "user"
FULL JOIN balance ON "user".id = balance.user_id
WHERE currency_id IN (SELECT id FROM currency)
ORDER BY name DESC, lastname ASC, currency_name ASC;
