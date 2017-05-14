#include <iostream>
#include <set>
#include <vector>

#define MAX 100020

using namespace std;

int Q, N;
long long M;

int main ()
{

  cin >> Q;
  for(int t=0;t<Q;t++){
      cin >> N >> M;
      set<long long> S;
      set<long long>::iterator itup;
      long long res = 0, input, sum = 0;

      for(int i=1;i<=N;i++){
        cin >> input;
        sum = (sum + input) % M;

        itup = S.upper_bound(sum);
        res = max(res, 
            max(sum, (sum - *itup + M) % M));

        S.insert(sum);
      }
      cout << res << endl;
  }

  return 0;
}