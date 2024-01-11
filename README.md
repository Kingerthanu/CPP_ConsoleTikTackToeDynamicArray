# CPP_ConsoleTikTackToeDynamicArray
A game of Tic-Tac-Toe. Uses a main game loop in the "main" function.
Uses boolean variable "turn" which could either be (1 (true),0 (false); 1 -> player 1; 0 -> player 2) and toggles
amongst these two states. Grid-style board (gameBoard) will be indexed for ease of use and will call upon a 
cout call for each player and their turn in a tuple-like style (x,y). The "gameBoard" size will also be
asked upon the user when the game initializes (craftBoard). Calculations for if someone has won will be done right after 
player calls their spot (determineWinner). Also, the player will be able to determine
which type of style of marker they wish to have (x,X,o,O, etc.). Game will declare winner in console
after the calculations are done and will ask if the players wish to restart, which will then reloop the game loop. 
