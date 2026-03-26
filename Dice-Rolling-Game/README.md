# Dice Rolling Game

A console-based dice rolling simulator written in C++. The program simulates rolling a pair of dice and displays the results with ASCII art visuals.

## Features

- Simulates rolling two dice with random values between 1 and 6
- Displays both dice as ASCII art side by side after each roll
- Shows individual die values and their total
- Detects and announces special outcomes: Doubles, Snake Eyes (total of 2), and Boxcars (total of 12)
- Allows the user to roll again or exit after each round
- Displays a session summary at the end including total rolls, grand total, and average roll value
- Input validation ensures only valid responses are accepted

## How to Compile and Run

**Compile:**
```
g++ dice_rolling_game.cpp -o dice_game
```

**Run:**
```
./dice_game
```

On Windows:
```
dice_game.exe
```

## Requirements

- C++ compiler (g++ or any standard C++11 compiler)
