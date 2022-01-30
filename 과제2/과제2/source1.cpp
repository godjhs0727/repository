#include <iostream>
using namespace std;

struct node {
	int data;
	node* nextNode;
};

class LinkedList {
	node* head;
	node* tail;
public:
	LinkedList() {		//생성자로 head와 tail 초기화
		head = NULL;
		tail = NULL;
	}
	void addFrontNode(int n);		//첫번째의 node 추가(들어오는 node 첫번째에 추가)
	void addNode(int n);			//마지막의 node 추가(들어오는 node 뒤쪽에 순서대로 추가)

	void insertNode(node* preNode, int n);		//node 삽입(node 중간에 삽입)
	void deleteNode(node* preNode);				//node 삭제(매개변수 preNode 뒤 쪽에 있는 노드 삭제)
	void deleteFirstNode();						//첫번째에 있는 node 삭제

	node* getHead() {		//첫번째 node 가져오기
		return head;
	}
	void show(node* head);		//LinkedList 출력
};

void LinkedList::addFrontNode(int n) //추가하는 node 첫번째에
{
	node* temp = new node;
	temp->data = n;			//temp 데이터 n

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		temp->nextNode = head;
		head = temp;
	}
}

void LinkedList::addNode(int n)	//마지막에 node 추가
{
	node* temp = new node;
	temp->data = n;
	temp->nextNode = NULL;		//쓰레기 값이 나오지 않게 nextNode를 NULL로 설정
	
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->nextNode = temp;		//마지막 node의 nextNode는 temp
		tail = temp;
	}
}

void LinkedList::insertNode(node* preNode, int n)		//preNode에 n이라는 data가 들어가 있는 temp라는 node 삽입
{
	node* temp = new node;		//임의의 들어갈 노드 생성
	temp->data = n;

	temp->nextNode = preNode->nextNode;		//바꿔줄 node가 가리키는 nextNode를 temp의 nextNode로
	preNode->nextNode = temp;				//원래 가리키던 nextNode를 temp를 향함으로 변경
}

void LinkedList::deleteNode(node* preNode)
{
	node* temp = preNode->nextNode;		//삭제할 노드의 전 노드가 가리키는 포인터 값으로 복사
	preNode->nextNode = temp->nextNode;	//원래 삭제할 노드가 가리키던 다음 노드 값을 복사, temp는 고립된다.
	delete temp;						//temp 삭제
}

void LinkedList::deleteFirstNode()
{
	if (head == NULL) return;
	else {
		node* temp = new node;
		temp = head;
		head = head->nextNode;
		delete temp;
	}
}

void LinkedList::show(node* head)
{
	if (head == NULL) {
		return;
	}
	else {
		cout << head->data << ' ';
		show(head->nextNode);		//다음 연결리스트를 보여주기 위하여 재귀함수로 실행
	}
	cout << endl;
}

int main() {
	LinkedList a;	//연결리스트 생성
	a.addNode(1);	
	a.addNode(2);
	a.addNode(3);	//1,2,3 순서대로 추가됨

	a.show(a.getHead());	//1,2,3 출력
	a.addFrontNode(0);		//가장 앞에 0 추가
	a.insertNode(a.getHead()->nextNode, 4);	//0,1,2,3 에서 1뒤에 4가 추가됨
	a.show(a.getHead());					//0,1,4,2,3 출력
	a.deleteNode(a.getHead());				//0 뒤에 있는 노드 삭제 0,4,2,3 저장
	a.show(a.getHead());					//0,4,2,3 출력
	a.deleteFirstNode();					//가장 앞에 노드 삭제 4,2,3 저장
	a.show(a.getHead());					//4,2,3 출력
}