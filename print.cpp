#include <iostream>
using namespace std;
int fisrstoccurence(int aar[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (aar[i] == key)
    {
        return i;
    }
    return fisrstoccurence(aar, n, i + 1, key);
}

int main()
{
    int aar[] = {4, 2, 1, 2, 5, 2, 7};
    cout << fisrstoccurence(aar, 7, 0, 2);

    return 0;
}