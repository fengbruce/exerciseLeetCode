#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

// #include <ctype>
using namespace std;
#include <stdlib.h>
#include <math.h>
// pre-condition a > b
int gcd(int a, int b)
{
	if(b == 0) return 1;
	int remain = a - a/b * b;
	if(remain == 0)
		return b;
	return gcd(b, remain);
}

class Rational{
public:
	Rational()
		:a(0),b(0),minus(1){}
	explicit Rational(int aa, int bb)
	{
		int c;
		minus = aa*bb >= 0 ? 1:-1;
		int la = abs(aa);
		int lb = abs(bb);
		if(la > lb)
			c = gcd(la, lb);
		else
			c = gcd(lb, la);
		a = la / c;
		b = lb / c;
	}
	Rational(const Rational& rat)
		:a(rat.a), b(rat.b), minus(rat.minus)
	{}
	Rational & operator = (const Rational& rat)
	{
		a = rat.a;
		b = rat.b;
		minus = rat.minus;
		return *this;
	}
	bool operator == (const Rational& rat) const
	{
		return a == rat.a && b == rat.b && minus == rat.minus;
	}
	bool operator > (const Rational& rat) const
	{
		if(minus > rat.minus)
			return true;
		if(minus < rat.minus)
			return false;
		if(minus == 1)
		return a*rat.b > rat.a*b;
		if(minus == -1)
		return a*rat.b < rat.a*b;
	}
	void show() const
	{
		if(minus == -1)
			cout<<"-";
		cout<<a<<"/"<<b;
	}

	int a;
	int b;
	int minus;
};
struct cmp_rational{
	// bool operator()(const Rational& r1, const Rational& r2)
	bool operator()(const Rational& r1, const Rational& r2)
	{
		return r1 > r2;
	}
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class line{
public:
	line()
		:k(), b(){}
	line(const Rational& kk, const Rational& bb)
		:k(kk), b(bb){}
	line(const line& l)
		:k(l.k), b(l.b){}
	line& operator=(const line& l)
	{
		k = l.k;
		b = l.b;
		return *this;
	}
	bool operator==(const line& l) const
	{
		return k == l.k && b == l.b;
	}
	bool operator <(const line& l) const
	{
		if(l.k > k) return true;
		if(k == l.k && l.b > b) return true;

		return false;

	}
	void show() const
	{
		cout<<"K = ";
		k.show();
		cout<<"   B = ";
		b.show();
		cout<<endl;
	}
	Rational k, b;
};
	void show(const line& l)
	{
		cout<<"K = ";
		l.k.show();
		cout<<"   B = ";
		l.b.show();
		cout<<endl;
	}

bool cmp_line1(const line& l1, const line& l2)
{
	return l1.k > l2.k;
}
bool cmp_line2(const line& l1, const line& l2)
{
	return l1.b > l2.b;
}
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int maxNum = 2;
		vector<line> llist;
		map<int, int> xnum;
        for(int i=0; i<points.size()-1; ++i)
			for(int j=i+1; j<points.size(); ++j){
				int x1 = points[i].x;
				int y1 = points[i].y;
				int x2 = points[j].x;
				int y2 = points[j].y;
				int yy = y2-y1;
				int xx = x2-x1;
				if(xx != 0)
				llist.push_back(line(Rational(yy, xx), Rational(xx*y1 - yy*x1, xx)));
				else if(xnum.count(x1) != 0)
					++xnum[x1];
				else
					xnum[x1] = 1;
			}

		map<int, int>::const_iterator xit = xnum.begin();
		while(xit != xnum.end()){
			int posNum = (1+ sqrt(1+8*xit->second))/2;

			maxNum = max(maxNum, posNum);
			++xit;
		}
		sort(llist.begin(), llist.end(), cmp_line1);

		map<line, int> mli;
		for(vector<line>::iterator lit = llist.begin(); lit!=llist.end(); ++lit){
			if(mli.count(line()) != 0)
				++mli[*lit];
			else
				mli[*lit] = 1;
		}
		map<line, int>::const_iterator lit = mli.begin();
		while(lit != mli.end()){
			int posNum = (1+ sqrt(1+8*lit->second))/2;
			cout<<posNum<<endl;
			maxNum = max(maxNum, posNum);
			++lit;
		}

		return maxNum;
    }
};

struct cmp_int{
	bool operator ()(int a, int b)
	{
		return a > b;
	}
};


bool myfunction (int i,int j) { return (i<j); }
struct myclass {
	bool operator() (int i,int j) { return (i<j);}
} myobject;
bool rat_cmp(Rational rat1, Rational rat2)
{
	return rat1 > rat2;
}
int main() {
	const int MAXOFF = 20;
	Solution so;
	vector<Point> vp;
	for(int i=0; i<20; ++i){
			int a = rand()%MAXOFF;
			int b = rand()%MAXOFF;
			if(a == 1) cout<<"DDDDDDDDDDDDDDDDD"<<endl;
			vp.push_back(Point(a, b));
	}
		// vp.push_back(Point(rand() % MAXOFF, rand() % MAXOFF));

	cout<<"somax: "<<so.maxPoints(vp)<<endl;

	cout<<"SQRT: "<<sqrt(25)<<endl;
	Rational r1(3,8);
	Rational r2(4,6);
	if(r1>r2)
		cout<<gcd(81, 53)<<endl;
	vector<Rational> vr;
	for(int i=0; i<20; ++i)
		vr.push_back(Rational(rand()%20, rand()%20));
	cmp_rational cration;
	// sort(vr[0], vr[19], cration);
	// sort(vr.begin(), vr.end(), rat_cmp);
	stable_sort(vr.begin(), vr.end(), cration);
	for(int i=0; i<20; ++i)
		vr[i].show();

	// vector<int> vi;
	// for(int i=0; i<20; ++i)
	// 	vi.push_back(rand()%20);
	// cmp_int mo;
	// // myclass mo;
	// sort(vi.begin(), vi.end(), mo);
	// for(int i=0; i<20; ++i)
	// 	cout<<vi[i]<<endl;
}
