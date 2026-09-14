#include<stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX],int rows,int cols){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX],int rows,int cols){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX],int b[MAX][MAX],int result[MAX][MAX],int rows,int cols){

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols; j++){
            result[i][j]=a[i][j]+b[i][j];
        }
    }
}

void multiplyMatrix(int a[MAX][MAX],int b[MAX][MAX],int result[MAX][MAX],int r1,int c1,int c2){

    for (int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            result[i][j]=0;

            for (int k=0;k<c1;k++){
                result[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX],int result[MAX][MAX],int rows,int cols){

    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            result[j][i]=matrix[i][j];
        }
    }
}

int main(){
    int a[MAX][MAX],b[MAX][MAX];
    int addition[MAX][MAX];
    int multiplication[MAX][MAX];
    int transpose[MAX][MAX];

    int r1,c1,r2,c2;

    // Matrix A
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d",&r1,&c1);

    printf("Enter elements of Matrix A:\n");
    inputMatrix(a,r1,c1);

    // Matrix B
    printf("\nEnter rows and columns of Matrix B: ");

    scanf("%d %d",&r2,&c2);

    printf("Enter elements of Matrix B:\n");

    inputMatrix(b,r2,c2);

    // Matrix Addition
    if (r1==r2 && c1==c2){
        addMatrix(a,b,addition,r1,c1);

        printf("\nMatrix Addition:\n");

        displayMatrix(addition,r1,c1);
    } else{
        printf("\nMatrix addition is not possible.\n");
    }

    // Matrix Multiplication
    if (c1==r2){
        multiplyMatrix(a,b,multiplication,r1,c1,c2);

        printf("\nMatrix Multiplication:\n");

        displayMatrix(multiplication,r1,c2);
    }else{
        printf("\nMatrix multiplication is not possible.\n");
    }

    // Transpose of Matrix A
    transposeMatrix(a,transpose,r1,c1);

    printf("\nTranspose of Matrix A:\n");

    displayMatrix(transpose,c1,r1);

    return 0;
}