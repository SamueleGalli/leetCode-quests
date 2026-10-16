SELECT  Students.student_id,
        Students.student_name,
        Subjects.subject_name,
        COUNT(Examinations.subject_name) AS attended_exams
FROM Students
CROSS JOIN Subjects
LEFT JOIN Examinations 
ON Examinations.subject_name = Subjects.subject_name AND Students.student_id = Examinations.student_id
GROUP BY Students.student_id, Subjects.subject_name
ORDER BY Students.student_id, Subjects.subject_name