The operation Union(x, y) replaces the set containing x and the set containing y with their union. Union first uses Find to determine the roots of the trees containing x and y.
If the roots are the same, there is nothing more to do. Otherwise, the two trees must be merged. This is done by either setting the parent pointer of x to y, or setting the parent
pointer of y to x.
The choice of which node becomes the parent has consequences for the complexity of future operations on the tree. If it is done carelessly, trees can become excessively tall.
For example, suppose that Union always made the tree containing x a subtree of the tree containing y. Begin with a forest that has just been initialized with elements 
1, 2, 3, ..., n, and execute Union(1, 2), Union(2, 3), ..., Union(n − 1, n). The resulting forest contains a single tree whose root is n, and the path from 1 to n passes 
through every node in the tree. For this forest, the time to run Find(1) is O(n).
In an efficient implementation, tree height is controlled using union by size or union by rank. 
Both of these require that a node store information besides just its parent pointer. This information is used to decide which root becomes the new parent. 
Both strategies ensure that trees do not become too deep.
In the case of union by size, a node stores its size, which is simply its number of descendants (including the node itself). When the trees with roots x and y are merged, 
the node with more descendants becomes the parent. If the two nodes have the same number of descendants, then either one can become the parent. In both cases, the size of the
new parent node is set to its new total number of descendants.



For union by rank, a node stores its rank, which is an upper bound for its height. When a node is initialized, its rank is set to zero. To merge trees with roots x and y, 
first compare their ranks. If the ranks are different, then the larger rank tree becomes the parent, and the ranks of x and y do not change. If the ranks are the same, 
then either one can become the parent, but the new parent's rank is incremented by one. While the rank of a node is clearly related to its height, storing ranks is 
more efficient than storing heights. The height of a node can change during a Find operation, so storing ranks avoids the extra effort of keeping the height correct. 


#include<bits/stdc++.h>
using namespace std;
#define V 200005

vector<vector<int>> graph[100005];

struct subset{
  int parent;
  int rank;
  };
  
  int find(struct subsets[] , int i)
  {
    if(subsets[i].parent != i )
     subsets[i].parent = find(subsets , subsets[i].parent);
     
     return subsets[i].parent;
  }
  
  //union of two sets x and y by using the union of rank
  
  void Union( struct subset subsets[] , int xroot , int yroot)
  {
    if(subsets[xroot].rank < subsets[yroot].rank)
             subsets[xroot].parent = yroot;
    else if(subsets[yroot].rank < subsets[xroot].rank)
             subsets[yroot].parent=xroot;
    else
        {
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
        }
   }
   
   bool cycle_detect(vector<vector<int>> graph[])
   {
      struct subset * subsets = new subset[V];
      for(int i=0;i<V;i++)
      {
          subsets[i].rank=0;
          subsets[i].parent=i;
      }
      for(int i=0;i<edges;i++)
      {
        int x= find(subsets , graph->edge[i].src);
        int y= find(subsets , graph->edge[i].dest);
        if(x==y)
        return true;
        
        Union(subsets , x,y);
    }
    
  //Implementing only the essential elements of the function.

  
  
  
  
  
  
  
  
  
  
  
  
  
   
