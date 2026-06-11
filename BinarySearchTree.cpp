#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor for the node class
    Node(string i, Node *l, Node *r) 
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree() 
    {
        ROOT = NULL; //initially set ROOT to null
    }

    //insert a node in the binary search tree
    void insert(string element)
    {
        Node* newNode = new Node(element, NULL, NULL); 

        newNode->info = element;
        newNode->leftchild = NULL;
        newNode->rightchild = NULL;

        Node *parent = NULL;
        Node *currentNode = NULL;

        search(element, parent, currentNode);

        if (parent == NULL) 
        {
            ROOT = newNode; 
            return;
        }

        if (element < parent->info) 
        {
            parent->leftchild = newNode; 
        }
        else if (element > parent->info) 
        {
            parent->rightchild = newNode; 
        }
    }

    //this function searches the current node of the specified node
    //as well as the current node of its parent
    void search(string element, Node* &parent, Node* &currentNode) 
    {
        currentNode = ROOT;
        parent = NULL;

        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;

            if (element < currentNode->info) 
                currentNode = currentNode->leftchild; 
            else 
                currentNode = currentNode->rightchild; 
            }
        }

        void inorder(Node* ptr) 
        {
            if (ROOT == NULL) 
            {
                cout << "Tree is empty" << endl;
                return;
            }

            if (ptr != NULL) 
            {
                inorder(ptr->leftchild); 
                cout << ptr->info << " "; 
                inorder(ptr->rightchild); 
            }
        }

        void preorder(Node* ptr) 
        {
            if (ROOT == NULL) 
            {
                cout << "Tree is empty" << endl;
                return;
            }

            if (ptr != NULL) 
            {
                cout << ptr->info << " "; 
                preorder(ptr->leftchild); 
                preorder(ptr->rightchild); 
            }
        }

        void postorder(Node* ptr) 
        {
            //performs postorder traversal of the tree
            if (ROOT == NULL) 
            {
                cout << "Tree is empty" << endl;
                return;
            }

            if (ptr != NULL) 
            {
                postorder(ptr->leftchild); 
                postorder(ptr->rightchild); 
                cout << ptr->info << " "; 
            }
        }
    };

int main()
{
    BinaryTree obj;
    
    while (true) 
    {
        cout << "Menu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        char ch;
        cin >> ch;

        cout << endl;

        switch (ch) 
        {
        case '1': 
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }
        case '2': 
        {
            obj.inorder(obj.ROOT);
            break;
        }
        case '3': 
        {
            obj.preorder(obj.ROOT);
            break;
        }
        case '4': 
        {
            obj.postorder(obj.ROOT);
            break;
        }
        case '5': 
            return 0;

        default: 
            {
                cout << "Invalid option" << endl;
                break;
            }
        }
        }
        return 0;
    }