with cte as(

SELECT

 Name,

 Country,

 Net_Worth,

 RANK() OVER(PARTITION BY Country ORDER BY Net_Worth DESC) as ranks

FROM richest_persons)

SELECT

Country,

SUM(Net_Worth)as Total_Net_Worth

FROM cte

WHERE ranks<=10

GROUP BY Country;

