#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>

using namespace std;

struct Punto{
    double x,y;
    double distanciaA(Punto & p1){
      return sqrt(pow(p1.x - x, 2)+pow(p1.y - y, 2));
    }
};

bool compare(Punto &a, Punto &b){
    return a.x < b.x;
}

int main(){
    vector<Punto>puntos;
    int n;
    while(cin>>n){
        if(n==0){break;}
        puntos.resize(n);
        for(int i=0; i<n; i++){
            cin>>puntos[i].x>>puntos[i].y;
        }
        sort(puntos.begin(), puntos.end(), compare);
        double min = 10000;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if (puntos[i].x + min < puntos[j].x){
                    break;
                }
                double dis = puntos[i].distanciaA(puntos[j]);
                if (dis < min){
                    min = dis;}
            }
        }
        if (min == 10000){
            cout<<"INFINITY"<<endl;
        }
        else{
            cout<<min<<endl;
        }
    }
    return 0;
}
