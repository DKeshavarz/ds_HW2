#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

vector <int> mySplit (string s)
{
    stringstream ss(s);  
    vector<int> vec;
    string word;
    while (ss >> word) 
    { 
       vec.push_back(stoi(word));
    }
    return vec;
}
int main ()
{
    string str1,str2 ;
    getline(cin , str1);
    getline(cin , str2);
   
    vector<int> vec = mySplit(str1);
    int n {vec.size()};
    int arrIn[n] {} , arrLevel[n] {};

    For(i,0,n)
        arrIn[i] = vec[i];

    vec = mySplit(str2);

    For(i,0,n)
        arrLevel[i] = vec[i];

    fucn(arrIn,arrLevel,n);

    return 0;
}