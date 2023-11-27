#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

string lines_file1,lines_file2;
int x,n1,n2;

//Function to tokenize the content of file1,2 (put it inside a table)
vector<string> tokenize(string text){
    vector<string> tokens;
    istringstream stream(text);
    string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    // for(int i=0;i<text.size();i++){
    //     getline(cin,token);
    //     tokens.push_back(token);
    // }
    return tokens;
     
}


int main(){
    

   // Write inside the file 1 
    ofstream write_file1("file1.txt");
    if(write_file1.is_open()){
        cout << "file 1 is open" << endl;
        write_file1 << "hello world ";
        if(write_file1){cout<< "writing successfuly in file 1!"<<endl;}
    }
    else{
        cout << "error opening the file 1!" << endl;
    }
    write_file1.close();
    // Write inside the file 2
    ofstream write_file2("file2.txt");
    if(write_file2.is_open()){
        cout << "file 2 is open" << endl;
        write_file2 << "hello world";
        if(write_file2){cout<< "writing successfuly in file 2!"<<endl;}
    }
    else{
        cout << "error opening the file 2!" << endl;
    }
    write_file2.close();

    //Read from the file 1
    ifstream read_file1("file1.txt");
    getline(read_file1,lines_file1);
    cout << "lines inside file 1: "<< lines_file1 <<endl;
    read_file1.close();
    //Read from the file 2
    ifstream read_file2("file2.txt");
    while(getline(read_file2,lines_file2)){
        cout << "lines inside file 2: "<< lines_file2 <<endl;
    }
    read_file2.close();
    

    //tekonize the lines inside file 1,2 into vectors tokens1 ,tokens2
    
    vector<string> tokens1 = tokenize(lines_file1);
    vector<string> tokens2 = tokenize(lines_file2);

    //similarity
    
    int x=0;
    for(int i=0;i<tokens1.size();i++){
        if(tokens1[i]==tokens2[i]){
            x++;
        }
    }
    if(x==0){
        double angleInRadians = 90;
        cout <<" in degrees: " << angleInRadians<< endl;
        int cosx=cos(angleInRadians);
        cout<<" similarity by cos= "<<cosx <<" (file1 and file2 are completly different)"<<endl;
    }else{
        float s=90*(tokens1.size()-x)/ tokens1.size();
        cout <<" in degrees: " << s<< endl;
        double cosx=cos(s* (180.0 / M_PI));
        cout<<" similarity by cos= "<<cosx<<endl;
    }
    
    
    
   return 0;
    
}