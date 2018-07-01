#include<iostream>

class Fraction{
	private:
		int num;
		int denom;
	public:
		Fraction(int x = 0, int y = 0):num(x), denom(y){
			if(y != 0)
				reduce();
		}
		int gcd(int a, int b);
		void reduce();
		friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
		friend std::istream& operator>>(std::istream& in, Fraction& f1);
		friend Fraction operator*(const Fraction& f1, const Fraction& f2);
		friend Fraction operator*(const Fraction& f1, int val);
		friend Fraction operator*(int val, const Fraction& f1);
		void print();
};

int Fraction::gcd(int a, int b){
	return (b == 0)?a:gcd(b, a%b);
}

void Fraction::reduce(){
	int gcd1 = gcd(num, denom);
	num /= gcd1;
	denom /= gcd1;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1){
	out<<f1.num<<"/"<<f1.denom<<std::endl;
}

std::istream& operator>>(std::istream& in, Fraction& f1){
	in>>f1.num;
	in>>f1.denom;
	f1.reduce();
}

Fraction operator*(const Fraction& f1, const Fraction& f2){
	return Fraction(f1.num * f2.num, f1.denom * f2.denom);
}

Fraction operator*(const Fraction& f1, int val){
	return Fraction(f1.num * val, f1.denom);
}

Fraction operator*(int val, const Fraction& f1){
	return f1 * val;
}

void Fraction::print(){
	std::cout<<num<<"/"<<denom<<std::endl;
}


int main(){
	Fraction f1;
	std::cin>>f1;
	std::cout<<f1<<std::endl;
	Fraction f2;
	std::cin>>f2;
	std::cout<<f2<<std::endl;
	Fraction f3 = f1 * f2;
	std::cout<<f3<<std::endl;
	std::cout<<"f1 * 4 = "<<f1 * 4<<std::endl;
	return 0;
}
