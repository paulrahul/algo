public class GCD {
	private static int gcd(int a, int b) {
		if (b > a) {
			a = a + b;
			b = a - b;
			a = a - b;
		}
		
		while (b > 0) {
			int t = a % b;
			a = b;
			b = t;
		}
		
		return a;
	}
	
	private static int gcd_euclid(int a, int b) {
		if (b > a) {
			a = a + b;
			b = a - b;
			a = a - b;
		}
		
		while (b > 0) {
			int t = a - b;
			a = b;
			b = t;
		}
		
		return a;		
	}
	
	public static void main(String[] args) {
		System.out.println(gcd(24, 36));
		System.out.println(gcd_euclid(8, 12));		
	}
	
}