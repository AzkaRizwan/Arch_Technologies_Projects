#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_TASKS = 100;

string tasks[MAX_TASKS];
int taskCount = 0;

void displayDivider()
{
    cout << "  =====================================" << endl;
}

void displayMenu()
{
    cout << endl;
    displayDivider();
    cout << "          TO-DO LIST APPLICATION" << endl;
    displayDivider();
    cout << "  1. Add Task" << endl;
    cout << "  2. View Tasks" << endl;
    cout << "  3. Remove Task" << endl;
    cout << "  4. Exit" << endl;
    displayDivider();
    cout << "  Enter your choice: ";
}

void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "\n  Task list is full. Cannot add more tasks." << endl;
        return;
    }

    string task;
    cout << "\n  Enter task: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, task);

    if (task.empty())
    {
        cout << "\n  Task cannot be empty." << endl;
        return;
    }

    tasks[taskCount] = task;
    taskCount++;
    cout << "\n  Task added successfully." << endl;
}

void viewTasks()
{
    cout << endl;
    displayDivider();
    cout << "            YOUR TASKS" << endl;
    displayDivider();

    if (taskCount == 0)
    {
        cout << "  No tasks available." << endl;
    }
    else
    {
        for (int i = 0; i < taskCount; i++)
        {
            cout << "  " << i + 1 << ". " << tasks[i] << endl;
        }
    }

    displayDivider();
}

void removeTask()
{
    if (taskCount == 0)
    {
        cout << "\n  No tasks to remove." << endl;
        return;
    }

    viewTasks();

    int taskNumber;
    cout << "\n  Enter task number to remove: ";
    cin >> taskNumber;

    if (cin.fail() || taskNumber < 1 || taskNumber > taskCount)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n  Invalid task number. Please try again." << endl;
        return;
    }

    string removedTask = tasks[taskNumber - 1];

    for (int i = taskNumber - 1; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;

    cout << "\n  Task \"" << removedTask << "\" removed successfully." << endl;
}

int main()
{
    int choice;

    cout << endl;
    displayDivider();
    cout << "          TO-DO LIST APPLICATION" << endl;
    displayDivider();
    cout << "  Manage your tasks easily." << endl;
    displayDivider();

    do
    {
        displayMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n  Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            removeTask();
            break;
        case 4:
            cout << endl;
            displayDivider();
            cout << "  Goodbye!" << endl;
            displayDivider();
            cout << endl;
            break;
        default:
            cout << "\n  Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}
