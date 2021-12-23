#include <iostream>
#include <fstream>
using namespace std;

class FileCompare {
	ifstream src, dest;
public:
	FileCompare(const char* fsrc, const char* fdest);
	bool compare();
};

FileCompare::FileCompare(const char* fsrc, const char* fdest)
{
	src.open(fsrc, ios::in | ios::binary);
	if (!src) {
		cout << "열기오류"; exit(0);
	}
	dest.open(fdest, ios::in | ios::binary);
	if (!dest) {
		cout << "열기오류"; exit(0);
	}
}

bool FileCompare::compare()
{
	int s;
	while ((s = src.get()) != EOF) {		//소스 파일에서 읽은 바이트는 s
		int t = dest.get();					//목적 파일에서 읽은 바이트는 t
		// t와 s비교						
		if (t == EOF) return false;			//같지 않음
		else if (s != t) return false;		//같지 않음
	}
	//소스 파일을 끝까지 읽었음
	//목적 파일에 읽을 것이 남았는지 확인
	int t = dest.get();
	if (t != EOF) return false;
	//목적 파일에서 읽은 것이 있다면 두 파일은 같지 않음
	//both EOF
	return true;
}

int main() {
	cout << "비교하는 두 파일은" << "a.jpg" << "와"
		<< "b.jpg" << "입니다" << endl;
	cout << "이 두 파일은 소스 폴더에 있어야 합니다" << endl;
	FileCompare comp("a.jpg", "b.jpg");
	//a.jpg와 b.jpg의 비교. 두 파일은 소스 폴더에 있어야 함
	if (comp.compare())
		cout << "두 파일은 같습니다" << endl;
	else
		cout << "두 파일은 같지 않습니다" << endl;
	return 0;
}