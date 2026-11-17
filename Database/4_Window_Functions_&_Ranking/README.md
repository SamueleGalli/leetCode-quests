# Window Functions & Ranking

This section introduces **Window Functions**, which perform calculations across a set of related **Rows**, using the current **Row** as a reference, without grouping or removing the original **Rows** from the result

The **Keywords** i encountered in this section are:

| **KEYWORD** | **REQUIRE OVER()?** | **DEFINITION** |
| :--- | :--- | :--- |
| `Lead(value, offset, default)` | **YEST** | Retrieves a **Value** from a following **Row**, `offset` specifies how many Rows ahead to look, while `default` specifies what to return if the requested Row does not exist |
| `DENSE_RANK()` | **YES** | Assigns an increasing **Rank** based on the specified **Order**, giving the same Rank to equal Values without leaving gaps |
| `ROUND(value, decimals)` | **NO** | Rounds a numeric **Value** to the specified number of **Decimal Places** |

- `OVER()` -> Defines the **Window** of Rows used by a **Window Function**
