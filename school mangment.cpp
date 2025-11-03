#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    int age;
    string className;
    vector<string> attendance; // "Present" or "Absent"
    vector<int> grades; // Grades per subject

    void inputDetails() {
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter class name: ";
        cin.ignore();
        getline(cin, className);
    }

    void displayDetails() {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Class Name: " << className << endl;
        cout << "Attendance: ";
        for (const auto& day : attendance)
            cout << day << " ";
        cout << "\nGrades: ";
        for (const auto& grade : grades)
            cout << grade << " ";
        cout << endl;
    }

    void markAttendance(string day) {
        attendance.push_back(day);
    }

    void addGrade(int grade) {
        grades.push_back(grade);
    }
};

class Teacher {
public:
    string name;
    string subject;
    int age;
    vector<string> attendance;

    void inputDetails() {
        cout << "Enter teacher name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter subject: ";
        getline(cin, subject);
        cout << "Enter age: ";
        cin >> age;
    }

    void displayDetails() {
        cout << "\n--- Teacher Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Age: " << age << endl;
        cout << "Attendance: ";
        for (const auto& day : attendance)
            cout << day << " ";
        cout << endl;
    }

    void markAttendance(string day) {
        attendance.push_back(day);
    }
};

int main() {
    vector<Student> students;
    vector<Teacher> teachers;
    int choice = 0;

    while (true) {
        cout << "\n--- School Management Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Display Student Details\n";
        cout << "4. Display Teacher Details\n";
        cout << "5. Mark Student Attendance\n";
        cout << "6. Add Student Grade\n";
        cout << "7. Mark Teacher Attendance\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            Student s;
            s.inputDetails();
            students.push_back(s);
        } else if (choice == 2) {
            Teacher t;
            t.inputDetails();
            teachers.push_back(t);
        } else if (choice == 3) {
            for (auto &student : students)
                student.displayDetails();
        } else if (choice == 4) {
            for (auto &teacher : teachers)
                teacher.displayDetails();
        } else if (choice == 5) {
            int idx;
            string day;
            cout << "Enter student index (0..."<< students.size()-1 << "): ";
            cin >> idx;
            cout << "Mark attendance (Present/Absent): ";
            cin >> day;
            students[idx].markAttendance(day);
        } else if (choice == 6) {
            int idx, grade;
            cout << "Enter student index (0..."<< students.size()-1 << "): ";
            cin >> idx;
            cout << "Enter grade: ";
            cin >> grade;
            students[idx].addGrade(grade);
        } else if (choice == 7) {
            int idx;
            string day;
            cout << "Enter teacher index (0..."<< teachers.size()-1 << "): ";
            cin >> idx;
            cout << "Mark attendance (Present/Absent): ";
            cin >> day;
            teachers[idx].markAttendance(day);
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}

