/*
   # Kruskal's algorithm to find the minimum cost spanning tree uses the greedy approach. 
   # This algorithm treats the graph as a forest and every node it has as an individual tree
     (i.e. n connected components initially). 
   # A tree connects to another only and only if, it has the least cost among all available options and does 
     not violate MST properties.

   # Algorithm ---->
     1. Remove all loops and Parallel Edges.
        (In case of parallel edges, keep the one which has the least cost associated and remove all others.)
     2. Sort all edges in their increasing order of weight.
     3. Repeatedly add the first (n-1) edges which have the least weightage, iff it does not form a cycle
        i.e. add the least cost edge one by one whose vertices are present in 2 different connected components.
*/