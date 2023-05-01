// Prim's Algorithm in C

#include <stdio.h>
#include <limits.h>

#define V 5 // number of vertices in graph

// function to find the vertex with minimum key value
int minKey(int key[], int mstSet[])
{
    // initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// function to print the constructed MST
void printMST(int parent[], int G[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, G[i][parent[i]]);
}

// function to construct and print MST
void primMST(int G[V][V])
{
    // array to store constructed MST
    int parent[V];

    // key values used to pick minimum weight edge
    int key[V];

    // to represent set of vertices not yet included in MST
    int mstSet[V];

    // initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // always include first 1st vertex in MST
    key[0] = 0;     // make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // first node is always root of MST

    // the MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // add the picked vertex to the MST set
        mstSet[u] = 1;

        // update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)

            // update the key only if G[u][v] is smaller than key[v]
            if (G[u][v] && mstSet[v] == 0 && G[u][v] < key[v])
                parent[v] = u, key[v] = G[u][v];
    }

    // print the constructed MST
    printMST(parent, G);
}

// driver program to test above function
int main()
{
    /* create a 2d array of size VxV for adjacency matrix to represent graph */
    int G[V][V];
    
    printf("Enter the adjacency matrix row by row:\n");
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&G[i][j]);
        }
    }

    // print the solution
    primMST(G);

    return 0;
}