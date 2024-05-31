#include <cctype>
#include <iostream>
#include <iterator>

#include "Str.h"

using namespace std;

ostream& operator<<(ostream& os, const Str& s) {
	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}
	return os;
}

// �Է� ������
istream& operator>>(istream& is, Str& s) {
	// ������ �� ����
	s.data.clear();
	char c;

	// ������ �Ǻ��ϴ� �� ���� ������ ����
	while (is.get(c) && std::isspace(c));

	// ���� ���ڰ� �����ִٸ� 
	// ���� ���� ���ڿ� ������ ������ ���ڸ� ����

	if (is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));

		// ������ �о��ٸ� �ٽ� ��Ʈ���� ���ܵ�
		if (is) {
			is.unget();
		}
	}
	return is;
}