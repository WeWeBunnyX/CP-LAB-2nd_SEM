
#include <iostream>
#include <list>
#include <string>
using namespace std;
class ToDoList {
private:
    list<list<string>> tasks;
public:
    ToDoList(const list<list<string>>& t) : tasks(t) {}
    void printToDoList() {
        int i = 1;
        for (const auto& task : tasks) {
            cout << "Task " << i++ << ": ";
            for (const string &subtask : task) {
                cout << subtask << ", ";
            }
            cout << endl;
        }
    }
    void addTask(list<string> newTask) {
        tasks.push_back(newTask);
    }
    void deleteTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            auto it = tasks.begin();
         advance(it, taskIndex);
         tasks.erase(it);
    } else {
        cout << "Invalid task index." << endl;
    }
}
    };

int main() {
    ToDoList todo({
        {"Go to school", "Attend classes", "Complete Homework"},
        {"Finish project", "Study for exam"},
        {"Walk the dog", "Water the plants", "Wash the car"}
    });
    cout << "Original ToDo List:" << endl;
    todo.printToDoList();
    todo.addTask({"Go to gym", "Cook dinner", "Watch movie"});
    cout << "\nToDo List after adding a task:" << endl;
    todo.printToDoList();
    todo.deleteTask(3);
    cout << "\nToDo List after deleting a task:" << endl;
    todo.printToDoList();
    return 0;
}
