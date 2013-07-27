/*
 * Prob 10
 */

import java.util.Arrays;

public class Prob10PrimeSum {
	static void printPrimeSum(int limit) {
		// Sieve of Eratosthenes
		boolean[] isPrime = new boolean[limit + 1];
		Arrays.fill(isPrime, Boolean.TRUE);
		
		long sum = 0;
		for (int i = 2; i < limit; ++i) {
			if (!isPrime[i]) continue;
			
			sum += i;
			for (int j = i * 2; j < limit; j += i) {
				isPrime[j] = false;
			}
		}
		
		System.out.println(sum);
	}
	
	public static void main(String[] args) {
		printPrimeSum(2000000);
	}
}