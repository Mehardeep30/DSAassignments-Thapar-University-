#include <iostream>
using namespace std;
int main() {
    int r,c;
    cout<<"Please enter the number of rows of Matrix:"; cin>>r;
    cout<<"Please enter the number of columns of Matrix:"; cin>>c;
    int mat[r][c];
    int transpose[c][r];
    cout<<"Enter elements of Matrix:"<<endl;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cout<<"Please enter the element at index ("<<i<<","<<j<<"):";
            cin>>mat[i][j];
        }
    }
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            transpose[j][i]=mat[i][j];
        }
    }
    cout<<endl;
    for (int i=0;i<c;i++) {
        for (int j=0;j<r;j++) {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}