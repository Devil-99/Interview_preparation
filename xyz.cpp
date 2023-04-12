// Souvik
#include <bits/stdc++.h>
using namespace std;

int main() {
    int matrix[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
        }
    }
    int idx,jdx;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matrix[i][j]==1){
                idx=i;
                jdx=j;
            }
        }
    }
    cout<<abs(idx-2)+abs(jdx-2)<<endl;
    
	return 0;
}