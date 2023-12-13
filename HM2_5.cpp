#include <iostream>
#include <vector>

#define For(i,start,end) for(int i {start}; i < end ; ++i)

using namespace std;

int findKey (vector<int> vec , int key);
struct node
{
    int data {};
    node* left {nullptr};
    node* right {nullptr};
};

class MyTree 
{
    public:

        MyTree();
        node* creatTree(vector<int> , vector<int>);
  
    private:

        node* root {nullptr};
    

};

MyTree::MyTree()
{}

node* MyTree::creatTree(vector<int> arrInorder,vector<int>arrPostOrder)
{
    if(arrInorder.size() < 1)
        return nullptr;

    int rootData = arrPostOrder[arrPostOrder.size()-1];
    node* root = new node ;
    root->data = rootData ;

    int rootIndex = findKey(arrInorder,rootData);
    
    vector<int> tempIn ;
    vector<int> tempPos;
    For(i,0,rootIndex)
    {
       tempIn.push_back(arrInorder[i]);
       tempPos.push_back(arrPostOrder[i]);
    }

    for(auto i:tempIn)
        cout << i << " ";
    cout << '\n';
    for(auto i:tempPos)
        cout << i << " ";
    cout << '\n';
    cout << '\n';

    vector<int> tempIn2 ;
    vector<int> tempPos2;
    For(i,rootIndex+1,int(arrInorder.size()))
    {
        tempIn2.push_back(arrInorder[i]);
        tempPos2.push_back(arrPostOrder[i-1]);
    }


    for(auto i:tempIn2)
        cout << i << " ";
    cout << '\n';
    for(auto i:tempPos2)
        cout << i << " ";
    cout << '\n';
    cout << '\n';



    return nullptr;
}

int findKey (vector<int> vec , int key)
{
    For(i,0,int(vec.size()))
        if(vec[i] == key)
            return i;

    cerr << "fucckkk key not found\n";
    return -1;
}





int main ()
{
    int n {};
    cin >> n;

    vector<int> arrInorder  (n);
    vector<int> arrPostOrder(n);
    For(i,0,n)
        cin >> arrInorder[i];
    For(i,0,n) 
        cin >> arrPostOrder[i];

    MyTree tree;

    tree.creatTree(arrInorder,arrPostOrder);

    return 0;
}