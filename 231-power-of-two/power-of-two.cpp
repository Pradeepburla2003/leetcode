class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==(2^31) || n==-2147483648)
        {
            return false;
        }
        int i=0,k=0;
        while(i<32)
        {
            if((n>>i)&1)
            {
                k+=1;
            }
            i+=1;
        }
        if(k==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};