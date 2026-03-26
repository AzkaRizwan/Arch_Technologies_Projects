# To-Do List Application

A console-based task management application written in C++. The program allows users to add, view, and remove tasks through a simple menu-driven interface.

## Features

- Add tasks to the list with a name or description
- View all current tasks displayed in a numbered list
- Remove a task by selecting its number once it is completed
- Confirmation message displayed after every add or remove action
- Handles up to 100 tasks at a time
- Input validation on all menu choices and task operations
- Prevents adding empty tasks

## How to Compile and Run

**Compile:**

```
g++ todo_list.cpp -o todo_list
```

**Run:**

```
./todo_list
```

On Windows:

```
todo_list.exe
```

## Requirements

- C++ compiler (g++ or any standard C++11 compiler)
