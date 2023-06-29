/*
Given an undirected graph with V vertices.
We say two vertices u and v belong to a single province if there is a path from u to v or v to u.
Your task is to find the number of provinces.
Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]
Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. 
As city 1 and city 3 has a path between them they belong to a single province.
City 2 has no path to city 1 or city 3 hence it belongs to another province.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int>adjl[],int vis[])
    {
        vis[node]=1;
        for(auto it:adjl[node])
        {
            if(!vis[it])
            {
                dfs(it,adjl,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<int>adjl[n];
        //to change adjacency matrix to list
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        /*
            To check the provinces , we have to find whether the nodes can reach another node
            or not . if they were not able to move to another then the number of provinces count will be
            incremented
            we use a dfs algorithm to search whether they are reachable or not.
            
        */
       int vis[n]={0};
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i,adjl,vis);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
