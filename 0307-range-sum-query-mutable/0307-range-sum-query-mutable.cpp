class SGT {
private:
    vector<int> sg_tree;
    int n;

    void build(int idx, int l, int h, vector<int>& nums) {
        if (l == h) {
            sg_tree[idx] = nums[l];
            return;
        }
        int mid = l + (h - l) / 2;
        build(idx*2+1, l, mid, nums);
        build(idx*2+2, mid+1, h, nums);
        sg_tree[idx] = sg_tree[2*idx+1] + sg_tree[2*idx+2];
    }

    int query(int idx, int l, int h, int L, int R) {
        if (R < l || L > h) return 0;              
        if (l >= L && h <= R) return sg_tree[idx]; 
        int mid = l + (h - l) / 2;
        return query(idx*2+1, l, mid, L, R) + query(idx*2+2, mid+1, h, L, R);
    }

    void updateUtil(int idx, int l, int h, int pos, int val) {
        if (l == h) {
            sg_tree[idx] = val;
            return;
        }
        int mid = l + (h - l) / 2;
        if (pos <= mid) updateUtil(idx*2+1, l, mid, pos, val);
        else updateUtil(idx*2+2, mid+1, h, pos, val);
        sg_tree[idx] = sg_tree[2*idx+1] + sg_tree[2*idx+2];
    }

public:
    SGT(vector<int>& nums) {
        n = nums.size();
        sg_tree.resize(4*n);
        build(0, 0, n-1, nums);
    }

    void update(int pos, int val) {
        updateUtil(0, 0, n-1, pos, val);
    }

    int sumRange(int L, int R) {
        return query(0, 0, n-1, L, R);
    }
};

class NumArray {
private:
    SGT* segmentTree;
public:
    NumArray(vector<int>& nums) {
        segmentTree = new SGT(nums);
    }
    
    void update(int index, int val) {
        segmentTree->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return segmentTree->sumRange(left, right);
    }
};
