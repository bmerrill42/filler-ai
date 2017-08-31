<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Filler</a>
<ul>
<li><a href="#sec-1-1">1.1. The game</a>
<ul>
<li><a href="#sec-1-1-1">1.1.1. Introduction</a></li>
<li><a href="#sec-1-1-2">1.1.2. The Filler</a></li>
</ul>
</li>
</ul>
</li>
<li><a href="#sec-2">2. Goals</a></li>
</ul>
</div>
</div>

# Filler<a id="sec-1" name="sec-1"></a>

## The game<a id="sec-1-1" name="sec-1-1"></a>

### Introduction<a id="sec-1-1-1" name="sec-1-1-1"></a>

Create your player to fight other students on the world famous (or infamous) Filler board. The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore. Have fun!

### The Filler<a id="sec-1-1-2" name="sec-1-1-2"></a>

• In this game, two players fight each other. They play one after the other.
• The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
• The board is defined by X columns and N lines, it will then become X\*N cells.
• At the beginning of each turn, you will receive your game piece.
• A game piece is defined by X columns and N lines, so it will be X\*N cells. Inside each game piece, will be included a shape of one or many cells.
• To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
• The shape must not exceed the dimensions of the board
• When the game starts, the board already contains one shape.
• The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

# Goals<a id="sec-2" name="sec-2"></a>

The goal of this project is to introduce you to basic algorithm and to have you manipulate inputs/outputs.
