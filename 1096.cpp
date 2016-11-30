#include <bits/stdc++.h>
using namespace std;
int mat[4][4], a, b, c;
const int mod = 10007;
void bigmod (int e) {  //mat ^e %mod
    if (e <= 1) return;
    bigmod (e >> 1);
    int tt[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) sum += (mat[i][k] * mat[k][j]) %mod;
            tt[i][j] = sum %mod;
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat[i][j] = tt[i][j];

    if (e %2 == 1) { //if odd one more multiply with previous square
        int temp[4][4];
        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) temp[i][j] = 0;
        temp[0][0] = a; temp[0][2] = b; temp[0][3] = c;
        temp[1][0] = temp[2][1] = temp[3][3] = 1;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) sum += (tt[i][k] * temp[k][j]) %mod;
                mat[i][j] = sum %mod;
            }
        }
    }
}
int main ()
{
    int tc, cs = 0, n, m, res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d %d %d", &n, &a, &b, &c);
        if (n <= 2) {printf ("Case %d: 0\n", ++cs); continue;}
        if (n == 3) {printf ("Case %d: %d\n", ++cs, c%mod); continue;}
        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) mat[i][j] = 0;
        mat[0][0] = a; mat[0][2] = b; mat[0][3] = c;
        mat[1][0] = mat[2][1] = mat[3][3] = 1;
        bigmod (n-2);
        res = (mat[0][0] * 0 + mat[0][2] * 0 + mat[0][3] * 1) %mod; //matrix |0 | ->F2
        printf ("Case %d: %d\n", ++cs, res %mod);                   //       |0 | ->F1
    }                                                               //       |0 | ->F0
                                                                    //       |1 | -> 1  //this for c
    return 0;
}
