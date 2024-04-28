#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream file("array.txt");
    vector<int> numbers;
    int num;
    while (file >> num)
    {
        numbers.push_back(num);
    }

    int sum = 0;
    int maxsum = -10000;
    int start = 0;
    int end = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        sum = sum + numbers[i];
        if (sum < 0)
        {
            sum = 0;
            start = i + 1;
        }

        if (sum > maxsum)
        {
            maxsum = sum;
        }
    }

    cout << "max sum is : " << maxsum << endl;
    cout << "start : " << start << endl;
    int check = 0;
    for (int i = start; i < numbers.size(); i++)
    {
        check = check + numbers[i];
        if (check == maxsum)
        {
            end = i;
            break;
        }
    }

    cout << "end : " << end << endl;
    return 0;
}