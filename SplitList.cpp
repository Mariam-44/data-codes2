#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* previous;
};

class DoublyLinkedList {
private:
	Node* head;
public:
	DoublyLinkedList() { head = nullptr; }
	void SplitList(Node** firstHalf, Node** secondHalf) {//time O(n) Space O(1)
		Node* p = head;
		if (!p) {
			cout << "Empty list \n";
			return;
		}
		if (!p->next) {
			*firstHalf = p;
			*secondHalf = nullptr;
			return;
		}
		Node* ptr = p;
		Node* runner = p->next;
		while (runner) {
			runner = runner->next;
			if (runner) {
				ptr = ptr->next;
				runner = runner->next;
			}
		}
		*firstHalf = p;
		*secondHalf = ptr->next;
		ptr->next->previous = nullptr;
		ptr->next = nullptr;

	}

};
