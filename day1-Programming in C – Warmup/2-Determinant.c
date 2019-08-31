/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:26 July 2019
Program description:Write a program to verify whether an input matrix is square ornot.  
                    If it is not a square matrix, printNOT SQUARE.Otherwise, further check whether it is singular (determinant is0) or unimodular (determinant is 1).  
                    Accordingly, printSQUARE - SINGULARorSQUARE - UNIMODULAR, otherwiseprintSQUARE - OTHER
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <string.h>
#define size 10
int isNeg = 1;
void pt(int *base,int order)
{
    int i, j;
    for(i=0;i<order;i++)
    {
        for(j=0;j<order;j++)
            printf("%d\t", *(base+(i*size)+j));
        printf("\n");
    }printf("DONE\n");
}

int gcd(int m, int n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}


void changeRow(int *base,int row, int pivotRow, int pivotLoc, int order)
{
    /*

    row = the row to be reduced
    pivotRow = WRT which row
    pivotLoc = Start from this location, mostly equal to pivot row
    order = nxn
    */

    //mat[i][j] = *(*(base+i)+j)
    int j;

    int num2 = *(base+(row*size)+pivotLoc);
    int pivot = *(base+(pivotRow*size)+pivotLoc);
    if(num2 == 0) return;
    //int gc = gcd(num2,pivot);
    //num2 = num2/gc;
    //pivot = pivot/gc;
    //printf("\npivot %d %d\n",pivot,num2);
    for(j=pivotLoc;j<order;j++)
    {
    //printf("Chamging %d to %d-%dn",*(base+(row*size)+j), *(base+(row*size)+j) * pivot ,(*(base+(pivotRow*size)+j))* num2);
        *(base+(row*size)+j) = *(base+(row*size)+j) * pivot - (*(base+(pivotRow*size)+j))* num2;
    }
    pt(base,order);
}


void swapRow(int *base, int row1, int order)
{
    int j;
    for(j=row1;j<order;j++)
        if(*(base+(j*size)+row1) != 0)
            break;
        int row2 = j;
        if(row2>=order) return;

        for(j=0;j<order;j++)
        {
            int tmp = *(base+(row1*size)+j);
            *(base+(row1*size)+j) = *(base+(row2*size)+j);
            *(base+(row2*size)+j) = tmp;
        }
        isNeg = -isNeg;
        printf("swapped R%d to R%d\n", row1, row2);
        pt(base,order);
}

int main()
{
    //************************************************************
    //Getting inut and checking if square and showing the matrix
    char input[256];
    fgets(input,256,stdin);    //take input row wise as string separated by space
    int i,j,k,row,col,negFlag = 1;
    row = 0; col = 0;
    int mat[size][size], rowsize[size];

    do
    {
        int no = 0;
        for(i=0;(k=input[i])!=10;i++)
        {

            if(k == 45) // if - means negative number
                negFlag = -1;
            else if(k!=32)//Not Space
                no = (10*no) + k -'0';
            else    //if sace then save the number as element of array
            {
                mat[row][col++] = negFlag * no;
                negFlag = 1;
                no=0;
            }
        }
        mat[row][col++] = negFlag * no;    // last number as there is no space at the end
        rowsize[row] = col; //save no of elements for square matrix comparision
        row++; col = 0; no=0; // reset the values
        fgets(input,256,stdin); // Next row input
    }while(input[0]!='$');    //$ is the end signal

    for(i=0;i<row;i++)
        if(rowsize[i] != row)
            {printf("NOT SQUARE\n"); return 0;}
        printf("SQUARE and The Matrix is\n");
        int order = row;
        pt(&mat[0][0],order);
    //*********************************************************

    // Determinant 
    int det = 1;
    int bias = 1;
    for(i=0;i<order;i++)
    {
        det = det*mat[i][i];
        if(mat[i][i] == 0)
            printf("%d is zero\n",mat[i][i]),swapRow(&mat[0][0],i,order);
        for(j=i+1;j<order;j++)
            changeRow(&mat[0][0],j,i,i,order),bias = bias*mat[i][i];
    }

    printf("Bias is %d\n", bias);

    printf("DET = %d\n", isNeg*det/bias);
    if(det == 0)
        printf("Square Singular\n");
    else if(det ==1)
        printf("Square Unimodal\n");
    else
        printf("OTHER\n");

}
