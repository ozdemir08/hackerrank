#include <iostream>
#include <map>
#include <vector>
#include <climits>

#define MAX_N 100006

using namespace std;

int A[MAX_N];
int lft[MAX_N / 2], rght[MAX_N / 2];
int N;

long long count_inversions(int beg, int end) {
	if(beg == end)
		return 0;
	int mid = (beg + end) / 2;
	long long changes = count_inversions(beg, mid) + count_inversions(mid+1, end);

	for(int i=beg;i<=mid;i++)
		lft[i-beg] = A[i];
	lft[mid-beg+1] = INT_MAX;

	for(int i=mid+1;i<=end;i++)
		rght[i-mid-1] = A[i];
	rght[end-mid] = INT_MAX;

	for(int i=0,l=0,r=0;i<end-beg+1;i++)
		if(lft[l] <= rght[r])
			A[i+beg] = lft[l++];
		else{
			A[i+beg] = rght[r++];
			changes += mid - l - beg + 1;
		}
	return changes;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        cin >> N;
        for(int arr_i = 0;arr_i < N;arr_i++){
           cin >> A[arr_i];
        }
        cout << count_inversions(0, N-1) << endl;
    }
    return 0;
}