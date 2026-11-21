# 🎮 Tic-Tac-Toe Game in C

## Project Title
**Tic-Tac-Toe – Two Player Console-Based Game**

## Team Members
1. Naitik Setia-26CSU321
2. chehak Mehta-26CSU318
3. Aryan Gupta-26CSU316
4. Abhishek-26CSU416
5. Bhavesh Kumar Singh-26CSU403

## Project Description
Tic-Tac-Toe is a simple two-player game developed using the C programming language. The game is played on a 3×3 grid where two players take turns marking their positions with X and O.

The objective is to get three identical symbols in a horizontal, vertical, or diagonal row. The first player to achieve this wins the game. If all nine positions are filled without a winner, the game ends in a draw.

## Features
- Two-player gameplay (X and O).
- Interactive 3×3 game board.
- Players can select positions from 1 to 9.
- Automatic checking of winning conditions.
- Detects draw situations.
- Prevents players from selecting already occupied positions.
- Handles invalid inputs.
- Scoreboard to maintain player wins and draws.
- Option to play multiple rounds.

## Technologies Used
- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Header File:** stdio.h

## Project Files
```text
Tic-Tac-Toe/
│
├── tictactoe.c
└── README.md
```

## How to Compile and Run

### Step 1: Clone the Repository
```bash
git clone <your-github-repository-link>
```

### Step 2: Open the Project Folder
```bash
cd Tic-Tac-Toe
```

### Step 3: Compile the C Program
```bash
gcc tictactoe.c -o tictactoe
```

### Step 4: Run the Program

**For Windows:**
```bash
tictactoe.exe
```

**For macOS / Linux:**
```bash
./tictactoe
```

## How to Play
1. Run the program.
2. Player X starts the game.
3. Enter a position between 1 and 9.
4. Player O takes the next turn.
5. Continue until a player wins or the game ends in a draw.
6. View the scoreboard.
7. Enter Y to play again or N to exit.

## Winning Conditions
A player wins by placing three identical symbols in:
- Any horizontal row.
- Any vertical column.
- Either diagonal.

## Conclusion
This project demonstrates the practical implementation of basic C programming concepts such as arrays, functions, loops, conditional statements, and user input handling. It helps beginners understand programming logic through an interactive game.
