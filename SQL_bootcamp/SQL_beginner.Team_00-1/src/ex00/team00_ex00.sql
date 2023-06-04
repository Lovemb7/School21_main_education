drop table nodes;

create table nodes (
    point_1 varchar not null, 
    point_2 varchar not null,
    cost integer not null
);

insert into nodes
values ('a', 'b', 10);
insert into nodes
values ('b', 'a', 10);
insert into nodes
values ('a', 'd', 20);
insert into nodes
values ('d', 'a', 20);
insert into nodes
values ('a', 'c', 15);
insert into nodes
values ('c', 'a', 15);
insert into nodes
values ('b', 'd', 25);
insert into nodes
values ('d', 'b', 25);
insert into nodes
values ('b', 'c', 35);
insert into nodes
values ('c', 'b', 35);
insert into nodes
values ('c', 'd', 30);
insert into nodes
values ('d', 'c', 30);

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
order by 1, 2;
