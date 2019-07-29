# Data Structures (Classes) needed to implement for the `IDA*` Algorithm:
- **Linked List**
- **Stack**
- **15Puzzle**
- **25Puzzle**
- **Tree**


## IDA* Pseudocode:
```
path <- current search path [STACK ADT]
node <- current node [last node in path]
g <- cost to reach current node
f(n) <- estimated cost of cheapeast path [ROOT ----> NODE -----> GOAL]
h(n) <- estimated cost of cheapest path [NODE ----> GOAL]
cost(node, successor) <- step cost [NODE ---> SUCCESSOR]
is_goal(node) <- goal test
successors(node) <- node expanding function ordered by `g+h(node)`
ida_star(root) <- return either "NOT_FOUND" or a pair with the best path and its cost.

function ida_star(root) {
  bound <- h(root)
  path <- [root]
  while (TRUE){
    t <- search(path,0,bound)
    if(t == "FOUND"){
      return (path,bound)
    }
    if(t==Infinity){
      return "NOT_FOUND"
    }
    bound <- t
  }
}

function search(path,g,bound){
  node <- path.last()
  f <- g + h(node)
  if(f > bound){
    return f
  }
  if is_goal(node){
    return FOUND
  }
  min <- Infinity
  for s in successors(node) {
    if(s not in path){
      path.push(s)
      t <- search(path,g + cost(node,s),bound)
      if(t==FOUND){
        return FOUND
      }
      if(t < min){
        min <- t
      }
      path.pop()
    }
  }
  return min
}
```
