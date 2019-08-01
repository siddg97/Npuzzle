# IDA* Search Implementation for the 15-puzzle and 25-puzzle Sliding Problem

#### Group Members:
> Jinyoung __(Clara)__ Hong <br>
> __Siddharth__ Gupta

## Project Overview:
- We were required to implement a **memory-efficient** variant of the **`A* Search Algorithm`**.
- We chose the **`IDA* Search`** algorithm.
- The implementation is in __`C++`__.
- We chose to incoporate one *heuristics* in our implementation: __`The Manhattan Distance Heuristic`__.

<br>

## Summary:
- We initialize 10 instances of the `15-puzzle`. The instances are initialized with a **random** board state, which is solvable in nature. 
- We then use our implementation(s) to solve these and get certain stats about solving each of these instances like:
    + __`Time`__ to solve.
    + __`Nodes visited`__ before reaching goal.
    + __`Cost of shortest path`__ to reach goal.


## Citations:-
- IDA* Pseudocode - __[https://en.wikipedia.org/wiki/Iterative_deepening_A*#Pseudocode]__
- ShuffleArray() function - __[https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/]__
- C++ reference for various headers used - __[http://www.cplusplus.com/]__ and __[http://cppreference.com/]__
