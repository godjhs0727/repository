#include <iostream>
using namespace std;

struct Stack {		//stack
	int Array[5];	//�ִ�뷮 5�� ����
	int top;		//������ ���� �ٱ��� �迭��
};
void init(Stack* s) {//�ʱⰪ ����
	s->top = -1;
}
bool isEmpty(Stack* s) {//stack�� ����� ����
	return (s->top == -1);
}
bool isFull(Stack* s) {//stack�� �� ���ִ���
	return (s->top == 4);
}
void push(Stack* s, int data) {//stack�� ������ ����
	if (isFull(s)) { cout << "�� ������ �����ϴ�."; return; }//overflow����
	else s->Array[++(s->top)] = data;
}
int pop(Stack* s) {//stack�� ������ ����
	if (isEmpty(s)) { cout << "Stack�� ������ϴ�."; return -1; }//underflow����
	else return s->Array[(s->top)--];
}
int Top(Stack* s) {//���� stack�� �ִ� �� Ȯ��
	if (isEmpty(s)) { cout << "Stack�� ������ϴ�."; return -1; }
	else return s->Array[s->top];
}
int size(Stack* s) { return s->top + 1; } //stack sizeȮ��
int main() {
	Stack s;
	init(&s);
	push(&s, 3);
	cout << pop(&s) << endl;
	cout << Top(&s) << endl;
	cout << boolalpha << isEmpty(&s) << endl;
	cout << size(&s);
	return 0;
}