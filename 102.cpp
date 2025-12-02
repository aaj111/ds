#include<iostream>
using namespace std;
int main()
{
    int rows,cols;
    cout<<"Enter number of rows\n";
    cin>>rows;
    cout<<"Enter number of columns\n";
    cin>>cols;

    int matrix[20][20];
    cout<<"Enter elements of the matrix\n";
    int nonZero = 0;
    for(int i = 0;i<rows;i++)
    {
        for(int j = 0;j<cols;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]!=0)
            nonZero++;
        }
    }
    int sparse[100][3];
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    int k = 1;
    for(int i = 0;i<rows;i++)
    {
        for(int j = 0;j<cols;j++)
        {
            if(matrix[i][j]!=0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    //display
    for(int i = 0;i<=nonZero;i++)
    {
        cout<<sparse[i][0]<<" "
        <<sparse[i][1]<<" "
        <<sparse[i][2]<<endl;
    }

    //simple transpose
    int transpose[100][3];

    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    int t = 1;
    for(int col = 0;col<cols;col++)
    {
        for(int i = 1;i<=nonZero;i++)
        {
            transpose[t][0] = sparse[i][1];
            transpose[t][1] = sparse[i][0];
            transpose[t][2] = sparse[i][2];
            t++;
        }
    }

    cout<<"Simple transpose(Row COl Value):\n";
    for(int i = 0;i<=nonZero;i++)
    {
        cout<<transpose[i][0]<<" "
        <<transpose[i][1]<<" "
        <<transpose[i][2]<<endl;
    }

    return 0;
}
