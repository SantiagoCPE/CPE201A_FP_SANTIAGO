#ifndef RICKETYTICKET_H
#define RICKETYTICKET_H

//Global variable declaration (tracks which user is active)
#include <string>
extern std::string currentStudentUsername;  //extern allows variables to be recognized EXTERNALLY by the compiler (haha get it please laugh im so alone)
extern std::string currentAdminUsername;
// Student-side functions
void createGradesComplaint();
void createSubjectsComplaint();
void createEnrollmentComplaint();
void createProfessorsComplaint();
void createLostFoundComplaint();
void createComplaint();
void viewMyComplaints();
void editComplaint();
void studentComplaintMenu();

// Admin-side functions
void viewAllComplaints();
void adminDeleteComplaint();
void adminComplaintMenu();

#endif 
