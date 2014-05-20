// 把简单的问题复杂化真是我的拿手好戏！
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <limits>
// #include <ctype>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

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
	bool operator < (const Rational& rat) const
	{
		if(minus < rat.minus)
			return true;
		if(minus > rat.minus)
			return false;
		if(minus == 1)
			return a*rat.b < rat.a*b;
		if(minus == -1)
			return a*rat.b > rat.a*b;
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

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.size() <= 2)
			return points.size();
		int maxNum = 0;

        for(int i=0; i<points.size()-1; ++i){
			int x1 = points[i].x;
			int y1 = points[i].y;
			int sameWithI = 0;
			map<Rational, int> xnum;
			for(int j=i+1; j<points.size(); ++j){
				// if(j == i) continue;
				int x2 = points[j].x;
				int y2 = points[j].y;
				int yy = y2-y1;
				int xx = x2-x1;
				if(xx == 0 && yy == 0){
					++sameWithI;
				}else {
					if(xx == 0){
						yy = numeric_limits<int>::max();
						xx = 1;
					}
					if(xnum.count(Rational(yy, xx)) == 0)
						xnum[Rational(yy, xx)] = 1;
					else
						++xnum[Rational(yy, xx)];
				}
			}

			int cur = 0;
			map<Rational, int>::const_iterator xit = xnum.begin();
			while(xit != xnum.end()){
				int posNum = xit->second;
				cur = max(cur, posNum);
				++xit;
			}
			maxNum = max(maxNum, cur+1+sameWithI);
		}
			return maxNum;
	}
	};

	int main() {
		const int MAXOFF = 20;
		Solution so;

		// for(int i=0; i<0; ++i){
		// 	int a = rand()%MAXOFF;
		// 	int b = rand()%MAXOFF;
		// 	// if(a == 1) cout<<"DDDDDDDDDDDDDDDDD"<<endl;
		// 	vp.push_back(Point(a, b));
		// }
		Point pv[] = {Point(29,87),Point(145,227),Point(400,84),Point(800,179),Point(60,950),Point(560,122),Point(-6,5),Point(-87,-53),Point(-64,-118),Point(-204,-388),Point(720,160),Point(-232,-228),Point(-72,-135),Point(-102,-163),Point(-68,-88),Point(-116,-95),Point(-34,-13),Point(170,437),Point(40,103),Point(0,-38),Point(-10,-7),Point(-36,-114),Point(238,587),Point(-340,-140),Point(-7,2),Point(36,586),Point(60,950),Point(-42,-597),Point(-4,-6),Point(0,18),Point(36,586),Point(18,0),Point(-720,-182),Point(240,46),Point(5,-6),Point(261,367),Point(-203,-193),Point(240,46),Point(400,84),Point(72,114),Point(0,62),Point(-42,-597),Point(-170,-76),Point(-174,-158),Point(68,212),Point(-480,-125),Point(5,-6),Point(0,-38),Point(174,262),Point(34,137),Point(-232,-187),Point(-232,-228),Point(232,332),Point(-64,-118),Point(-240,-68),Point(272,662),Point(-40,-67),Point(203,158),Point(-203,-164),Point(272,662),Point(56,137),Point(4,-1),Point(-18,-233),Point(240,46),Point(-3,2),Point(640,141),Point(-480,-125),Point(-29,17),Point(-64,-118),Point(800,179),Point(-56,-101),Point(36,586),Point(-64,-118),Point(-87,-53),Point(-29,17),Point(320,65),Point(7,5),Point(40,103),Point(136,362),Point(-320,-87),Point(-5,5),Point(-340,-688),Point(-232,-228),Point(9,1),Point(-27,-95),Point(7,-5),Point(58,122),Point(48,120),Point(8,35),Point(-272,-538),Point(34,137),Point(-800,-201),Point(-68,-88),Point(29,87),Point(160,27),Point(72,171),Point(261,367),Point(-56,-101),Point(-9,-2),Point(0,52),Point(-6,-7),Point(170,437),Point(-261,-210),Point(-48,-84),Point(-63,-171),Point(-24,-33),Point(-68,-88),Point(-204,-388),Point(40,103),Point(34,137),Point(-204,-388),Point(-400,-106)};

		// Point p1(-1,-1);
		// Point p2(0,0);
		// Point p3(2,2);
		// cout<<sizeof(pv)/sizeof(Point)<<endl;
		vector<Point> vp(pv, pv+sizeof(pv)/sizeof(Point));
		cout<<vp.size()<<endl;
		// Point p1(1,1);
		// Point p2(0,0);
		// Point p3(1,1);

		// vp[0] = p1;
		// vp[1] = p2;
		// vp[2] = p3;

		// vp.push_back(Point(rand() % MAXOFF, rand() % MAXOFF));

		cout<<"somax: "<<so.maxPoints(vp)<<endl;

	}
