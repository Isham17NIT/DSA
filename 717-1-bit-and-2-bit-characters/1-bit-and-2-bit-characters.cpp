class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int i=0;
        while(i<bits.size()-1)
        {
            if(bits[i]==1) //2-bit char
                i+=2;
            else if(bits[i]==0)
                i++;
        }
        return i!=bits.size();
    }
};