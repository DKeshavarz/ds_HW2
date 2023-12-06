#include <iostream>

#define For(i,start,end) for(int i {start}; i < end ; ++i)

using namespace std;

struct node
{
    int data {};
    node* left {nullptr};
    node* right {nullptr};
};

int findKey (int* arr, int start, int end ,int key)
{
    For(i,start,end)
        if(arr[i] == key)
            return i;

    cerr << "fucckkk key not found\n";
    return -1;
}

node* fucn (int* arrInorder,int* arrPostOrder,int start , int end , int postRoot)
{
    if(start == end)
        cout << "end\n";
    
    cout << "root :" << arrPostOrder[postRoot] << '\n';

    int inRoot = findKey(arrInorder,start,end,arrPostOrder[postRoot]);

    cout << "left: ";
    For(i,start,inRoot)
        cout << arrInorder[i] << " ";

    cout << "\nright: ";
    For(i,inRoot+1,end)
        cout << arrInorder[i] << " ";

    return nullptr;
}



int main ()
{
    int n {};
    cin >> n;

    int arrInorder[n]  {};
    int arrPostOrder[n] {};
    For(i,0,n)
        cin >> arrInorder[i];
    For(i,0,n) 
        cin >> arrPostOrder[i];

    fucn(arrInorder,arrPostOrder,0,n,n-1);

    return 0;
}