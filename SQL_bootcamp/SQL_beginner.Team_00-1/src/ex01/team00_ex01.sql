with recursive routes as (
    select point_1 as way,
    point_1, point_2, cost
    from nodes
    where point_1 = 'a'
    union all
    select parent.way ||  ',' || child.point_1 as trace,
    child.point_1, child.point_2, parent.cost + child.cost
    from nodes as child
    join routes as parent on child.point_1 = parent.point_2
    where way not like '%' || child.point_1 || '%'
)

select cost as total_cost, 
'{' || way || ',a}' as tour
from routes 
where length(way) = 7
and point_2 = 'a'
and cost = (select min(cost) 
from routes where length(way) = 7
and point_2 = 'a')
union
select cost as total_cost, 
'{' || way || ',a}' as tour
from routes 
where length(way) = 7
and point_2 = 'a'
and cost = (select max(cost) 
from routes where length(way) = 7
and point_2 = 'a')
order by 1, 2;
