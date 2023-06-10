CREATE OR REPLACE FUNCTION fnc_fibonacci(IN pstop INT DEFAULT 10) RETURNS SETOF int AS $$
    BEGIN
        RETURN QUERY (WITH RECURSIVE fib(Num, Prev) AS (
            SELECT 0, 1
            UNION ALL
            SELECT fib.Num + fib.Prev, fib.Num
            FROM fib
            WHERE fib.Num < pstop - fib.Prev)
        SELECT Num
        FROM fib);
    END;
$$ LANGUAGE plpgsql;

SELECT * FROM fnc_fibonacci(100);
SELECT * FROM fnc_fibonacci();
