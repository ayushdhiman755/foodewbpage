// C++ program to detect cycle in a linked list
#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

bool detectLoop(struct Node* h)
{
	unordered_set<Node*> s;
	while (h != NULL) {
		if (s.find(h) != s.end())
			return true;
		s.insert(h);
		h = h->next;
	}

	return false;
}

int main()
{
  struct Node* head = NULL;

	push(&head, 20);
	push(&head, 1);
	push(&head, 23);
	push(&head, 43);
	push(&head, 434);
	push(&head, 4324);
	push(&head, 1342);

	head->next->next->next->next = head;

	if (detectLoop(head))
		cout << "The list contain Loops";
	else
		cout << "No Loop present in link list";

	return 0;
}
// This code is contributed by Geetanjali
