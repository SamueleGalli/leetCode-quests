SELECT id, visit_date, people
FROM (
    SELECT *,
    ROW_NUMBER() OVER(ORDER BY id) AS this_row,
    LEAD(id,1) OVER(ORDER BY id) AS next_id,
    LEAD(id,2) OVER (Order BY id) AS next_2_id
    FROM Stadium) AS S
WHERE id - this_row = next_id - (this_row + 1) AND next_id - (this_row + 1) = next_2_id - (this_row + 2) AND people >= 100
ORDER BY visit_date