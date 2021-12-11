#include <iostream>
using namespace std;

struct Stack {		//stack
	int Array[5];	//최대용량 5로 설정
	int top;		//스택의 가장 바깥쪽 배열값
};
void init(Stack* s) {//초기값 설정
	s->top = -1;
}
bool isEmpty(Stack* s) {//stack의 빈공간 유무
	return (s->top == -1);
}
bool isFull(Stack* s) {//stack이 꽉 차있는지
	return (s->top == 4);
}
void push(Stack* s, int data) {//stack에 데이터 삽입
	if (isFull(s)) { cout << "들어갈 공간이 없습니다."; return; }//overflow방지
	else s->Array[++(s->top)] = data;
}
int pop(Stack* s) {//stack에 데이터 제거
	if (isEmpty(s)) { cout << "Stack이 비었습니다."; return -1; }//underflow방지
	else return s->Array[(s->top)--];
}
int Top(Stack* s) {//현재 stack에 있는 값 확인
	if (isEmpty(s)) { cout << "Stack이 비었습니다."; return -1; }
	else return s->Array[s->top];
}
int size(Stack* s) { return s->top + 1; } //stack size확인
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