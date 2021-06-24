// Binary Search Tree (TreeSet)
// Code from Liang, C++ Data Structures
//
// changed significantly by W.P. Iverson
// Bellevue College, WA
// Spring 2021

// Gary Tou
// Program 10 (final): Binary Search Tree
// 6/23/2021

#include <string>
#include <iostream>
#include <map>
using namespace std;

// the basic nodes for tree
template<typename T>
class TreeNode
{
public:
    T element; // Element contained in the node
    TreeNode<T>* left; // Pointer to the left child
    TreeNode<T>* right; // Pointer to the right child
    TreeNode<T>* parent; // Pointer to the parent node

    TreeNode(T element) // Constructor
    {
        this->element = element;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    // comparison operators
    bool operator == (const TreeNode<T>& node) const
    {
        return this->element == node.element;
    }

    bool operator != (const TreeNode<T>& node) const
    {
        return this->element != node.element;
    }

    ~TreeNode() {
        delete left;
        delete right;
    }
};

// one way to get a standard forward iterator:
template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    Iterator(TreeNode<T>* node)
    {
        initialCurrent = node;
        current = node;
        findingMissing = false;

        // this starting node to history
        this->history.emplace(node, true);
    }

    // prefix forward increment
    Iterator& operator++()
    {
        if (findingMissing) {
            current = missingNext();
        }
        else {
            current = next(current);
            if (current == NULL) {
                findingMissing = true;
                current = missingNext();
            }
        }
        return *this;
    }

    // dereference
    T& operator*()
    {
        return current->element;
    }

    // comparison operators
    bool operator == (const Iterator<T>& Iterator) const
    {
        return current == Iterator.current;
    }

    bool operator != (const Iterator<T>& Iterator) const
    {
        return current != Iterator.current;
    }

private:
    TreeNode<T>* initialCurrent;
    TreeNode<T>* current;
    map<TreeNode<T>*, bool> history;
    bool findingMissing;

    TreeNode<T>* next(TreeNode<T>* node) {
        // currently on branch node, move to right
        if (node->right != NULL) {
            node = node->right;
            while (node->left != NULL) {
                node = node->left;
            }

            // add to history and return
            this->history.emplace(node, true);
            return node;
        }

        while (true) {
            // reached the end
			if (node->parent == NULL) {
                return NULL;
            }
            // is on left node, move to parent
            if (node->parent->left == current) {
                node = node->parent;

                // add to history and return
                this->history.emplace(node, true);
                return node;
            }

            // move to parent
            node = node->parent;
        }
    }

    TreeNode<T>* missingNext() {
        TreeNode<T>* start = initialCurrent;
        while (start->parent != NULL) {
            start = start->parent;
        }
        while (start->left != NULL) {
            start = start->left;
        }

        TreeNode<T>* inspect = start;
        while (inspect != NULL) {
            // if it has not been visited
            if (history.count(inspect) == 0) {
                this->history.emplace(inspect, true);
                return inspect;
            }

            // move to next node
            TreeNode<T>* next = inspect;
            if (next->right != NULL) {
                next = next->right;
                while (next->left != NULL) {
                    next = next->left;
                    break;
                }
            }
			while (true) {
                if (next->parent == NULL) {
                    next = NULL;
                    break;
                }
                if (next->parent->left == current) {
                    next = next->parent;
                    break;
                }

                // move to parent
                next = next->parent;
			}
            inspect = next;
        }

        // there are no unvisited nodes
        return NULL;
    }
};


// HERE starts the actual Binary Search Tree structure
template <typename T>
class TreeSet
{
public:
    TreeSet();
    TreeSet(T elements[], int arraySize);
    TreeSet(TreeSet<T>& tree);
    ~TreeSet();
    bool search(T element) const;
    bool insert(T element);
    bool remove(T element);
    int getSize() const;

    Iterator<T> begin() const
    {
        return Iterator<T>(start());
    };

    Iterator<T> end() const
    {
        return Iterator<T>(NULL);
    };

    TreeNode<T>* start() const
    {
        TreeNode<T>* start = root;
        while (start->left != NULL) {
            start = start->left;
        }
        return start;
    }

private:
    int size;
    TreeNode<T>* root;
    TreeNode<T>* createNewNode(T element);
    void copy(TreeNode<T>* root);
};

template <typename T>
TreeSet<T>::TreeSet()
{
    root = NULL;
    size = 0;
}

template <typename T>
TreeSet<T>::TreeSet(T elements[], int arraySize)
{
    root = NULL;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
        insert(elements[i]);
    }
}

/* Copy constructor */
template <typename T>
TreeSet<T>::TreeSet(TreeSet<T>& tree)
{
    root = NULL;
    size = 0;
    copy(tree.root); // Recursively copy nodes to this tree
}

/* Copies the element from the specified tree to this tree */
template <typename T>
void TreeSet<T>::copy(TreeNode<T>* root)
{
    if (root != NULL)
    {
        insert(root->element);
        copy(root->left);
        copy(root->right);
    }
}

/* Destructor */
template <typename T>
TreeSet<T>::~TreeSet()
{
    delete this->root;
}

/* Return true if the element is in the tree */
template <typename T>
bool TreeSet<T>::search(T element) const
{
    TreeNode<T>* current = root; // Start from the root

    while (current != NULL)
        if (element < current->element)
        {
            current = current->left; // Go left
        }
        else if (element > current->element)
        {
            current = current->right; // Go right
        }
        else // Element matches current.element
            return true; // Element is found

    return false; // Element is not in the tree
}

template <typename T>
TreeNode<T>* TreeSet<T>::createNewNode(T element)
{
    return new TreeNode<T>(element);
}

/* Insert element into the binary tree
 * Return true if the element is inserted successfully
 * Return false if the element is already in the list
 */
template <typename T>
bool TreeSet<T>::insert(T element)
{
    if (root == NULL)
        root = createNewNode(element); // Create a new root
    else
    {
        // Locate the parent node
        TreeNode<T>* parent = NULL;
        TreeNode<T>* current = root;
        while (current != NULL)
            if (element < current->element)
            {
                parent = current;
                current = current->left;
            }
            else if (element > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                return false; // Duplicate node not inserted

        // Create the new node and attach it to the parent node
        if (element < parent->element) {
            parent->left = createNewNode(element);
			parent->left->parent = parent;
		}
        else {
            parent->right = createNewNode(element);
            parent->right->parent = parent;
        }
    }

    size++;
    return true; // Element inserted
}


/* Get the number of nodes in the tree */
template <typename T>
int TreeSet<T>::getSize() const
{
    return size;
}

/* Delete an element from the binary tree.
 * Return true if the element is deleted successfully
 * Return false if the element is not in the tree */
template <typename T>
bool TreeSet<T>::remove(T element)
{
    // Locate the node to be deleted and also locate its parent node
    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;
    while (current != NULL)
    {
        if (element < current->element)
        {
            parent = current;
            current = current->left;
        }
        else if (element > current->element)
        {
            parent = current;
            current = current->right;
        }
        else
            break; // Element is in the tree pointed by current
    }

    if (current == NULL)
        return false; // Element is not in the tree

      // Case 1: current has no left children
    if (current->left == NULL)
    {
        // Connect the parent with the right child of the current node
        if (parent == NULL)
        {
            root = current->right;
        }
        else
        {
            if (element < parent->element) {
                parent->left = current->right;
                current->right->parent = parent;
            }
            else {
                parent->right = current->right;
                current->left->parent = parent;
            }
        }

        delete current; // Delete current
    }
    else
    {
        // Case 2: The current node has a left child
        // Locate the rightmost node in the left subtree of
        // the current node and also its parent
        TreeNode<T>* parentOfRightMost = current;
        TreeNode<T>* rightMost = current->left;

        while (rightMost->right != NULL)
        {
            parentOfRightMost = rightMost;
            rightMost = rightMost->right; // Keep going to the right
        }

        // Replace the element in current by the element in rightMost
        current->element = rightMost->element;

        // Eliminate rightmost node
        if (parentOfRightMost->right == rightMost) {
            parentOfRightMost->right = rightMost->left;
            rightMost->left->parent = parentOfRightMost;
        }
        else {
            // Special case: parentOfRightMost->right == current
            parentOfRightMost->left = rightMost->left;
            rightMost->left->parent = parentOfRightMost;
        }
        delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
}
