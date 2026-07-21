#include "Dictionary.h"
/**
 * find()
 * Finds `key` in the Dictionary. Returns the associated data (throws if absent).
 */
template <typename K, typename D>
const D & Dictionary<K, D>::find(const K & key) {
  TreeNode *& node = _find(key, head_);
  if (node == nullptr) { throw std::runtime_error("key not found"); }
  return node->data;
}

// ... (other members) ...

template <typename K, typename D>
typename Dictionary<K, D>::TreeNode *& Dictionary<K, D>::_find(
    const K & key, TreeNode *& cur) const {
  if      (cur == nullptr)   { return cur; }
  else if (key == cur->key)  { return cur; }
  else if (key < cur->key)   { return _find(key, cur->left); }
  else                       { return _find(key, cur->right); }
}


/**
 * insert()
 * Inserts `key` and associated `data` into the Dictionary.
 */
template <typename K, typename D>
void Dictionary<K, D>::insert(const K & key, const D & data) {
  TreeNode *& node = _find(key, head_);
  node = new TreeNode(key, data);
}


/**
 * remove()
 * Removes `key` from the Dictionary. Returns the associated data.
 */
template <typename K, typename D>
const D & Dictionary<K, D>::remove(const K & key) {
  TreeNode *& node = _find(key, head_);
  return _remove(node);
}

template <typename K, typename D>
const D & Dictionary<K, D>::_remove(TreeNode *& node) {
  // Zero child remove:
  if (node->left == nullptr && node->right == nullptr) {
    const D & data = node->data;
    delete(node);
    node = nullptr;
    return data;
  }

  // One-child (left) remove
  else if (node->left != nullptr && node->right == nullptr) {
    const D & data = node->data;
    TreeNode *temp = node;
    node = node->left;
    delete(temp);
    return data;
  }

  // One-child (right) remove
  else if (node->left == nullptr && node->right != nullptr) {
    const D & data = node->data;
    TreeNode *temp = node;
    node = node->right;
    delete(temp);
    return data;
  }

  // Two-child remove:
  else {
    // Find the IOP (in-order predecessor)
    TreeNode *& iop = _iop( node->left );

    // Swap the node to remove and the IOP
    _swap( node, iop );

    // Remove the new IOP node that was swapped
    return _remove( node );
  }
}