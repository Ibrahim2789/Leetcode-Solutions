template <typename K, typename D>
class Dictionary {
    public:
        Dictionary();
        const D & find(const K & key);
        void insert(const K & key, const D & data);
        const D & remove(const K & key);

    private:
        class TreeNode {
        public:
            const K & key;
            const D & data;
            TreeNode *left, *right;
            TreeNode(const K & key, const D & data)
                : key(key), data(data), left(nullptr), right(nullptr) { }
        };

    TreeNode *head_;

    // Private helpers (declarations inferred from usage below)
    typename Dictionary<K, D>::TreeNode *& _find(const K & key, TreeNode *& cur) const;
    const D & _remove(TreeNode *& node);
    TreeNode *& _iop(TreeNode *& node);   // referenced, not shown in slides
    void _swap(TreeNode *& a, TreeNode *& b); // referenced, not shown in slides
};