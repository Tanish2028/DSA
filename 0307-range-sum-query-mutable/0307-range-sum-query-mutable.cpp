class NumArray {
public:

    vector<int>nums;
    vector<int>blocks;
    int n;
    int blockSize;

    NumArray(vector<int>& nums) {

        this->nums = nums;
        n = nums.size();

        blockSize = ceil(sqrt(n));
        blocks.resize(blockSize, 0);

        for(int i = 0; i < n; i++){
            blocks[i/blockSize] += nums[i];
        }

    }
    
    void update(int index, int val) {
        int blockIndex = index/blockSize;

        blocks[blockIndex] -= nums[index];
        nums[index] = val;
        blocks[blockIndex] += nums[index];
    }
    
    int sumRange(int left, int right) {
        
        int sum = 0;

        // case 1 : both on same block
        int startLeft = left/blockSize;
        int startRight = right/blockSize;

        if(startLeft == startRight){
            for(int i = left; i <= right; i++){
                sum += nums[i];
            }
        }

        else{

            //left
            int startBlock = left/blockSize;
            int endofStartBlock =  (startBlock + 1)*blockSize - 1;

            for(int i = left ; i <= endofStartBlock; i++){
                sum += nums[i];
            }

            //middle
            for(int i = startBlock + 1; i < startRight; i++){
                sum += blocks[i];
            }

            //right
            int startoflastblock = startRight*blockSize;

            for(int i = startoflastblock; i <= right; i++){
                sum += nums[i];
            }
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */