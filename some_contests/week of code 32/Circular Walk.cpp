#include <iostream>
#include <vector>
#include <queue>

#define MAX 10000002

#define pos first
#define start first

#define end second
#define time second

using namespace std;

int N, S, T;
int g, seed, p;
int R[MAX];
bool visited[MAX];
vector< pair<int,int> > intervals; //start, end
queue< pair<int, int> > q; // pos, time

void read(){
    cin >> N >> S >> T;
    cin >> R[0] >> g >> seed >> p;
    for(int i=1;i<N;i++)
        R[i] = ((long long) R[i-1] * g + seed) % p;
}

void addQueue(int a, int b, int t){
    for(int j=a; j<= b; j++)
        if(!visited[j]){
            q.push(make_pair(j, t));
            visited[j] = true;
        }
}

void lookFor(int a, int b, int t){
    bool intersected = false;

    for(int i=0;i<intervals.size();i++){
        if(b <= intervals[i].end && b >= intervals[i].start){
            intersected = true;
            addQueue(a, intervals[i].start, t);
            intervals[i].start = min(intervals[i].start, a);
        }
        if(a >= intervals[i].start && a <= intervals[i].end){
            intersected = true;
            addQueue(intervals[i].end + 1, b, t);
            intervals[i].end = max(intervals[i].end, b);
        }
    }

    if(!intersected){
        intervals.push_back(make_pair(a, b));
        addQueue(a, b, t);
    }
}

int solve(){
    q.push(make_pair(S, 0));
    intervals.push_back(make_pair(S, S));
    visited[S] = true;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        if(cur.pos == T)
            return cur.time;

        int a = cur.pos - R[cur.pos], b = cur.pos + R[cur.pos];
        lookFor(max(0, a), min(N-1, b), cur.time + 1);
        if(a < 0)
            lookFor(a + N, N-1, cur.time + 1);
        if(b > N-1)
            lookFor(0, b - N, cur.time + 1);
    }

    return -1; // if he is stuck.
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
