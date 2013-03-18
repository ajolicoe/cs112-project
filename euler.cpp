#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <inttypes.h>
#include <cmath>
#include <cassert>

using namespace std;

//coin denomination vector
vector<int> coins;

void initCoins();

int triplet (int);
int lcm (int, int);
int countWays (int, int);
bool isPermutationOf (vector <int>, vector<int>);
bool isPenta (int);
int fibonacci (int);

int euler31Total;

int euler2 ();
long long euler3 ();
int euler5 ();
int euler9 ();
int euler31 ();
int euler44 ();
int euler52 ();

/*recursively calculate fibonacci numbers
 *@param int n - fibonacci index
 *@return int fib - nth fibonacci number */
int fibonacci (int n) {
	if (n == 0 || n == 1) return n;
	else return (fibonacci (n-1) + fibonacci (n-2));
}

/*@return the sum of all even fibonacci numbers less than 4,000,000 */
int euler2 () {
	clock_t begin = clock();
	int i = 0, c;
	int sum = 0;
	//definitely cannot go past first 50 fibonacci numbers
	for (c = 1; c <= 50; c++) {
		int f = fibonacci (i);
		if (f > 4000000) break;   //f is not less than 4,000,000
		if (f % 2 == 0) sum += f; //f is even
		i++;
	}
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 2: " << sum << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(sum == 4613732);
	return sum;
}

/*@return largest prime factor of 600,851,475,143 */
long long euler3 () {
	clock_t begin = clock();
	long long num = 600851475143;

	for (int i = 2; i < sqrt(num); i++) {
		while (num % i == 0 && num != i) {
		//num is divisible by i, so divide it.
		num = num/i;
		}
	}
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 3: " << num << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(num == 6857);
	return num;
}

/*return lowest common multiple
 *to calculate lcm(a, b, c) do lcm(lcm(a,b),c)
 *@param int a - first number
 *@param int b - second number
 *@return int lcm - lowest common multiple of a and b */
int lcm (int a, int b) {
	int c = 2, s = 1;
	while (a >= c && b >= c) {
		if (a % c == 0 && b % c == 0) {
			s *= c;
			a /= c;
			b /= c;
		} else {
			c++;
		}
	}
	return s*a*b;
}

/*@compute lowest common multiple of all numbers 1 through 20 */
int euler5 () {
	clock_t begin = clock();
	//if num is a multiple of 11..20, then num is already a multiple of 1..10
	int m = lcm(lcm(lcm(lcm(lcm(lcm(lcm(lcm(lcm(11,12),13),14),15),16),17),18),19),20);
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 5: " << m << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(m == 232792560);
	return m;
}

/*compute pythagorean triplet with a specific perimeter p
 *@param int p - right triangle's perimeter
 *@return int product  - product of right triangle's perimeter */
int triplet (int p) {
	int limit = floor (sqrt (p));
	for (int m = 2; m < limit; m++) {
		for (int n = 1; n < (m-1); n++) {
			int a = m*m - n*n;
			int b = 2*m*n;
			int c = m*m + n*n;
			if ((a + b + c) == p) return a*b*c;
		}
	}
}

/*compute special pythagorean triplet with perimeter equal to 1000 */
int euler9 () {
	clock_t begin = clock();
	int t = triplet (1000);
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 9: " << t << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(t == 31875000);
	return t;
}

/*increment counter for each time we reach the wanted sum of 200 pence.
 *@param int a - size of coin denomination vector
 *@param int b - wanted sum = 200 pence (2 pounds) 
 *@return int euler31Total - total number of ways */
int countWays (int a, int b) {
	int pred = a - 1; //index of denomination
	if (a == 1) return 1;
	else {
		//v = amount left / largest coin denomination. first call v = 200/200
		int v = b / (coins.at(pred));
		for (int i = 0; i <= v; i++) {
			euler31Total += countWays (pred, (b - i * coins.at(pred)));
		}
	}
}

//initialize coin denomination vector
void initCoins () {
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(20);
	coins.push_back(50);
	coins.push_back(100);
	coins.push_back(200);

	/*vector<int>::iterator it;
	for (it = coins.begin(); it != coins.end(); ++it) {
		cout << ' ' << *it;
	}
	cout << endl;
	*/
}

/*@compute number of ways 200 pence (2 pounds) can be made out of
 * the british coin denominations */
int euler31 () {
	clock_t begin = clock();
	euler31Total = 0;
	countWays (coins.size(), 200);
	clock_t end = clock();
	double time= double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 31: " << euler31Total << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(euler31Total == 73682);
	return euler31Total;
}

int penta (int x) {
	return x * (3 * x - 1) / 2; 
}

bool isPenta (int x) {
	double pentaX = (sqrt(24*x+1)+1)/6;
	return fmod(pentaX, 1.0) == 0;
}

/*@return the pair of pentagonal numbers, such that a+b is pentagonal,
 * a-b is pentagonal, and a-b is minimized */
int euler44 () {
	clock_t begin = clock();

	int res = 0;
	for (int i = 1; res == 0; i++) {
		int pi = penta(i);
		for (int j = 1; j < i; j++) {
			int pj = penta(j);
			if (isPenta(pi - pj) && isPenta(pi + pj)) {
				res = pi - pj;
				break;
			}
		}
	}
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 44: " << res << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(res == 5482660);
	return res;
}

bool isPermutationOf(vector<int> a, vector<int> b) {
	if (a.size() == b.size()) {
		sort (a.begin(), a.end());
		sort (b.begin(), b.end());
		if (a == b) return true;
	}
	return false;
}

int euler52() {
	clock_t begin = clock();
	int res;
	vector<int> one;
	vector<int> two;
	vector<int> three;
	vector<int> four;
	vector<int> five;
	vector<int> six;
	
	for (int i = 0; i < 150000; i++) {
		two.clear();
		three.clear();
		four.clear();
		five.clear();
		six.clear();
		int temp = 2*i;
		while (temp > 0) {
			cout << "inserting " << temp%10 << " into two" << endl;
			two.insert(two.begin(),temp%10);
			temp/=10;
		}
		temp = 3*i;
		while (temp > 0) {
			three.insert(three.begin(),temp%10);
			temp/=10;
		}
		if (isPermutationOf(two,three)) {
			temp = 4*i;
			while (temp > 0) {
				four.insert(four.begin(),temp%10);
				temp/=10;
			}
			if (isPermutationOf(two,four)) {
				temp = 5*i;
				while (temp > 0) {
					five.insert(five.begin(),temp%10);
					temp/=10;
				}
				if (isPermutationOf(two,five)) {
					temp = 6*i;
					while (temp > 0) {
						six.insert(six.begin(),temp%10);
						temp/=10;
					}
					if (isPermutationOf(two,six)) {
					  res = i;
					}
				}
			}
		}
	}
	
	clock_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Problem 52: " << res << endl;
	cout << "time elapsed : " << time << " s" << endl;
	assert(res == 142857);
	return res;
}

int main (int argc, char **argv) {
	initCoins();
	euler2();
	euler3();
	euler5();
	euler9();
	euler31();
	euler44();
	euler52();
	return 0;
}
