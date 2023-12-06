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

    return -1;
}

node* fucn (int* arrInorder,int* arrLevel,int size)
{
    cout << "           " << arrLevel[0] << '\n';
    cout << "      /           \\     \n";
    cout << "     /             \\     \n";

    int rootIndex = findKey(arrInorder,0,size,arrLevel[0]);

    cout << "{";
    For(i,0,rootIndex)
        cout << arrInorder[i] << " ";
    cout << "}";
    cout << "\t { ";
    For(i,rootIndex+1,size)
        cout << arrInorder[i] << " ";

    cout << "}";

    return nullptr;
}

int main ()
{
    int n {};
    cin >> n;
    int arrIn[n] {} , arrLevel[n] {};

    For(i,0,n)
        cin >> arrIn[i];

     For(i,0,n)
        cin >> arrLevel[i];

    fucn(arrIn,arrLevel,n);

    return 0;
}