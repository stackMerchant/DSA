// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

bool isLeaf(TreeNode* A) {
    return A -> left == NULL && A -> right == NULL;
}

void trav(TreeNode* A, int number, int &ret) {
    if (!A) return;
    
    int updatedNumber = (number * 10 + A -> val) % 1003;
    if (isLeaf(A)) ret = (ret + updatedNumber) % 1003;
    else {
        trav(A -> left, updatedNumber, ret);
        trav(A -> right, updatedNumber, ret);
    }
}

int Solution::sumNumbers(TreeNode* A) {
    int ret = 0;
    trav(A, 0, ret);
    return ret;
}