#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Task {
    string title;
    int priority;
    bool completed;
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& title, int priority) {
        tasks.push_back({title, priority, false});
    }

    void completeTask(int index) {
        if (index >= 0 && index < static_cast<int>(tasks.size())) {
            tasks[index].completed = true;
        }
    }

    void showTasks() const {
        vector<Task> sorted = tasks;

        sort(sorted.begin(), sorted.end(), [](const Task& a, const Task& b) {
            return a.priority > b.priority;
        });

        cout << "Task Manager\n";
        cout << "============\n";

        for (size_t i = 0; i < sorted.size(); ++i) {
            cout << i + 1 << ". "
                 << "[" << (sorted[i].completed ? "Done" : "Open") << "] "
                 << sorted[i].title
                 << " | Priority: " << sorted[i].priority << '\n';
        }
    }
};

int main() {
    TaskManager manager;

    manager.addTask("Finish project", 5);
    manager.addTask("Read documentation", 3);
    manager.addTask("Fix login bug", 5);
    manager.addTask("Update dependencies", 2);

    manager.completeTask(1);
    manager.showTasks();

    return 0;
}