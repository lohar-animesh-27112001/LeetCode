# Write your MySQL query statement below
-- SELECT s.student_id, s.student_name, e.subject_name, COUNT(e.student_id) AS attended_exams
-- FROM Students AS s LEFT JOIN Examinations AS e
-- ON s.student_id = e.student_id
-- WHERE e.subject_name IS NOT NULL
-- GROUP BY s.student_id, e.subject_name
-- HAVING COUNT(e.student_id) <> 0
-- ORDER BY s.student_id ASC, attended_exams DESC;
SELECT stu.student_id, stu.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams
FROM (Students AS stu JOIN Subjects AS sub)
    LEFT JOIN Examinations AS e
    ON stu.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY stu.student_id, sub.subject_name
ORDER BY stu.student_id, sub.subject_name;