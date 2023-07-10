```c++
void factorize(int k) {
	while(k!=1 && !isprime[k]){
        cout<<spf[k]<<"\n";
        k/=spf[k];
    }
    if(k!=1)cout<<k<<"\n";
}
```

here spf is found through sieve of erastothenes
