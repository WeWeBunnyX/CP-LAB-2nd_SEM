
#include <iostream>
#include <vector>
#include <string>
#include<limits>

using namespace std;
class GradeManager {
private:
    vector<string> gradeList;
public:
    void addGrade(string grade) {
        gradeList.push_back(grade);
    }
    void displayGrades() {
        if (gradeList.empty()) {
            cout << "No grade entered, Please enter a numeric or alphabetical grade!";
        } else {
            cout << "\nGrades: ";
            for (string grade : gradeList) {
                cout << grade << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    GradeManager gradeManager;
    char userChoice;
    string Grade;
    do {
        cout<<endl;
        cout << "1. Add grades (Both numeric and alphabetical accepted)\n";
        cout << "2. Display all grades\n";
        cout << "3. Exit\n";
        cout << "Please enter your choice: ";
        cin >> userChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        switch (userChoice) {
            case '1': 
                do {
                    cout << "Please enter the grade (or 'x' to stop): ";
                    getline(cin, Grade);
                    if (Grade != "x") {
                        gradeManager.addGrade(Grade);
                    }
                } while (Grade != "x");
                break;
            case '2':
                gradeManager.displayGrades();
                break;
            case '3':
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (userChoice != 3);
    return 0;
}
