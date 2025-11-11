# Word-Guessing-Game
# 🔠 Word Guessing Game

## 📘 Project Description
This is a fun and interactive *Word Guessing Game* created using the C programming language.  
The program randomly selects a secret word from a predefined list, and the player must guess the word one letter at a time.  
If the player guesses the correct letters, they are revealed in their respective positions.  
The game continues until the full word is guessed or the player reaches the maximum number of attempts.

---

## 🧠 Concepts Used

### 🔸 C Programming Concepts
- Loops (for, while)
- Conditional statements (if, else if, switch)
- Arrays and strings (char word[], strlen())
- Functions for modular code
- Random number generation (rand(), srand())
- User input/output (scanf, printf)
- Character comparison (tolower(), toupper())

### 🔸 Maths / Logic Concepts
- Counting attempts
- Index tracking and matching letters
- Randomized word selection

---

## ⚙ How to Compile

Use the *GCC compiler* with the following command:

```bash
gcc main.c -o word_game -lm
