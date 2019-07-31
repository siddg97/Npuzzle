# IDA* Search Implementation for the 15-puzzle and 25-puzzle Sliding Problem

#### Group Members:
> Jinyoung __(Clara)__ Hong <br>
> __Siddharth__ Gupta

## Project Overview:
- We were required to implement a **memory-efficient** variant of the **`A* Search Algorithm`**.
- We chose the **`IDA* Search`** algorithm.
- The implementation is in __`C++`__.
- We chose to incoporate two main *heuristics* in our implementation:
  + __`Manhattan Distance Heuristic`__
  + __`Eucledian Square Heuristic`__
> __NOTE:-__
> We also use the maximum of the two heuristics above to get a __third__ heuristic!

## Summary:
- We initialize 20 instances of the `15-puzzle` and the `25-puzzle` as well. The instances are initialized with a **random** board state, which is solvable in nature. 
- We then use our implementation(s) to solve these and get certain stats about solving each of these instances.
