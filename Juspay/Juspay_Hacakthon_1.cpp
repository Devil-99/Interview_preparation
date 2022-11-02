#include<bits/stdc++.h>
using namespace std;

struct Tree{
	string country; // Places
	int lockedCountryCount = 0; // Count of children which are locked 
	int lockedBy = -1; // User Id who locked the node
	bool isLocked = false; 

	vector<Tree *>children; // To store childrens
	Tree* parentNode;
	map<Tree*, int>HashNodeId; // To store which children have been locked by whom

	Tree(string country, Tree *parent){
		this->country = country;
		this->parentNode = parent;
		this->lockedBy = -1;
		this->isLocked = false;
		children.clear();
		HashNodeId.clear();
	}
};

map<string, Tree*>mp; // Helps to find the node of a place in just O(1) time

Tree* buildTree(int N, int M, vector<string>&countries){
	queue<Tree*>Q;
	
	Tree* root = new Tree(countries[0], NULL);
	Q.push(root);
	mp[countries[0]]=root; // To store the place in map

	int i=1;
	while(!Q.empty()){
		auto temp = Q.front();
		Q.pop();

		for(int j=0;j<M && i<N ;j++){
			Tree* child = new Tree(countries[i], temp);
			mp[countries[i]]=child;
			temp->children.push_back(child);
			Q.push(child);
			i++;
		}
	}
	return root;
}


bool lock(Tree* currentNode, int uid){
	if(currentNode->isLocked) return false;
	if(currentNode->lockedCountryCount)	return false;
	
	// This while is to check if any of the parent is already locked or not
	Tree *parent = currentNode->parentNode;
	while(parent){
		if(parent->isLocked) return false;
		parent = parent->parentNode;
	}

	// This while is to enter the locked child names to all of its parents.
	parent = currentNode->parentNode;
	while(parent){
		parent->lockedCountryCount++;
		parent->HashNodeId.insert({currentNode, uid});
		parent = parent->parentNode;
	}

	currentNode->isLocked = true;
	currentNode->lockedBy = uid;

	return true;
}

bool unlock(Tree* currentNode, int uid){
	if(!currentNode->isLocked) return false;
	if(currentNode->lockedBy!=uid) return false;

	Tree* parent = currentNode->parentNode;
	while(parent){
		parent->lockedCountryCount--;
		if(parent->HashNodeId.find(currentNode)==parent->HashNodeId.end()){
			return false;
		}
		parent->HashNodeId.erase(currentNode);
		parent = parent->parentNode;
	}

	currentNode->isLocked = false;
	currentNode->lockedBy = -1;
	
	return true;
}

bool upgrade(Tree* currentNode, int uid){
	if(currentNode->isLocked) return false;
	if(currentNode->lockedCountryCount==0) return false;

	vector<Tree*>toUnlock;
	for(auto p: currentNode->HashNodeId){
		if(p.second!=uid) return false;
		toUnlock.push_back(p.first);
	}
	// Using the vector toUnlock to store all the locked children so that complexity never occurs.Otherwise if we directly unlock
	// the child then may be a condition occur that
	for(auto X: toUnlock){
		unlock(X, uid);
	}

	return lock(currentNode, uid);	
}


int main(){

	int N, M, Q;
	cin>>N>>M>>Q;

	vector<string>countries(N);
	for(int i=0;i<N;i++)
		cin>>countries[i];
	Tree* root = buildTree(N, M, countries);

	while(Q--){
		int ty, id;
		string country;
		cin>>ty>>country>>id;

		if(ty==1){
			if(lock(mp[country], id)){
				cout<<"true"<<endl;
			}else 
				cout<<"false"<<endl;
		}else if(ty==2){
			if(unlock(mp[country], id)){
				cout<<"true"<<endl;
			}else 
				cout<<"false"<<endl;
		}else{
			if(upgrade(mp[country], id)){
				cout<<"true"<<endl;
			}else 
				cout<<"false"<<endl;
		}
	}

}
// n=7,m=2
// nodes = [‘World’, ‘Asia’, ‘Africa’, ‘China’, ‘India’, ‘SouthAfrica’, ‘Egypt’],
// q= [‘1 China 9’, ‘1 India 9’, ‘3 Asia 9’, ‘2 India 9’, ‘2 Asia 9’]