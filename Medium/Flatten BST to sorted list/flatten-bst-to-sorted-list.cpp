//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void printList(Node *head)
{
    while (head)
    {
        if(head->left)
            cout<<"-1 ";
        cout << head->data << " ";
        head = head->right;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    //Another way
    /*void Inorder(vector<int> &v, Node *root){
        if(root==NULL)return;
        Inorder(v,root->left);
        v.emplace_back(root->data);
        Inorder(v,root->right);
    }
    
    Node *flattenBST(Node *root)
    {
        // code here
        vector<int>v;
        Inorder(v,root);
        Node *Ans = new Node(NULL);
        Node *t = Ans;
        for(auto it : v){
            Node *NN = new Node(it);
            if(Ans==NULL){
                Ans = NN;
                t = Ans;
            }
            else{
                t -> right = NN;
                t = NN;
            }
        }
        return Ans = Ans->right;
    }*/
    void Inorder(Node* &t, Node* root){
        if(root==NULL)return;
        Inorder(t,root->left);
        Node *NN = new Node(root->data);
        if(t==NULL){
            t = NN;
        }
        else{
            t -> right = NN;
            t = NN;
        }
        Inorder(t,root->right);
    }
    
    Node *flattenBST(Node *root)
    {
        // code here
        
        Node *Ans = new Node(NULL);
        Node *t = Ans;
        Inorder(t,root);
        return Ans = Ans->right;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    }
    return 0;
}


// } Driver Code Ends
