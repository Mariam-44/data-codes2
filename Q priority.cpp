#include <iostream>
#include<queue>
using namespace std;
struct Q {
	char alpha;
	int priority;
};
int main()
{
	queue<Q> q;
	Q item, temp;
	int num;
	cout << "Enter number of elements";
	cin >> num;
	while (num != 0) { //time O(num) Space O(num)
		cout << "alpha: ";
		cin >> item.alpha;
		cout << "priority: ";
		cin >> item.priority;
		q.push(item);
		num--;
	}
	temp.priority = q.front().priority;
	temp.alpha = q.front().alpha;
	q.pop();
	for (int i = 0; i < q.size(); ++i) { //time O(n^2) Space O(1)
		if (temp.priority > q.front().priority) {
			Q frontElem = q.front();
			q.pop();
			q.push(temp);
			temp = frontElem;
		}
		else {

			q.push(q.front());
			q.pop();
		}
	}
	q.push(temp);
	cout << "Elements with highest priority: ";
	while (!q.empty()) {//time O(n) Space O(1)
		cout << q.front().alpha;
		q.pop();
	}


}