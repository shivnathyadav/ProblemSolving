# Write your MySQL query statement below
select W2.id from Weather as W1 , Weather as W2 where subdate(W2.recordDate , 1) = W1.recordDate and W1.temperature  < W2.temperature ;