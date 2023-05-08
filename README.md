# Chess Console Game
This is a console-based two-player Chess game implemented in C++.
## Update:
This repository is no longer being updated. Visit https://github.com/EnacheGeorgeAlexandru/Chess for the latest version with a GUI.
## Usage
When the game starts, the board will be displayed, and the first player (playing as white) will be prompted to enter a move. 
Players take turns moving, with the board being displayed after each move, until one of them checkmates the other and the game ends.
## Input format
The input format for moves is the coordinate notation. Each square on the board is identified by a combination of a letter (a-h) and a number (1-8), such as "a1" or "h8". 
A move is represented by the starting and ending coordinates of the piece being moved, such as "e2" followed by "e4" for moving a pawn from square e2 to square e4.
## Code Overview
The code is implemented using object-oriented programming principles.
* The **Game** class keeps two **Player** objects and a **Board** object.
* The **Player** class takes care of user input and passes it on in the form of a **Move** object.
* The **Board** class keeps a matrix of **Tile** objects, each capable of holding a **Piece** object (the base class for all the chess pieces).
* Each **Piece** derived class overrides its methods for returning a list of legal **Moves** in a given position.
* The **Board** class uses those legal moves in order to implement game logic (look for checkmate etc.).
## Further Improvements
There are several areas of the code that will be improved in the future, such as:
* Implementing smart pointers to manage memory more efficiently.
* Adding more error handling for user input.
* Clean up redundant code.
## Contributing
Contributions are welcomed! If you find any bugs or have ideas for new features, please feel free to create an issue or submit a pull request.
