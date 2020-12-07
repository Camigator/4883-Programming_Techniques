/************************************
/ 
/ Cameron O'Neal
/ UVA judge 920 Sunny mountains
/ Programming Techniques
/
*************************************/

#include <iostream>
#include <algorithm>
#include <complex>
#include <limits>
using namespace std;

// found this idea online of define the equations before #define
// instead of constantly calcualting within the function
#define x real()
#define y imag()
#define crs(a, b) ( (conj(a) * (b)).y )
#define intrN(a, b, p, q) ( crs((p)-(a),(b)-(a)) * (q) - crs((q)-(a),(b)-(a)) * (p) )
#define intrD(a, b, p, q) ( crs((p)-(a),(b)-(a)) - crs((q)-(a),(b)-(a)) )
#define equ(a, b, e) ( abs((a) - (b)) <= (e) )
 
typedef long double Mountain;


const Mountain length = 1E8;
const Mountain EL = numeric_limits<Mountain>::epsilon() * length;
typedef complex <Mountain> peak;

 
bool cmp(peak i, peak j) {
    return i.x < j.x;
}
 
int main() {
    int c, n;
    peak p[128];
    cin >> c;
    cout.precision(2);
    while (c--) {
        // input
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        sort(p, p + n, cmp);
        // solve
        Mountain maxY = 0, num = 0;
        for (int i = n - 2; i >= 0; --i) {
            // a peak that sees the sun
            if (maxY <= p[i].y) {
                Mountain d = intrD(p[i], p[i + 1], peak(0, maxY), peak(1, maxY));
                if (!equ(d, 0, EL)) {
                    peak r = intrN(p[i], p[i + 1], peak(0, maxY), peak(1, maxY)) / d;
                    num += abs(p[i] - r);
                }
                maxY = p[i].y;
            }
        }
        cout << fixed << num << endl;
    }
    return 0;
}