//heap sort

#include <iostream>

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

node* fucn (int* arrInorder,int* arrPostOrder,int start , int end)
{
    cout << "root :" << arrPostOrder[end-1] << '\n';

    int rootIndex = findKey(arrInorder,start,end,arrPostOrder[end-1]);

    cout << "left: ";
    For(i,start,rootIndex)
        cout << arrInorder[i] << " ";

    cout << "\nright: ";
    For(i,rootIndex+1,end)
        cout << arrInorder[i] << " ";

    return nullptr;
}

int main ()
{


    retrun 0;
}