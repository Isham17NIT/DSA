# Write your MySQL query statement below
WITH 
    cte1 AS (SELECT u.name AS results, COUNT(mr.movie_id) AS cnt
            FROM MovieRating AS mr
            INNER JOIN Users AS u ON u.user_id=mr.user_id
            GROUP BY u.user_id
            ORDER BY cnt DESC, u.name ASC
            LIMIT 1),
    cte2 AS (SELECT m.title AS results, AVG(mr.rating) AS avg_rating
            FROM MovieRating AS mr
            INNER JOIN Movies AS m ON m.movie_id=mr.movie_id
            WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-28'
            GROUP BY m.movie_id
            ORDER BY avg_rating DESC, m.title ASC
            LIMIT 1)
    SELECT results
    FROM cte1
    UNION ALL #doesn't avoid duplicates
    SELECT results
    FROM cte2;