#include <bits/stdc++.h>

typedef struct item_t
{
    int indx;
    int val;
} item;
typedef struct node_t {
    int val;
    struct node_t* left;
    struct node_t* right;

} node;

void insertNode(node* root, int val) {
    if (val > root->val) {
        if (root->right == NULL) {
            node* temp = new node;
            temp->left=NULL;
            temp->right=NULL;
            temp->val=val;
            root->right = temp;
        } else {
            insertNode(root->right, val);
        }
    } else {
        if (root->left == NULL) {
            node* temp = new node;
            temp->left=NULL;
            temp->right=NULL;
            temp->val=val;
            root->left = temp;

        } else {
            insertNode(root->left, val);
        }
    }
}
bool chechNode(node* root, int val) {
    if (root == NULL)
        return false;
    if (root->val == val) 
        return true;
    if (val > root->val)
        chechNode(root->right, val);       
    else
        chechNode(root->left, val);
}


bool compare(item a, item b) {
    return a.val < b.val;
}

int main(void) {
    int N, M;

    std::cin >> N >> M;
    item A[N];
    item B[M];

    for (int i=0; i < N; i++) {
        item temp;
        std::cin >> temp.val;
        temp.indx = i;
        A[i] = temp;
    }
    for (int i=0; i < M; i++) {
        item temp;
        std::cin >> temp.val;
        temp.indx = i;
        B[i] = temp;
    }
    
    std::sort(A, A+N, compare);
    std::sort(B, B+M, compare);

    // for (int i=0; i < N; i++) {
    //     std::cout << A[i].indx << " " << A[i].val << "\n";
    // }
    // for (int i=0; i < M; i++) {
    //     std::cout << B[i].indx << " " << B[i].val << "\n";
    // }
    int max = 0;
    int c = 0;
    node* root = new node;
    root->left=NULL;
    root->right=NULL;
    root->val = A[0].val +  B[0].val;
    std::cout << A[0].indx << " " << B[0].indx << "\n";


    for (int i=0; (i < N); i++) {
        int a = A[i].val;
        if (c >= N+M-1) {
            break;
        }
        for (int j=0; j < M;) {
            if (c >= N+M-1) {
                break;
            }
            int b = B[j].val;
            
            if (!chechNode(root, a+b)) {
                insertNode(root, a+b);
                c++;
                std::cout << A[i].indx << " " << B[j].indx << "\n";
            }
            // std::cout << a << " " << b << " " << a+b << "\n";
            
            if (j < M/2) j++; else j--;
            j = M - j;
        }
        
    }
    


}