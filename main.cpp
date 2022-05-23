#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void max_dis(vector<int> a, int k){
    int ib = 0;
    int jb = k + 1;
    int imax = 0;
    for(int i = k + 1; i < a.size(); i += 1){
        if (i - k >= 0){
            if (a[i - k - 1] > a[imax])
                imax = i - k - 1;
        }
        if (a[i] + a[imax] > a[jb] + a[ib]){
            jb = i;
            ib = imax;
        }
    }
    cout <<ib + 1 <<endl;
    cout <<jb + 1 <<endl;
}
int mainz()
{
    int n, num, k;
    vector<int> b;
    cin >>n >>k;
    for(int i = 0; i < n; i++){
        cin >>num;
        b.push_back(num);
    }
    max_dis(b, k);
    return 0;
}
