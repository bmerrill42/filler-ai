<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Introduction</a></li>
<li><a href="#sec-2">2. Filler</a>
<ul>
<li><a href="#sec-2-1">2.1. The Filler</a></li>
<li><a href="#sec-2-2">2.2. The Board</a></li>
<li><a href="#sec-2-3">2.3. The tokens</a></li>
</ul>
</li>
<li><a href="#sec-3">3. The topic</a>
<ul>
<li><a href="#sec-3-1">3.1. The Player</a></li>
</ul>
</li>
<li><a href="#sec-4">4. Goals</a></li>
<li><a href="#sec-5">5. My strategy</a></li>
</ul>
</div>
</div>

# Introduction<a id="sec-1" name="sec-1"></a>

Create your player to fight other students on the world famous (or infamous) Filler board. The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore. Have fun!

# Filler<a id="sec-2" name="sec-2"></a>

## The Filler<a id="sec-2-1" name="sec-2-1"></a>

-   In this game, two players fight each other. They play one after the other.
-   The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
-   The board is defined by X columns and N lines, it will then become X\*N cells.
-   At the beginning of each turn, you will receive your game piece.
-   A game piece is defined by X columns and N lines, so it will be X\*N cells. Inside each game piece, will be included a shape of one or many cells.
-   To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
-   The shape must not exceed the dimensions of the board
-   When the game starts, the board already contains one shape.
-   The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

## The Board<a id="sec-2-2" name="sec-2-2"></a>

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

## The tokens<a id="sec-2-3" name="sec-2-3"></a>

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

# The topic<a id="sec-3" name="sec-3"></a>

## The Player<a id="sec-3-1" name="sec-3-1"></a>

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

# Goals<a id="sec-4" name="sec-4"></a>

The goal of this project is to introduce you to basic algorithm and to have you manipulate inputs/outputs.

# My strategy<a id="sec-5" name="sec-5"></a>

My player scans the whole board for legal spots to place a piece, when it finds a legal spot it stores that in a linked list with the count of the surrounding enemy and friendly pieces.
