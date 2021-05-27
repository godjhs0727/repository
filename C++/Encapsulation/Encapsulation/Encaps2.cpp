#include <iostream>
using namespace std;

class SinivelCap //Äà¹° Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { cout << "Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù." << endl; }
};

class SneezeCap //ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << endl; }
};

class SnuffleCap //ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { cout << "ÄÚ°¡ »½~ ¶Õ¸³´Ï´Ù." << endl; } //Ãâ·Â¿ë const»ó¼öÈ­
};

class CONTAC600 //ÇÑ¹ø¿¡ ´Ù µé¾îÀÖ´Â ¾à
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient //ÀüºÎ Ä¸½¶È­ÇØ¼­ ¹­¾î¹ö¸°´Ù.
{
public:
	void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

int main()
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);

	return 0;
}