# min max distance in graph of a subset of nodes [reference](https://github.com/sm745052/cp/blob/main/references/min_ugly_solution_codechef.html)
Let subset of a Graph be S \
define dist(x, S) = max(d(x, y)) y over all nodes in S \
then min(dist(x, S)) , x over all nodes of graph is >= ceil(d/2) where d is the longest path starting and ending in S.
# WHY?
take example where all nodes are in S. min distance node will lie in diameter. [prove by contradiction: suppose not] Then extend it.
