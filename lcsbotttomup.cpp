#include <iostream>
using namespace std;
void print(char x[], char s[][20], int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (s[i][j] == 'p')
    {
        print(x, s, i - 1, j - 1);
        cout << x[i] << " ";
    }
    else if (s[i][j] == 'q')
        print(x, s, i - 1, j);
    else
        print(x, s, i, j - 1);
}
void lcs(char x[], char y[], int m, int n, int &count)
{
    int c[20][20];
    char s[20][20];
    for (int i = 0; i <= m; i++)
    {
        c[i][0] = '0';
    }
    for (int j = 1; j <= n; j++)
    {
        c[0][j] = '0';
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << c[i][j] << " ";
        }
    }
    cout << "After:" << endl;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            count++;
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 'p';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                s[i][j] = 'q';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                s[i][j] = 'r';
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << c[i][j] << " ";
        }
    }
    print(x, s, 1, n);
}
int main()
{
    int m, n;
    cout << "Enter length of 1st and 2nd array:";
    cin >> m >> n;
    char x[m + 1], y[n + 1];
    cout << "Enter 1st string:";
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i];
    }
    cout << "Enter 2nd string:";
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i];
    }
    int count = 0;
    lcs(x, y, m, n, count);
}