//Written By: Evan Owre, Apr 25, 2021

#include <stack>
#include <string>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string no_op(string s);
string empty(string s);
string has_epsilon(string s);
string has_nonepsilon(string s);
string infinite(string s);
string starts_with(string s);
string ends_with(string s);
string reverse(string s);
string prefixes(string s);
string suffixes(string s);
string b_before_a(string s);
string drop_one(string s);
string strip(string s);

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
    if(string(argv[1]) == "--has-epsilon") {
      cout << has_epsilon(n) << endl;
    }
    if(string(argv[1]) == "--has-nonepsilon") {
      cout << has_nonepsilon(n) << endl;
    }
    if(string(argv[1]) == "--infinite") {
      cout << infinite(n) << endl;
    }
    if(string(argv[1]) == "--starts-with") {
      cout << starts_with(n) << endl;
    }
    if(string(argv[1]) == "--ends-with") {
     cout << ends_with(n) << endl;
    }
    if(string(argv[1]) == "--reverse") {
      cout << reverse(n) << endl;
    }
    if(string(argv[1]) == "--prefixes") {
     cout << prefixes(n) << endl;
    }
    if(string(argv[1]) == "--suffixes") {
      cout << suffixes(n) << endl;
    }
    if(string(argv[1]) == "--b-before-a") {
      cout << b_before_a(n) << endl;
    }
    if(string(argv[1]) == "--drop-one") {
      cout << drop_one(n) << endl;
    }
    if(string(argv[1]) == "--strip") {
      cout << strip(n) << endl;
    }
  }
}
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
bool hasEpsilonTree(et *t) {
  char c = t->value;
  if(c == '/') {
    return false;
  } else if(c == '+') {
    return hasEpsilonTree(t->left) || hasEpsilonTree(t->right);
  } else if(c == '.') {
    return hasEpsilonTree(t->left) && hasEpsilonTree(t->right);
  } else if(c == '*') {
    return true;
  }
  return false;
}
bool hasNonEpsilonTree(et *t) {
  char c = t->value;
  if(c == '+') {
    return hasNonEpsilonTree(t->left) || hasNonEpsilonTree(t->right);
  } else if (c == '.') {
    return hasNonEpsilonTree(t->left) && hasNonEpsilonTree(t->right);
  } else if (c == '*') {
    return hasNonEpsilonTree(t->right);
  } else if(c =='/') {
    return false;
  } 
  return true;
}
// A utility function to create a new node
et* newNode(char v) {
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
string bool_to_string(bool b) {
  if (b == true) {
    return "yes";
  }
  return "no";
}
string no_op(string s) {
  et* r = constructTree(s);
  string ret = preorder(r);
  return ret;
}

string empty(string s) {
  et* r = constructTree(s);
  return bool_to_string(emptyTree(r));
}

string has_epsilon(string s) {
  et* r = constructTree(s);
  return bool_to_string(hasEpsilonTree(r));
}

string has_nonepsilon(string s) {
  et* r = constructTree(s);
  return bool_to_string(hasNonEpsilonTree(r));
}

string infinite(string s) {
  return s;
}

string starts_with(string s) {
  return s;
}

string ends_with(string s) {
  return s;
}

string reverse(string s) {
  return s;
}

string prefixes(string s) {
  return s;
}

string suffixes(string s) {
  return s;
}

string b_before_a(string s) {
  return s;
}

string drop_one(string s) {
  return s;
}

string strip(string s) {
  return s;
}
