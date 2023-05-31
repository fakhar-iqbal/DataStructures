#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int* b){
    int temp = *b;
    *b = *a;
    *a=temp;
}

void heapify(vector<int> &ht,int i){
    int size = ht.size();
    int smallest = i;

    int l = 2*i +1;
    int r = 2*i +2;

    if(l<size && ht[l]<ht[smallest]){
        smallest = l;
    }
    if(r<size && ht[r]< ht[smallest]){
        smallest = r;
    }

    if(smallest!=i){
        swap(&ht[i],&ht[smallest]);
        heapify(ht,smallest);
    }
}

void insert(vector<int> &ht,int num){
    int size = ht.size();
    if(size==0){
        ht.push_back(num);
    }else
    {
        ht.push_back(num);
        for(int i=size-1;i>=0;i--){
            heapify(ht,i);
        }
    }
}

void Delete(vector<int> &ht, int num){
    int size=ht.size();
    if(size==0){
        cout<<"the heap is empty"<<endl;
    }else{
        int i;
        for(i=0;i<size;i++){
            if(ht[i]==num){
                break;
            }
        }

        if(ht[i]==num){
            swap(&ht[i],&ht[size-1]);
        ht.pop_back();

        for(int i=size-1;i>=0;i--){
            heapify(ht,i);
        }
        }

    }
}

void print(vector<int> &ht){
    for(int i=0;i<ht.size();i++){
        cout<<ht[i]<<endl;
    }
}

int main(){
    vector<int> heapTree;
    insert(heapTree,6);
    insert(heapTree,5);
    insert(heapTree,3);
    insert(heapTree,2);
    insert(heapTree,1);
    //insert(heapTree,0);
    
    print(heapTree);
    cout<<"deleting the element"<<endl;
    Delete(heapTree,13);
    cout<<"after deletion"<<endl;
    print(heapTree);
    return 0;
}