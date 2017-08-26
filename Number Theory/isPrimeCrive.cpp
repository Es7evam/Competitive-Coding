//Generate boolean array, 1 if n is prime and 0 otherwise
//O(N logN)

#define MAXN 1000007
int isPrime[MAXN+1];

void findPrime(int n) {
	int i, j;
	isPrime[0] = isPrime[1] = 0;
	isPrime[2] = 1;

	for(i=3; i<=n; i++)
		isPrime[i] = i%2;
	
	for(i=3; i*i<=n; i+=2)
		if(isPrime[i])
		for(j=i*i; j<=n; j+=i)
			isPrime[j] = 0;
}