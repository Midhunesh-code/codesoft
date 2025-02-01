#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Task {
public:
    std::string description;
    bool completed;
    
    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;
    
    void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void displayMenu() {
        std::cout << "\n=== MIDHUNESH TODO LIST MANAGER ===\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option (1-5): ";
    }

public:
    void addTask() {
        std::string description;
        std::cout << "\nEnter task description: ";
        clearInput();
        std::getline(std::cin, description);
        
        if (!description.empty()) {
            tasks.push_back(Task(description));
            std::cout << "Task added successfully!\n";
        } else {
            std::cout << "Task description cannot be empty!\n";
        }
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "\nNo tasks in the list!\n";
            return;
        }

        std::cout << "\n=== TASK LIST ===\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << "[" << (tasks[i].completed ? "X" : " ") << "] ";
            std::cout << tasks[i].description << "\n";
        }
    }

    void markTaskCompleted() {
        viewTasks();
        if (tasks.empty()) return;

        int taskNum;
        std::cout << "\nEnter task number to mark as completed: ";
        std::cin >> taskNum;

        if (std::cin.fail()) {
            std::cout << "Invalid input!\n";
            clearInput();
            return;
        }

        if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
            tasks[taskNum - 1].completed = true;
            std::cout << "Task marked as completed!\n";
        } else {
            std::cout << "Invalid task number!\n";
        }
    }

    void removeTask() {
        viewTasks();
        if (tasks.empty()) return;

        int taskNum;
        std::cout << "\nEnter task number to remove: ";
        std::cin >> taskNum;

        if (std::cin.fail()) {
            std::cout << "Invalid input!\n";
            clearInput();
            return;
        }

        if (taskNum > 0 && taskNum <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskNum - 1);
            std::cout << "Task removed successfully!\n";
        } else {
            std::cout << "Invalid task number!\n";
        }
    }

    void run() {
        int choice;
        
        while (true) {
            displayMenu();
            if (!(std::cin >> choice)) {
                std::cout << "Invalid input! Please enter a number.\n";
                clearInput();
                continue;
            }

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    viewTasks();
                    break;
                case 3:
                    markTaskCompleted();
                    break;
                case 4:
                    removeTask();
                    break;
                case 5:
                    std::cout << "\nThank you for using Midhunesh TODO List Manager!\n";
                    return;
                default:
                    std::cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

int main() {
    TodoList todoList;
    todoList.run();
    return 0;
}