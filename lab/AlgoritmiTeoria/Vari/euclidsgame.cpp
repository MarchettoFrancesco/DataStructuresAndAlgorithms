/*
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 

int toglimultiplo(int n, int m){
    int mult;
    for (int i = 1;  m*i < n ; i++)
    {
        if ( m*i <  n)
        {
            mult = i;
        }  
    }
     
     return mult;
}

bool caniwin(int n,int m){
    bool p = false;
    for (int i = 1; i < 10; i++)
    {
        if ((m -  n * i) == 0)
        {
            p = true;
            return p;
        } 
        
    }
    return p;
    
}

void euclidsgame(int n,int m){
    if (m <= 0 || n <= 0 )
    {
        printf("fine");
    } else {
    
    if (n < m)
    {
        if(caniwin(n,m)){
            printf("Stan wins");
        } else {
            int b = toglimultiplo( m,n);
            euclidsgame( n, m-b*n);
        }
    } else {
        if(caniwin(m,n)){
            printf("Ollie wins");
        } else {
            int c = toglimultiplo( n, m);
            euclidsgame( n-c*m, m);
        }
    }
    }
}
void swap(int x,int y){ 
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
bool euclidesgame(int n, int m) {
	if (n < m){
        swap(n, m);
    } 
    if (m == 0) return false;

	if (n % m == 0){
        return true;
    } 
	int p = (n/m) * m;
	bool f = euclidesgame(n-p, m); // ho vinto?
	if (n-p+m < n || !f) return true;

	return false;
}

int main(){
    int n=34,m = 12;
    int a=15,b = 24;
   //  int l,p;
   // scanf("%d %d", &n, &m);
 //   scanf("%d %d", &a, &b);
//   scanf("%d %d", &l, &p);
    if(euclidesgame(n,m)) {
        printf("Stan wins");
    } else{
        printf("Ollie wins");
    }
    // euclidesgame(a,b);
    
   

    
    

    return 0;
}
*/
#include <iostream>
#include <string>

using namespace std;
bool euclidesgame(int n, int m) {
	if (n < m){
        std:swap(n, m);
    } 
    if (m == 0) return false;

	if (n % m == 0){
        return true;
    } 
	int p = (n/m) * m;
	bool f = euclidesgame(n-p, m); // ho vinto?
	if (!f){
        return true;
    } 
    if(n-p+m < n ){
        return true;
    }

	return false;
}
int provaeuclide(int n, int m){
    if(n%m == 0 || n/m >1){
        return true;
    } else if(m%n == 0 || m/n >1){
        return false;
    } 
    
}

int main() {
	
	int n, m;
	int a,b;
	int p,l;
	
	cin >> n >> m;
	cin >> a >> b;
	cin >> p >> l;
	if (provaeuclide(n, m)){
	    cout << "Stan wins\n";
	} else{
	    cout << "Ollie wins\n";
	}
	
	if (provaeuclide(a, b)){
	    cout << "Stan wins";
	} else{
	    cout << "Ollie wins";
	}
	
	return 0;
}