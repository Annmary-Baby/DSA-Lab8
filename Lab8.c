#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Employee {
    int empID;
    char name[50];
    
};


struct TreeNode {
    struct Employee data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createEmployeeNode(int empID, const char* name) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data.empID = empID;
    strcpy(newNode->data.name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct TreeNode* insertEmployee(struct TreeNode* root, int empID, const char* name) {
    if (root == NULL) {
        return createEmployeeNode(empID, name);
    }

    
    if (empID < root->data.empID) {
        root->left = insertEmployee(root->left, empID, name);
    } else if (empID > root->data.empID) {
        root->right = insertEmployee(root->right, empID, name);
    }

    return root;
}


struct TreeNode* createTreeLevelOrder(int empIDs[], const char* names[], int n) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertEmployee(root, empIDs[i], names[i]);
    }
    return root;
}


struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;


    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}


struct TreeNode* deleteEmployee(struct TreeNode* root, int empID) {
 
}


struct TreeNode* searchEmployee(struct TreeNode* root, int empID) {
    
}


int calculateHeight(struct TreeNode* root) {

}


void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
        inOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("Employee ID: %d, Name: %s\n", root->data.empID, root->data.name);
    }
}

int main() {
   
    int empIDs[] = {101, 102, 103, 104, 105};
    const char* names[] = {"Annmary", "Sona", "Rojal", "Manju", "Ancy"};

    
    struct TreeNode* rootLevelOrder = createTreeLevelOrder(empIDs, names, 5);

    
    printf("Pre-order Traversal:\n");
    preOrderTraversal(rootLevelOrder);

  
    printf("\nIn-order Traversal:\n");
    inOrderTraversal(rootLevelOrder);

    
    printf("\nPost-order Traversal:\n");
    postOrderTraversal(rootLevelOrder);

    
    int empIDToDelete = 103;
    rootLevelOrder = deleteEmployee(rootLevelOrder, empIDToDelete);
    printf("\nDeleted employee with ID %d\n", empIDToDelete);

    
    int empIDToSearch = 102;
    struct TreeNode* searchedNode = searchEmployee(rootLevelOrder, empIDToSearch);
    if (searchedNode != NULL) {
        printf("\nEmployee found - ID: %d, Name: %s\n", searchedNode->data.empID, searchedNode->data.name);
    } else {
        printf("\nEmployee with ID %d not found\n", empIDToSearch);
    }

    
    int height = calculateHeight(rootLevelOrder);
    printf("\nHeight of the Binary Tree: %d\n", height);

    return 0;
}
