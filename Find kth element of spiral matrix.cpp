/*
Spiral matrix:
=============
The Spiral Matrix problem takes a 2-Dimensional array of N-rows and M-columns as an input,
and prints the elements of this matrix in spiral order.
The spiral begins at the top left corner of the input matrix,
and prints the elements it encounters, while looping towards the center of this matrix, in a clockwise manner.
Problem:
============
Given a matrix with n rows and m columns. Your task is to find the kth element which is obtained while traversing the matrix spirally. 
You need to complete the method findK which takes four arguments the first argument is the matrix A
and the next two arguments will be n and m denoting the size of the matrix A and then the forth argument is an integer k.
The function will return the kth element obtained while traversing the matrix spirally.
Input:
============
n = 4, m = 4, k = 10
A[][] = {{1  2  3  4},
         {5  6  7  8},
         {9  10 11 12},
         {13 14 15 16}}
Output:
13
Explanation:​
The spiral order of matrix will look like 1->2->3->4->8->12->16->15->14->13->9->5->6->7->11->10.
So the 10th element in this order is 13. 
===============================================
Approach :
================================================
It's an implementation based question.
This seems to be a pattern , firstly we move to right of the matrix and then towards the bottom of the matrix , and then to left 
finally we move to top of the given matrix.
Observation of the pattern:
==========================
      Right--> Bottom --> Left --> Top
Pseudocode:
=========
    First we moving to left to right , in this we can observe that the column varies ,but the row becomes constant.
    for(left->right)
    {
      ve.push_back(a[top][i])
    }
    top++;
    Then we are moving from top to bottom , in this we can observe that row varies , but the column remains constant.
    for(top->bottom)
    {
      ve.push_back(a[i][right])
    }
    right--;
    Then we are moving from right to left , here the column varies but row remains constant.
    for(right->left)
    {
      ve.push_back(a[bottom][i])
    }
    bottom--;
    Then we are moving to bottom to top , here the row varies but column remains constant.
    for(bottom->top)
    {
       ve.push_back(a[i][left]);
    }
    left++;
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<int>ve;
 		int left=0, right=m-1;
 		int top=0, bottom=n-1;
 		//right->bottom-> left->top;
 		while(left<=right && top<=bottom)
 		{
 		    for(int i=left;i<=right;i++)
 		    {
 		     ve.push_back(a[top][i]);
 		    }
 	    	top++;
 		    for(int i=top;i<=bottom;i++)
 		    {
 		        ve.push_back(a[i][right]);
 		    }
 		    right--;
 		    if(top<=bottom)
 		    {
 		        for(int i=right;i>=left;i--)
 		        {
 		            ve.push_back(a[bottom][i]);
 		         }
 		        bottom--;
 		    }
 		    if(left<=right)
 		    {
 		        for(int i=bottom;i>=top;i--)
 		        {
 		            ve.push_back(a[i][left]);
 		        }
 		        left++;
 		    }
 	    }
 	   return ve[k-1];
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
