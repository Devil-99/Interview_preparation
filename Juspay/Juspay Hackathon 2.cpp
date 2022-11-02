#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	string country; // Places
	int lockedCount = 0; // Count of children which are locked 
	int lockedById = -1; // User Id who locked the node
	bool isLocked = false; 
	int cnt = 0;
	vector<TreeNode *>children; // To store childrens
	TreeNode* parentNode;
	map<TreeNode*, int>storeChildenById; // To store which children have been locked by whom
	TreeNode(string country, TreeNode *parent){
		this->country = country;
		this->parentNode = parent;
		this->lockedById = -1;
		this->isLocked = false;
		this->cnt = 0;
		children.clear();
		storeChildenById.clear();
	}
};

map<string, TreeNode*>store; // Helps to find the node/struct of a place

TreeNode* buildTree(int N, int M, vector<string>&countries){
	queue<TreeNode*>Q;
	
	TreeNode* root = new TreeNode(countries[0], NULL);
	Q.push(root);
	store[countries[0]]=root; // To store the place in map

	int i = 1;
	while(Q.size()){
		auto temp = Q.front();
		Q.pop();
		for(int j = 0 ; j < M && i< N ;j++){
			TreeNode* child = new TreeNode(countries[i], temp);
			store[countries[i]]=child;
			temp->children.push_back(child);
			Q.push(child);
			i++;
		}
	}
	return root;
}


bool lock(TreeNode* currentNode, int uid){
	
	if(currentNode->lockedCount){
		return false;
	}
	if(currentNode->cnt>=1){
		return false;
	}
	currentNode->cnt++;

	TreeNode *parent = currentNode->parentNode;

	while(parent){
       
         parent->lockedCountryCount++;
         parent->HashNodeId.insert({currentNode, uid});

        if(parent->cnt >= 1) {
           
            Tree* parent1 = currentNode->parent;
            while(parent != parent1){
                parent1->lockedCountryCount--;
                parent1->HashNodeId.erase(currentNode,uid);
                parent1 = parent1->parentNode;
            }
            currentNode->cnt--;
            currentNode->lockedBy = -1;
           
            parent->lockedCountryCount--;
            parent->HashNodeId.erase(currentNode);
            return false;
       
        }
	parent = parent -> parentNode;
	
	}
	currentNode->lockedById = uid;
	return true;
}


bool unlock(TreeNode* currentNode, int uid){
	if(!currentNode->cnt){
		return false;
	}

	if(currentNode->lockedById!=uid){
		return false;
	}

	currentNode->cnt--;
	if(currentNode->cnt < 0){
		currentNode->cnt = 0;
		return false;
	}
	TreeNode* parent = currentNode->parentNode;
	
	while(parent){
	
		parent->lockedCount--;
		parent->storeChildenById.erase(currentNode);
		parent = parent->parentNode;
	}

	currentNode->isLocked = false;
	currentNode->lockedById = -1;
	
	return true;
}

bool upgrade(TreeNode* currentNode, int uid){
	if(currentNode->isLocked)
		return false;
	if(currentNode->lockedCount==0)
		return false;

	vector<TreeNode*>haveToUnlock;
	for(auto p: currentNode->storeChildenById){
		if(p.second!=uid){
			return false;
		}
		haveToUnlock.push_back(p.first);
	}

	for(auto node: haveToUnlock){
		unlock(node, uid);
	}

	return lock(currentNode, uid);	
}


int main(){

	int N, M, Q;
	cin>>N>>M>>Q;
	vector<string>countries(N);
	for(string &countryInput : countries) cin >> countryInput;
	TreeNode* root = buildTree(N, M, countries);
	for(int i = 0 ; i < Q ; i += 1){
		int type, id;
		string country;
		cin>>type>>country>>id;
        auto checkAns = [&](string country, int id)->bool{
            if(type==1) {
                return lock(store[country], id);
		    }else if(type==2){
			    return unlock(store[country], id);
		    }else{
			    return upgrade(store[country], id); 
		    }
        };
        checkAns(country,id) ? cout << "true\n":cout<<"false\n";
	}

}