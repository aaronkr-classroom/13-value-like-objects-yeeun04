#ifndef GUARD_Str
#define GUARD_Str

#include "Vec.h"
#include <algorithm>
#include <cstring>
#include<cctype>
#include<iterator>

class Str {
	// �Է� ������
	friend std::istream& operator >>(std::istream&,  Str&);
	// getline();
public:
	typedef Vec<char>::size_type size_type;
	size_type size() const {return data.size();}

	// ����ִ� Str ��ü�� ����� �⺻ ������
	Str() { }

	// c�� ���纻 n���� �ִ� Str ��ü�� ����
	Str(size_type n, char c) : data(n, c){ }

	// null�� ������ char Ÿ���� �迭���� Str ��ü�� ����
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp),
			std::back_inserter(data));
	}

	// �ݺ��� b�� c�� ����Ű�� �������� Str ��ü�� ����
	template<class ln> Str(ln b, ln c) {
		std::copy(b, e, std::back_inserter(data));
	}

	// �ε��� ������
	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }
private:
	Vec<char>data;
};

std::ostream& operator<<(std::ostream&, const Str&);



#endif