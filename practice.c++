#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream myFile;
    myFile.open("interns.txt");
	string s;
    int count=0;
    ofstream outputFile;
    outputFile.open("Output.txt",ios::out);
    if(myFile.is_open())
    while(myFile)
    {
        myFile>>s;
        count++;
        outputFile<<count<<" : "<<s<<endl;
        //cout<<count<<" : "<<s<<endl;
    }
    else
        cout<<"error opening file";
   //cout<<s;
	
	// long long len=s.length(),count=0;
	// string str="";
	// for(int i=0;i<len;i++)
	// {
	//     str+=s[i];
	//     if(s[i]==' ')
	//     {
	//         count++;
	//        
	//         str="";
	//     }
	// }
 	// cout<<count<<endl;
	return 0;
}

