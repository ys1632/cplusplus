#include <iostream>
#include <queue>
using namespace std;

class Process2 {
public:
        int arr;
        int exe;
        Process2(int arriveTime, int excuteTime) {
                arr = arriveTime;
                exe = excuteTime;
        }
};

struct Process
{
	int arr;
	int exe;
	Process(int x, int y) : arr(x), exe(y) {}
};

double aveWaitingTime(int len, int arrivalTime[], int executionTime[], int q) {
	if (len == 0) return 0;

	int curEnd = 0;
	queue<Process2*> que;
	int nextId = 0;
	int total = 0;
	int cnt = 0;
	while (!que.empty() || nextId < len) {
		
		if (!que.empty()) {
			Process2 *cur = que.front();
			que.pop();
			total += curEnd - cur->arr;
			curEnd += min(q, cur->exe);
			for (int i = nextId; i < len; i++) {
				if (arrivalTime[i] > curEnd)
					break;
				else {
					
					que.push(new Process2(arrivalTime[i], executionTime[i]));
					nextId = i + 1;
				}
			}
			if (cur->exe > q) {
				que.push(new Process2(curEnd, cur->exe - q));
			}

		}
		else {
			que.push(new Process2(arrivalTime[nextId], executionTime[nextId]));
			curEnd = arrivalTime[nextId++];
		}
	}
	return (double) total / (double) len;
}

int main() {
	//answer: total = 28   aveWait = 28/4 = 7
	int arrivalTime[] = {0,2,4,5};
	int executionTime[] = {7,4,1,4};
	int len = 4;

	cout << aveWaitingTime(len, arrivalTime, executionTime, 3) << endl;
}