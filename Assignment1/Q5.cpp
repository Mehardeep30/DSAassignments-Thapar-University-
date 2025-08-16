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
        int sum=0;
        for (int j=0;j<c;j++) {
            sum+=mat[i][j];
        }
        cout<<"r"<<i<<" sum:"<<sum<<endl;
    }
    for (int i=0;i<c;i++) {
        int sum=0;
        for (int j=0;j<r;j++) {
            sum+=mat[j][i];
        }
        cout<<"c"<<i<<" sum:"<<sum<<endl;
    }
    return 0;
}