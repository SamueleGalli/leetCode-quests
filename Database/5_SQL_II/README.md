# SQL II

The **Keywords** i encountered in this section are:

| **KEYWORD**               | **DEFINITION**                                                                                               |
| :------------------------ | :----------------------------------------------------------------------------------------------------------- |
| `MAX(Expression)`         | Returns the **Maximum Value Non-Null** from a specified **Expression**                                       |
| `(...) IN (Subquery)`     | Checks whether a **Value** or a **List Of Values** _matches_ one of the results returned by the **Subquery** |
| `UNIQUE`                  | Prevents **duplicate values** in a **column** and may allow `NULL` values                                    |
| `COALESCE(columns,value)` | Replaces **NULL values** in a column with a specified _value_                                                |

## Common Table Expressions (CTEs)

Creates a named **temporary result** set that can be referenced within the main _SQL statement_

```sql
WITH name AS (
    Subquery
)
```

Creates a recursive CTE, allowing a query to reference its own results

It consists of two parts:

- **ANCHOR:** Defines the **starting point** - _initial rows_
- **RECURSIVE PART:** Uses the **previous results** to generate new rows.

```sql
WITH RECURSIVE name AS (
    --ANCHOR
    Subquery

    UNION ALL

    --RECURSIVE PART
    Recursive_Subquery)
```

The recursion continues until the **Recursive Part**
returns no more rows
