class SegmentTree {
public:
    struct Node {
        int d_l;
        int d_r;
        int d_sum;
        Node* d_ln;
        Node* d_rn;
        Node(int l, int r): d_l(l), d_r(r), d_sum(0), d_ln(NULL), d_rn(NULL) {}
    };
    
    void updateSingle(int i, int val) {
        update(d_root, i, val);
    }
    
    int queryRange(int l, int r) {
        return query(d_root, l, r);
    }
    
    SegmentTree(const vector<int>& nums) {
        d_root = new Node(0, nums.size()-1);
        initTree(d_root, nums);
    }
private:
    Node* d_root;
    
    void initTree(Node* root, const vector<int>& nums) {
        if (root->d_l == root->d_r) {
            root->d_sum = nums[root->d_l];
            return;
        }
        int mid = root->d_l+(root->d_r-root->d_l)/2;
        root->d_ln = new Node(root->d_l, mid);
        initTree(root->d_ln, nums);
        root->d_rn = new Node(mid+1, root->d_r);
        initTree(root->d_rn, nums);
        root->d_sum = root->d_ln->d_sum+root->d_rn->d_sum;
    }
    
    void update(Node* root, int i, int val) {
        if (i < root->d_l || i > root->d_r) {
            return;
        }
        if (root->d_l == root->d_r) {
            root->d_sum = val;
            return;
        }
        update(root->d_ln, i, val);
        update(root->d_rn, i, val);
        root->d_sum = root->d_ln->d_sum+root->d_rn->d_sum;
    }
    
    int query(Node* root, int l, int r) {
        if (l > root->d_r || r < root->d_l) {
            return 0;
        }
        if (l <= root->d_l && r >= root->d_r) {
            return root->d_sum;
        }
        return query(root->d_ln, l, r) + query(root->d_rn, l, r);
    }
};
