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
                i+=2;
            }
            else{
                bool leftEmpty = (i==0) || flowerbed[i-1]==0;
                bool rightEmpty = (i==len-1) || flowerbed[i+1]==0;
                if(leftEmpty && rightEmpty){
                    flowerbed[i]=1;
                    n--;
                    i+=2;
                }
                else
                    i++;
            }
        }
        return n==0;
    }
};