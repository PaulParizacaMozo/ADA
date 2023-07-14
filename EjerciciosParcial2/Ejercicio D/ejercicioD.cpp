#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Intervalo {
    int izquierda, derecha;
};

bool compare(Intervalo& x,Intervalo& y) {
    return x.izquierda < y.izquierda;
}

int main(){
    int m;
    while (cin>>m) {
        int prueba = m;
        int temp, tizq, tder;
        Intervalo input;
        vector<Intervalo>interv, rpta;

        for(int i=0; i<prueba; i++){
            if(i){
                cout<<"\n";
            }
            cin>>m;
            interv.clear();
            while (cin>>input.izquierda>>input.derecha && (input.izquierda != 0 || input.derecha != 0)){
                interv.push_back(input);
            }
            sort(interv.begin(), interv.end(), compare);

            rpta.clear();
            
            tizq = tder = 0;
            for(int i=0; i<interv.size(); i++){
                temp = -1;
                for (; i< interv.size() && interv[i].izquierda <= tizq; i++){
                    if(interv[i].derecha > tder){
                        tder = interv[i].derecha;
                        temp = i;
                    }
                }
                if(temp == -1){break;}

                rpta.push_back(interv[temp]);
                if(tder >= m){break;}

                tizq = tder;
                i--;
            }
            if(tder < m){
                cout<<"0\n";
                continue;
            }
            cout<<rpta.size()<<"\n";
            for(int i=0; i<rpta.size(); i++){
                cout<<rpta[i].izquierda<<" "<<rpta[i].derecha<<"\n";
            }
        }
    } 
    return 0;
}

