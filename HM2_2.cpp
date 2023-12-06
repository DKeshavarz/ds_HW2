#include <iostream>

class Heap 
{
    public:
        Heap(int, int*);
        ~Heap();

        void buildHeap();
        void heapSort();
        void print();

    private:
        int size {};
        int* arr {nullptr};

        void heapify(int);
};

using namespace std;

Heap::~Heap()
{
    delete []arr;
}
Heap::Heap(int size, int *InputArr)
{
    this->size = size;
    arr = new int[size];
    for(int i {0}; i < size ; ++i)
        arr[i] = InputArr[i];
}
void Heap::print()
{
    for(int i {0}; i < size ; ++i)
        cout << arr[i] << "  ";
}
void Heap::heapify(int index)
{
    int max {index} ;
    int leftChilde {2*index+1};
    int rightChilde{2*index+2};

    max = leftChilde  < size && arr[leftChilde]  > arr[max] ? leftChilde  : max ;
    max = rightChilde < size && arr[rightChilde] > arr[max] ? rightChilde : max ;

    if(max != index)
    {
        swap(arr[max],arr[index]);
        this->heapify(max);
    }
}
void Heap::buildHeap()
{
    for (int i {size/2} ; i > -1 ; i--)
        this->heapify(i) ;
}
void Heap::heapSort()
{
    int sizeHolder {size};
    for (int i {0} ; i < sizeHolder ; ++i)
    {
        swap(arr[0],arr[size-1]);
        size--;
        heapify(0);
    }
    size = sizeHolder;
}
int main ()
{
    int n {};
    cin >> n;

    int* tempArr {new int[n]};
    for(int i {0}; i < n ; ++i)
        cin >> tempArr[i];

    Heap myHeap(n,tempArr);
    myHeap.buildHeap();
    myHeap.heapSort();
    myHeap.print();
    


    delete []tempArr;
    tempArr = nullptr;

    return 0;
}