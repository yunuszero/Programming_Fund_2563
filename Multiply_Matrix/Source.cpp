#include <iostream> 
using namespace std;

void multiply(int mat1[][10], int mat2[][10], int res[][10], int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += mat1[i][k] *
                mat2[k][j];
        }
    }
}
 
int main()
{
    int n1, m1, n2, m2;
    int mat1[10][10], mat2[10][10], res[10][10] = { 0 };
    cout << "Enter size of matrix1 : "; cin >> n1 >> m1;
    cout << "Enter size of matrix2 : "; cin >> n2 >> m2;
    for(int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cin >> mat1[i][j];
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            cin >> mat2[i][j];
        }
    }

    multiply(mat1, mat2, res, n1, m1, n2, m2);

    cout << "Result matrix is \n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}