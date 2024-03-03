
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Student {
    int id;
    string name;
    float grade;
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};
class StudentManager {
private:
    vector<Student*> records;
public:
    void addStudent(int id, string name, float grade) {
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }
    
    void updateGrade(int id, float newGrade) {
        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }
    
    void displayRecords() {
        for (Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
        }
    }
    
    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};
int main() {
    StudentManager sm;
    sm.addStudent(1, "John Doe", 92.5);
    sm.addStudent(2, "Jane Doe", 88.0);
    sm.addStudent(3, "Reza", 56.6);
    sm.addStudent(4, "Ali", 45.5);
    sm.addStudent(5, "Ahmed", 67.67);
    sm.addStudent(6, "Luis", 70.53);


    sm.displayRecords();
    sm.updateGrade(1, 95.0);
    sm.updateGrade(2, 89.5);
    sm.updateGrade(3, 68.5);
    sm.updateGrade(4, 55.0);
    sm.updateGrade(5, 73.1);
    sm.updateGrade(6, 79.5);
    
    cout << "\nAfter grade update:" << endl;
    sm.displayRecords();
    return 0;
}
