//Check if a number is prime
//O (sqrt(N))

int CheckPrime(int n) {
	if(n == 2)
		return 1;
	if(n <= 1 || n % 2 == 0)
		return 0;
	
	int i, raiz;
	raiz = sqrt(n) + 1;
	for(i = 3; i <= raiz; i+=2)
		if(n % i == 0)
			return 0;
	
	return 1;
}