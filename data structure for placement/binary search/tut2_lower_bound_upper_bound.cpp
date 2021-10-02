#include <bits/stdc++.h>
using namespace std;
int lower_bound(vector<int> &v, int key)
{

    // 1,2,3,4,5,6,7,8
    int l = 0;
    int r = v.size() - 1;
    int mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (v[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (v[l] >= key)
    {
        return l;
    }
    if (v[r] >= key)
    {
        return r;
    }
    return -1;
}

int upper_bound(vector<int> v, int key)
{
    // 1,2,3,4,5,6,7,8
    int l = 0;
    int r = v.size() - 1;
    int mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (v[mid] <= key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    if (v[l] > key)
    {
        return l;
    }
    if (v[r] > key)
    {
        return r;
    }
    return -1;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 6, 7, 8};
    int key = 5;
    int indxl = lower_bound(v, key);
    int indxu = upper_bound(v, key);
    cout << indxl << " " << v[indxl]<<endl;
    cout << indxu << " " << v[indxu]<<endl;
    return 0;
}