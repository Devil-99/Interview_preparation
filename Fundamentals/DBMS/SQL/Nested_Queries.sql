-- Create Students table
CREATE TABLE Students (
  s_id VARCHAR(2) PRIMARY KEY,
  s_name VARCHAR(30) NOT NULL,
  s_roll_number INTEGER
  
);

INSERT INTO Students VALUES 
('s1', 'Nilesh Chandra',4005),
('s2', 'Souvik Maji',4017),
('s3', 'Nilufa Islam', 4021),
('s4', 'SHreejeeb Kesh', 4023),
('s5', 'Akash Mondal', 5030),
('s6', 'Aryashree', 4050),
('s7', 'Apurba Mondal', 4051),
('s8', 'Siddhant Singh', 6028);

INSERT INTO Students (s_id,s_name) VALUES ('s9','Rick Mondal');

-- SELECT * FROM Students;

-- Create Courses table
CREATE TABLE Courses (
  c_id VARCHAR(2) PRIMARY KEY,
  c_name VARCHAR(30) NOT NULL,
  c_HOD VARCHAR(20)
);

INSERT INTO Courses VALUES
('c1', 'DSA', "Dhiman Mondal"),
('c2', 'DBMS', "Subhas Barman"),
('c3', 'C', "Dipak Koley"),
('c4', 'MATH', "Jhuma Banerjee");

-- SELECT * FROM Courses;

-- Create Student-Course Relationship table
CREATE TABLE student_course_relation (
    s_id VARCHAR(2),
    c_id VARCHAR(2)
);

INSERT INTO student_course_relation VALUES
('s1','c1'),
('s1','c3'),
('s2','c1'),
('s3','c2'),
('s4','c2'),
('s4','c3');

-- SELECT * FROM student_course_relation;


-- Q. Find out the students name who are enrolled in courses DSA or DBMS.
-- Nested Query Solution
SELECT s_name FROM Students WHERE s_id IN
(SELECT s_id FROM student_course_relation WHERE c_id IN
(SELECT c_id FROM Courses WHERE c_name='DSA' OR c_name='DBMS')) ;
-- Join Solution
SELECT s.s_name FROM 
Students AS s INNER JOIN 
(SELECT sc.s_id,c.c_name FROM student_course_relation AS sc INNER JOIN Courses as c ON sc.c_id=c.c_id WHERE c.c_name='DSA' OR c.c_name='DBMS')
AS temp ON s.s_id=temp.s_id;



