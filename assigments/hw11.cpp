// Shao, Zihao
// CS211 Section 52B Homework 11

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
//ok function
bool ok(int q[], int c){
    //create two 3*3 2d arrays for men and women
    int mp[3][3]={
        {0,2,1},
        {0,2,1},
        {1,2,0}};
    int wp[3][3]={
        {2,1,0},
        {0,1,2},
        {2,0,1}};
    //go check the input values are ok
    for (int i=0; i<c; i++){
            if (q[c]==q[i])
                return false;
        if((mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) || (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]))
                return false;
    }
    return true;
}
//backtrack
void backtrack(int &col){
    //go back to the last col
    --col;
    
    if(col == -1)
        exit(0);
}
//print function
void print(int q[], int count){
    cout << "\nSolutions #" << count << ": " << endl;
    cout << "Men:   0 1 2" << endl << "Women: ";
    for (int i=0; i<3; i++)
        cout <<  q[i] << ' ';
    cout << endl << endl;
}

//main function
int main() {
    int c=0, q[3], count =0;
    q[0] = 0;
    //set the default test equal false
    bool test=false;

        while(true){
            while(c<3){
                //if test is true, stop
                if(!test)
                    q[c] = -1;
                
                test =  false;
        
                while(q[c]<3){
                    q[c]++;
                    //if the number on column is 3, go backtrack
                    if(q[c] == 3){
                        backtrack(c);
                        continue;
                    }
                    //if pass the ok function, break
                    if (ok(q,c) ) break;
                }
                
                c++;
            }
            // print the result and backtrack again
            print(q, ++count);
            backtrack(c);
            test = true;
        }
        return 0;
    }
