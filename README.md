🎮 Tic-Tac-Toe with AI (C++)
A console-based Tic-Tac-Toe game written in C++. Play against another player or challenge an unbeatable AI powered by the Minimax algorithm.

📌 Features
✅ Two-player mode (PvP) – Play against another person.
✅ AI Mode – Challenge an unbeatable AI that always plays optimally.
✅ Minimax Algorithm – AI evaluates moves using game theory.
✅ Turn-based system – Players alternate turns automatically.
✅ Win & Draw detection – The game announces the result (Win, Loss, or Draw).
✅ Board display – Visually appealing console board updates after every move.
✅ Replay option – Restart the game after each round.

🛠️ Installation & Usage
🔹 Prerequisites
A C++ compiler (e.g., g++, MinGW, MSVC, Clang).
A terminal or command prompt.
🔹 Clone the Repository
Download the code or clone the repository:

git clone https://github.com/yourusername/Tictactoe.git
cd Tictactoe
🔹 Compile & Run
Compile the game:

g++ Game.cpp -o Tictactoe
Run the game:

./Tictactoe
(On Windows, use Tictactoe.exe instead.)
🎮 How to Play
Choose your mode:

1 for Two-Player mode (PvP).
2 for AI mode (Player vs. AI).
Select your marker (X or O).

The first player gets to choose their marker.
The second player (or AI) gets the other marker.
Enter your move (1-9) corresponding to board positions:


 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
The game continues until:

A player wins (3 markers in a row, column, or diagonal).
The board is full (resulting in a draw).
Replay or exit after the game ends.

🧠 How AI Works (Minimax Algorithm)
The AI simulates all possible moves and their outcomes.
It assigns scores:
+10 for AI win.
-10 for Player win.
0 for a draw.
It chooses the best move by minimizing the worst-case scenario.
🎯 Result: The AI is unbeatable!

🚀 Future Improvements
Implement Machine Learning-based AI.
Add a graphical user interface (GUI).
Allow different difficulty levels for AI.
📜 License
This project is licensed under the MIT License – feel free to modify and distribute.

🙌 Contributing
Want to improve the game? Fork the repo, make changes, and submit a pull request. Contributions are welcome! 🎉

📞 Contact
Author: Hassane Jaber
Email: hassane.jaber9@gmail.com
