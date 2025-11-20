#ifndef LOGIN_H
#define LOGIN_H

//Student-side Functions
void registerStudent();
void studentMenu();
void loadStudentsFromFile();
//Admin-side Functions
void loadAdminsFromFile();
void listAllStudents();
void adminAddStudent();
void adminRemoveStudent();
void adminResetStudentPassword();
void adminMenu();
//Main menu function
void mainMenu();
#endif
