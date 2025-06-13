#Single Player Bowling Game

This project is a C++ console application that simulates a single-player bowling game, implementing **all official bowling rules**, including strikes, spares, the 10th frame bonus, and proper exception handling.

---

#Features

- Simulates 10-frame bowling game for 1 player
- Full support for **strike**, **spare**, and **10th frame bonus**
- Handles invalid input and re-prompts instead of exiting
- Robust exception handling using `try-catch`
- Easily extendable to multiplayer version or GUI

---

#Game Rules Covered

| Rule Type         | Description                                               |
|------------------|-----------------------------------------------------------|
| Strike            | 10 pins in 1st roll → next 2 rolls as bonus               |
| Spare             | All 10 pins in 2 rolls → next 1 roll as bonus             |
| 10th Frame        | Strike/Spare allows extra roll(s)                         |
| Input Validation  | Pins per roll must be between 0–10; sum max 10 (except 10th) |

---

#Requirements

- A C++ compiler like `g++` (GCC) or MSVC
- Linux / macOS / Windows command line

#Compile

```bash
g++ -std=c++11 -o BowlingGame main.cpp
