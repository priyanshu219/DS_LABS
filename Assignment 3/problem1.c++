/**
 * @file problem1.c++
 * @author Priynshu Garg
 * @date 21/08/2019
 * @brief  A C++ program to create a binary search tree (BST) and print all
possible paths for it.
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * A function which converts red and black in numbers.
 */
enum COLOR
{
    red,
    black
};
/**
 * A structure to represent the node of a tree
 */
typedef struct node
{
    int data;            /**< It stores the data/value of a node */
    int height = 0;      /**< It stores the height of node */
    int color;           /**< It stores the color of node */
    int level;           /**< It stores the level of a node*/
    struct node *left;   /**< Pointer to the left child of a node*/
    struct node *right;  /**< Pointer to the right child of a node*/
    struct node *parent; /**< Pointer to the parent node of a node*/
} node;

node *root_bst = NULL; /**< Root of Binary Search Tree(BST)*/
node *root_rbt = NULL; /**< Root of Red_Black Tree(RBT)*/
node *root_avl = NULL; /**< Root of AVL Tree*/

/**
 * @brief To find the height of a node
 * @param root Pointer to the node to find height
 * @return Height of input node
 */
int height(node *root);
/**
 * @brief To create BST from input data with help of recursion
 * @param root Pointer to the root node of that tree
 * @param data Value which we want to add in root
 * @return Pointer to the root node after adding value
 */
node *insert_bst(node *root, int data);
/**
 * @brief Rotate the nodes right one time about the root node
 * @param root pointer to the node about which we want to rotate
 * @return Pointer to the input node after rotation
 */
node *rotate_right_single(node *root);
/**
 * @brief Rotate the nodes left one time about the root node
 * @param root pointer to the node about which we want to rotate
 * @return Pointer to the input node after rotation
 */
node *rotate_left_single(node *root);
/**
 * @brief Rotate the nodes two times about the root node but first about provided then about its parent
 * @param root pointer to the node about which we want to rotate
 * @return Pointer to the input node after rotation
 */
node *rotate_right_double(node *root);
/**
 * @brief Rotate the nodes two times about the root node but first about provided then about its parent
 * @param root pointer to the node about which we want to rotate
 * @return Pointer to the input node after rotation
 */
node *rotate_left_double(node *root);
/**
 * @brief To create AVL Tree from the inorder transversal of BST
 * @param root Pointer to the root node of AVL Tree
 * @param data Value which we want to add in AVL Tree
 * @return Returns the pointer to the root node after adding data
 */
node *insert_avl(node *root, int data);
/**
 * @brief To rotate the nodes about the given node in anti-clockwise
 * @param node Pointer to the node about which we want to rotate
 * @return As we use pass by reference that no explicit return is used
 */
void rotate_left(node *&node);
/**
 * @brief To rotate the nodes about the given node in clockwise
 * @param node Pointer to the node about which we want to rotate
 * @return As we use pass by reference that no explicit return is used
*/
void rotate_right(node *&node);
/**
 * @brief To insert node in Binary search tree of rbt before fixing it
 * @param pointer to the root node of RBT
 * @param Pointer to the node which we want to add
 * @return As we use pass by reference that no explicit return is used
 */
node *insert_rbt_bst(node *&root, node *&node);
/**
 * @brief To fix the BST of RBT according to the rules
 * @param root Pointer to the root node of RBT
 * @param node pointer of the node which we newly added in RBT
 * @return As we use pass by reference that no explicit return is used
 * */
void fixrbt(node *&root, node *&node);
/**
 * @brief To add data in RBT
 * @param root Pointer to the root node of RBT
 * @param data Value which we want to add in RBT
 * @return Returns the pointer pointing towards node
 * */
node *insert_rbt(node *&root, int data);
/**
 * @brief Transverse the array in inorder to make AVL and print inorder
 * @param root Pointer to the root node of BST
 * @param flag To tell the program when to make AVL and when to print root value
 */
void transverse_node(node *root, int flag);
/**
 * @brief Print the path from the given node to the leaf node
 * @param node Pointer to the node from which we have to print data upto leaf node
 * @param leaf Pointer to the leaf node
 */
void print_path(node *root, node *leaf);
/**
 * @brief To find the leaf node and when founded call print_path
 * @param root Pointer to the root node of given tree
 * @param flag To tell program which tree we have to take
 */
void find_leaf(node *root, int flag);
/**
 * @brief To find the level of each node of all trees
 * @param node_parent Pointer to the parent node of given node
 * @param node Pointer to the node for which we have to find height
 */
void find_level(node *node_parent, node *node);
/**
 * @brief To print the node using intendation
 * @param root Pointer to the root node of a tree
 * @param flag To tell program which tree we have to take
 */
void print_bst_avl(node *root, int flag);

/**
 * @brief To take input and print menu to do task and call menu again and again
 */
int main()
{
    clock_t c_start = clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    int n, i, x, opt;

    cout << "Enter number of terms\n";
    cin >> n;
    cout << "Enter numbers:\n";
    for (i = 0; i < n; i++)
    {
        cin >> x;
        root_bst = insert_bst(root_bst, x);
        insert_rbt(root_rbt, x);
    }
    while (1)
    {
        cout << "1. To insert a node in the node and in the red-black tree\n"
             << "2. To create AVL tree from the inorder traversal of the node\n"
             << "3. To print the inorder traversal of the node/AVL/red-black tree\n"
             << "4. To display all the paths in the node/AVL tree/red-black tree \n"
             << "5. To print the node/AVL tree/red-black Tree in the terminal using level-wise indentation\n"
             << "6. Exit\n"
             << "Enter option:\n";

        cin >> opt;
        if (opt == 1)
        {
            cout << "Enter node value\n";
            cin >> x;
            root_bst = insert_bst(root_bst, x);
            insert_rbt(root_rbt, x);
        }
        else if (opt == 2)
        {
            root_avl = NULL;
            transverse_node(root_bst, 1);
        }
        else if (opt == 3)
        {
            cout << "Inorder Transversal: ";
            transverse_node(root_bst, 2);
            cout << "\n";
        }
        else if (opt == 4)
        {
            cout << "Paths(BST):\n";
            find_leaf(root_bst, 1);
            if (root_avl != NULL)
            {
                cout << "Paths(AVL Tree):\n";
                find_leaf(root_avl, 2);
            }
            cout << "Paths(Red-Black Tree):\n";
            find_leaf(root_rbt, 3);
        }
        else if (opt == 5)
        {
            find_level(NULL, root_bst);
            find_level(NULL, root_avl);
            find_level(NULL, root_rbt);
            cout << "BST:\n";
            print_bst_avl(root_bst, 1);
            cout << "\nAVL Tree:\n";
            print_bst_avl(root_avl, 2);
            cout << "\nRed-Black Tree:\n";
            print_bst_avl(root_rbt, 3);
        }
        else if (opt == 6)
        {
            clock_t c_end = clock();
            auto t_end = std::chrono::high_resolution_clock::now();
            cout << fixed << setprecision(2) << "CPU time: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
            cout << "Real time passed: " << std::chrono::duration<double, milli>(t_end - t_start).count() << " ms\n";
            return 0;
        }
    }
}

//====================================================================================================================================================//
int height(node *root)
{
    if (!root)
        return 0;
    return root->height;
}

node *insert_bst(node *root, int data)
{
    if (!root)
    {
        root = new struct node();
        root->data = data;
        root->left = root->right = NULL;
        root->height = 0;
        return root;
    }
    else
    {
        if (root->data > data)
            root->left = insert_bst(root->left, data);
        else if (root->data < data)
            root->right = insert_bst(root->right, data);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    if (root->right)
        root->right->height = root->height - 1;
    if (root->left)
        root->left->height = root->height - 1;
    return root;
}

node *insert_avl(node *root, int data)
{
    if (!root)
    {
        root = new node();
        root->data = data;
        root->height = 1;
        root->left = root->right = NULL;
        return root;
    }
    else if (data < root->data)
    {
        root->left = insert_avl(root->left, data);
        if (height(root->left) - height(root->right) == 2)
        {
            if (data < root->left->data)
                root = rotate_right_single(root);
            else
                root = rotate_right_double(root);
        }
    }
    else if (data > root->data)
    {
        root->right = insert_avl(root->right, data);
        if (height(root->right) - height(root->left) == 2)
        {
            if (data > root->right->data)
                root = rotate_left_single(root);
            else
                root = rotate_left_double(root);
        }
    }
    root->height = max(height(root->right), height(root->left)) + 1;
    return root;
}

void fixrbt(node *&root, node *&node)
{
    struct node *parent = NULL, *grndprt = NULL, *uncle = NULL;
    while ((node != root) && (node->parent->color == red) && (node->color != black))
    {
        parent = node->parent;
        grndprt = node->parent->parent;

        if (parent == grndprt->left)
        {
            uncle = grndprt->right;
            if ((uncle) && (uncle->color == red))
            {
                parent->color = uncle->color = black;
                grndprt->color = red;
                node = grndprt;
            }
            else
            {
                if (node == parent->right)
                {
                    rotate_left(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotate_right(grndprt);
                swap(parent->color, grndprt->color);
                node = parent;
            }
        }
        else
        {
            uncle = grndprt->left;
            if (uncle && (uncle->color == red))
            {
                grndprt->color = red;
                parent->color = uncle->color = black;
                node = grndprt;
            }
            else
            {
                if (node == parent->left)
                {
                    rotate_right(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotate_left(grndprt);
                swap(parent->color, grndprt->color);
                node = parent;
            }
        }
    }
    if (root == root_rbt)
        root->color = black;
}

void print_path(node *root, node *leaf)
{
    cout << root->data;
    struct node *temp = root;
    while (temp != leaf)
    {
        if (temp->data > leaf->data)
        {
            temp = temp->left;
            cout << "->" << temp->data;
        }
        else if (temp->data < leaf->data)
        {
            temp = temp->right;
            cout << "->" << temp->data;
        }
    }
    cout << "\n";
    temp = root;
    if (temp->data > leaf->data)
    {
        temp = temp->left;
        print_path(temp, leaf);
    }
    else if (temp->data < leaf->data)
    {
        temp = temp->right;
        print_path(temp, leaf);
    }
}

node *insert_rbt(node *&root, int data)
{
    struct node *node = new struct node();
    node->data = data;
    node->color = red;
    node->left = node->right = node->parent = NULL;
    node->height = 1;
    insert_rbt_bst(root, node);
    fixrbt(root, node);
}

void transverse_node(node *root, int flag)
{
    if (!root)
        return;
    transverse_node(root->left, flag);
    if (flag == 1)
        root_avl = insert_avl(root_avl, root->data);
    if (flag == 2)
        cout << root->data << " ";
    transverse_node(root->right, flag);
}

void find_leaf(node *root, int flag)
{
    if (!(root->left) && !(root->right))
    {
        if (flag == 1)
        {
            print_path(root_bst, root);
            return;
        }
        else if (flag == 2)
            print_path(root_avl, root);
        else if (flag == 3)
            print_path(root_rbt, root);
    }
    if (root->left)
        find_leaf(root->left, flag);
    if (root->right)
        find_leaf(root->right, flag);
}

void find_level(node *node_parent, node *node)
{
    if (node == root_bst || node == root_avl || node == root_rbt)
        node->level = 0;
    else
        node->level = node_parent->level + 1;
    if (node->left)
        find_level(node, node->left);
    if (node->right)
        find_level(node, node->right);
}

void print_bst_avl(node *root, int flag)
{
    cout << string(4 * root->level, ' ');
    if (flag == 1)
        cout << root->data << "[" << root->height << "]"
             << "\n";
    if (flag == 2)
        cout << root->data << "[" << (height(root->left) - height(root->right)) << "]\n";
    if (flag == 3)
        cout << root->data << "[" << root->height << "]"
             << "[" << root->color << "]\n";
    if (root->left)
        print_bst_avl(root->left, flag);
    else if (!root->left && root->right)
        cout << "\n";
    if (root->right)
        print_bst_avl(root->right, flag);
    else if ((root->left) && !(root->right))
        cout << "\n";
}

node *rotate_right_single(node *root)
{
    node *left = root->left;
    root->left = left->right;
    left->right = root;
    root->height = max(height(root->right), height(root->left)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;
    return left;
}

node *rotate_left_single(node *root)
{
    node *right = root->right;
    root->right = right->left;
    right->left = root;
    root->height = max(height(root->right), height(root->left)) + 1;
    right->height = max(height(right->left), height(right->right)) + 1;
    return right;
}

node *rotate_right_double(node *root)
{
    root->left = rotate_left_single(root->left);
    return rotate_right_single(root);
}

node *rotate_left_double(node *root)
{
    root->right = rotate_right_single(root->right);
    return rotate_left_single(root);
}

void rotate_left(node *&node)
{
    struct node *node_right = node->right;
    node->right = node_right->left;
    if (node_right->left)
        node_right->left->parent = node;
    if (!node->parent)
        root_rbt = node_right;
    else if (node == node->parent->left)
        node->parent->left = node_right;
    else
        node->parent->right = node_right;
    node_right->left = node;
    node_right->parent = node->parent;
    node->parent = node_right;
}

void rotate_right(node *&node)
{
    struct node *node_left = node->left;
    node->left = node_left->right;
    if (node_left->right)
        node_left->right->parent = node;
    if (!(node->parent))
        root_rbt = node_left;
    else if (node == node->parent->left)
        node->parent->left = node_left;
    else
        node->parent->right = node_left;
    node_left->right = node;
    node_left->parent = node->parent;
    node->parent = node_left;
}

node *insert_rbt_bst(node *&root, node *&node)
{
    if (!root)
    {
        root = node;
        return node;
    }
    if (node->data > root->data)
    {
        insert_rbt_bst(root->right, node);
        root->right->parent = root;
    }
    else if (node->data < root->data)
    {
        insert_rbt_bst(root->left, node);
        root->left->parent = root;
    }
    root->height = max(height(root->left), height(root->right)) + 1;
}