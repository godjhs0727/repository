#pragma once
//헤더파일에는 왠만하면 다른헤더를 안넣는게 좋다.
//--------------------------
//부모 클래스(종족)
//--------------------------
class Brood
{
public:
	virtual ~Brood() = default; //소멸자를 넣어야하는데 몸체가 없을때
	virtual void Print() = 0;
};
//--------------------------
//자식 클래스(테란, 저그, 프로토스)
//--------------------------

class Terran : public Brood
{
	void Print() override { cout << "Terran" << endl; }
};
class Zerg : public Brood
{
	void Print() override { cout << "Zerg" << endl; }
};
class Protoss : public Brood
{
	void Print() override { cout << "Protoss" << endl; }
};
//-------------------------
//내가 선택한 종족
//-------------------------
template<typename T>
class MySelect
{
public:
	void Set(T* brood) { selected = brood; }
	T* Get() { return selected; }
private:
	T*selected;
};

class Temp
{
public:
	string Print() { return "나는 누구?"; }
};