#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    Task newTask;
    newTask.description = description;
    newTask.completed = false;

    tasks.push_back(newTask);
    std::cout << "Task added successfully!\n";
}

void completeTask(std::vector<Task>& tasks) {
    int index;
    std::cout << "Enter the index of the task to mark as completed: ";
    std::cin >> index;

    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task index!\n";
    }
}

void displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        std::cout << "Tasks:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << i << "] ";
            std::cout << (tasks[i].completed ? "[X] " : "[ ] ");
            std::cout << tasks[i].description << "\n";
        }
    }
}

int main() {
    std::vector<Task> tasks;

    int choice;
    do {
        std::cout << "\nTask Management Application\n";
        std::cout << "---------------------------\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character after reading the choice

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                completeTask(tasks);
                break;
            case 3:
                displayTasks(tasks);
                break;
            case 0:
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
