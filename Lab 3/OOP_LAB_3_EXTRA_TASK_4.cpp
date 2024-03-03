
#include <iostream>
#include <vector>
using namespace std;
class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};
class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { 
        tasks.push_back(new Task(desc)); 
    }
    
    void listTasks() {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i+1 << ". " << tasks[i]->description;
            if (tasks[i]->completed) {
                cout << " (completed)";
            }
            cout << endl;
        }
    }
    
    void markAsCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber-1]->completed = true;
            cout << "Task " << taskNumber << " has been marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
    
    ~ToDoList() { 
        for (auto &task : tasks) delete task; 
    }
};
int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.addTask("Pack the bag");
    myList.addTask("Upload Assignments");
    myList.addTask("Check for upcoming quiz");
    myList.listTasks();
    cout<<"\n";
    myList.markAsCompleted(1);
    myList.markAsCompleted(2);
    myList.markAsCompleted(3);
    cout<<"\n";
    myList.listTasks();
    return 0;
}
