# CPP_ConsoleTikTackToeDynamicArray
A game of Tic-Tac-Toe. Uses a main game loop in the "main" function.
Uses boolean variable "turn" which could either be (1 (true),0 (false); 1 -> player 1; 0 -> player 2) and toggles
amongst these two states.

<img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/9b0c0b33-b084-4b11-8c8e-a75f8adc36f7" alt="Cornstarch <3" width="95" height="99">

Grid-style board (gameBoard) will be indexed for ease of use and will call upon a 
cout call for each player and their turn in a tuple-like style (x,y). The "gameBoard" size will also be
asked upon the user when the game initializes (craftBoard). Calculations for if someone has won will be done right after 
player calls their spot (determineWinner). Also, the player will be able to determine
which type of style of marker they wish to have (x,X,o,O, etc.). Game will declare winner in console
after the calculations are done and will ask if the players wish to restart, which will then reloop the game loop. 

----------------------------------------------
<img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/b0d5897e-f4a7-4c4e-ba7b-3f11e64bb589" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/b0d5897e-f4a7-4c4e-ba7b-3f11e64bb589" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/b0d5897e-f4a7-4c4e-ba7b-3f11e64bb589" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/b0d5897e-f4a7-4c4e-ba7b-3f11e64bb589" alt="Cornstarch <3" width="55" height="49">


**The Breakdown:**

  Our Program Consists Of Working With The Terminal In C++ To Use User-Input To Create And Play A Dynamic Free-For-All Of User-Defined Size Local Game Of Tic-Tac-Toe.

  On Startup Our Program Will Ask The User For Dimensions For Their Tic-Tac Board As Well As The Players' Icons.

  The Board Will Be Represented As A 2D-Array Of Chars, Allowing Our Board Not Technically To Be Defined Under Its Own Class/Wrapper. Using Functions We Will Change The State Of This Dynamic Board To Write, Display, And Check For Winner. 

  The Player Will Have Its Own Struct Holding Their Icon As Well As Player_Num (Used For Turn Number) And Their Total Win Count.

  After These Requests, We Will Start Our Main Game Loop. In This We Will Ask Player 1 -> Player **x**  For Their Action During This Turn. To Win This, On The Dynamic-Sized Map You Must Cover Either A Diagonal, Vertical, Or Corner-To-Corner With Only Your Icon As In Normal Tic-Tac-Toe.

  This Project Was Super Fun And Was Something I've Done Many Times But This Iteration Of The Game Was Really Refined And Fun To Make Even Though It Looks Quite Dainty With Its Terminal Output.

  Using Exceptions As Well As Interesting Tactics For Input Santiziation Was Fun For Me To Do And Taught Me To Think More Defensively In My Programming Tactics On Some Cases Compared To Contract-Based Ways As Sometimes You Cant Trust The User Sadly :/

<img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/ff048acd-2577-49d5-b958-21e2e50ff7cf" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/ff048acd-2577-49d5-b958-21e2e50ff7cf" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/ff048acd-2577-49d5-b958-21e2e50ff7cf" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/ff048acd-2577-49d5-b958-21e2e50ff7cf" alt="Cornstarch <3" width="55" height="49">


----------------------------------------------

**Features:**

![2024-01-1023-10-06-ezgif com-video-to-gif-converter](https://github.com/Kingerthanu/CPP_ConsoleTikTackToeDynamicArray/assets/76754592/ab14778e-c29c-45ff-b706-e7bd26b7415a)
