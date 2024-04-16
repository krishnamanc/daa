#include <iostream>
using namespace std;
struct node
{
    int s, f, x;
};

void activity(int s[], int f[], int b[], int k, int n)
{
    int m = k + 1;
    while (m <= n && s[m] < f[k])
        m++;
    if (m <= n)
    {
        cout << b[m];
        activity(s, f, b, m, n);
    }
    else
        return;
}

void is(node a[], int n)
{
    for (int j = 2; j <= n; j++)
    {
        int i = j - 1;
        node key = a[j];
        while (i >= 1 && a[i].f > key.f)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}
int main()
{
    int n;
    cout << "Enter no.of activities:";
    cin >> n;
    node a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter start time:";
        cin >> a[i].s;
        cout << "Enter finish time:";
        cin >> a[i].f;
        a[i].x = i;
    }

    is(a, n);
    for (int i = 1; i <= n; i++)
    {

        cout << a[i].s << " " << a[i].f << " " << a[i].x;
        cout << endl;
    }
    int s[n + 1], f[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        s[i] = a[i].s;
        f[i] = a[i].f;
        b[i] = a[i].x;
    }
    cout << a[1].x;
    activity(s, f, b, 1, n);
}