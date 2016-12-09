#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_N 2002
#define MOD 1000000007

using namespace std;

int Q, N;
long long result;
int arr[MAX_N];

long long comb(int a, int b){
    if(b>a) return 1;

    long long result = 1;
    for(int i=a-b+1;i<=a;i++)
        result = result * i % MOD;
    for(int i=1;i<=b;i++)
        result /= i;
    return result;
}

int main() {

    cin >> Q;
    for(int i=0;i<Q;i++){
        cin >> N;

        for(int j=0;j<N;j++)
            scanf("%d", arr + j);

        sort(arr, arr+N);

        result = 1;
        int odds = 0, evens = 0;
        for(int j=0;j<N;j++)
            if(j<N-1 && arr[j] == arr[j+1]){
                evens++;
                j++;
            }
            else
                odds++;
        int numberOfPermutation = 0;
        do{
            bool flag = false;
            for(int j=0;j<N-1;j++)
                if(arr[j] == arr[j+1])
                    flag = true;
            if(!flag){
                for(int j=0;j<N;j++)
                    cout << arr[j] << ' ';
                cout << endl;
                numberOfPermutation ++;
            }

        }while(next_permutation(arr, arr+N));

        cout << odds << ' ' << evens << ' ' << numberOfPermutation << endl;

        // cout << result << endl;
    }
    return 0;
}
