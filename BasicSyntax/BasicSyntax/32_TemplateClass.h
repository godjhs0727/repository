#pragma once
//������Ͽ��� �ظ��ϸ� �ٸ������ �ȳִ°� ����.
//--------------------------
//�θ� Ŭ����(����)
//--------------------------
class Brood
{
public:
	virtual ~Brood() = default; //�Ҹ��ڸ� �־���ϴµ� ��ü�� ������
	virtual void Print() = 0;
};
//--------------------------
//�ڽ� Ŭ����(�׶�, ����, �����佺)
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
//���� ������ ����
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
	string Print() { return "���� ����?"; }
};