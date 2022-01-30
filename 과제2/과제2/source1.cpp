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
	LinkedList() {		//�����ڷ� head�� tail �ʱ�ȭ
		head = NULL;
		tail = NULL;
	}
	void addFrontNode(int n);		//ù��°�� node �߰�(������ node ù��°�� �߰�)
	void addNode(int n);			//�������� node �߰�(������ node ���ʿ� ������� �߰�)

	void insertNode(node* preNode, int n);		//node ����(node �߰��� ����)
	void deleteNode(node* preNode);				//node ����(�Ű����� preNode �� �ʿ� �ִ� ��� ����)
	void deleteFirstNode();						//ù��°�� �ִ� node ����

	node* getHead() {		//ù��° node ��������
		return head;
	}
	void show(node* head);		//LinkedList ���
};

void LinkedList::addFrontNode(int n) //�߰��ϴ� node ù��°��
{
	node* temp = new node;
	temp->data = n;			//temp ������ n

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		temp->nextNode = head;
		head = temp;
	}
}

void LinkedList::addNode(int n)	//�������� node �߰�
{
	node* temp = new node;
	temp->data = n;
	temp->nextNode = NULL;		//������ ���� ������ �ʰ� nextNode�� NULL�� ����
	
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->nextNode = temp;		//������ node�� nextNode�� temp
		tail = temp;
	}
}

void LinkedList::insertNode(node* preNode, int n)		//preNode�� n�̶�� data�� �� �ִ� temp��� node ����
{
	node* temp = new node;		//������ �� ��� ����
	temp->data = n;

	temp->nextNode = preNode->nextNode;		//�ٲ��� node�� ����Ű�� nextNode�� temp�� nextNode��
	preNode->nextNode = temp;				//���� ����Ű�� nextNode�� temp�� �������� ����
}

void LinkedList::deleteNode(node* preNode)
{
	node* temp = preNode->nextNode;		//������ ����� �� ��尡 ����Ű�� ������ ������ ����
	preNode->nextNode = temp->nextNode;	//���� ������ ��尡 ����Ű�� ���� ��� ���� ����, temp�� ���ȴ�.
	delete temp;						//temp ����
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
		show(head->nextNode);		//���� ���Ḯ��Ʈ�� �����ֱ� ���Ͽ� ����Լ��� ����
	}
	cout << endl;
}

int main() {
	LinkedList a;	//���Ḯ��Ʈ ����
	a.addNode(1);	
	a.addNode(2);
	a.addNode(3);	//1,2,3 ������� �߰���

	a.show(a.getHead());	//1,2,3 ���
	a.addFrontNode(0);		//���� �տ� 0 �߰�
	a.insertNode(a.getHead()->nextNode, 4);	//0,1,2,3 ���� 1�ڿ� 4�� �߰���
	a.show(a.getHead());					//0,1,4,2,3 ���
	a.deleteNode(a.getHead());				//0 �ڿ� �ִ� ��� ���� 0,4,2,3 ����
	a.show(a.getHead());					//0,4,2,3 ���
	a.deleteFirstNode();					//���� �տ� ��� ���� 4,2,3 ����
	a.show(a.getHead());					//4,2,3 ���
}