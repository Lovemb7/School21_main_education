CREATE OR REPLACE FUNCTION func_minimum(VARIADIC arr numeric[]) RETURNS numeric AS $$
  DECLARE min_value numeric;
      BEGIN
      SELECT MIN(unnest) INTO min_value FROM unnest(arr);
      RETURN min_value;
      END;
$$ LANGUAGE plpgsql;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);
