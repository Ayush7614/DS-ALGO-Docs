---
title: Depth First Search
slug: /graphs/Depth First Search/DFS
---


## Introduction

The DFS algorithm is a recursive algorithm that uses the idea of backtracking. 
It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path,
you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the
unvisited nodes have been traversed after which the next path will be selected.

The data structure which is being used in DFS is stack. The process is similar to BFS algorithm. 
In DFS, the edges that leads to an unvisited node are called discovery edges
while the edges that leads to an already visited node are called block edges.  




##Approach: 

 Depth-first search is an algorithm for traversing or searching tree or graph data structures.
 The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and
 as far as possible along each branch before backtracking. So the basic idea is to start from the root or any arbitrary node 
 and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. 
 Then backtrack and check for other unmarked nodes and traverse them. Finally print the nodes in the path.






##Algorithm

Step 1: SET STATUS = 1 (ready state) for each node in G
Step 2: Push the starting node A on the stack and set its STATUS = 2 (waiting state)
Step 3: Repeat Steps 4 and 5 until STACK is empty
Step 4: Pop the top node N. Process it and set its STATUS = 3 (processed state)
Step 5: Push on the stack all the neighbours of N that are in the ready state (whose STATUS = 1) and set their
STATUS = 2 (waiting state)
[END OF LOOP]
Step 6: EXIT 





Pseudocode

    DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
      let S be stack
      S.push( s )            //Inserting s in stack 
      mark s as visited.
      while ( S is not empty):
          //Pop a vertex from stack to visit next
          v  =  S.top( )
         S.pop( )
         //Push all the neighbours of v in stack that are not visited   
        for all neighbours w of v in Graph G:
            if w is not visited :
                     S.push( w )         
                    mark w as visited


    DFS-recursive(G, s):
        mark s as visited
        for all neighbours w of s in Graph G:
            if w is not visited:
                DFS-recursive(G, w)






###Example: 

Input: n = 4, e = 6 
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3 
Output: DFS from vertex 1 : 1 2 0 3 





## Code
``` C++

#include <iostream>
   #include <vector>
    using namespace std;

    vector <int> adj[10];
    bool visited[10];

    void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

    void initialize() {
        for(int i = 0;i < 10;++i)
         visited[i] = false;
    }

    int main() {
        int nodes, edges, x, y, connectedComponents = 0;
        cin >> nodes;                       //Number of nodes
        cin >> edges;                       //Number of edges
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;     
     //Undirected Graph 
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }

        initialize();                           //Initialize all nodes as not visited

        for(int i = 1;i <= nodes;++i) {
         if(visited[i] == false)     {
             dfs(i);
             connectedComponents++;
         }
        }
        cout << "Number of connected components: " << connectedComponents << endl;
        return 0;
    }

## Sample Input and Output:

## Input 
Adjacency list
Input File
6
4
1 2
2 3
1 3
4 5


##Output

Number of connected components: 3

Time complexity O(V+E) , when implemented using the adjacency list.






-----PYTHON

# Using a Python dictionary to act as an adjacency list
graph = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}

visited = set() # Set to keep track of visited nodes of graph.

def dfs(visited, graph, node):  #function for dfs 
    if node not in visited:
        print (node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

# Driver Code
print("Following is the Depth-First Search")
dfs(visited, graph, '5')



##Output

Following is the Depth-First Search
5 3 2 4 8 7



##Complexity Analysis: 

Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V). 
Since, an extra visited array is needed of size V.


## Credits
* [Akanksha Rai](https://github.com/akanksharai001) for the [C++ and python  implementation]
