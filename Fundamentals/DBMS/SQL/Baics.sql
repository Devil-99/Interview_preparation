-- Create a table
CREATE TABLE Students (
  id INTEGER PRIMARY KEY,
  name VARCHAR(30) NOT NULL,
  gender CHAR(1) NOT NULL,
  roll_number INTEGER NOT NULL,
  CGPA DECIMAL(3,2)
);

-- Insert some values
INSERT INTO Students VALUES 
(1, 'Nilesh Chandra', 'M', 4005, 9.10),
(2, 'Souvik Maji', 'M', 4017, 8.40),
(3, 'Nilufa Islam', 'F', 4021, 9.45),
(4, 'SHreejeeb Kesh', 'M', 4023, 9.30),
(5, 'Akash Mondal', 'M', 5030, 8.70),
(6, 'Aryashree', 'F', 4050, 8.25),
(7, 'Apurba Mondal', 'M', 4051, 8.10),
(8, 'Siddhant Singh', 'M', 6028, 8.30);

-- Add new Column
ALTER TABLE Students ADD department VARCHAR(5);

-- Update new data (Attribute specific and tuple specific)
UPDATE Students SET department="CSE";
UPDATE Students SET department="ECE" WHERE id=5;
UPDATE Students SET department="IT" WHERE id=8;

-- ALTER TABLE Students DROP COLUMN gender;

-- fetch All
SELECT * FROM Students;

-- Conditional
SELECT name FROM Students WHERE CGPA >9;

-- Sort
SELECT name FROM Students ORDER BY CGPA DESC;

SELECT DISTINCT gender FROM Students;

-- Aggregation function
SELECT COUNT(DISTINCT department) AS No_of_Departments FROM Students;
SELECT SUM(CGPA), MAX(CGPA), MIN(CGPA), ROUND(AVG(CGPA),2) FROM Students;

SELECT COUNT(roll_number), department FROM Students GROUP BY(department);

