SELECT  id, 
        CASE
            WHEN p_id IS NULL
                THEN 'Root'
            WHEN EXISTS (
                SELECT 1
                FROM Tree AS leaf
                WHERE leaf.p_id = Tree.id
                ) THEN 'Inner'
            ELSE 'Leaf'
        END AS type
FROM Tree