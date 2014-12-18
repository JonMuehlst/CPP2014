#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <cassert>

template <typename T>
class BinarySearchTree{
    
    private:
    
        // Inner Node struct
        //=======================
        struct node{
            // Member variables
            //=======================
            T key;
            node * left;
            node * right;
            //=======================
            
            // Ctor
            //=======================
            node(T _val){
                key = _val;
                left = NULL;
                right = NULL;
            }
            
            node(const node * n){ 
                
                if(n == NULL){    
                    this = NULL;
                } else {
                    key = n->key;
                    delete left;
                    delete right;
                    left = new node(n->left);
                    right = new node(n->right);
                }
                
            }
            //=======================
            
            // Assignment operator
            //=======================
            const node& operator = (const node& n) {
                
                key = n.key;
                delete left;
                delete right;
                
                left = new node(n.left);
                right = new node(n.right);
                
                return *this;
            }
            //=======================
            
            // Dtor
            //=======================
            ~node(){
                delete left;
                delete right;
            }
            //=======================
            
            // Equality operator
            //=======================
            template<typename innerT>
            friend bool operator == (const node & lhs, const node & rhs);
            //=======================
            
            // Inequality operator
            //=======================
            template<typename innerT>
            friend bool operator != (const node & lhs, const node & rhs);
            //=======================
            
            // get minimum of the (sub)tree
            // represented by the current node
            //=======================
            T minimum(){
                if(left == NULL)
                    return key;
                return left->minimum();
            //=======================
        }
            
        };
        //=======================
        
        // Member variables
        //=======================
        node * root;
        //=======================
        
    public:
        
        // Ctor
        //=======================
        BinarySearchTree(){
            root = NULL;
        }
        
        BinarySearchTree(const BinarySearchTree * bst) { 
            *this = *bst;
        }
    
        BinarySearchTree(T a[], int size){
            root = NULL;
            for(int i = 0; i < size; i++)
                insert(a[i]);
        }
        //=======================
        
        // Dtor
        //=======================
        ~BinarySearchTree(){
            delete root; 
        }
        //=======================
        
        // Assignment operator
        //=======================
        const BinarySearchTree<T> & operator = (const BinarySearchTree<T>& bst) {
                
            if(*this != bst){

                if(bst.root == NULL)
                    root = NULL;
                else{
                    delete root;
                    root = new node(bst.root);
                }
            }
                
                return *this;
            }
        //=======================
        
        // Equality operator
        //=======================
        template <typename P>
        friend bool operator == (const BinarySearchTree<P>& lhs, const BinarySearchTree<P>& rhs);
        //=======================
        
        // Inequality operator
        //=======================
        template <typename P>
        friend bool operator != (const BinarySearchTree<P>& lhs, const BinarySearchTree<P>& rhs);
        //=======================
        
        // Insert
        //=======================
        bool insert(T _val){
            if(root == NULL){
                root = new node(_val);
                return true;
            }
            
            node * traverser = root;
            node * parent = NULL;
            
            while(traverser != NULL){
                
                if(_val == traverser->key)
                    return false;
                    
                parent = traverser;
                // std::cout << parent->key << std::endl;
                if(_val < traverser->key){
                    traverser = traverser->left;
                } else {
                    traverser = traverser->right;
                }
                
            }
            
            if(_val < parent->key){
                parent->left = new node(_val);
                return true;
            } else {
                parent->right = new node(_val);
                return true;
            }
                
            return false;
            
        }
        //=======================
        
        // Delete
        //=======================
        bool deleteNode(T val){
            node * parent = NULL;
            node * traverser = root;
            while(traverser){
                if(traverser->key == val)
                    break;
                if(val < traverser->key){
                    parent = traverser;
                    traverser = traverser->left;
                } else {
                    parent = traverser;
                    traverser = traverser->right;
                }
            }
            
            if(traverser == NULL)
                return false;
            
            // case 1: node has no child
            if( ( traverser->left == NULL ) && ( traverser->right == NULL ) ){ 
                node * tmp = traverser;
                traverser = NULL;
                delete tmp;
            // case 2: node only has right children
            } else if(traverser->left == NULL){
                onlyRightChildren(traverser,parent);
            } else {
                twoChildren(traverser,parent);
            }
            
            return true;
        }
        //=======================
        
        // Delete helpers
        //=======================
        void onlyRightChildren(node * to_remove, node * parent){
            if(to_remove == root){
                node * tmp = to_remove;
                root = to_remove->right;
                delete tmp;
                return;
            }
            
            if(to_remove == parent->left){
                parent->left = to_remove->right;
                to_remove->right = NULL;
                delete to_remove;
            } else if(to_remove == parent->right){
                parent->right = to_remove->right;
                to_remove->right = NULL;
                delete to_remove;
            }
        }
        
        void twoChildren(node * to_remove, node * parent){
            
            T min_of_right_subtree = to_remove->right->minimum();
            deleteNode(min_of_right_subtree);
            to_remove->key = min_of_right_subtree;
            
        }
        //=======================
        
        // Contains
        //=======================
        bool contains(T val){
            node * traverser = root;
            while(traverser){
                if(traverser->key == val)
                    return true;
                if(val < traverser->key)
                    traverser = traverser->left;
                else
                    traverser = traverser->right;
            }
            return false;
        }
        //=======================
        
        
        // Traverse: Pre order
        //=======================
        void preOrderWalk(){
            node * traverser = root;
            if(traverser != NULL){
                std::cout << traverser->key << std::endl;
                preOrderWalk(traverser->left);
                preOrderWalk(traverser->right);
            } 
            
           
        }
        
        void preOrderWalk(node * n){
            
            if(n != NULL){
                std::cout << n->key << std::endl;
                preOrderWalk(n->left);
                preOrderWalk(n->right);
            }
        }
        //=======================
        
        // Traverse: In order
        //=======================
        void inOrderWalk(){
            node * traverser = root;
            if(traverser != NULL){
                inOrderWalk(traverser->left);
                std::cout << traverser->key << std::endl;
                inOrderWalk(traverser->right);
            } 
            
           
        }
        
        void inOrderWalk(node * n){
            
            if(n != NULL){
                inOrderWalk(n->left);
                std::cout << n->key << std::endl;
                inOrderWalk(n->right);
            }
        }
        //=======================
        
        // Traverse: Post order
        //=======================
        void postOrderWalk(){
            node * traverser = root;
            if(traverser != NULL){
                postOrderWalk(traverser->left);
                postOrderWalk(traverser->right);
                std::cout << traverser->key << std::endl;
            } 
            
           
        }
        
        void postOrderWalk(node * n){
            
            if(n != NULL){
                postOrderWalk(n->left);
                postOrderWalk(n->right);
                std::cout << n->key << std::endl;
            }
        }
        //=======================
    
        // Friend TESTs
        //=======================
        FRIEND_TEST(bst_test_class, print_bst);
        //=======================
        
    
};


template<typename T>
bool operator == (const typename BinarySearchTree<T>::node & lhs, const typename BinarySearchTree<T>::node & rhs){
    if( (lhs.key == rhs.key) && (lhs.left == rhs.left) && (lhs.right == rhs.right) )
        return true;
    return false;
}

template<typename T>
bool operator != (const typename BinarySearchTree<T>::node & lhs, const typename BinarySearchTree<T>::node & rhs){
    return !(lhs == rhs);
}


template <typename P>
bool operator == (const BinarySearchTree<P>& lhs, const BinarySearchTree<P>& rhs) {

    if(lhs.root == rhs.root)
        return true;
    return false;

}

template <typename P>
bool operator != (const BinarySearchTree<P>& lhs, const BinarySearchTree<P>& rhs) {

    return !(lhs == rhs);

}

#endif