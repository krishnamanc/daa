#include <iostream>
using namespace std;
void print(int s[][20], int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}
void mcm(int p[], int n, int &count)
{
    int m[n + 1][n + 1];
    int s[n + 1][20];

    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= (n - l + 1); i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                count++;
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    print(s, 1, n);
}
int main()
{
    int n;
    cout << "Enter the no.of matrices:";
    cin >> n;
    int p[n + 1];
    cout << "Enter the order of matrices:";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    int count = 0;
    mcm(p, n, count);
    cout << "Count:" << count << endl;
}