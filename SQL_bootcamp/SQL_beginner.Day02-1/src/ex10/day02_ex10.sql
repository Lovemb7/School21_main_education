select p1.name as person_name1, p2.name as person_name2, p1.address as common_address
from person as p1
join person as p2 on p1.address = p2.address
where p1.id > p2.id
order by person_name1, person_name2, common_address;
