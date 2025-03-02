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

    void print(){
        if(size==0){
            cout<<"No element present in Heap\n";
            return ;
        }
        for(int i=1 ; i<=size; i++){
            cout<<arr[i]<<" ";
        }
    }

};

int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);

    h.print();




    return 0;
}