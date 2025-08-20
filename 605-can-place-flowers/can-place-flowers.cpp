class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int i=0, len=flowerbed.size();
        if(n==0)
            return true;
        if(len==1)
            return flowerbed[0]==0;
        while(i<len && n>0){
            if(flowerbed[i]==1){
                i++;
                continue;
            }
            if(i==0 && flowerbed[i+1]!=1){
                flowerbed[i]=1;
                n--;
            }                
            else if(i==len-1 && flowerbed[i-1]!=1){
                flowerbed[i]=1;
                n--;
            }
            else if(i>0 && i<len-1 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                flowerbed[i]=1;
                n--;
            }
            i++;
        }
        return n==0;
    }
};