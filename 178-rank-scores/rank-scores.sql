# Write your MySQL query statement below
select score,rnk as 'rank'
from(
    select score,DENSE_RANK() over(order by score desc) as rnk
    from Scores
)t
order by score desc;
;