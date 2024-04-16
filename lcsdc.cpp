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
int lcstop(char x[], char y[], int i, int j, int &count)
{
    count++;
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (x[i] == y[j])
    {
        return lcstop(x, y, i - 1, j - 1, count) + 1;
    }
    else
    {
        int t1 = lcstop(x, y, i - 1, j, count);
        int t2 = lcstop(x, y, i, j - 1, count);
        if (t1 >= t2)
        {
            return t1;
        }
        else
        {
            return t2;
        }
    }
    return 0;
}
void lcs(char x[], char y[], int m, int n)
{
    int count = 0;
    lcstop(x, y, m, n, count);
    // print(x,s,m,n);
    cout << "Count:" << count << endl;
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
    lcs(x, y, m, n);
}