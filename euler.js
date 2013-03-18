/*recursively calculate fibonacci numbers
 *@param int n - fibonacci index
 *@return int fib - nth fibonacci number */
function fibonacci (n) {
	if (n === 0 || n === 1) return n;
	else return (fibonacci (n-1) + fibonacci (n-2));
}

/*@return the sum of all even fibonacci numbers less than 4,000,000 */
function euler2 () {
	var begin = new Date().getTime();
	var i = 0, c;
	var sum = 0;
	//definitely cannot go past first 50 fibonacci numbers
	for (c = 1; c <= 50; c++) {
		var f = fibonacci (i);
		if (f > 4000000) break;   //f is not less than 4,000,000
		if (f % 2 === 0) sum += f; //f is even
		i++;
	}
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 2: " + sum);
	console.log("time elapsed : " + time); 
}

/*@return largest prime factor of 600,851,475,143 */
function euler3 () {
	var begin = new Date().getTime();
	var num = 600851475143;
	for (var i = 2; i < Math.sqrt(num); i++) {
		while (num % i === 0 && num !== i) {
			//num is divisible by i, so divide it.
			num = num/i;
		}
	}
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 3: " + num);
	console.log("time elapsed : " + time); 
}

/*return lowest common multiple
 *to calculate lcm(a, b, c) do lcm(lcm(a,b),c)
 *@param int a - first number
 *@param int b - second number
 *@return int lcm - lowest common multiple of a and b */
function lcm (a, b) {
	var c = 2, s = 1;
	while (a >= c && b >= c) {
		if (a % c === 0 && b % c === 0) {
			s *= c;
			a /= c;
			b /= c;
		} else {
			c++;
		}
	}
	return s*a*b;
}

/*@return lowest common multiple of all numbers 1 through 20 */
function euler5 () {
	var begin = new Date().getTime();
	//if num is a multiple of 11..20, then num is already a multiple of 1..10
	var m = lcm(lcm(lcm(lcm(lcm(lcm(lcm(lcm(lcm(11,12),13),14),15),16),17),18),19),20);
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 5: " + m);
	console.log("time elapsed : " + time);
}

/*return pythagorean triplet
 *@param int p - right triangle's perimeter
 *@return int product  - product of right triangle's perimeter */
function triplet (s) {
	var limit = Math.floor (Math.sqrt (s));
	for (var m = 2; m < limit; m++) {
		for (var n = 1; n < (m-1); n++) {
			var a = m*m - n*n;
			var b = 2*m*n;
			var c = m*m + n*n;
			if ((a + b + c) === s) return a*b*c;
		}
	}
}

/*@return special pythagorean triplet with perimeter equal to 1000 */
function euler9 () {
	var begin = new Date().getTime();
	var m = triplet (1000);
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 9: " + m);
	console.log("time elapsed : " + time);
}

/*@return number of ways 2 pounds can be made out of
 * the british coin denominations */
GLOBAL.euler31Total = 0;
function euler31 () {
	var begin = new Date().getTime();
	countWays (8, 200);
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 31: " + euler31Total);
	console.log("time elapsed : " + time);
}

/*increment counter for each time we reach the wanted sum of 200 pence.
 *@param int a - size of coin denomination vector
 *@param int b - wanted sum = 200 pence (2 pounds) 
 *@return int euler31Total - total number of ways */
function countWays (a, b) {  
	var coins = [1,2,5,10,20,50,100,200];
	var pred = a - 1;
	if (a === 2) return 1;
	else {
		//v = amount left / largest coin denomination. first call v = 200/200
		var v = b / (coins[pred]);
		for (var i = 0; i <= v; i++) {
			euler31Total += countWays (pred, (b - i * coins[pred]));
		}
	}
}

/*quick generate of pentagonal number*/
function penta(x) {
	return x * (3 * x - 1) / 2;
}

/*quick check for pentagonal number*/
function isPenta(n) {
	return ((Math.sqrt(24*n+1)+1)/6) % 1 === 0;
}

/*check if both a+b and a-b are pentagonal numbers
 *@return int a-b */
function euler44 () {
	var begin = new Date().getTime();
	var res = 0;
	for (var i = 1; res === 0; i++) {
		var pi = penta(i);
		for (var j = 1; j < i; j++) {
			var pj = penta(j);
			if (isPenta(pi-pj) && isPenta(pi+pj)) {
				res = pi-pj;
				break;
			}
		}
	}
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 44: " + res);
	console.log("time elapsed : " + time);
}

function sameDigits(x, y) {
	var xDigits = x.toString().split('').sort().join(',');
	var yDigits = y.toString().split('').sort().join(',');
	return (xDigits == yDigits);
}

function euler52() {
	var begin = new Date().getTime();
	var res = 0;
	var same = false;
	for(var i = 1; i < 150000; i++) {
		same = allSameDigits(i);
		if (same) res = i;
	}
	var end = new Date().getTime();
	var time = end - begin;
	console.log("Problem 52: " + res);
	console.log("time elapsed : " + time);
}

function allSameDigits(a) {
	return sameDigits(a,2*a) && sameDigits(2*a,3*a)
		&& sameDigits(3*a,4*a) && sameDigits(4*a,5*a)
		&& sameDigits(5*a,6*a);
}

function runProblems () {
	euler2();
	euler3();
	euler5();
	euler9();
	euler31();
	euler44();
	euler52();
}

runProblems();
