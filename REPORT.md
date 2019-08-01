# IDA* Search Implementation for the 15-puzzle and 25-puzzle Sliding Problem

### Group Members:
#### Jinyoung __(Clara)__ Hong <br>
####__Siddharth__ Gupta

#### NOTE:
>We worked on this project using the __pair-programming__ methodology. In this we basically sat down and one person would code and the other would be actively reviewing the code currently written. We would switch the roles of __programmer__ and __reviewer__ every time we got together to work on the project.

## Project Overview:
- We were required to implement a **memory-efficient** variant of the **`A* Search Algorithm`**.
- We chose the **`IDA* Search`** algorithm.
- The implementation is in __`C++`__.
- We chose to incoporate one *heuristic* in our implementation: __`The Manhattan Distance Heuristic`__.
- We use a pattern database for the manhattan distance heuristic.

## Summary:
- We initialize 20 instances of the __`15-puzzle`__. These instances are initialized with a **random** board state, which is solvable in nature. 
- We then use our implementation(s) to solve and get certain stats about solving each of these instances. Stats are namely:
    + __`Time`__ to solve.
    + __`Nodes visited`__ before reaching goal.
    + __`Cost of shortest path`__ to reach goal.

- We also made a solver for the __25 puzzle__ problem using the __`IDA* Search`__ algorithm:
    + This solver is not the most optimal but it does solve a "good-enough" instance of a random 25 puzzle.
    + It uses the manhattan distance heuristic as well.

## Running Instructions:
- We made 2 separate files for each solver:
    + __`15p.cpp`__ => The 15 puzzle solver.
    + __`25p.cpp`__ => The 25 puzzle solver.
- You can run the desired program using the following commands (once in the root directory of the project in your terminal)[On an Ubunutu machine]:
    + __`make p15 && ./a.out`__ => For running the __15-puzzle solver__.
    + __`make p25 && ./a.out`__ => For running the __25-puzzle solver__.

## Citations:-
- IDA* Pseudocode - __[https://en.wikipedia.org/wiki/Iterative_deepening_A*]__
- ShuffleArray() function - __[https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/]__
- C++ reference for various header modules used - __[http://www.cplusplus.com/]__ and __[http://cppreference.com/]__
