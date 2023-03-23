#include <stack>
#include <string>
#include <cstddef>
#include <iostream>
using namespace std;
struct et
{
    char value;
    et* left, *right;
};
 
// Utility function to do inorder traversal
void inorder(et *t)
{
    if(t)
    {
        inorder(t->left);
        cout << t->value;
        inorder(t->right);
    }
}
string preorder(et *t) {
  string ret;
  if(t) {
    ret = t->value;
    ret += preorder(t->left);
    ret += preorder(t->right);
  }
  return ret;
}
bool emptyTree(et *t) {
  char c = t->value;
  if(c == '/') {
    return true;
  } else if(c == '+') {
    return emptyTree(t->left) && emptyTree(t->right);
  } else if(c == '.') {
    return emptyTree(t->left) || emptyTree(t->right);
  } else if(c == '*') {
    return false;
  }
  return false;
}
// A utility function to create a new node
et* newNode(char v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
 
// Returns root of constructed tree for given
// postfix expression
et* constructTree(string postfix) {
  stack<et *> st;
  et *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
  for (int i=0; i<postfix.length(); i++) {
        // If operand, simply push into stack
    if (postfix[i] == '+' || postfix[i] == '.') { //operator
      t = newNode(postfix[i]);
      // Pop two top nodes
      t1 = st.top(); // Store top
      st.pop();      // Remove top
      t2 = st.top();
      st.pop(); 
      //  make them children
      t->right = t1;
      t->left = t2;
      // Add this subexpression to stack
      st.push(t);
      } else if ( postfix[i] == '*') {
        t = newNode(postfix[i]);
        t1 = st.top();
        st.pop();
        t->right = t1;
        t->left = NULL;
        st.push(t);
      } else {
        t = newNode(postfix[i]);
	st.push(t);
      }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
string no_op(string s) {
	cout << "test";
  et* r = constructTree(s);
  string ret = preorder(r);
  return ret;
}
string bool_to_string(bool b) {
  if (b == true) {
    return "yes";
  }
  return "no";
}
string empty(string s) {
  et* r = constructTree(s);
  return bool_to_string(emptyTree(r));
}
int main(int argc, char* argv[]) {
  while(cin.good()) {
    string n;
    cin >> n;
    if(string(argv[1]) == "--no-op") {
      cout << no_op(n) << endl;
    }
    if(string(argv[1]) == "--empty") {
      cout << empty(n) << endl;
    }
  }
  return 0;
}
