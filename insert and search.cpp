#include<iostream>
using namespace std;
struct Node {
	Node* lchild;
	int data;
	Node* rchild;
}*root=NULL;


void Insert(int key) {
    Node* t = root;
    Node* p, * r=NULL;
    if (root == NULL) {
        p = new Node;
        p->lchild = p->rchild = NULL;
        p->data = key;
        root = p;
        return;
    }
    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = new Node;
    p->lchild = p->rchild = NULL;
    p->data = key;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void inorder(Node* p) {
	if (p) {
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
	}
}


Node* Rsearch(Node* t,int key) {
    
    if (t == NULL)
        return NULL;
    if (t->data == key)
        return t;
    if (key < t->data)
        return Rsearch(t->lchild, key);
    else
        return Rsearch(t->rchild, key);
}
Node* search(Node* t, int key) {
    
   
    while (t != NULL) {

    if (t->data == key)
        return t;
    if (key < t->data)
        t = t->lchild;
    else
        t = t->rchild;
    }
    return NULL;

}
int main() { 
    Node* r;
	Insert(30);
	Insert(15);
	Insert(50);
	Insert(10);
	Insert(20);
	Insert(40);
	Insert(60);
	inorder(root);
    cout << "\n";
    r = search(root,200);
    if (r)
        cout << "Number is found:" << r->data;
    else
        cout << "Number doesn't found/n";



}