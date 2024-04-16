#include <iostream>
#include <limits.h>
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
int mcmtop(int m[][20], int s[20][20], int p[], int i, int j, int &count)
{

    if (m[i][j] < INT_MAX)
    {
        return m[i][j];
    }
    if (i == j)
    {
        m[i][j] = 0;
        return m[i][j];
    }
    for (int k = i; k < j; k++)
    {
        count++;
        int q = mcmtop(m, s, p, i, k, count) + mcmtop(m, s, p, k + 1, j, count) + (p[i - 1] * p[k] * p[j]);
        if (q < m[i][j])
        {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
}
void mcm(int p[], int n)
{
    int s[20][20];
    int m[20][20];
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            m[i][j] = INT_MAX;
        }
    }

    mcmtop(m, s, p, 1, n, count);
    print(s, 1, n);
    cout << "Count:" << count << endl;
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
    mcm(p, n);
}