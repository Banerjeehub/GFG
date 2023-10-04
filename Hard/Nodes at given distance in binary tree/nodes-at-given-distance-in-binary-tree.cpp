//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:
void findparent(Node* root, Node* pNode,map<Node*,Node*>&mp,int tar, Node* &start){
        if(!root)return;
        mp[root]=pNode;
        if(!start && root->data==tar)start=root;  //this line will not execute after getting first target
        findparent(root->left,root,mp,tar,start);
        findparent(root->right,root,mp,tar,start);
    }
 

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        
        map<Node*,Node*>mp; 
        Node *start=NULL;
        findparent(root,NULL,mp,target,start);
        
        map<Node*,bool>vis;
        queue<Node*>q;
        q.push(start);
        vis[start]=true; // mark vis so that again we are not storing same node and it will make infinite loop.
        int lvl=0;
        while(!q.empty()){
            int sz=q.size();
            if(lvl==k)break;
            for(int i=0; i<sz; i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                    }
                if(mp[curr] && !vis[mp[curr]]){
                    q.push(mp[curr]);
                    vis[mp[curr]]=true;
                }
                
               
            }
            lvl++;
        }
        vector<int>ans;
        ans.clear();
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
           
        }
        sort(ans.begin(),ans.end());
    
        
        return ans;
        
    }


};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends