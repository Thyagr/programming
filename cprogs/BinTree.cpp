#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <climits>

//can just be binary tree
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};

/*
BSTNode* MakeNode(int val)
{
	BSTNode* newNode = new BSTNode();

	if (newNode != NULL)
	{
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	return newNode;
}
*/

BSTNode* InsertNode(BSTNode* ptr, int data)
{
	if (ptr == NULL)  // can integrate the MakeNode function here
	{
		ptr = new BSTNode();
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->data = data;
	}
	else if (data <= ptr->data)
        ptr->left = InsertNode(ptr->left,data);
	else
        ptr->right = InsertNode(ptr->right,data);

	return ptr;
}

//same as listing in ascending order for BST
void PrintInOrder(BSTNode* ptr) // left - root -right
{
	if (ptr == NULL) return;

	PrintInOrder(ptr->left);
	cout << ptr->data << " ";
	PrintInOrder(ptr->right);
}

void PrintPreOrder(BSTNode* ptr) // root -left -right
{
	if (ptr == NULL) return;

	cout << ptr->data << " ";
	PrintPreOrder(ptr->left);
	PrintPreOrder(ptr->right);
}

void PrintPostOrder(BSTNode* ptr) //left -right - root
{
	if (ptr == NULL) return;

	PrintPostOrder(ptr->left);
	PrintPostOrder(ptr->right);
	cout << ptr->data << " ";
}

/*
Additional problems:
Find vertical sums of bin tree
Find boundary sums of bin tree
My soln: do level order traversal
put it in a matrix (or list) and then compute
*/
void LevelOrderTraverse(BSTNode* ptr)
{
	if (ptr == NULL) return;
	queue<BSTNode*> Q; //Queue of BSTNode* pointers
	Q.push(ptr);
	while(Q.empty() == false)
	{
		ptr = Q.front();
		cout << ptr->data << " ";
		//cout << Q.size() << " " << endl; // use this later for levels?
		if (ptr->left  != NULL) Q.push(ptr->left);
		if (ptr->right != NULL) Q.push(ptr->right);
		Q.pop();
	}
}

int maxval(int x, int y)
{
    return x > y ? x : y;
}

int TreeDepth(BSTNode* root)
{
    if (root == NULL) return -1; // as we add +1, leaf height
    int leftheight = TreeDepth(root->left);
    int rightheight = TreeDepth(root->right);
    return maxval(leftheight,rightheight) + 1;
	// return leftheight > rightheight ? leftheight + 1: rightheight + 1;
}

//sub optimal, also can use static variables instead of passing address in recursion
int PrintPathToNode(BSTNode* root, int val, std::stack<int>& S)
{
    if (root == NULL) return 0;
    if (root->data == val)
    {
        S.push(root->data);
        cout << root->data << "->";
        return 1;
    }
    if (PrintPathToNode(root->left,val,S) || PrintPathToNode(root->right,val, S))
    {
        S.push(root->data);
        cout << root->data << "->";
        return 1;
    }
    else
        return 0;
}

void PrintArray(int paths[], int len)
{
    cout << endl;
    for (int i=0;i<len;i++) cout << paths[i] << " ";
}

void PrintPathToNode2(BSTNode* root, int val, int paths[], int i)
{
    if (root == NULL) return;
    paths[i] = root->data; i++;
    if (root->data == val) PrintArray(paths, i);
    PrintPathToNode2(root->left, val, paths,i);
    PrintPathToNode2(root->right,val, paths,i);
}

void PrintAllPaths(BSTNode* root, int paths[], int len)
{
    if (root == NULL) return;

    paths[len] = root->data; len++;
    if (root->left == NULL && root->right == NULL)
        PrintArray(paths,len);
    PrintAllPaths(root->left, paths, len);
    PrintAllPaths(root->right, paths, len);
}

bool CheckInorderArray(int nodesarr[],int index)
{
    if (index == 0) return true;
    int i = 1;
    do
    {
        int first = nodesarr[i];
        int second = nodesarr[++i]; //increase count
        if (first > second) return false;
    } while (i < index);
    return true;
}

// use pre-order and compare
void CheckifBST(BSTNode* root, int nodesarr[], int& index)
{
    if (root == NULL) return;
    CheckifBST(root->left, nodesarr, index);
    index++; nodesarr[index] = root->data; //index -1
    CheckifBST(root->right,nodesarr,index);
}

//use a static variable for c instead of passing address
int countleaves(BSTNode* root, int& c)
{
    if (root == NULL) return 0;
    c++;
    /*ignoring return value -usually discarded unless
    -Wunused-result flag is set in gcc*/
    countleaves(root->left,c);
    countleaves(root->right,c);
    return c;
}

// more compact method for leaf count and w/o extra var
int countleaves2(BSTNode* root)
{
    if (root == NULL) return 0;
    else
        return (1 + countleaves2(root->left)
                + countleaves2(root->right));
}

int countleaves3(BSTNode* root) // same as above but like tree-height
{
    if (root == NULL) return 0;
    
    int left = countleaves3(root->left);
    int right = countleaves3(root->right);
    return 1 + left + right;
}

//wrong implementation!!!!
bool LeastCommonAncestor(BSTNode* root, int val1, int val2)
{
    if (root == NULL) return false;
    if (root->data == val1 || root ->data == val2)
        return true;
    else
        return false;
    if (LeastCommonAncestor(root->left, val1, val2) &&
            LeastCommonAncestor(root->right, val1, val2))
    {
        cout << endl << root->data;
        return true;
    }
    return false;
}

void SerializeTree (BSTNode* root, int serial[], int& i)
{
    if (root == NULL) { serial[i] = -1; i++; return;}
    else {serial[i] = root->data; i++;}
    SerializeTree(root->left,serial,i);
    SerializeTree(root->right,serial,i);
}

void LevelOrderTraversePrintLinebyLine(BSTNode* root)
{
    if (root == NULL) return;
    std::queue<BSTNode*> Q;
    Q.push(root);
    while (1)
    {
        int nodecount = Q.size();
        if (nodecount == 0) break;
        while (nodecount)
        {
            BSTNode* node = Q.front();
            cout << node->data << " ";
            if (node->left  != NULL) Q.push(node->left);
            if (node->right != NULL) Q.push(node->right);
            Q.pop();
            nodecount--;
        }
        cout << std::endl;
    }
}

/* can also be used for Printing Level by level (find max k with tree depth)*/
void PrintAtKDistance(BSTNode* root, int k)
{
    if (root == NULL) return;
    //cout << "*" << root->data << "*";
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    PrintAtKDistance(root->left,  k-1);
    PrintAtKDistance(root->right, k-1);
}

void LeastCommonAncestorBST(BSTNode* root, int val1, int val2)
{
    // works only for Binary Search Tree
    // Binary Tree print the path to nodes and compare
    if (root == NULL) return;
    while (root != NULL)
    {
        if (val1 < root->data && val2 < root->data)
            root = root->left;
        else if (val1 > root->data && val2 > root->data)
            root = root->right;
        else break;
    }
    if (root != NULL)
        cout << endl << "Common Ancestor BST: " << root->data;
}

int main(void)
{
	BSTNode* root = NULL;
	int numnodes;
	int val;
	vector<int> nodelist;

	cout << "Enter the # of nodes: ";
	cin >> numnodes;
	for (int i=0; i< numnodes; i++)
    {
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        nodelist.push_back(val);
    }

    for (unsigned int j = 0; j < nodelist.size(); j++)
    {
        root = InsertNode(root,nodelist[j]);
    }

	cout << "\nInOrder   ";
	PrintInOrder(root);
	cout << "\nPreOrder  ";
	PrintPreOrder(root);
	cout << "\nPostOrder ";
	PrintPostOrder(root);
	cout << "\nLevelOrder ";
	LevelOrderTraverse(root);
	cout << "\nLevelOrder 2\n";
	LevelOrderTraversePrintLinebyLine(root);
//
//    cout << "\nHeight of tree ";
//    cout << TreeDepth(root);
//
//    std::stack<int> S;
//    int nodeval;
//    cout << "\nEnter a node for path: ";
//    cin >> nodeval;
//    cout << "\nPath from node ";
//    PrintPathToNode(root,nodeval,S);
//    cout << "\nPath from root";
//    cout << endl;
//    while(!S.empty())
//    {
//        cout<< S.top() << " ";
//        S.pop();
//    }
//    cout << endl;
//    int nodesarr[50], len = 0;
//    CheckifBST(root,nodesarr,len);
//    if (CheckInorderArray(nodesarr, len))
//        cout << endl << "Binary Tree is BST";
//    else
//        cout << endl << "\nBinary Tree is NOT BST";

//    cout << "Is BST: " << result;
//    int c = 0;
//    int paths[50], p = 0, serial[50], i = 0;
//    cout << "\nleaves: " << countleaves(root, c);
//    cout << "\nleaves: " << countleaves2(root);
//    cout << "\nRoot to leaf paths : ";
//    PrintAllPaths(root,paths,p);
//    cout << endl << "Serialization: ";
//    SerializeTree(root, serial,i);
//    PrintAllPathsArr(serial,i);

//    int val1, val2;
//    cout << "\nFind Ancestor";
//    cout << endl << "Enter val1: ";
//    cin >> val1;
//    cout << endl << "Enter val2: ";
//    cin >> val2;
//    cout << LeastCommonAncestor(root, val1, val2);

//      int paths[50], i = 0;
//      cout << endl;
//      PrintPathToNode2(root,6,paths,i);

    cout << endl <<  "Print at distance 2: ";
    PrintAtKDistance(root,2);
    LeastCommonAncestorBST(root, 5, 8);
    return 0;
}

