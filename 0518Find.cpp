#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
// #include <ctype>
using namespace std;

class Rational{
public:
	Rational()
		:a(0),b(0){}
	int a;
	int b;
};
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
bool same_line(const Point& p1, const Point& p2)
{
	if(p2.y == 0)
		return p1.y == 0;
	if(p1.y == 0)
		return p2.y == 0;
	return p1.x / p1.y == p2.x / p2.y;
}
class sort_k{
	bool operator () (Point& p1, Point& p2){
		if(p1.x == 0)
			return true;
		if(p2.x == 0)
			return false;
		return double(p1.y)/p1.x > double(p2.y)/p2.x;
}
};
class sort_b{
	bool operator () (Point& p1, Point& p2){
		if(p1.x == 0)
			return true;
		if(p2.x == 0)
			return false;
		return double(p1.y)/p1.x > double(p2.y)/p2.x;
}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int max = 2;
		vector<Point> pos;
		int len = points.size();
		pos.resize(len*(len-1)/2);
        for(int i=0; i<points.size()-1; ++i)
			for(int j=i+1; j<points.size(); ++j)
				pos.push_back(Point(points[i].x - points[j].x, points[i].y - points[j].y));


		return max;
    }
};

class Solution2 {
public:
	int evalRPN(vector<string> &tokens) {
		vector<int> result;
		for(int i=0; i<tokens.size(); ++i){
			if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i].size() > 1)){
				stringstream ss(tokens[i]);
				int a;
				ss>>a;
				result.push_back(a);
			}
			else{
				if(result.size() < 2) ;
				int b = result.back();
				result.pop_back();
				int a = result.back();

				result.pop_back();
				if(tokens[i] == "+"){
					result.push_back(a+b);
				}else if(tokens[i] == "-"){
					result.push_back(a-b);
				}else if(tokens[i] == "*"){
					result.push_back(a*b);
				}else if(tokens[i] == "/"){
					result.push_back(a/b);
				}
			}
		}
		return result.back();
	}
};


string reverse_string(istringstream & iss)
{
	string ss;
	if(iss >> ss)
		{
			const string & rets = reverse_string(iss);
			if(rets != "")
				return rets + " " + ss;
			else
				return ss;
		}
	else
		return "";
}
class Solution1 {
public:
	void reverseWords(string &s) {
		istringstream iss(s);
		s=reverse_string(iss);
	}
};

int main() {

	string sentence = "And   I   feel fine...  ";
	istringstream iss(sentence);
	ostringstream oss;
	// copy(istream_iterator<string>(iss),
	//          istream_iterator<string>(),
	//          ostream_iterator<string>(oss, " "));
	// vector<string> vstr;
	// string ostr;
	// while(iss >> ostr)
	// 	vstr.push_back(ostr);
	// cout<<ostr<<endl;
	string rets = reverse_string(iss);
	cout<<rets<<endl;
	Solution so;
	Point p1(1,1);
	Point p2(2,2);
	Point p3(3,3);
	vector<Point> vp(3);
	vp[0] = p1;
	vp[1] = p2;
	vp[2] = p3;
	cout<<"somax: "<<so.maxPoints(vp)<<endl;
	// int rpn = so.evalRPN(vrpn);
	// cout<<rpn<<endl; 
	// cout<<oss.str()<<endl;
}

// #include <iostream>
// #include <algorithm>
// #include <string>

// using namespace std;
// 	int iarray[20];
// int main()
// {

// 	iarray[3] = 90;
// 	int *ip = find(iarray, iarray+20, 90);
// 	cout<<ip-iarray<<endl;
// 	string ss = "hello damn";

// 	return 0;
// }
