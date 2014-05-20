#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>

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

class line{
public:
	line()
		:k(), b(){}
	line(const Rational& kk, const Rational& bb, int ii, int jj)
		:k(kk), b(bb), i(ii), j(jj){}
	line(const line& l)
		:k(l.k), b(l.b), i(l.i), j(l.j){}
	line& operator=(const line& l)
	{
		k = l.k;
		b = l.b;
		i = l.i;
		j = l.j;
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
	int i, j;
};
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.size() <= 2)
			return points.size();
		int maxNum = 2;

		vector<int> ptCount;
		vector<Point> npoints;
        for(int i=0; i<points.size(); ++i){
			int a = points[i].x;
			int b = points[i].y;
			int j;
			for(j=0; j<npoints.size(); ++j){
				int c = npoints[j].x;
				int d = npoints[j].y;
				if(a==c && b==d){
					++ptCount[j];
					break;
				}
			}
			if(j==npoints.size()){
				npoints.push_back(points[i]);
				ptCount.push_back(1);
			}
		}
			// for(int j=0; j<npoints.size(); ++j){
				// cout<<ptCount[j]<<endl;
			// }


		vector<line> llist;
		map<int, int> xnum;
        for(int i=0; i<npoints.size()-1; ++i)
			for(int j=i+1; j<npoints.size(); ++j){
				// if(j == i) continue;
				int x1 = npoints[i].x;
				int y1 = npoints[i].y;
				int x2 = npoints[j].x;
				int y2 = npoints[j].y;
				int yy = y2-y1;
				int xx = x2-x1;
				if(xx != 0)
					llist.push_back(line(Rational(yy, xx), Rational(xx*y1 - yy*x1, xx), i, j));
				else if(xnum.count(x1) != 0)
					++xnum[x1];
				else
					xnum[x1] = 1;
			}
		// cout<<"llist.size: "<<llist.size()<<endl;
		// vector<int> bitmap(npoints.size());
		// fill(bitmap.begin(), bitmap.end(), 0);


		map<int, int>::const_iterator xit = xnum.begin();
		while(xit != xnum.end()){
			int posNum = (1+ sqrt(1+8*xit->second))/2;
			maxNum = max(maxNum, posNum);
			++xit;
		}

		// sort(llist.begin(), llist.end(), cmp_line1);
		// #typedef vector<int> vtmp(npoints.size());
			map<line, vector<int> > mli;
			// cout<<llist.size()<<endl;
			for(vector<line>::const_iterator lit = llist.begin(); lit!=llist.end(); ++lit){
				if(mli.count(*lit) == 0){
					mli[*lit] = vector<int>(npoints.size());
					fill(mli[*lit].begin(), mli[*lit].end(), 0);
				}
					// cout<<"DDDDDDDDDDDDDDDDDDDDDDDD"<<endl;
				int a = (*lit).i;
				int b = (*lit).j;
				// cout<<a<<" "<<b<<endl;
				mli[*lit][a] = 1;
				mli[*lit][b] = 1;
			}
			map<line, vector<int> >::const_iterator lit = mli.begin();
			while(lit != mli.end()){
				// cout<<"D: "<<lit->second<<endl;
				// int posNum = (1+ sqrt(1+8*lit->second))/2;
				// maxNum = max(maxNum, posNum);

				vector<int> tmp = lit->second;
				vector<int>::const_iterator iici = tmp.begin();
				int cur = 0;
				int ccc=0;
				while(iici != tmp.end()){

					if(*iici == 0){
						++iici;
						++ccc;
						continue;
					}
					// cout<<ptCount[ccc]<<endl;
						cur += ptCount[ccc];
					++iici;
					++ccc;
					// cout<<"DD"<<ccc<<" "<<cur<<endl;
				}
				// cout<<"sdf: "<<lit->second.size()<<endl;
				// cout<<cur<<endl;
				maxNum = max(cur, maxNum);
				++lit;
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
