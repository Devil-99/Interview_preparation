-- Create Students table
CREATE TABLE Students (
  id INTEGER PRIMARY KEY,
  name VARCHAR(30) NOT NULL,
  department VARCHAR(3),
  roll_number INTEGER,
  CGPA DECIMAL(3,2)
  
);

INSERT INTO Students VALUES 
(1, 'Nilesh Chandra', 'CSE', 4005, 9.10),
(2, 'Souvik Maji', 'CSE', 4017, 8.40),
(3, 'Nilufa Islam', 'CSE', 4021, 9.45),
(4, 'SHreejeeb Kesh', 'CSE', 4023, 9.30),
(5, 'Akash Mondal', 'ECE', 5030, 8.70),
(6, 'Aryashree', 'CSE', 4050, 8.25),
(7, 'Apurba Mondal', 'CSE', 4051, 8.10),
(8, 'Siddhant Singh', 'IT', 6028, 8.30);

INSERT INTO Students (id,name) VALUES (9,'Rick Mondal');

-- SELECT * FROM Students;

-- Create Courses Table
CREATE TABLE Courses (
  id INTEGER PRIMARY KEY,
  name VARCHAR(30) NOT NULL,
  HOD VARCHAR(20)
);

INSERT INTO Courses VALUES
(1, 'CSE', "Dhiman Mondal"),
(2, 'ECE', "Subhas Barman"),
(3, 'IT', "Dipak Koley"),
(4, 'ME', "Jhuma Banerjee");

-- SELECT * FROM Courses;

SELECT Students.name, Students.roll_number,Students.department,Courses.HOD 
FROM Students INNER JOIN Courses ON Students.department=Courses.name;


