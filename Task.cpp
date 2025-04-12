#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a structure to represent a task
struct Task
{
    string name;
    string description;
    bool completed;
};

// Function to add a new task to the task list
void addTask(vector<Task> &tasks)
{
    Task newTask;

    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, newTask.name);
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);

    newTask.completed = false;
    tasks.push_back(newTask);

    cout << "Task added successfully!" << endl;
}

// Function to display all tasks in the task list
void displayTasks(const vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks to show.\n";
        return;
    }

    cout << "\nTasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i)
    { // size_t is an unsigned integer type used to represent the size or index of an object — especially useful when dealing with sizes of arrays, vectors, strings, and so on.
        cout << i + 1 << ". " << tasks[i].name
             << " - " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks, int index)
{
    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

int main()
{
    vector<Task> tasks;
    int choice;
    int taskIndex;

    do
    {
        cout << "\nTask Management System\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore(); // Ignore the newline character left by cin
            addTask(tasks);
            break;
        case 2:
            displayTasks(tasks);
            break;
        case 3:
            cout << "Enter the index of the task to mark as completed: ";
            cin >> taskIndex;
            markTaskCompleted(tasks, taskIndex);
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
