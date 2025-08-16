// https://leetcode.com/problems/delete-duplicate-folders-in-system/description/?envType=daily-question&envId=2025-07-20

class Solution {
private:
    struct Node {
        map<string, Node*> child;
        bool deleted = false;
    };

    void insert(Node* root, const vector<string>& path){
        Node* node = root;
        for(string p : path){
            if(!node->child.count(p)) node->child[p] = new Node();
            node = node->child[p];
        }
    }

    string encode(Node* node, unordered_map<string, vector<Node*>>& map){
        if(node->child.empty()) return "()";
        vector<string>parts;
        for(auto& [key, val] : node->child){
            parts.push_back(key + encode(val, map));
        }
        sort(parts.begin(), parts.end());
        string sign = "(" + accumulate(parts.begin(), parts.end(), string()) + ")";
        map[sign].push_back(node);
        return sign;
    }

    void markDeleted(unordered_map<string, vector<Node*>>& map){
        for(auto& [sign, nodes] : map){
            if(nodes.size() > 1){
                for(Node* node : nodes) node->deleted = true;
            }
        }
    }

    void collect(Node* root, vector<string>& path, vector<vector<string>>& res){
        for(auto& [key, val] : root->child){
            if(val->deleted) continue;
            path.push_back(key);
            res.push_back(path);
            collect(val, path, res);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();

        for(auto& path : paths){
            insert(root, path);
        }

        unordered_map<string, vector<Node*> > map;
        encode(root, map);
        markDeleted(map);

        vector<vector<string>> res;
        vector<string> curr;
        collect(root, curr, res);
        return res;
    }
};
