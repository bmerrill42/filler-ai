<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Introduction</a></li>
<li><a href="#sec-2">2. Goals</a></li>
<li><a href="#sec-3">3. My strategy</a></li>
<li><a href="#sec-4">4. Subject</a>
<ul>
<li><a href="#sec-4-1">4.1. The Filler</a></li>
<li><a href="#sec-4-2">4.2. The Board</a></li>
<li><a href="#sec-4-3">4.3. The tokens</a></li>
<li><a href="#sec-4-4">4.4. The Player</a></li>
<li><a href="#sec-4-5">4.5. Multi Players</a></li>
<li><a href="#sec-4-6">4.6. How the game rolls</a></li>
</ul>
</li>
</ul>
</div>
</div>

# Introduction<a id="sec-1" name="sec-1"></a>

Create your player to fight other students on the world famous (or infamous) Filler board. The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore. Have fun!

# Goals<a id="sec-2" name="sec-2"></a>

The goal of this project is to introduce you to basic algorithm and to have you manipulate inputs/outputs.

# My strategy<a id="sec-3" name="sec-3"></a>

My player scans the whole board for legal spots to place a piece, when it finds a legal spot it stores that in a linked list with the count of the surrounding enemy and friendly pieces. 

# Subject<a id="sec-4" name="sec-4"></a>

## The Filler<a id="sec-4-1" name="sec-4-1"></a>

-   In this game, two players fight each other. They play one after the other.
-   The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
-   The board is defined by X columns and N lines, it will then become X\*N cells.
-   At the beginning of each turn, you will receive your game piece.
-   A game piece is defined by X columns and N lines, so it will be X\*N cells. Inside each game piece, will be included a shape of one or many cells.
-   To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
-   The shape must not exceed the dimensions of the board
-   When the game starts, the board already contains one shape.
-   The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

## The Board<a id="sec-4-2" name="sec-4-2"></a>

    A 14x30 board:
    Plateau 14 30:
    012345678901234567890123456789
    000 ..............................
    001 ..............................
    002 ..............................
    003 ..............................
    004 ..............................
    005 ..............................
    006 ..............................
    007 ..............................
    008 ...............O..............
    009 ..............................
    010 ..............................
    011 ..............................
    012 ..............................
    013 ..............................

## The tokens<a id="sec-4-3" name="sec-4-3"></a>

-   An example of a 4x7 token
    
        Piece 4 7:
        ...*...
        ...*...
        ...*...
        ..***..
-   An example of a 4x5 token
    
        Piece 4 5:
        .**..
        .***.
        ..*..
        .....
-   An example of a 3x6 token
    
        Piece 3 6:
        .****.
        **....
        *.....

## The Player<a id="sec-4-4" name="sec-4-4"></a>

-   The executable that will enable you to play the filler is attached to this subject.
    -   For this project, you will have to create a filler player. Your goal is to win:
    -   It will read the board and the game pieces placed on the standard output.
    -   Each turn the filler rewrites the board map and includes a new piece to be placed.
    -   In order to place the game piece on the board, the player will have to write it’s coordinates on the standard ouput.
    -   The following format must be used “X Y\n”.
    -   You will collect points each time you place a piece.
        
            Plateau 14 30:
            012345678901234567890123456789
            000 ..............................
            001 ..............................
            002 ..............................
            003 ..............................
            004 ..............................
            005 ..............................
            006 ..............................
            007 ..............................
            008 ...............O..............
            009 ..............................
            010 ..............................
            011 ..............................
            012 ..............................
            013 ..............................
            Piece 4 7:
            ...*...
            ...*...
            ...*...
            ..***..

## Multi Players<a id="sec-4-5" name="sec-4-5"></a>

-   Player number:
    -   The first two lines of the filler must be in the following format:
        
            $$$ exec pPLAYER_NUMBER : [PLAYER_NAME]
    -   The filler will only send the line that concerns your program. You’ll have to get your player number.
    -   If you are Player 1 your program will be represented by “o” and “O”. If you are Player 2, your program will be represented by “x” and “X”. The first step will be to get your player number.
    -   The lowercases (“x” or “o”) will highlight the piece last placed on the board. At the following turns, that same piece will be represented by the uppercase letters (“X” or “O”), as it won’t be the piece last placed anymore.
    -   You will collect points each time you place a piece.
-   How the game works
    -   At each turn, the filler will send the updated map and a new token to the player concerned.
    -   The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.
    -   The filler will send the map and a new piece to the other player.

## How the game rolls<a id="sec-4-6" name="sec-4-6"></a>

-   Here is an example on how a game will roll out.
    
        $>./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr
        $$$ exec p1 : [user1]
        $$$ exec p2 : [user2]
        Plateau 14 30:
        012345678901234567890123456789
        000 ..............................
        001 ..............................
        002 ..............................
        003 ..............................
        004 ......X.......................
        005 ..............................
        006 ..............................
        007 ..........................O...
        008 ..............................
        009 ..............................
        010 ..............................
        011 ..............................
        012 ..............................
        013 ..............................
        Piece 3 6:
        .****.
        **....
        *.....
        <got (O) : [7 24] (7,24)
        Plateau 14 30:
        012345678901234567890123456789
        000 ..............................
        001 ..............................
        002 ..............................
        003 ..............................
        004 ......X.......................
        005 ..............................
        006 ..............................
        007 .........................oooo.
        008 ........................oo....
        009 ........................o.....
        010 ..............................
        011 ..............................
        012 ..............................
        013 ..............................
        Piece 3 8:
        ......*.
        ......**
        .......*
        <got (X) : [4 0] (4,0)
        Plateau 14 30:
        012345678901234567890123456789
        000 ..............................
        001 ..............................
        002 ..............................
        003 ..............................
        004 ......x.......................
        005 ......xx......................
        006 .......x......................
        007 .........................OOOO.
        008 ........................OO....
        009 ........................O.....
        010 ..............................
        011 ..............................
        012 ..............................
        013 ..............................
        [...]
        == X fin : 175 [1018918090]
        == O fin : 168 [1018918090]
