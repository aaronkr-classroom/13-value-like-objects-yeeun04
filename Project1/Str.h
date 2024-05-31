#ifndef GUARD_Str
#define GUARD_Str

#include "Vec.h"
#include <algorithm>
#include <cstring>
#include<cctype>
#include<iterator>

class Str {
	// 입력 연산자
	friend std::istream& operator >>(std::istream&,  Str&);
	// getline();
public:
	typedef Vec<char>::size_type size_type;
	size_type size() const {return data.size();}

	// 비어있는 Str 객체를 만드는 기본 생성자
	Str() { }

	// c의 복사본 n개가 있는 Str 객체를 생성
	Str(size_type n, char c) : data(n, c){ }

	// null로 끝나는 char 타입의 배열에서 Str 객체를 생성
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp),
			std::back_inserter(data));
	}

	// 반복자 b와 c가 가르키는 범위에서 Str 객체를 생성
	template<class ln> Str(ln b, ln c) {
		std::copy(b, e, std::back_inserter(data));
	}

	// 인덱스 연산자
	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }
private:
	Vec<char>data;
};

std::ostream& operator<<(std::ostream&, const Str&);



#endif