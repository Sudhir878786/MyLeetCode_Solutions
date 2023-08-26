# Write your MySQL query statement below
SELECT S.Score, COUNT(S2.Score) AS `Rank` FROM Scores S,
(SELECT DISTINCT Score FROM Scores) S2
WHERE S.Score<=S2.Score
GROUP BY S.Id
order by S.Score DESC;