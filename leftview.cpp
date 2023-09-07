#include<bits/stdc++.h>
using namespace std;

struct Node   {
       Node * left;
       int data;
       Node * right;
       Node(int x )  {
              data = x;
              left  = right = NULL;
       }
};
void leftview(Node * root )       {
       queue<pair<Node * , int> > q;
       map<int , int> mpp;
       q.push({root , 0});
       while(q.empty() == false)   {
              auto p = q.front();
              Node * curr = p.first;
              q.pop();
              int level = p.second;
              if(mpp.find(level) == mpp.end())
              mpp[level] = curr -> data;
              if(curr -> left != NULL)    
              q.push({curr -> left , level+1});
              if(curr -> right != NULL)
              q.push({curr -> right , level +1});
       }
       for(auto it : mpp)   
       cout <<it.second <<" ";

}
int main()    {
       Node * root = new Node(1);
       root -> left = new Node(2);
       root -> right = new Node(3);
       root -> left -> left = new Node(4);
       root -> left -> right = new Node(5);
       root -> right -> left = new Node(6);
       root -> right -> right = new Node(7);   
       leftview(root);
       return 0;
}