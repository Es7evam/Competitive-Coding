//Crive, creates vector with all primes from 2 to upperbound
//O(N logN)
long long _sieve_size;
bitset <10000010> bs; //10e7 usually enough
vector <int> prime;

void sieve(long long upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	for(ll i=2; i<= _sieve_size;i++){
		if(bs[i]){

			for(ll j = i*i;j<= _sieve_size;j += i){
				bs[j] = 0;
				
			} 
			prime.push_back((int)i);
		}
	}
}
