#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void read_protein(vector<string>& proteins){
	ifstream myfile ("protein sequence.txt"); 
	if (myfile.is_open()){
		string line, seq_id, seq_prot;
		while (getline(myfile,line)){
			if(line.empty()) 
				continue;
			if(line[0] == '>'){
				if(!seq_id.empty()){
					proteins.push_back(seq_prot);
				}
				seq_id = line;
				seq_prot.clear();
			}	
			else {
				line = line.substr(0, line.length() - 1);
				seq_prot += line; 
			}
		}
		if(!seq_id.empty()){
			proteins.push_back(seq_prot);
		}
		myfile.close();
	}	
	else cout << "Unable to open file" << endl;
}

void read_id(vector<string>& id){
	ifstream myfile ("rosalind_mprt.txt");
	if (myfile.is_open()){
		string line; 
		while (getline(myfile,line)){
			id.push_back(line);
		}
		myfile.close();
	  }
	else cout << "Unable to open file" << endl;
}

void N_glycosylation(vector<string>& id, vector<string>& proteins){
	for(int i = 0; i < id.size(); i++){
		bool first = true; 
		for(int j = 0; j < proteins[i].size() - 3; j++){
			if(proteins[i][j] == 'N'){
				if(proteins[i][j + 1] != 'P'){
					if(proteins[i][j + 2] == 'S' or proteins[i][j + 2] == 'T'){
						if(proteins[i][j + 3] != 'P'){
							if(first == true) {
								cout << id[i] << endl << j + 1;
								first = false;
							}
							else cout << ' ' << j + 1;
						}
					}
				}
			}
		}
		if(first == false) cout << endl; 
	}
}

int main(){
	vector<string> protein_seq;
	vector<string> id;
	read_protein(protein_seq);
	read_id(id); 
	N_glycosylation(id, protein_seq);
}
