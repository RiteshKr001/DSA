#include<bits/stdc++.h>
using namespace std;


class heap{

    vector<int> arr;
    int size;

public:

    heap(){
        arr.push_back(-1);
        size = 0;
    }

    void insert(int x){
        arr.push_back(x);
        size += 1;
        int index = size;

        while(index>1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromheap(){
        if(size == 0){
            return ;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int left = i*2;
            int right = i*2+1;

            if(left < size && arr[i] < arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right < size && arr[i] < arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }
            else{
                return;
            }
        }
    }

    void print(){
        if(size==0){
            cout<<"No element present in Heap\n";
            return ;
        }
        for(int i=1 ; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

void heapify(vector<int> & arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void arrPrint(vector<int> & arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapSort(vector<int> & arr, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    for(int i = n-1; i>0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}


int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);

    h.print();

    h.deletefromheap();

    h.print();

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int n = arr.size();

    arrPrint(arr);

    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }


    vector<int> arr = {60, 44, 23, 10, 12, 20, 30, 40, 50, 70};
    int n = arr.size();
    heapSort(arr, n);

    arrPrint(arr);


    return 0;
}