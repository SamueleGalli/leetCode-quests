SELECT result.id, result.visit_date, result.people
FROM (
        SELECT  Stadium.id, Stadium.visit_date, Stadium.people,
                S_next.people AS next_people , S_2_next.people AS next_2_people,
                S_prev.people AS prev_people, S_2_prev.people AS prev_2_people
        FROM Stadium
        LEFT JOIN Stadium AS S_next ON Stadium.id + 1 = S_next.id
        LEFT JOIN Stadium AS S_2_next ON Stadium.id + 2 = S_2_next.id
        LEFT JOIN Stadium AS S_prev ON Stadium.id - 1 = S_prev.id
        LEFT JOIN Stadium AS S_2_prev ON Stadium.id - 2 = S_2_prev.id
        ) AS result
WHERE   people >= 100 AND
        (
            (--FIND the next ones
            result.next_people >= 100 AND
            result.next_2_people >= 100
            ) OR
            (--FIND the prvious one
            result.prev_people >= 100 AND
            result.prev_2_people >= 100
            ) OR
            (--FIND the midlle one
            result.next_people >= 100 AND
            result.prev_people >= 100
            )
        )
ORDER BY visit_date