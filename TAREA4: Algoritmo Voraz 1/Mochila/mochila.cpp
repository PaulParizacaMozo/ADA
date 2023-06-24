#include <iostream>
//compilador Dev-C++ 5.11
//CH ST
using namespace std;

int main()
{ 
 int n,m;
 cout<<"Ingrese n y m de la matriz ( separados por un espacio ) (n=cantidad de objetos)(m=peso max): "<<endl;
 cin>>n>>m;
 n=n+1;
 m=m+1;
 int A[n][m];
 int p[n+1];
 int b[n+1];
 p[0]=0;
 b[0]=0;	
 for(int q=1;q<n;++q){
 	cout<<"Ingrese peso para p["<<q<<"] : "<<endl;
 	cin>>p[q];
 }
  for(int q=1;q<n;++q){
 	cout<<"Ingrese beneficio para b["<<q<<"] : "<<endl;
 	cin>>b[q];
 }
 for(int a=0;a<m;a++){
 	A[0][a]=0;
 	if(a<n){
 		A[a][0]=0;
	 }
 }		
 for(int i=1;i<=n-1;++i){
    for(int j=1;j<=m-1;++j){
    	if(j-p[i]<0){
    			A[i][j]=A[i-1][j];
		}
		else{	
        A[i][j]= max(A[i-1][j], A[i-1][j-p[i]] + b[i]);
    	}
    }
 }
 cout<<"\n";
 int may=-1,V=0;
 for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
    	cout<<A[i][j]<<" ";
    	if(A[i][j]>may){
    		may=A[i][j];
    		V=A[i][j];
		}
    	
    }
    cout<<"\n";
}
cout<<"\n";
cout<<"El mayor beneficio es: "<<V<<endl;
	
}
