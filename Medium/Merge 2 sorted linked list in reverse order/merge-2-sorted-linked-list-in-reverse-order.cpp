//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node *rev(Node * head){
         Node *temp=NULL;
        while(head!=NULL)
        {
            Node *temp1=head->next;
            head->next=temp;
            temp=head;
            head=temp1;
        }
        return temp;
    }
    
    Node* sorrt(Node *list1,Node *list2){
         if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->data<=list2->data){
			list1->next=sorrt(list1->next,list2);
			return list1;
		}
		else{
			list2->next=sorrt(list1,list2->next);
			return list2;
		}
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node * temp=sorrt(node1,node2);
        Node *res=rev(temp);
        return res;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends