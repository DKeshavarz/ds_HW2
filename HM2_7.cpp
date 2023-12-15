#include <iostream>
#include <vector> 
#include <sstream>
#include <stack>

class Node
{
    public:
        Node(int =-1, Node* =nullptr, Node* =nullptr);
        operator std::string () ;

        void addLeftChilde (Node*);
        void addRightChilde(Node*);

        int   getData   (){return data;}
        Node* leftChild (){return left ;}
        Node* rightChild(){return right;}
    private:
        int data {-1};
        Node* left  {nullptr};
        Node* right {nullptr};
};

class MyTree 
{
    public:
        MyTree(Node* =nullptr);

        std::string dfs(); /* pre order*/
        bool contionTree(MyTree);

        Node* getRoot() {return root;};
    private:
        Node* root {nullptr};

        std::string dfsFrom(Node *);
        void findKeys(std::stack<Node*>&,int,Node*);


};
using namespace std;
bool MyTree::contionTree(MyTree input)
{
    stack<Node*> myStack ;
    findKeys(myStack,input.getRoot()->getData(), root);

    string dfs = dfsFrom(input.getRoot());
    while(myStack.size() > 0)
    {
        Node* front {myStack.top()};
        
        if(dfsFrom(front) == dfs)
            return true;

        myStack.pop();
    }

    return false;
}
void MyTree::findKeys(stack<Node*>& myStack, int key , Node* root)
{
    if(!root) return ;

    if(root->getData() == key) myStack.push(root);

    findKeys(myStack,key,root->leftChild ());
    findKeys(myStack,key,root->rightChild());
}
int main ()
{
    Node a6 (6) , a30(30) ;
    Node a4 (4,nullptr,&a30);
    Node a10(10,&a4,&a6);

    MyTree firstTree (&a10);
    cout << firstTree.dfs() << '\n';

    //*******************************

    Node b6 (6) , b30(30) , b3Leaf (3);
    Node b4 (4,nullptr,&b30) , b3(3,nullptr,&b3Leaf);
    Node b10(10,&b4,&b6);
    Node b26(26,&b10,&b3);

    MyTree secondTree (&b26);
    cout << secondTree.dfs() << '\n';

    //*******************************

    cout << secondTree.contionTree(firstTree);

    return 0;
}

//start class Node function..................................
Node::Node(int d ,Node* l,Node* r):data(d),left(l),right(r)
{}
Node::operator std::string () 
{
    stringstream outPut;
    outPut << data ;

    if(left)  outPut << " L: " << left->getData();
    else       outPut << " L: " << "empty";
    if(right) outPut << " R: " << right->getData();
    else       outPut << " R: " << "empty";

    return outPut.str();
}
void Node::addLeftChilde (Node*input)
{
    this-> left = input; 
}
void Node::addRightChilde(Node* input)
{
    this-> right = input; 
}
//end class Node function.....................................

//start class MyTree functions................................
MyTree::MyTree(Node* root)
{
    this->root = root;
}
string MyTree::dfs()
{
    return dfsFrom(root);
}
string MyTree::dfsFrom(Node *root)
{
    if(!root) return "";

    stringstream output ;

    output << root->getData()             << " " 
           << dfsFrom(root->leftChild() ) << " "
           << dfsFrom(root->rightChild()) << " ";

    return output.str();
}
//end class MyTree functions..................................