#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct treeNode {
	int data;
	struct treeNode *leftNode;
	struct treeNode *rightNode;
};

void insert(struct treeNode *node, int data) {
	struct treeNode *tempNode = (struct treeNode*) malloc(sizeof(struct treeNode));
	struct treeNode *current;
	struct treeNode *parent;

	tempNode->data = data;
	tempNode->leftNode = NULL;
	tempNode->rightNode = NULL;

	current = node;
	while(1) {
		parent = current;
		if(parent->data > data) {
			current = current->leftNode;
			if(current == NULL) {
				parent->leftNode = tempNode;
				return;
			}
		} else {
			current = current->rightNode;
			if(current == NULL) {
				parent->rightNode = tempNode;
				return;
			}
		}
	}
}

void inorder_traverse(struct treeNode *node) {
	if(node != NULL) {
		inorder_traverse(node->leftNode);
		printf("%d\n", node->data);
		inorder_traverse(node->rightNode);
	}
}

void pre_order_traversal(struct treeNode *node) {
   if(node != NULL) {
      printf("%d\n",node->data);
      pre_order_traversal(node->leftNode);    
      pre_order_traversal(node->rightNode);
   }
}

void post_order_traversal(struct treeNode *node) {
   if(node != NULL) {
      post_order_traversal(node->leftNode);
      post_order_traversal(node->rightNode);
      printf("%d\n", node->data);
   }
}

int main() {
	struct treeNode *root = (struct treeNode*) malloc(sizeof(struct treeNode));
	root->data = 6;
	root->leftNode = NULL;
	root->rightNode = NULL;
	insert(root, 5);
	insert(root, 6);
	insert(root, 2);
	insert(root, 1);
	insert(root, 8);
	insert(root, 10);
	insert(root, 3);
	insert(root, 11);
	insert(root, 7);
	printf("inorder_traverse:\n");
	inorder_traverse(root);
	printf("pre_order_traversal:\n");
	pre_order_traversal(root);
	printf("post_order_traversal:\n");
	post_order_traversal(root);
	return 0;
}