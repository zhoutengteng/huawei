#include <iostream>
#include <map> 
#include <string>
using namespace std;


map<string, int> my_map;

int inValid = 0;

int AddCandidate (string pCandidateName) {
	if (my_map.count(pCandidateName) != 0) return 0;
	my_map.insert(pair<std::string, int>(pCandidateName, 0));
	return 1;
}

void Vote(string pCandidateName) {
	if (my_map.find(pCandidateName) != my_map.end()) {
		my_map.find(pCandidateName)->second++;
	} else {
		inValid++;
	}
}


void Clear() {
	my_map.clear();
}


int  GetVoteResult (string pCandidateName) {
	if (pCandidateName.empty()) {
		Clear();
		return -1;
	}
	if (my_map.find(pCandidateName) != my_map.end()) {
		return my_map.find(pCandidateName)->second;
	}
	return -1;
}



int main() {
	int peopleNum;
	string name[100];
	int voteNum;
	string vote[100];


	while (cin >> peopleNum) {
		for (int i = 0; i < peopleNum; i++) {
			cin >> name[i];
			AddCandidate(name[i]);
		}

		cin >> voteNum;
		for (int i = 0; i < voteNum; i++) {
			cin >> vote[i];
			Vote(vote[i]);
		}

		for (int i = 0; i < peopleNum; i++) {
			int result = GetVoteResult(name[i]);
			cout <<  name[i] << " : " << result << endl;;
		}
		cout << "Invalid : " << inValid << endl;
		my_map.clear();
		inValid = 0;
	}
}