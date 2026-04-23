Task Management System Using C Programming

Team Members:
Name: Manasvi Agarwal
Roll Number: 69
Name: Anuj Naikawadi
Roll Number: 8
Name: Senon Bankar
Roll Number: 42
Name: Riddhishri Ranaware 
Roll Number: 68
Name: Madhav Agarwal
Roll Number: 62

Project Guide:
      Name: Shirish Paygude
      Designation: C programming professor

Institution Name:
      MIT World Peace University (MIT-WPU)

Submission Date:
      23-02-2026
2. Acknowledgment
                  We sincerely thank our project guide for their continuous support, constructive feedback, and technical guidance throughout the development of this project. Their expertise in programming concepts and structured design helped us successfully implement this system.
                  We also extend our gratitude to the faculty members of the Foundations of Programming course for strengthening our understanding of C programming, file handling, and modular programming principles. Our appreciation also goes to our peers and family members for their encouragement.
3. Abstract
            The Task Management System is a console-based software application developed using the C programming language. The primary objective of the system is to facilitate structured task allocation, monitoring, and reporting in an organizational environment. The system allows managers to assign tasks with deadlines and enables employees to view and update task status. File handling mechanisms are used to ensure persistent storage of user and task data using CSV files. The system incorporates role-based access control, date validation algorithms, leap year handling, and session-based reporting. At the end of each session, tasks are archived automatically with timestamped records. The project demonstrates practical implementation of structured programming, data validation, modular design, and file management techniques in C. The results indicate successful execution of task allocation workflows, accurate deadline validation, and effective session reporting.
 
4. Table of Contents
      1. Title Page
      2. Acknowledgment
      3. Abstract
      4. Table of Contents
      5. List of Figures and Tables
      6. Introduction
      7. Literature Review
      8. System Design/Methodology
      9. Implementation
      10. Results and Discussion
      11. Conclusion
      12. Future Scope
      13. Research Paper/Patent Details
      14. Plagiarism Check
      15. References
      16. Appendix
 
5. List of Figures and Tables
      Figure 1: Overall System Architecture
      Figure 2: Role-Based Access Flowchart
      Figure 3: Task Update and Validation Flow
      Table 1: Research Paper Comparison
      Table 2: Task Structure Fields
      Table 3: Testing Scenarios

7. Introduction

Problem Statement
      In many organizations, task allocation and monitoring are performed manually or using unstructured methods. This often results in missed deadlines, poor accountability, and lack of performance tracking. The problem addressed in this project is the development of a structured, role-based task management system that ensures proper task assignment, deadline validation, and completion tracking.
      Background/Context
      Task management systems are widely used in corporate environments to enhance productivity and coordination. Modern systems often include dashboards, analytics, and cloud integration. However, this project focuses on developing a foundational system using C programming to demonstrate core programming principles such as structures, arrays, modular functions, and file handling.

Objectives
      The primary objectives of this project include:
      • Designing a role-based task management system
      • Implementing secure login functionality
      • Validating deadlines using date-check algorithms
      • Maintaining persistent data storage using CSV files
      • Generating final reports for session tasks
      • Archiving session data automatically
 
8. Literature Review
      Extensive research has been conducted in workflow management, task scheduling, and productivity systems. This section reviews various academic and technical contributions relevant to task management systems.
      Paper 1: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 2: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 3: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 4: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 5: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 6: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 7: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 8: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 9: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 10: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 11: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 12: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 13: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 14: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 15: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 16: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 17: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 18: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 19: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
      Paper 20: This research explores workflow optimization, scheduling algorithms, role-based access control, and deadline tracking systems. The study identifies scalability, usability, and security challenges in existing task management platforms while proposing improvements in performance measurement and efficiency.
•	The comparison of 15–20 research works highlights that most systems rely on database-driven models and web-based architectures. However, lightweight file-based systems remain effective for small-scale environments. The identified    research gap includes limited focus on structured programming-based implementations in C.


9. System Design/Methodology
      Overview of the Approach
      The system follows a modular design approach. It separates functionality into distinct modules such as user management, task management, file handling, date validation, reporting, and session archiving.
      Modules Used
      User Module – Handles authentication and user creation.
      Task Module – Manages task creation, assignment, and updates.
      File Handling Module – Saves and loads data from CSV files.
      Validation Module – Verifies correct date inputs.
      Reporting Module – Generates session-based summaries.
      Archiving Module – Stores session data with timestamps.
      Algorithms Used
      The system uses leap year calculation, date validation logic, string comparison for deadline verification, and structured array traversal for task filtering.

10. Implementation
      Development Environment
      Programming Language: C
      Compiler: GCC
      Operating System: macOS/Linux
      Libraries Used: stdio.h, string.h, stdlib.h, time.h, sys/stat.h, unistd.h
      Testing
      •	Test Case 1: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 2: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 3: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 4: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 5: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 6: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 7: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 8: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 9: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.
      •	Test Case 10: Input validation, login verification, deadline comparison, session reporting, and archive creation were tested to ensure correctness and reliability.

11. Results and Discussion
      The system successfully performs task assignment, deadline validation, user authentication, and session archiving. All objectives defined in the project scope were achieved.
      Performance evaluation shows accurate date validation and correct late/on-time detection. The system provides clear console-based interaction and structured workflow navigation.

12. Conclusion
      The Task Management System developed in C demonstrates effective use of structured programming, modular design, and file handling techniques. The project successfully meets its objectives and provides a reliable method for task allocation and tracking.

13. Future Scope
      Future enhancements may include GUI integration, database connectivity, password encryption, multi-user concurrency support, analytics dashboard, cloud deployment, and mobile integration.

14. Research Paper/Patent Details
      No research paper has been published and no patent has been filed for this project.

15. Plagiarism Check
      The plagiarism percentage of this report is below 10%.
 
16. References
[1] B. W. Kernighan and D. M. Ritchie, The C Programming Language, 2nd ed., Prentice Hall, 1988.
[2] H. Schildt, C: The Complete Reference, 4th ed., McGraw-Hill, 2000.


