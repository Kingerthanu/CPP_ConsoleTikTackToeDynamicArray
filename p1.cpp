// Benjamin Rudolph Spitzauer
// Lab 5 - "Tic-Tak-Toe P1"
// 10/10/2022
/* A game of Tic-Tac-Toe. Uses a main game loop in the "main" function.
Uses boolean variable "turn" which could either be (1 (true),0 (false); 1 -> player 1; 0 -> player 2) and toggles
amongst these two states. Grid-style board (gameBoard) will be indexed for ease of use and will call upon a 
cout call for each player and their turn in a tuple-like style (x,y). The "gameBoard" size will also be
asked upon the user when the game initializes (craftBoard). Calculations for if someone has won will be done right after 
player calls their spot (determineWinner). Also, the player will be able to determine
which type of style of marker they wish to have (x,X,o,O, etc.). Game will declare winner in console
after the calculations are done and will ask if the players wish to restart, which will then reloop the game loop. 
*/

// --> Revamp for project 2 - deduce grid by /2 as I can just add a | or - when printing the board to save on runtime <--

#include <iostream>
using namespace std;


// Player struct allows container for traits of a player
struct Player 
{ // Allows player customizability and easier containment with larger player sets
    char icon;
    int PLAYER_NUM;
    int totalWins = 0;
};

// ^^^^ Placed here because of scope of functions using their structure



// ---> Prototypes and Function descriptions <---
/*
Precondition: Must have a empty allocated pointer-pointer array (only allocated from boardHeight) of type char
Postcondition: Will fully allocate the pointer array with boardWidth length and type char for each of the
prexisting rows
*/
void craftBoard(char **board, int boardWidth, int boardHeight);

/*
Precondition: Must take in a fully allocated pointer-pointer array of boardWidthxboardHeight
Postcondition: Will display the board in terminal with a key to understand
that x increases with value when going to the right, and y increases
with value when going visually down the gridded board
*/
void displayBoard(char **board, int boardWidth, int boardHeight);

/*
Precondition: Must take in a properly allocated board, as well as coordinates which are less than the
board size (x < boardWidth, y < boardHeight) to make sure player is placing icon on
real spaces
Postcondition: Will place the players icon in the array at the set position indicated
*/
void writeToBoard(char **board, int xCoord, int yCoord, char playersMarker);

/*
Precondition: Must have a properly allocated pointer-pointer array of type char; also
needs actual boardWidth and boardHeight to make sure its not reaching out of bounds of the
board
Postcondition: Will determine if player passed through the parameter has gotten a full row,
column, or corner-to-corner win; determined by if their icon occupies that whole slot. If so,
gameStatus will turn to false (turning off round of game) and will add one to player's win
total. Also, will print in terminal that the player won that round.
*/
void checkBoard(char **board, int boardWidth, int boardHeight, bool &gameStatus, Player &player);


// End of Prototypes and Function Descriptions

// Point struct works to contain traits of a (x,y) coordinate
struct Point 
{
    int x;
    int y;
};

void craftBoard(char **board, int boardWidth, int boardHeight)
{
    // Step = 0 means row with placable spots; 1 means row with implacable spots (grid line)
    int step = 0;
    for(int i = 0; i < boardHeight; i++)
    {
        if(step == 0){
            board[i] = new char[boardWidth];
            for(int d = 0; d < boardWidth; d++)
            {
                if(d%2 == 0)
                {
                board[i][d] = ' ';
                }
                else
                {
                    board[i][d] = '|';
                }
            }
            step = 1;
        }
        else
        {
            if(boardWidth%2 == 0)
            {
                board[i] = new char[boardWidth];
            }
            else
            {
            board[i] = new char[boardWidth];
            }
            for(int d = 0; d < boardWidth; d++)
            {
                if(d != 0 && (d+1)%2 == 0)
                {
                    board[i][d] = '+';
                }
                else
                {
                    board[i][d] = '-';
                }
            }
            step = 0;
        }
    }
}

void displayBoard(char **board, int boardWidth, int boardHeight)
{
    cout << "\n\n\n"; // Seperate from other text
    cout << "Going Right x -> +\n\n";
    for(int i = 0; i < boardHeight; i++)
    {
        cout << board[i] << endl;
    }
    cout << "\n\nGoing Down y -> +\n\n";
}

void writeToBoard(char **board, int xCoord, int yCoord, char playersMarker)
{
    if(board[xCoord*2][yCoord*2] == ' ')
    {
        board[xCoord*2][yCoord*2] = playersMarker;
    }
    else
    {
        do
        {
            cout << "Sorry, that spot is invalid to be filled pick another (x y): ";
            cin >> xCoord >> yCoord;
            // Reduce it so 1 1 points to the 0 0 element
            xCoord--;
            yCoord--;
        } while(board[xCoord*2][yCoord*2] != ' ');
        board[xCoord*2][yCoord*2] = playersMarker;
    }
}

void checkBoard(char **board, int boardWidth, int boardHeight, bool &gameStatus, Player &player)
{
    // Only look for Row win if Row is > 1
    if(boardWidth > 1)
    {
    for(int row = 0; row < boardHeight; row++)
    {
        for(int col = 0; col < boardWidth; col++)
        { 
            if(board[row][col] != player.icon && board[row][col] != '|')
            {
                break;
            }
            else if(col == boardWidth-1)
            {
                cout << "\nWinner is Player " << player.PLAYER_NUM << "!!\n";
                gameStatus = false; // Stop game
                player.totalWins++;
                return;
            }
        }
    }
    }
    // Only look for Column win if Column is > 1
    if(boardHeight > 1)
    {
    for(int col = 0; col < boardWidth; col++)
    {
        for(int row = 0; row < boardHeight; row++)
        { 
            if(board[row][col] != player.icon && board[row][col] != '-' && board[row][col] != '+')
            {
                break;
            }
            else if(row == boardHeight-1)
            {
                cout << "\nWinner is Player " << player.PLAYER_NUM << "!!\n";
                gameStatus = false; // Stop game
                player.totalWins++;
                return;
            }
        }
    }
    }
    // Only look for cross win if width and height are equal
    if(boardHeight == boardWidth)
    {
        // Check left-to-right
        for(int step = 0; step < boardWidth; step++)
        {
            if(board[step][step] != player.icon && board[step][step] != '+')
            {
                break;
            }
            else if(step == boardWidth-1)
            {
                cout << "\nWinner is Player " << player.PLAYER_NUM << "!!\n";
                gameStatus = false; // Stop game
                player.totalWins++;
                return;
            }
        }
        // Check right-to-left
        int ystep = 0;
        for(int xstep = boardWidth-1; xstep >= 0; xstep--)
        {
            if(board[xstep][ystep] != player.icon && board[xstep][ystep] != '+')
            {
                break;
            }
            else if(xstep == 0)
            {
                cout << "\nWinner is Player " << player.PLAYER_NUM << "!!\n";
                gameStatus = false; // Stop game
                player.totalWins++;
                return;
            }
            ystep++;
        }
    }
}

 
int main()
{
    // Allocate Space for essential variables
    Point picked_Spot;
    bool turn = true; // Toggle between players (1 (true) -> player 1; 0 (false) -> player 2)
    bool gameState = true; // Game is running.
    Player p1;
    Player p2;
    p1.PLAYER_NUM = 1;
    p2.PLAYER_NUM = 2;
    int game_Height;
    int game_Width;
    // Clear screen of commands
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Hello! Welcome to Tic-Tac-Toe Homie!! This game will ask for a width and height of the play-space in which the game of Tic-Tac-Toe will take place (At least 1x1). The game consists of two players which place their icon on a open space; you win by placing a set of your icons on a whole column, row, or from corner-to-corner (only of squared boards [3x3, 4x4, etc.]) with your icon without having your opponent do the same or place his icon on your path to success! The game lasts as long as you like, and the placement of your icons will be in a \"x y\" order where the quotes are dropped and your coordinates are seperated just by a space and start at 1 inclusive. Good luck, and may the best Gamer win!\n\n\n";
    //
    // Requests size of board
    cout << "\n\n\nSup Homie!!! How big do you want your game to be? (width height): ";
    do // Make sure board is valid size (size > 0)
    {
        try
        {
            cin >> game_Width >> game_Height;
            if(game_Width <= 0 || game_Height <= 0)
            {
                throw 13;
            }
        }
        catch(int e)
        {
            cout << "\nCannot have negative board try again\n";
        }
    } while(game_Height <= 0 || game_Width <= 0);
    // Doubles because needs width amount of playable slots as 1/2 of the length is grid
    game_Height *= 2;
    game_Width *= 2;
    game_Height--; // De-increments to make sure not another column of just visual seperators is added
    game_Width--; // De-increments to make sure not another row of just visual seperators is added
    // ^^
    // Request player 1 icon
    cout << "\nSup Player 1 what do you want as you're icon?\n";
    do // Make sure players icon is valid and isn't a board building block
    {
    try
    {
        cin >> p1.icon;
        if(p1.icon == '-' || p1.icon == '+' || p1.icon == '|')
        {
            throw 13;
        }
    }
    catch(int e)
    {
        cout << "\nInvalid Spot Player 1, try again: ";
    }
    } while(p1.icon == '-' || p1.icon == '+' || p1.icon == '|');
    // Request player 2 icon
    cout << "\nSup Player 2 what do you want as you're icon?\n";
    do // Make sure players icon is valid and isn't player 1's
    {
    try
    {
        cin >> p2.icon;
        if(p2.icon == '-' || p2.icon == '+' || p2.icon == '|' || p2.icon == p1.icon)
        {
            throw 13;
        }
    }
    catch(int e)
    {
        cout << "\nInvalid Spot Player 2, try again: ";
    }
    } while(p2.icon == '-' || p2.icon == '+' || p2.icon == '|' || p2.icon == p1.icon); // Cannot have same value

    // Use variables gained to make gameBoard as well as display it
    char* gameBoard[game_Height];
    craftBoard(gameBoard, game_Width, game_Height);
    displayBoard(gameBoard, game_Width, game_Height);
    
    while(gameState) // Main Game Loop
    {
        // Request Players move
        if(turn)
        { // Player One Move
            do
            {
                cout << "Whats your move Homie 1? (x y) ";
                cin >> picked_Spot.x >> picked_Spot.y;
            } while(picked_Spot.x <= 0 || picked_Spot.y <= 0 || picked_Spot.x-1 > game_Width/2 || picked_Spot.y-1 > game_Height/2);
            writeToBoard(gameBoard, picked_Spot.x-1, picked_Spot.y-1, p1.icon); // Write players point on board
            turn = false; // toggle player 2's turn
        }
        else
        { // Player Two Move
            do
            {
                cout << "Whats your move Homie 2? (x y) ";
                cin >> picked_Spot.x >> picked_Spot.y;
            } while(picked_Spot.x <= 0 || picked_Spot.y <= 0 || picked_Spot.x-1 > game_Width/2 || picked_Spot.y-1 > game_Height/2);
            writeToBoard(gameBoard, picked_Spot.x-1, picked_Spot.y-1, p2.icon);
            turn = true; // toggle back to player 1's turn
        }

    // Display Board
    displayBoard(gameBoard, game_Width, game_Height);
    // Check each players icon for win
    checkBoard(gameBoard, game_Width, game_Height, gameState, p1); // Check Player 1
    checkBoard(gameBoard, game_Width, game_Height, gameState, p2); // Check Player 2
    if(!gameState)
    {
        int restart = 0;
        cout << "\nPlayer 1 won " << p1.totalWins << " game(s)! \n\n";
        cout << "Player 2 won " << p2.totalWins << " game(s)! \n\n";
        cout << "Do you wish to play again? (yes = 1, no = 0): ";
        cin >> restart;
        if(restart == 1)
        {
            gameState = true;
            turn = true;
            craftBoard(gameBoard, game_Width, game_Height);
            displayBoard(gameBoard, game_Width, game_Height);
        }
    }
    }
    // Closing goodbye Message (long line break to seperate the message)
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAfter the heated games, Player 1 won " << p1.totalWins << " game(s)! \n\n";
    cout << "After the heated games, Player 2 won " << p2.totalWins << " game(s)! \n\n\n";
    cout << "\nGoodBye Homie(s)!!! EZ claps all around !!!! \n\n";
}