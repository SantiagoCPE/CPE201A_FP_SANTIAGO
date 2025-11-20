#include "ricketyticket.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Global variables for user context
std::string currentStudentUsername;
std::string currentAdminUsername;

// Structures for a basic complaint ticket system
struct Complaint {
    int id;
    std::string username;
    std::string category;
    std::string subcategory;
    std::string description;
    std::string adminReply;
    std::string status; // "Open", "Edited", "Deleted"
};
std::vector<Complaint> complaints;
int nextComplaintID = 1;

// Struct for lost and found items (IMPROVED)
struct LostFoundItem {
    std::string name;
    std::string location;
    std::string time;
};

// Utility for input
static std::string getInput(const std::string& prompt, int maxlen = 200) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    if (maxlen > 0 && s.length() > (size_t)maxlen) s = s.substr(0, maxlen);
    return s;
}

// Student-side
void createGradesComplaint() {
    Complaint c;
    c.id = nextComplaintID++;
    c.username = currentStudentUsername;
    c.category = "Grades";
    std::cout << "Grades Subcategories:\n  1) Grading System\n  2) Encoding Errors\n";
    int sub = 0;
    while (sub != 1 && sub != 2) {
        std::cout << "Choose subcategory: ";
        std::cin >> sub;
        std::cin.ignore();
    }
    c.subcategory = (sub == 1) ? "Grading System" : "Encoding Errors";
    c.description = getInput("Describe your complaint (max 200 chars): ");
    c.status = "Open";
    c.adminReply = "";
    complaints.push_back(c);
    std::cout << "Complaint submitted! Ticket ID: " << c.id << "\n";
}
void createSubjectsComplaint() {
    Complaint c;
    c.id = nextComplaintID++;
    c.username = currentStudentUsername;
    c.category = "Subjects";
    std::vector<std::string> subjects{
        "CHEM001C", "CPE007", "CPEG008", "CPE201A", "EMATH016",
        "GEC001", "MATH006", "NSTP001", "PEH001"
    };
    std::cout << "Subject Subcategories:\n";
    for (size_t i = 0; i < subjects.size(); ++i)
        std::cout << "  " << (i+1) << ") " << subjects[i] << "\n";
    int sub = 0;
    while (sub < 1 || sub > (int)subjects.size()) {
        std::cout << "Choose subject: ";
        std::cin >> sub;
        std::cin.ignore();
    }
    c.subcategory = subjects[sub-1];
    c.description = getInput("Describe your complaint (max 200 chars): ");
    c.status = "Open";
    c.adminReply = "";
    complaints.push_back(c);
    std::cout << "Complaint submitted! Ticket ID: " << c.id << "\n";
}
void createEnrollmentComplaint() {
    Complaint c;
    c.id = nextComplaintID++;
    c.username = currentStudentUsername;
    c.category = "Enrollment";
    c.subcategory = "";
    c.description = getInput("Describe your complaint (max 200 chars): ");
    c.status = "Open";
    c.adminReply = "";
    complaints.push_back(c);
    std::cout << "Complaint submitted! Ticket ID: " << c.id << "\n";
}
void createProfessorsComplaint() {
    Complaint c;
    c.id = nextComplaintID++;
    c.username = currentStudentUsername;
    c.category = "Professors";
    std::cout << "Professors Subcategories:\n  1) Consultation Period\n";
    int sub = 0;
    while (sub != 1) {
        std::cout << "Choose subcategory: ";
        std::cin >> sub;
        std::cin.ignore();
    }
    c.subcategory = "Consultation Period";
    c.description = getInput("Describe your complaint (max 200 chars): ");
    c.status = "Open";
    c.adminReply = "";
    complaints.push_back(c);
    std::cout << "Complaint submitted! Ticket ID: " << c.id << "\n";
}
void createLostFoundComplaint() {
    Complaint c;
    c.id = nextComplaintID++;
    c.username = currentStudentUsername;
    c.category = "Lost and Found";
    // IMPROVED lost and found items (struct, not tuple)
    std::vector<LostFoundItem> items = {
        {"Umbrella", "P.E Center 2", "9:30 AM"},
        {"Wallet", "Q2107", "1:30 PM"},
        {"ID", "Q9310", "2:45 PM"},
        {"Hydroflask", "Building 1-9", "7:00AM - 6:30PM"}
    };
    std::cout << "Lost and Found Items:\n";
    std::cout << std::left << std::setw(5) << "No."
              << std::setw(20) << "Item"
              << std::setw(20) << "Location"
              << std::setw(15) << "Time" << "\n";
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << std::setw(5) << (i+1)
                  << std::setw(20) << items[i].name
                  << std::setw(20) << items[i].location
                  << std::setw(15) << items[i].time << "\n";
    }
    int idx = 0;
    while (idx < 1 || idx > (int)items.size()) {
        std::cout << "Select lost item: ";
        std::cin >> idx;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input, try again.\n";
            continue;
        }
        std::cin.ignore();
    }
    c.subcategory = items[idx-1].name;
    std::string time = getInput("Enter your preferred appointment time to visit Student Affairs (e.g., 1:30 PM): ");
    c.description = "Lost and Found appointment for '" + c.subcategory +
                    "', found at " + items[idx-1].location +
                    ", found time: " + items[idx-1].time +
                    ", student appointment: " + time;
    c.status = "Open";
    c.adminReply = "";
    complaints.push_back(c);
    std::cout << "Appointment ticket submitted! Ticket ID: " << c.id << "\n";
}
void createComplaint() {
    while (true) {
        std::cout << "\nComplaint Categories:\n"
                  << "1. Grades\n"
                  << "2. Subjects\n"
                  << "3. Enrollment\n"
                  << "4. Professors\n"
                  << "5. Lost and Found\n"
                  << "0. Return\n"
                  << "Select a category: ";
        int cat;
        std::cin >> cat;
        std::cin.ignore();
        if (cat == 0) break;
        if (cat == 1) createGradesComplaint();
        else if (cat == 2) createSubjectsComplaint();
        else if (cat == 3) createEnrollmentComplaint();
        else if (cat == 4) createProfessorsComplaint();
        else if (cat == 5) createLostFoundComplaint();
        else std::cout << "Invalid. Try again.\n";
        char again;
        std::cout << "Create another complaint? (y/n): ";
        std::cin >> again;
        std::cin.ignore();
        if (again != 'y' && again != 'Y') break;
    }
}
void viewMyComplaints() {
    std::cout << "\nYour Complaints:\n";
    bool found = false;
    for (const auto& c : complaints) {
        if (c.username == currentStudentUsername && c.status != "Deleted") {
            found = true;
            std::cout << "Ticket ID: " << c.id << "\n"
                      << "Category: " << c.category << "\n";
            if (!c.subcategory.empty())
                std::cout << "Subcategory: " << c.subcategory << "\n";
            std::cout << "Description: " << c.description << "\n"
                      << "Status: " << c.status << "\n";
            if (!c.adminReply.empty())
                std::cout << "Admin Reply: " << c.adminReply << "\n";
            std::cout << "---------------------------\n";
        }
    }
    if (!found) std::cout << "No complaints found.\n";
}
void editComplaint() {
    std::cout << "Enter Ticket ID to edit: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    for (auto& c : complaints) {
        if (c.id == id && c.username == currentStudentUsername && c.status != "Deleted") {
            std::cout << "Current Description: " << c.description << "\n";
            c.description = getInput("Enter new description (max 200 chars): ");
            c.status = "Edited";
            std::cout << "Complaint updated!\n";
            return;
        }
    }
    std::cout << "Complaint not found or you do not have permission to edit it.\n";
}
void studentComplaintMenu() {
    int choice;
    do {
        std::cout << "\nComplaint Ticket System (Student)\n"
                  << "1. Create Post\n"
                  << "2. View My Posts\n"
                  << "3. Edit a Post\n"
                  << "4. Return to Student Menu\n"
                  << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) createComplaint();
        else if (choice == 2) viewMyComplaints();
        else if (choice == 3) editComplaint();
        else if (choice == 4) break;
        else std::cout << "Invalid choice. Try again.\n";
    } while (choice != 4);
}

// Admin-side
void viewAllComplaints() {
    std::cout << "\nAll Complaints:\n";
    bool found = false;
    for (const auto& c : complaints) {
        if (c.status != "Deleted") {
            found = true;
            std::cout << "Ticket ID: " << c.id << "\n"
                      << "User: " << c.username << "\n"
                      << "Category: " << c.category << "\n";
            if (!c.subcategory.empty())
                std::cout << "Subcategory: " << c.subcategory << "\n";
            std::cout << "Description: " << c.description << "\n"
                      << "Status: " << c.status << "\n";
            if (!c.adminReply.empty())
                std::cout << "Admin Reply: " << c.adminReply << "\n";
            std::cout << "---------------------------\n";
        }
    }
    if (!found) std::cout << "No complaints found.\n";
}
void adminDeleteComplaint() {
    std::cout << "Enter Ticket ID to delete: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    for (auto& c : complaints) {
        if (c.id == id && c.status != "Deleted") {
            char yn;
            std::cout << "Are you sure you want to delete this complaint? (y/n): ";
            std::cin >> yn;
            std::cin.ignore();
            if (yn == 'y' || yn == 'Y') {
                c.status = "Deleted";
                std::cout << "Complaint deleted.\n";
            } else {
                std::cout << "Deletion cancelled.\n";
            }
            return;
        }
    }
    std::cout << "Complaint not found.\n";
}
void adminReplyToComplaint() {
    std::cout << "Enter Ticket ID to reply to: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    for (auto& c : complaints) {
        if (c.id == id && c.status != "Deleted") {
            std::cout << "Current Description: " << c.description << "\n";
            c.adminReply = getInput("Enter your reply: ");
            std::cout << "Reply posted.\n";
            return;
        }
    }
    std::cout << "Complaint not found.\n";
}
void adminComplaintMenu() {
    int choice;
    do {
        std::cout << "\nComplaint Ticket System (Admin)\n"
                  << "1. View All Posts\n"
                  << "2. Reply to a Post\n"
                  << "3. Delete a Post\n"
                  << "4. Return to Admin Menu\n"
                  << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) viewAllComplaints();
        else if (choice == 2) adminReplyToComplaint();
        else if (choice == 3) adminDeleteComplaint();
        else if (choice == 4) break;
        else std::cout << "Invalid choice. Try again.\n";
    } while (choice != 4);
}
