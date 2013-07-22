#include <iostream>  
using namespace std;  
  
int main()  
{  
    int n,var,ans;  
    cin >> n;  
  
	ans = 0;  
	for(var = 1;var<=n;var+=2)  
	if(n%var==0)  
	ans++;  
	cout << ans << endl;  

    return 0;  
} 