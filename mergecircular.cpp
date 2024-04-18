 #include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
class CircularLinkedList {
public:
	Node* rear;
public:
	CircularLinkedList() {
		rear = nullptr;;
	}
	Node* MergeTwoLists(Node* list1, Node* list2) { //time= O(n+m) n=nodes in list1 m=nodes in list2 Space=O(1)
		if (!list1) return list2;
		if (!list2) return list1;
		Node* list3 = nullptr;
		Node* ptr = nullptr;

		Node* l1 = list1;
		Node* l2 = list2;
		if (l1->data < l2->data) {
			list3 = ptr = l1;
			l1 = l1->next;
		}
		else if (l1->data == l2->data) {
			list3 = ptr = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		else {
			list3 = ptr = l2;
			l2 = l2->next;
		}

		do {
			if (l1->data < l2->data) {
				ptr->next = l1;
				l1 = l1->next;
			}
			else if (l1->data > l2->data) {
				ptr->next = l2;
				l2 = l2->next;
			}
			else {
				ptr->next = l1;
				l1 = l1->next;
				l2 = l2->next;
			}
			ptr = ptr->next;
		} while (l1 != list1->next && l2 != list2->next);

		while (l1 != list1) {
			ptr->next = l1;
			l1 = l1->next;
			ptr = ptr->next;
		}
		while (l2 != list2) {
			ptr->next = l2;
			l2 = l2->next;
			ptr = ptr->next;
		}

		ptr->next = list3;

		return list3;
	}



};
int main() {
	
}