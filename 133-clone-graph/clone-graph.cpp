/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* cloneTheGraph(Node* node, map<Node*,Node*> &m)
    {
        if(!node)
            return nullptr;
        Node* newNode = new Node(node->val);
        m[node] = newNode; //store the corresponding address mappings
        for(Node* n : node->neighbors)
        {
            if(m.find(n)==m.end()){
                cloneTheGraph(n, m);
            }
            newNode->neighbors.push_back(m[n]);
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) 
    {
        map<Node*,Node*> m;
        return cloneTheGraph(node,m);
    }
};