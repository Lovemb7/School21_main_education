WITH t1 AS (

    SELECT id AS t1_id, name AS t1_name, MAX(updated) AS t1_updated
    FROM currency
    GROUP BY id, name
), t2 AS (
    SELECT DISTINCT id, name AS currency_name, rate_to_usd
    FROM currency
    JOIN t1 ON currency.updated = t1.t1_updated
), t3 AS (
    SELECT name, lastname, type, SUM(money) AS summ, currency_id
      FROM "user"
      FULL JOIN balance ON "user".id = balance.user_id
      GROUP BY name, lastname, type, currency_id
), t4 AS (SELECT name, lastname, type, summ AS volume, currency_name,
       (CASE WHEN rate_to_usd ISNULL THEN 1 ELSE rate_to_usd END) AS last_rate_to_usd
        FROM t3
        FULL JOIN t2 ON t2.id = t3.currency_id
        ORDER BY name DESC, lastname ASC, type ASC
)

SELECT COALESCE(name, 'not defined') AS name, COALESCE(lastname, 'not defined') AS lastname,
       type, volume, COALESCE(currency_name, 'not defined') AS currency_name, last_rate_to_usd,
       (volume * last_rate_to_usd) AS total_volume_in_usd
FROM t4
ORDER BY name DESC, lastname ASC, type ASC;
