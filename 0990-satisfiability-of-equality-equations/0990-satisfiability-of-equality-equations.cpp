class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int node) {
        if(parent[node] == node) return node;

        return parent[node] = find(parent[node]);
    }

    void Union(int node1, int node2) {
        int par_node1 = find(node1);
        int par_node2 = find(node2);

        if(par_node1 == par_node2) return;

        if(size[par_node1] > size[par_node2]) {

            parent[par_node2] = par_node1;
            size[par_node1] += size[par_node2];

        }
        else if(size[par_node2] > size[par_node1]) {

            parent[par_node1] = par_node2;
            size[par_node2] += size[par_node1];

        }
        else{

            parent[par_node2] = par_node1;
            size[par_node1] += size[par_node2];            

        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        size.resize(26, 1);

        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for(string x: equations) {

            if(x[1] == '=') {
                Union(x[0] - 'a', x[3] - 'a');
            }

        }

        for(string x: equations) {

            if(x[1] == '!') {

                char var1 = x[0] - 'a';
                char var2 = x[3] - 'a';

                int par_var1 = find(var1);
                int par_var2 = find(var2);

                if(par_var1 == par_var2) {
                    return false;
                }

            }

        }
        return true;
    }
};