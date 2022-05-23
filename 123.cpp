#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    long long sum = 0;
    vector <int> requests;
    vector<int> prefex_sum;
    int num, index = 0;
    ifstream file ("test.txt");
    while (file >> num) {
        sum += num;
        prefex_sum.push_back(sum);
    }
    sum = 0;
    ifstream request ("requests.txt");
    while (request >> num){
        requests.push_back(num);
    }
    for(int i = 0; i < requests.size(); i += 2){
        if (requests[i + 1] == 300)
            requests[i + 1] = 299;
        if (requests[i] == 0){
            sum += prefex_sum[requests[i + 1]];
        }
        else
            sum += prefex_sum[requests[i + 1]] - prefex_sum[requests[i] - 1];
    }
    cout <<sum;
    return 0;
}
