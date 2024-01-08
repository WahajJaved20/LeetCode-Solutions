class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int emptySpots = 0;
        int length = flowerbed.size();
        if(length == 1 && flowerbed[0] == 0){
            return true;
        }
        for(int i=0;i<length;i++){
            if(i>0){
                if(i+1<length && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    emptySpots++;
                }else if(i+1 == length && flowerbed[i-1] == 0 && flowerbed[i] == 0){
                    emptySpots++;
                    flowerbed[i] = 1;
                }
            }else{
                if(i+1 < length && flowerbed[i+1] == 0 && flowerbed[i] == 0){
                    flowerbed[i] = 1;
                    emptySpots++;
                }
            }
        }
        return emptySpots >= n;
    }
};
