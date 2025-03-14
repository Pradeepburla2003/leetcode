class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long int c=0,k=0;
        for(int i=31;i>=0;i--)
        {
            if((n>>i)&1)
            {
                c+=pow(2,k);
            }
            k+=1;
        }
        return c;
    }
};