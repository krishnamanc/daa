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
    {
        print(x, s, i - 1, j);
    }
    else
    {
        print(x, s, i, j - 1);
    }
}
int lcstop(int c[][20], char s[][20], char x[], char y[], int i, int j, int &count)
{
    if (c[i][j] >= 0)
        return c[i][j];
    count++;
    if (i == 0 || j == 0)
    {
        c[i][j] = 0;
        return c[i][j];
    }
    if (x[i] == y[j])
    {
        c[i][j] = lcstop(c, s, x, y, i - 1, j - 1, count) + 1;
        s[i][j] = 'p';
    }
    else
    {
        int t1 = lcstop(c, s, x, y, i - 1, j, count);
        int t2 = lcstop(c, s, x, y, i, j - 1, count);
        if (t1 >= t2)
        {
            c[i][j] = t1;
            s[i][j] = 'q';
        }
        else
        {
            c[i][j] = t2;
            s[i][j] = 'r';
        }
    }
    return c[i][j];
}
void lcs(char x[], char y[], int m, int n, int &count)
{
    int c[20][20];
    char s[20][20];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            c[i][j] = INT_MIN;
        }
    }

    lcstop(c, s, x, y, m, n, count);
    print(x, s, m, n);
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
    cout << "Count:" << count << endl;
}