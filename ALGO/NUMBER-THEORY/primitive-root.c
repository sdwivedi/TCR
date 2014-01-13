/* check if a given int is a primitive root mod p, where p is prime */
/* source http://math.stackexchange.com/questions/124408/finding-a-primitive-root-of-a-prime-number */
/* to find any primitive root: just test candidates until this routine
   returns true */
/* requires powmod and a list of primes generated by genprimes() */
/* OK project euler 437 p<100000000 2013-09-21 */
int isprimitiveroot(int root,int p) {
	static int div[100];
	int dn,i,j,phi=p-1,P=phi;
	/* find all prime divisors of p-1 */
	for(dn=i=0;i<primes && prime[i]*prime[i]<=P;i++) if(P%prime[i]==0) {
		div[dn++]=prime[i];
		do P/=prime[i]; while(P%prime[i]==0);
	}
	if(P>1) div[dn++]=P;
	/* check multiplicative group order thingy */
	for(j=0;j<dn;j++) if(powmod(root,phi/div[j],p)<2) return 0;
	return 1;
}