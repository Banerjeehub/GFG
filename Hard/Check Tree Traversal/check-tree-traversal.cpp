//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//Back-end complete function Template for C++

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    public:
    int ind = 0;
    Node *generateTree(int pre[],int in[],int i,int j,unordered_map<int,int>&mp,int n){
        if(i>j || ind==n){
            return NULL;
        }
        int currElement = pre[ind++];
        Node *root = new Node(currElement);
        // if(i==j){
        //     return root;
        // }
        int mid = mp[root->data];  // yeah yaha per milega index
        root->left = generateTree(pre,in,i,mid-1,mp,n);
        root->right = generateTree(pre,in,mid+1,j,mp,n);
        return root;
    }
    void solve(Node *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->data);
    }
    bool checktree(int pre[], int in[], int post[], int N) 
    { 
    	// Your code goes here
    	unordered_map<int,int>mp; //map lega apun root->data ko dundne ke liye
        for(int i=0;i<N;i++){
            mp[in[i]] = i;            //index store toh krna padega 
        }
        Node *root = generateTree(pre,in,0,N-1,mp,N);
        vector<int>ans;
        solve(root,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=post[i]){
                return 0;
            }
        }
        return true;
    } 
};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 


// } Driver Code Ends