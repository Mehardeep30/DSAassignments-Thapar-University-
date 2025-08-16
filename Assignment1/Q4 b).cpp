#include <iostream>
using namespace std;
int main() {
    int r1,c1,r2,c2;
    cout<<"Please enter the number of rows of Matrix 1:"; cin>>r1;
    cout<<"Please enter the number of columns of Matrix 1:"; cin>>c1;
    cout<<"Please enter the rows of Matrix 2:"; cin>>r2;
    cout<<"Please enter the number of columns of Matrix 2:"; cin>>c2;
    int mat1[r1][c1];
    int mat2[r2][c2];
    if (c1!=r2) {
        cout<<"The matrix cannot be multiplied!";
        return 0;
    }
    cout<<"Enter elements of Matrix 1:"<<endl;
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c1;j++) {
            cout<<"Please enter the element at index ("<<i<<","<<j<<"):";
            cin>>mat1[i][j];
        }
    }
    cout<<endl;
    cout<<"Enter elements of Matrix 2:"<<endl;
    for (int i=0;i<r2;i++) {
        for (int j=0;j<c2;j++) {
            cout<<"Please enter the element at index ("<<i<<","<<j<<"):";
            cin>>mat2[i][j];
        }
    }
    cout<<endl;
    int res[r1][c2];
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c2;j++) {
            int sum=0;
            for (int k=0;k<c1;k++) sum+=mat1[i][k]*mat2[k][j];
            res[i][j]=sum;
        }
    }
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c2;j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}