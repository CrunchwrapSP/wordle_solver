# wordle_solver
Wordle Solver in C
A command-line tool written in C that helps you solve Wordle puzzles by suggesting optimal guesses based on letter frequency and positional data.

About The Project
This program analyzes a list of possible Wordle solutions (SOLUTION.txt) to calculate the best next guess. It uses statistical analysis of letter frequency and position to rank words by their probability of being the correct answer.

Features
Statistical Analysis: Calculates the score for each word based on how common its letters are in specific positions.

Smart Guessing: Suggests the top 1-5 most probable words to guess next.

Interactive Feedback: Incorporates your feedback (green, yellow, gray squares) after each guess to narrow down the possibilities.

Efficient: Processes a list of over 2300 words quickly.

How to Use
Compile the Code:

bash
gcc -o wordle_solver wordle_solver.c
Run the Program:

bash
./wordle_solver
Follow the Prompts:

Tell the program how many guess suggestions you'd like to see (1-5).

It will display its top suggestions (e.g., "Your best guesses are: 1: crate - 1234").

Enter the word you chose from the list.

Report the color patterns you got back from Wordle using g (green), y (yellow), and r (red/gray). For example, if the word "crate" got green, gray, gray, yellow, gray, you would enter grryr.

The program will use this information to eliminate incorrect words and suggest the next best guess.

Repeat until you win!

File Structure
text
wordle_solver/
├── wordle_solver.c  # Main source code
├── SOLUTION.txt     # Word list (one word per line)
├── README.md        # This file
└── (optional) Makefile
Requirements
A C compiler (e.g., GCC, Clang)

The SOLUTION.txt file must be in the same directory as the executable when running the program.

Disclaimer: This project is for educational purposes to demonstrate algorithms and C programming. It is not affiliated with the official Wordle game.
