#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Task {
public:
    string description;
    bool completed;
    Task(const string& desc, bool comp = false) : description(desc), completed(comp) {}
};
class ToDoList {
private:
    vector<Task> tasks;
public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task \"" << description << "\" added.\n";
    }
   void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks.\n";
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                char status = tasks[i].completed ? '✓' : ' ';
                cout << i + 1 << ". [" << status << "] " << tasks[i].description << endl;
            }
        }
    }
 void markTaskCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task \"" << tasks[taskIndex - 1].description << "\" marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
 void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            cout << "Task \"" << tasks[taskIndex - 1].description << "\" removed.\n";
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index.\n";
        }
    }
};
int main() {
    ToDoList todoList;
    while (true) {
        cout << "\n==== To-Do List Manager ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        int choice;
        cin >> choice;
      switch (choice) {
            case 1: {
                cin.ignore(); 
                                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                cout << "Enter task index to mark as completed: ";
                size_t taskIndex;
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                cout << "Enter task index to remove: ";
                size_t taskIndex;
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
 return 0;
}
