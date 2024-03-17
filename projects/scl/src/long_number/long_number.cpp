#include "long_number.hpp"

namespace ABelyaeva {
	LongNumber::LongNumber() {
		sign = POSITIVE;
		length = 0;
		numbers = nullptr;
	}
	
	LongNumber::LongNumber(const char* const str) {
		length = get_length(str);

		if (str[0] == MINUS) {
			sign = NEGATIVE;
			str++;
		}
		else {
			sign = POSITIVE;
		}

		numbers = new int[length];
		for (int i = 0; i < length; i++) {
			numbers[i] = str[i] - '0';
		}
	}
	
	LongNumber::LongNumber(const LongNumber& x) {
		sign = x.sign;
		length = x.length;
		numbers = new int[length];
		for (int i = 0; i < length; ++i) {
			numbers[i] = x.numbers[i];
		}
	}
	
	LongNumber::LongNumber(LongNumber&& x) {
		sign = x.sign;
		length = x.length;
		numbers = x.numbers;
		x.numbers = nullptr;
		x.length = 0;
	}
	
	LongNumber::~LongNumber() {
		if (numbers != nullptr) {
			delete[] numbers;
		}
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
		~LongNumber();
		LongNumber(str);
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {
		if (this == &x) {
			return *this;
		}
		~LongNumber();
		LongNumber(x);

		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
		if (this != &x) {
			~LongNumber();
		}
		LongNumber(x);
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x) {
		if (sign != x.sign || length != x.length) {
			return false;
		}

		for (int i = 0; i < length; ++i) {
			if (numbers[i] != x.numbers[i]) {
				return false;
			}
		}
		return true;
	}
	
	bool LongNumber::operator > (const LongNumber& x) {
		if (sign > x.sign) {
			return true;
		}
		else if (sign < x.sign) {
			return false;
		}

		if (sign == POSITIVE) {
			if (length > x.length) {
				return true;
			}
			else if (length < x.length) {
				return false;
			}

			for (int i = 0; i < length; ++i) {
				if (numbers[i] > x.numbers[i]) {
					return true;
				}
				else if (numbers[i] < x.numbers[i]) {
					return false;
				}
			}
		}
		else {
			if (length > x.length) {
				return false;
			}
			else if (length < x.length) {
				return true;
			}

			for (int i = 0; i < length; ++i) {
				if (numbers[i] > x.numbers[i]) {
					return false;
				}
				else if (numbers[i] < x.numbers[i]) {
					return true;
				}
			}
		}
		return false;
	}
	
	bool LongNumber::operator < (const LongNumber& x) {
		if (sign < x.sign) {
			return true;
		}
		else if (sign > x.sign) {
			return false;
		}

		if (sign == POSITIVE) {
			if (length < x.length) {
				return true;
			}
			else if (length > x.length) {
				return false;
			}

			for (int i = 0; i < length; ++i) {
				if (numbers[i] < x.numbers[i]) {
					return true;
				}
				else if (numbers[i] > x.numbers[i]) {
					return false;
				}
			}
		}
		else {
			if (length > x.length) {
				return true;
			}
			else if (length < x.length) {
				return false;
			}

			for (int i = 0; i < length; ++i) {
				if (numbers[i] > x.numbers[i]) {
					return true;
				}
				else if (numbers[i] < x.numbers[i]) {
					return false;
				}
			}
		}
		return false;
	}

	LongNumber LongNumber::operator + (const LongNumber& x) {
		LongNumber result;
		int max_length = std::max(this->length, x.length) + 1;  // �������������� ������� ��� ����� ��������

		// ������������� ���� ����������
		if (this->sign == x.sign) {
			result.sign = this->sign;
		}
		else {
			bool abs = false;

			if (this->length != x.length) {
				abs = this->length > x.length;
			}
			else {
				for (int i = this->length - 1; i >= 0; --i) {
					if (this->numbers[i] != x.numbers[i]) {
						abs = this->numbers[i] > x.numbers[i];
						break;
					}
				}
			}

			result.sign = abs ? this->sign : x.sign;
		}

		// �������� ������ ��� ����� � �������������� ������� result
		result.numbers = new int[max_length];

		int trans = 0;
		for (int i = 0; i < max_length - 1 || trans; ++i) {
			int sum = trans;
			if (i < this->length) sum += this->numbers[i];
			if (i < x.length) sum += x.numbers[i];

			trans = sum / 10;
			sum %= 10;

			result.numbers[i] = sum;
		}

		// ��������� ����� ����������
		result.length = trans ? max_length : max_length - 1;

		return result;
	}


	
	LongNumber LongNumber::operator - (const LongNumber& x) {
		LongNumber result;
		int max_length = std::max(this->length, x.length); // ������������ ����� ��� ����� ���� ��������

		// ���������� ���� ����������
		if (this->sign != x.sign) {
			result.sign = this->sign;
		}
		else {
			// ����� ����������, ����� �������� ���������� ��������
			bool abs = false;

			if (this->length != x.length) {
				abs = this->length > x.length;
			}
			else {
				for (int i = this->length - 1; i >= 0; --i) {
					if (this->numbers[i] != x.numbers[i]) {
						abs = this->numbers[i] > x.numbers[i];
						break;
					}
				}
			}

			result.sign = abs ? this->sign : x.sign;
		}

		// �������� ������ ��� ����� � �������������� ������� result
		result.numbers = new int[max_length];

		int borrow = 0;
		for (int i = 0; i < max_length; ++i) {
			int diff = borrow;
			if (i < this->length) diff += this->numbers[i];
			if (i < x.length) diff -= x.numbers[i];

			if (diff < 0) {
				diff += 10;
				borrow = -1;
			}
			else {
				borrow = 0;
			}

			result.numbers[i] = diff;
		}

		// ��������� ����� ����������
		int new_length = max_length;
		while (new_length > 0 && result.numbers[new_length - 1] == 0) {
			new_length--;
		}

		result.length = new_length > 0 ? new_length : 1; // ����� �� ������ ����� ������ 0

		return result;
	}

	
	LongNumber LongNumber::operator * (const LongNumber& x) {
		LongNumber result;

		result.sign = (this->sign == x.sign) ? POSITIVE : NEGATIVE; // ����������� ����� ����������

		// �������� ������ ��� ����� � �������������� ������� result
		int result_length = this->length + x.length; // ������������ ����� ������������
		result.numbers = new int[result_length];
		std::fill(result.numbers, result.numbers + result_length, 0); // ���������� ������

		// ��������� "� �������"
		for (int i = 0; i < this->length; ++i) {
			int trans = 0;
			for (int j = 0; j < x.length || trans; ++j) {
				long long temp = result.numbers[i + j] + this->numbers[i] * 1LL * (j < x.length ? x.numbers[j] : 0) + trans;
				result.numbers[i + j] = temp % 10;
				trans = temp / 10;
			}
		}

		// ��������� ����� ����������
		int new_length = result_length;
		while (new_length > 0 && result.numbers[new_length - 1] == 0) {
			new_length--;
		}

		result.length = new_length > 0 ? new_length : 1; // ����� �� ������ ����� ������ 0

		return result;
	}

	
	LongNumber LongNumber::operator / (const LongNumber& x) {
		LongNumber result;

		// ���������� ���� ����������
		result.sign = (this->sign == x.sign) ? POSITIVE : NEGATIVE;

		// �������� ������ ��� ����� � �������������� ������� result
		int result_length = std::max(1, this->length - x.length + 1);
		result.numbers = new int[result_length];
		std::fill(result.numbers, result.numbers + result_length, 0); // �������� ������

		LongNumber tempDividend = *this; // ��������� ������� ��� ��������� ����������

		for (int i = this->length - x.length; i >= 0; --i) {
			int digit = 0;
			LongNumber product = x * LongNumber(digit);

			// �������� ��������� ����� ��� �������
			while (tempDividend >= product) {
				digit++;
				product = x * LongNumber(digit);
			}

			// ���������� ����� ����������
			result.numbers[i] = digit;

			// ��������� ���������� ����� ��������
			tempDividend = tempDividend - (product - x);
		}

		// ��������� ����� ����������, �������� ������� ����
		int new_length = result_length;
		while (new_length > 0 && result.numbers[new_length - 1] == 0) {
			new_length--;
		}

		result.length = new_length > 0 ? new_length : 1; // ����� �� ������ ����� ������ 0

		return result;
	}

	
	LongNumber LongNumber::operator % (const LongNumber& x) {
		LongNumber result;

		// ���������� ���� ���������� 
		result.sign = this->sign;

		// ��������� ������� � �������� ������ ���������� ��������
		LongNumber quotient = *this / x;
		LongNumber product = x * quotient;
		result = *this - product;

		return result;
	}

	
	int LongNumber::get_digits_number() const {
		int count = 0;

		if (length == 1 && numbers[0] == 0) {
			// ���� ����� ����� ����, ���������� 1
			return 1;
		}

		LongNumber temp = *this; // �������� ������� ����� ��� ���������

		while (temp.length > 0) {
			int lastDigit = temp.numbers[temp.length - 1];
			count++;

			temp = temp / LongNumber(10);
		}

		return count;
	}

	
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}

	bool LongNumber::is_negative() const {
		return sign == NEGATIVE;
	}
	
	
	int LongNumber::get_length() const {
		int �ount = 0;

		if (length == 1 && numbers[0] == 0) {
			// ���� ����� ����� ����, ���������� 1
			return 1;
		}

		LongNumber temp = *this; // �������� ������� ����� ��� ���������

		while (temp.length > 0) {
			int lastDigit = temp.numbers[temp.length - 1];
			�ount++;

			temp = temp / LongNumber(10);
		}

		return �ount;
	}

	
	std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
		// ������� ���� �����
		if (x.sign == NEGATIVE) {
			os << '-';
		}

		// ������� ������ ����� �����
		for (int i = x.length - 1; i >= 0; --i) {
			os << x.numbers[i];
		}

		return os;
	}
}
