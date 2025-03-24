class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                int flag=0;
                if(i-1>=0 && flowerbed[i-1]==1) flag++;
                if(i+1<size && flowerbed[i+1]==1) flag++;
                cout<<flag<<endl;
                if(flag==0){
                    n--;
                    cout<<i<<endl;
                    flowerbed[i]=1;
                }  
            }
        }
        cout<<n;
        return (n<=0);
    }
};