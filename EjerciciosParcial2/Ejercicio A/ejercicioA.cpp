#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calcularMediana(vector<int>n){
    sort(n.begin(),n.end());
    int size = n.size();
    if(size == 1){
        cout<<n[0]<<endl;
        return;
    }
    if(size%2 == 0){
        int med = size/2;
        cout<<(n[med-1]+n[med])/2<<endl;
    }
    else{
        int med = (size+1)/2;
        cout<<n[med-1]<<endl;
    }
}

int main(){
    int a;
    vector<int>arreglo;

    while(cin>>a){
        arreglo.push_back(a);
        calcularMediana(arreglo);
    }

    return 0;
}
