#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
  int key;
  node *left,*right,*p;
  node(){}
  node(int key):key(key){left=right=p=NULL;};
};
node *root;
void insert(node z){
  node *y=NULL;
  node *x=root;
  while(x!=NULL){
    y=x;
    if(z.key<x->key) x=x->left;
    else x=x->right;
  }
  z.p=y;
  if(y==NULL) root=new node(z);
  else if(z.key<y->key) y->left=new node(z);
  else y->right=new node(z);
}
void inorderTreeWalk(node *v){
  if(v==NULL) return;
  inorderTreeWalk(v->left);
  cout<<" "<<v->key;
  inorderTreeWalk(v->right);
}

vector<int> tmp;

void preorderTreeWalk(node *v){
  if(v==NULL) return;
//   cout<<" "<<v->key;
tmp.push_back(v->key);
  preorderTreeWalk(v->left);
  preorderTreeWalk(v->right);
}
void postorderTreeWalk(node *v) {
    if (v == NULL) return;
    postorderTreeWalk(v->left);
    postorderTreeWalk(v->right);

}
signed main(){
    for (int n = 2; n <= 9; ++n) {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }
    set<vector<int>> st;

    do {
        root = NULL;
        for (int i = 0; i < n; ++i) {
            insert(node(p[i]));
        }
        tmp.clear();
        preorderTreeWalk(root);
        st.insert(tmp);
    } while (next_permutation(p.begin(), p.end()));

    cout << st.size() << endl;
    }

  return 0;
}