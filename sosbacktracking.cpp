#include <iostream>
using namespace std;

void sos1(int s, int k, int w[], int r, int m, int x[])
{
    if (s + w[k] == m)
    {
        x[k] = 1;
        for (int i = 1; i <= k; i++)
        {
            cout << x[i] << "  ";
        }
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        x[k] = 1;
        sos1(s + w[k], k + 1, w, r - w[k], m, x);
    }
    if (s + r - w[k] >= m and s + w[k + 1] <= m)
    {
        x[k] = 0;
        sos1(s, k + 1, w, r - w[k], m, x);
    }
}
int main()
{
    int m, n;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter elements:";
    int w[n + 1];
    int x[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    cout << "Enter sum:";
    cin >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += w[i];
    }
    sos1(0, 1, w, sum, m, x);
}