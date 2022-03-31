#include <iostream>
#include <set>

using namespace std;

bool check(int n, int sum) {
    for(int i = 0; i < n / 2; i ++)
        if((i * sum) % n == 0)
            return true;
    return false;
}

bool solve(int n, int* array, int sum) {
    if(!check(n, sum))
        return false;
    set<int> sums[n / 2 + 1];
    sums[0].insert(0);

    for(int k = 0; k < n; k ++) {
        for(int i = n / 2; i > 0; i --) {
            for(int j : sums[i - 1]) {
                if(j + array[k] == (i * sum) / n && (sum * i) % n == 0)
                    return true;
                sums[i].insert(j + array[k]);
            }
        }
    }
    return false;
}

int main() {

    int n, sum = 0;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i ++) {
        cin >> array[i];
        sum += array[i];
    }

    if(solve(n, array, sum))
        cout << "True";
    else
        cout << "False";
    return 0;
}
