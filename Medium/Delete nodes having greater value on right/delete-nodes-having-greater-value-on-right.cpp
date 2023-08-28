//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution

{

    private:

    Node* Reverse(Node* head){

        

        Node* curr=head;

        Node* next=NULL;

        Node* prev=NULL;

        while(curr!=NULL){

            next=curr->next;

            curr->next=prev;

            prev=curr;

            curr=next;

        }

        return prev;

    }

    

    public:

    Node *compute(Node *head)

    {

       

    

    head=Reverse(head);

    Node* curr=head;

    int ma=head->data;

    Node* prev=head;

    head=head->next;

while(head){

    if(head->data>=ma){

        ma=head->data;

        prev=head;

        head=head->next;

    }

    else{

        prev->next=head->next;

        head=prev->next;

    }

    

}

   head=Reverse(curr);

   return head;

    

    }

};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends