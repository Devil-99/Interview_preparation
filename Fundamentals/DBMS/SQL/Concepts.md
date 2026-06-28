## Important SQL Concepts for Interview

### 1. Placeholder / Default values :
- **COALESCE** is the operator that is used to give a default value for any null value.

        SELECT
            p.id,
            p.name,
            COALESCE(a.city, 'Unknown') AS city,
            COALESCE(a.state, 'NA')     AS state
        FROM person p
        LEFT JOIN address a
            ON p.id = a.person_id;

- COALESCE returns the first non-null value.
    
### 2. What is the difference between "" and '' in SQL ?

- Double quotes are used for identifier (column alias).

        SELECT 
            E.name as "Employee"
        FROM Employee E

    - Renames the output column to Employee
    - Case-sensitive
    - Returned as a column header
    -  Without double quote, postgres defines <span style="color:yellow">Employee</span> as <span style="color:yellow">employee</span>

- Single quotes are for string values, not identifiers.
    - Used for string matching or printing something with case-sensitivity.

### 3. Conditional / Value matching parameter
- If we have to print all the values which doesn't contain a particular value in a column, we can use -

        WHERE column_name != 'string'

    But if that column contains null value then -
        WHERE column_name IS DISTINCT FROM 'string'