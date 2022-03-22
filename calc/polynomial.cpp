#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <conio.h>
#include <Windows.h>
#include "polynomial.h"
#include "ChekOnRightOfNumber.h"

using namespace std;

//пров на кор. вода
int ProvVod(int k) {
	int prov = 0, a;
	if (k == -1) {
		do {
			cout << "Введите n(0 < n < 10): ";
			a = ChekOnInt();
			if (a > 0 && a < 10)
				prov = 1;
			else
				printf_s("n должно быть в ределах от 0 до 10!\n");
		} while (prov == 0);
	}
	else {
		do {
			printf_s("N%d(N!=1): ", k + 1);
			a = ChekOnInt();
			if (a != 0)
				prov = 1;
			else
				printf_s("N не должно быть равно 1!\n");
		} while (prov == 0);
	}
	return a;
}

//строку в инт
int StrToInt(string& s, int begin, int end) { 
	int val = 0;               
	bool negative = 0;          
	if (s[begin] == '+') begin++;
	else {
		if (s[begin] == '-') {   
			negative = 1;
			begin++;
		}
	}
	for (auto i = begin; i < end; ++i) { 
		val *= 10;
		val += s[i] - 48;
	}
	if (val == 0 && s[begin] != '0') val++; 
	if (negative == 1) val *= -1;
	return val;
}

//инт в строку
string IntToStr(int val) { 
	string s, tmp;
	if (val > 0) s.push_back('+'); 
	else {
		val *= -1;
		s.push_back('-');
	}
	while (val > 0) {
		tmp.push_back(val % 10 + 48); 
		val /= 10;
	}
	for (int i = tmp.size() - 1; i >= 0; --i) { 
		s.push_back(tmp[i]);
	}
	return s;
}

//оброботка знаков
void EraseThePlus(string& s) {  
	if (s[0] == '+') s.erase(s.begin());
}

//разбиение многочлена на состовляющие
void EraseTheOne(string& s) {  
	if ((s[1] == '1') && (s.size() == 2)) s.erase(s.begin() + 1);
}

//удаляет единицу
void Analyze(string& s, vector <int>& v) {  
	if (s.find("x") == string::npos) v[0] += StrToInt(s, 0, s.size()); 
	else {
		if (s.find("^") == string::npos) v[1] += StrToInt(s, 0, s.find("x"));  //Строка вида "ax".
		else {
			int power = StrToInt(s, s.find("^") + 1, s.size()); 
			v[power] += StrToInt(s, 0, s.find("x"));
		}
	}
}

//разбиение многочлена на слогаемые
vector <int> Decompose(string& s) { 
	vector <int> v(11);
	string cur_s;
	int i = 0;
	while (i < s.size()) {
		cur_s.clear();
		cur_s.push_back(s[i]);
		i++;
		while ((s[i] != '+') && (s[i] != '-') && (i < s.size())) { 
			cur_s.push_back(s[i]);
			i++;
		}
		Analyze(cur_s, v);
	}
	return v;
}

//умножение многочленов
vector <int> Multiplicate(vector <int>& a, vector <int>& b) { 
	vector <int> c(21);      
	for (int i = 0; i < c.size(); ++i) c[i] = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

//проверка на ошибку в многочлене
int Prov(string& s) {
	string a = "qwertyuiopasdfghjklzcvbnm-йцукенгшщзхъфывапролджэячсмитьбю";
	string A = "QWERTYUIOPASDFGHJKLZCVBNM-ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
	int i = 0, n = 0, n1 = 0;
	while (i < s.size()) {
		if ((s[i] == 'x' || s[i] == 'X') && n == 0) {
			n++;
		}
		for (int j = 0; j < 59; j++)
		{
			if (s[i] == a[j]) {
				n += 2;
				break;
			}
		}
		for (int j = 0; j < 59; j++)
		{
			if (s[i] == A[j]) {
				n += 2;
				break;
			}
		}
		if (s[i] == ' ' && s[i] == '.' && s[i] == ' ' && s[i] == '?' && s[i] == '!' && s[i] == ',' && s[i] == ':') {
			n+=2;
			break;
		}
		if (n > 2)
			break;
		i++;
	}
	return n;
}

//из вектора составляется строка
string Compose(vector <int>& v) { 
	string s;
	for (int i = v.size() - 1; i >= 2; --i) {
		if (v[i] != 0) {
			string coef = IntToStr(v[i]); 
			EraseTheOne(coef);
			s = s + coef;
			s.push_back('x');
			s.push_back('^');
			string power = IntToStr(i);  
			EraseThePlus(power);
			s = s + power;
		}
	}
	if (v[1] != 0) {  
		string coef = IntToStr(v[1]);
		EraseTheOne(coef);
		s = s + coef;
		s.push_back('x');
	}
	if (v[0] != 0) {
		s = s + IntToStr(v[0]);
	}
	return s;
}

//сложение многочленов
void AdditionOfPolynomials() {
	int polyn_a[2], polyn_b[2], polyn_n[2], polyn_c[2];
	cout << "Многочлен вида ax^2+bx+c:\n" << "Введите коэфиценты и степень для первого многочлена: \n";
	cout << "Введите a: "; polyn_a[0] = ChekOnInt(); cout << "Введите b: "; polyn_b[0] = ChekOnInt(); cout << "Введите n: "; polyn_n[0] = ChekOnInt(), cout << "Введите c: "; polyn_c[0] = ChekOnInt();
	cout << "Введите коэфиценты и степень для второго многочлена: \n";
	cout << "Введите a: "; polyn_a[1] = ChekOnInt(); cout << "Введите b: "; polyn_b[1] = ChekOnInt(); cout << "Введите n: "; polyn_n[1] = ChekOnInt(), cout << "Введите c: "; polyn_c[1] = ChekOnInt();
	if (polyn_n[0] == polyn_n[1] ) {
		if (polyn_a[0] + polyn_a[1] != 0) {
			if(polyn_n[0] != 0)
				printf_s("%dx^(%d)", polyn_a[0] + polyn_a[1], polyn_n[0]);
			else
				printf_s("%dx", polyn_a[0] + polyn_a[1]);
		}
		if (polyn_b[0] + polyn_b[1] != 0) {
			if (polyn_b[0] + polyn_b[1] > 0)
				printf_s("+%dx", polyn_b[0] + polyn_b[1]);
			else {
				printf_s("%dx", polyn_b[0] + polyn_b[1]);
			}
		}
		if (polyn_c[0] + polyn_c[1] != 0) {
			if (polyn_c[0] + polyn_c[1])
				printf_s("+%d", polyn_c[0] + polyn_c[1]);
			else
				printf_s("%d\n", polyn_c[0] + polyn_c[1]);
		}
	}
	else {
		if(polyn_a[0] != 0)
			if(polyn_n[0]!= 0)
				printf_s("%dx^(%d)", polyn_a[0], polyn_n[0]);
			else
				printf_s("%dx", polyn_a[0]);
		if (polyn_a[1] != 0) {
			if (polyn_a[1] > 0) {
				if (polyn_n[1] != 0)
					printf_s(" + %dx^(%d)", polyn_a[1], polyn_n[1]);
				else
					printf_s(" + %dx", polyn_a[1]);
			}
			else {
				if (polyn_n[1] != 0)
					printf_s("%dx^(%d)", polyn_a[1], polyn_n[1]);
				else
					printf_s("%dx", polyn_a[1]);
			}
		}
		if (polyn_b[0] + polyn_b[1] != 0) {
			if (polyn_b[0] + polyn_b[1] > 0)
				printf_s("+%dx", polyn_b[0] + polyn_b[1]);
			else {
				printf_s("%dx", polyn_b[0] + polyn_b[1]);
			}
		}
		if (polyn_c[0] + polyn_c[1] != 0) {
			if (polyn_c[0] + polyn_c[1] > 0)
				printf_s("+%d", polyn_c[0] + polyn_c[1]);
			else
				printf_s("%d\n", polyn_c[0] + polyn_c[1]);
		}
	}
}

//вычитание многочленов
void PolynomialSubtraction() {
	int polyn_a[2], polyn_b[2], polyn_n[2], polyn_c[2];
	cout << "Многочлен вида ax^2+bx+c:\n" << "Введите коэфиценты и степень для первого многочлена:\n";
	cout << "Введите a: "; polyn_a[0] = ChekOnInt(); cout << "Введите b: "; 
	polyn_b[0] = ChekOnInt(); cout << "Введите n: "; polyn_n[0] = ChekOnInt(), cout << "Введите c: "; polyn_c[0] = ChekOnInt();
	cout << "Введите коэфиценты и степень для второго многочлена:\n";
	cout << "Введите a: "; polyn_a[1] = ChekOnInt(); cout << "Введите b: "; 
	polyn_b[1] = ChekOnInt(); cout << "Введите n: "; polyn_n[1] = ChekOnInt(), cout << "Введите c: "; polyn_c[1] = ChekOnInt();
	if (polyn_n[0] == polyn_n[1]) {
		if (polyn_a[0] - polyn_a[1] != 0) {
			if (polyn_n[0] != 0)
				printf_s("%dx^(%d)", polyn_a[0] - polyn_a[1], polyn_n[0]);
			else
				printf_s("%dx", polyn_a[0] - polyn_a[1]);
		}
		if (polyn_b[0] - polyn_b[1] != 0) {
			if (polyn_b[0] + polyn_b[1] > 0)
				printf_s("+%dx", polyn_b[0] - polyn_b[1]);
			else {
				printf_s("%dx", polyn_b[0] - polyn_b[1]);
			}
		}
		if (polyn_c[0] - polyn_c[1] != 0) {
			if (polyn_c[0] + polyn_c[1]>0)
				printf_s("+%d", polyn_c[0] - polyn_c[1]);
			else
				printf_s("%d\n", polyn_c[0] - polyn_c[1]);
		}
	}
	else {
		if (polyn_a[0] != 0)
			if (polyn_n[0] != 0)
				printf_s("%dx^(%d)", polyn_a[0], polyn_n[0]);
			else
				printf_s("%dx", polyn_a[0]);
		if (polyn_a[1] != 0) {
			if (polyn_a[1] > 0) {
				if (polyn_n[1] != 0)
					printf_s(" + %dx^(%d)", polyn_a[1], polyn_n[1]);
				else
					printf_s(" + %dx", polyn_a[1]);
			}
			else {
				if (polyn_n[1] != 0)
					printf_s("%dx^(%d)", polyn_a[1], polyn_n[1]);
				else
					printf_s("%dx", polyn_a[1]);
			}
		}
		if (polyn_b[0] - polyn_b[1] != 0) {
			if (polyn_b[0] + polyn_b[1] > 0)
				printf_s("+%dx", polyn_b[0] - polyn_b[1]);
			else {
				printf_s("%dx", polyn_b[0] - polyn_b[1]);
			}
		}
		if (polyn_c[0] - polyn_c[1] != 0) {
			if (polyn_c[0] + polyn_c[1] > 0)
				printf_s("+%d", polyn_c[0] - polyn_c[1]);
			else
				printf_s("%d\n", polyn_c[0] - polyn_c[1]);
		}
	}
}

//Умножение многочленов
void PolynomialMultiplication() {
	string a, b;
	int col = 0, k = 0;
	vector <int> a_decomposed(11, 0);
	vector <int> b_decomposed(11, 0);
	do {
		cout << "Пример ввода: 3x^2+5x+6\n";
		cout << "Введите первый многочлен:\n";
		getline(cin, a);
		col += Prov(a);
		if (col == 1) {
			cout << "Введите второй многочлен:\n";
			getline(cin, b);
			col += Prov(b);
		}
		if (col == 2)
			k = 1;
		else {
			col = 0;
			cout << "Неверный ввод многочелна! Повоторите попытку.\n";
		}
	} while (k == 0);
	a_decomposed = Decompose(a);
	b_decomposed = Decompose(b);
	vector <int> c_decomposed = Multiplicate(a_decomposed, b_decomposed);
	string c = Compose(c_decomposed);
	EraseThePlus(c);
	if (c.size() > 0) cout << c;
	else cout << 0;
}

//Умножение многочлена на число
void MultiplicationByNumber() {
	string a, b;
	int col = 0, k = 0;
	vector <int> a_decomposed(11, 0);
	vector <int> b_decomposed(11, 0);
	do {
		cout << "Пример ввода: 3x^2+5x+6\n";
		cout << "Введите многочлен:\n";
		getline(cin, a);
		col += Prov(a);
		if (col == 1) {
			cout << "Введите число:\n";
			getline(cin, b);
			col += Prov(b);
		}
		else
			col = 2;
		if (col == 1)
			k = 1;
		else {
			col = 0;
			cout << "Неверный ввод многочелна! Повоторите попытку.\n";
		}
	} while (k == 0);
	a_decomposed = Decompose(a);
	b_decomposed = Decompose(b);
	vector <int> c_decomposed = Multiplicate(a_decomposed, b_decomposed);
	string c = Compose(c_decomposed);
	EraseThePlus(c);
	if (c.size() > 0) cout << c;
	else cout << 0;
}

//Производная от многочлена
void DerivativeOfaPolynomial() {
	int polyn_a[10], polyn_b, polyn_n[10], polyn_c, n;
	cout << "Многочлен вида aAx^N1+...+Akx^Nk+Bx+C:\n" << "Введите коэфиценты и степень для многочлена:\n";
	n = ProvVod(-1);
	for (int i = 0; i < n; i++) {
		printf_s("Введите A%d: ", i + 1);
		polyn_a[i]= ChekOnInt();
		polyn_n[i] = ProvVod(1);
	}
	printf_s("Введите B: ");
	polyn_b=  ChekOnInt();
	printf_s("Введите С: ");
	polyn_c = ChekOnInt();
	for (int i = 0; i < n; i++) {
		if (polyn_n[i] != 0 ) {
			if (polyn_a[i] != 0) {
				if (i == 0)
					printf_s("%dX^%d", polyn_a[i] * polyn_n[i], polyn_n[i] - 1);
				else {
					if (polyn_a[i] * polyn_n[i] > 0)
						printf_s("+%dX^%d", polyn_a[i] * polyn_n[i], polyn_n[i] - 1);
					else
						printf_s("%dX^%d", polyn_a[i] * polyn_n[i], polyn_n[i] - 1);
				}
			}
		}
		else {
			if (polyn_a[i] != 0) {
				if (i == 0)
					printf_s("%dX", polyn_a[i] );
				else {
					if (polyn_a[i]  > 0)
						printf_s("+%dX", polyn_a[i] );
					else
						printf_s("%dX", polyn_a[i] );
				}
			}
		}
	}
	if(polyn_b>0)
		printf_s("+%d", polyn_b);
	else
		printf_s("%d", polyn_b);
}

//Деления многочленов
void DivisionOfPolynomials() {
	double A1, A2, B1, C1, C2, A3,N3,B3,C3;
	int prov = 0, N1, N2;
	cout << "Пример ввода множителей:\n1 - A1X^N1+BX+C1\n2 - A2X^N2+C2\nПримечание все вводимые переменные не равны нулю, (N1-1)==N2, N1>=2\n";
	do {
		cout << "Введите A1: "; A1 = ChekOnDouble();;
		if (A1 != 0.0) {
			cout << "Введите N1: "; N1= ChekOnInt();
			if (N1 != 0 && N1>=2) {
				cout << "Введите B1: "; B1 = ChekOnDouble();
				if (B1 != 0.0) {
					cout << "Введите C1: ";C1 = ChekOnDouble();
					if (C1 != 0.0) {
						cout << "Введите A2: "; A2 = ChekOnDouble();
						if (A2 != 0.0) {
							cout << "Введите N2: "; N2 = ChekOnInt();
							if (N1 - 1 == N2) {
								cout << "Введите C2: "; C2 = ChekOnDouble();
								if (C2 != 0.0)
									prov = 1;
							}
						}
					}
				}
			}
		}
		else
			printf_s("Не удовлетворияет условию! Повторите попытку.\n");
		if(prov == 0)
			printf_s("Не удовлетворияет условию! Повторите попытку.\n");
	} while (prov == 0);

	if (N1 - 1 == 1.0) {
		A3 = A1 / A2;
		B3 = B1 - (A1 / A2) * C2;
		B3 = B3 / A2;
		C3 = C1 - B3 * C2;
		if (C2 > 0) {
			if (B3 > 0)
				printf_s("(%0.3lfX+%0.3lf)(%0.3lfX^%d+%0.3lf)", A3, B3, A2, N2, C2);
			else
				printf_s("(%0.3lfX%0.3lf)(%0.3lfX^%d+%0.3lf)", A3, B3, A2, N2, C2);
		}
		else{
			if (B3 > 0)
				printf_s("(%0.3lfX+%0.3lf)(%0.3lfX^%d %0.3lf)", A3, B3, A2, N2, C2);
			else
				printf_s("(%0.3lfX%0.3lf)(%0.3lfX^%d %0.3lf)", A3, B3, A2, N2, C2);
		}
		if (C3 > 0)
			printf_s("+%0.3lf", C3);
		else
			printf_s("%0.3lf", C3);
	}
	else {
		A3 = A1 / A2;
		if (C2 > 0)
			printf_s("(%0.3lfX)(%0.3lfX^%d+%0.3lf)",A3,A2,N2,C2);
		else
			printf_s("(%0.3lfX)(%0.3lfX^%d %0.3lf)", A3, A2, N2, C2);
		B3 = B1 - (A1 / A2) * C2;
		if(B3 > 0.0)
			printf_s("+%0.3lfX", B3);
		else
			printf_s("%0.3lfX", B3);
		if(C1 > 0)
			printf_s("+%0.3lf", C1);
		else
			printf_s("%0.3lf", C1);
	}

}

void Polynomial(int taskNumber) {

	switch (taskNumber) {
	case 0: DivisionOfPolynomials(); break;
	case 1: AdditionOfPolynomials(); break;
	case 2: PolynomialSubtraction(); break;
	case 3: PolynomialMultiplication(); break;
	case 4: MultiplicationByNumber(); break;
	case 5: DerivativeOfaPolynomial(); break;
	default: break;
	}
}