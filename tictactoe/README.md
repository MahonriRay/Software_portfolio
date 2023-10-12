# Overview  

This is a project where I took old code source from a previous class, implemented it into C++ and added a MiniMax algorithm. The code I changed for this project was for a simple tic tac toe game that was written in C. Changing the code into C++ wasn't the hardest task about this project, but it still garnered me having to learn quite a bit about C++. Which because of this, I really have started to like C++ and all it's capabilities even though I feel I have just scratched the surface.  

## MiniMax Algorithm  
By far the hardest part about this project I undertook was implementing the MiniMax algorith into a game as "simple" as tic tac toe. A short overview of the MiniMax algorithm is that it is used to calculate possible states of the program that may come to be. While these states are being calculated, each decision is given a "weight" or "score" along the way. As the name implies, one side of the algorithm will be trying to *MINIMIZE* the score, while the other side will try to do the opposite and *MAXIMIZE* the score. Since tic tac toe is a turn based game with two players, this can be easier to visualize. The *MAX*, which in this program is the "COMPUTER", will always choose the decision with the highest possible score. Then the *MINI*, "PLAYER", will make a decision unbeknownst of the weight, which is important to know. Even if the *MINI* doesn't always choose the decision or route with the lowest possible score, the *MAX* will then make the decision from there with the highest score. Recurring until it wins or the game is over. As long as the "COMPUTER" in this program goes first, most games will end in a draw and the "PLAYER" will **NEVER** win.  

[Software Demo Video](https://youtu.be/VMBWO1rsMPM)  

## Development Environment  
For my environment it was a little bit of a challenge to be able to work on my project. My laptop is a MacBook so I was mostly utilizing my Windows PC to develop this program. Using my laptop only when it was absolutely necessary. The use of the debugger in VSCode greatly helped me troubleshoot all of the issues that would arise.

## Useful Websites  

* [The Coding Train - Tic Tac Toe with MiniMax](https://www.youtube.com/watch?v=trKjYdBASyQ&t=831s)  
Super useful video that showed how a JavaScript program implemented the MiniMax function.

* [CledersonBC - GitHub Repository](https://github.com/Cledersonbc/tic-tac-toe-minimax)
Repository with code written in Python that helped me better understand the MiniMax algorithm and how it should run.
