class Solution {
public:
    bool isPrime(int n) {
  
    // Check if n is 1 or 0
    if (n <= 1)
        return false;

    // Check if n is 2 or 3
    if (n == 2 || n == 3)
        return true;

    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
    vector<int> closestPrimes(int left, int right) {
        
        int num1=-1,num2=-1;
        int last_prime;
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i))
            {
                if(num1==-1)
                {
                    num1=i;
                }
                else if( num2==-1)
                {
                    num2=i;
                }
                else
                {
                    if(num2-num1<=2)
                    break;
                    if(i-last_prime<num2-num1)
                    {
                        num1=last_prime;
                        num2=i;
                    }
                }
                last_prime=i;
            }
        }
        if(num1!=-1 && num2!=-1)
        {
            return {num1,num2};
        }
        return {-1,-1};
        
    }
};