vector<int> sieve(int n) {
	vector<bool> valid(n+1, true);
	for (int i = 2; i*i <= n; ++i) {
		if (!valid[i]) {
			continue;
		}
		for (int j = i*i; j <= n; j += i) {
			valid[j] = false;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= n; ++i) {
		if (valid[i]) {
			primes.push_back(i);
			cout << i << ",";
		}
	}
	return primes;
}
