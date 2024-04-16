#include <iostream>
using namespace std;
void sumexhaustive(int s, int k, int w[], int m, int x[], int n)
{
    if (m == s)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << x[i] << endl;
        }
        cout << endl;
        return;
    }
    else
    {
        if (k > n)
            return;
        x[k] = 1;
        sumexhaustive(s + w[k], k + 1, w, m, x, n);
        x[k] = 0;
        sumexhaustive(s, k + 1, w, m, x, n);
    }
}
int main()
{
    int m;
    int n;
    cout << "Enter a m value";
    cin >> m;
    cout << "Enter a n value";
    cin >> n;
    int w[n + 1];
    int x[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    sumexhaustive(0, 1, w, m, x, n);
}