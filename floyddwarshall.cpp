#include <iostream>
using namespace std;
void warshall(int d[][20], int pi[][20], int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (pi[i][k] != -1 && pi[k][j] != -1 && d[i][j] > (d[i][k] + d[k][j]))
                {
                    pi[i][j] = pi[k][j];
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
void floyd(int w[][20], int n)
{
    int d[20][20], pi[20][20];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = w[i][j];
            if (i == j || w[i][j] == 999)
            {
                pi[i][j] = -1;
            }
            else
            {
                pi[i][j] = i;
            }
        }
    }
    warshall(d, pi, n);
    cout << "D matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << "PI matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << pi[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter no.of vertices:";
    cin >> n;
    int w[20][20];
    cout << "Enter weighted matrix:";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    floyd(w, n);
}