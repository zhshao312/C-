// Shao, Zihao
// CS211 Section 52B Homework 17

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
//ok function
bool ok(int q[], int c, int n){
    for (int i=0; i<c; i++)
        if(q[i]/n+q[i]%n==q[c]/n+q[c]%n || q[i]/n-q[i]%n==q[c]/n-q[c]%n)//check the two diagonal lines
            return false;
    return true;
}

int factorial(int n){
    if (n==1) return n;
    return n*factorial(n-1);
}
//backtrack
void backtrack(int &c, int count, int k){
    c--;
    if(c==-1){
        cout <<count/factorial(k);//do backtrack using factorial function
        exit(0);
    }
}
//print
void print(int q[], int &count){
    count++;
}
//move function
void move(int* q, int c, int n, int k, int count){ 
    
    bool from_backtrack=false;
    
    while(true){
        while(c<k){
            
            if(!from_backtrack)
                q[c]=-1; 
            
            from_backtrack=false; 
            
            while(q[c]<n*n){ 
                q[c]++;
                
                if(q[c]==n*n){
                    backtrack(c, count, k);
                    from_backtrack=true;
                    continue;
                }
                if(ok(q, c, n)){
                    c++;
                    break;
                }
            }
        }
        print(q,count);
        backtrack(c, count, k);
        from_backtrack=true;
    }
}
//main function
int main(){
    
    int c=1, count=0, n = 0, k = 0;
    
    
        cout <<"Give me an nXn board: ";
        cin >>n;
    
        cout <<"Enter k bishops: ";
        cin >>k;
        
        int* q = new int[k];
    
        q[0]=0;
    
        cout << "N: " << n << " \nK: " << k << " \n# Bishops: ";
    
        move(q, c, n, k, count);
    
        cout << endl << endl;
    
        delete [] q;

    return 0;
}

