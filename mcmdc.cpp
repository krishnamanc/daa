#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
int mcm(int p[], int i, int j, int &count)
{
    if (i == j)
        return 0;
    int t = INT_MAX;
    for (int k = i; k < j; k++)
    {
        count++;
        int q = mcm(p, i, k, count) + mcm(p, k + 1, j, count) + (p[i - 1] * p[k] * p[j]);
        if (q < t)
        {
            t = q;
        }
    }
    return t;
}
int main()
{
    int n, count = 0;
    cout << "Enter the no.of matrices:";
    cin >> n;
    int p[n + 1];
    cout << "Enter the order of matrices:";
    ifstream read("abc.txt");
    for (int i = 0; i <= n; i++)
    {
        read >> p[i];
    }
    mcm(p, 1, n, count);
    cout << "Count:" << count << endl;
}