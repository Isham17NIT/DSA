# Write your MySQL query statement below
WITH 
    cte1 AS (SELECT user_id, COUNT(movie_id) AS cnt
            FROM MovieRating
            GROUP BY user_id),
    cte2 AS (SELECT u.name AS results
            from cte1
            inner join Users AS u on cte1.user_id = u.user_id
            ORDER BY cte1.cnt DESC, u.name ASC
            LIMIT 1),
    cte3 AS (SELECT movie_id, AVG(rating) AS avg_rating
            FROM MovieRating
            WHERE created_at BETWEEN '2020-02-01' AND '2020-02-28'
            GROUP BY movie_id),
    cte4 AS (SELECT m.title AS results
            FROM cte3
            INNER JOIN Movies AS m ON m.movie_id=cte3.movie_id
            ORDER BY cte3.avg_rating DESC, m.title ASC
            LIMIT 1)
    SELECT *
    FROM cte2
    UNION ALL
    SELECT *
    FROM cte4;