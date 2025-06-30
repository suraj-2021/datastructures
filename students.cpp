#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
    string name;
    int rollNumber;
    double marks;
public:
    Student(string n, int r, double m) : name(n), rollNumber(r), marks(m) {}

    double getMarks() const { return marks; }
    void display() const {
        cout << "Name: " << name
             << ", Roll No: " << rollNumber
             << ", Marks: " << marks << endl;
    }
};

class Classroom {
    vector<Student> students;
public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No students in the class." << endl;
            return;
        }
        cout << "Student List:" << endl;
        for (const auto& s : students)
            s.display();
    }

    void displayAverage() const {
        if (students.empty()) {
            cout << "No students to calculate average." << endl;
            return;
        }
        double sum = 0;
        for (const auto& s : students)
            sum += s.getMarks();
        cout << fixed << setprecision(2);
        cout << "Class Average: " << (sum / students.size()) << endl;
    }
};

int main() {
    Classroom classroom;
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display All Students\n3. Display Class Average\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                int roll;
                double marks;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> roll;
                cout << "Enter marks: ";
                cin >> marks;
                classroom.addStudent(Student(name, roll, marks));
                break;
            }
            case 2:
                classroom.displayAll();
                break;
            case 3:
                classroom.displayAverage();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
