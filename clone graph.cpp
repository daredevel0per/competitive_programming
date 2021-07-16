/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node. */
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
public:
    void dfs(Node* curr, Node* node, unordered_map<int,Node*>&visit){
        visit[curr->val]=curr;
        for (auto i:node->neighbors){
            if (visit.find(i->val)!=visit.end()){
                (curr->neighbors).push_back(visit[i->val]);
            }
            else {
                Node* temp=new Node(i->val);
                (curr->neighbors).push_back(temp);
                dfs(temp,i,visit);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node==NULL){
            return NULL;
        }
        Node* root=new Node(node->val);
        unordered_map<int,Node*>visit;
        visit[root->val]=root;
        for (auto i: node->neighbors){
            if (visit.find(i->val)!=visit.end()){
                (root->neighbors).push_back(visit[i->val]);
            }
            else {
                Node* temp=new Node(i->val);
                (root->neighbors).push_back(temp);
                dfs(temp,i,visit);
            }
        }
        return root;
    }
};
