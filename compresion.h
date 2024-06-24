#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

class compresion {

public:
	vector<int> comprimir(const string& input) {
    vector<int> compressedResult;
    
    int j=0;
    
    

    ifstream file(input);
    
    
    if (!file.is_open()) {
        cerr << "Error abriendo el archivo." << endl;
        compressedResult.push_back(0);
        return compressedResult;
    }
    string line;
    string block;
    int abc=1;
    while (file.peek() != EOF){
        Trie trie;
        while (getline(file, line) && block.size()<20000 ) {
        block+=line;
        
        
    }
    



    string aux=block;
    

    j=0;

    for(int i= 0;i< block.size();i++){
        
        if(aux.size()<1){
            break;
            }

        
        string aux2=aux.substr(0, 1);
        

        
        while( trie.startsWith(aux2)){

            j++;
            if(aux.size()==j){
                    break;
                }
            aux2=aux.substr(0, j+1);
            


            }
        if(j==0){

            trie.insert(aux);
            compressedResult.push_back(aux[0]);
            compressedResult.push_back(0);
            aux=aux.substr(1);
            

        }else{
            size_t position = block.find(aux[0], 0);
            
            compressedResult.push_back(position);
            compressedResult.push_back(j);
            if(aux.size()>j){
                aux = aux.substr(j);
                

            }else{
                break;
                }
            

            }
        j=0;

        }
        compressedResult.push_back(0);
        compressedResult.push_back(0);
        block.clear();
        trie.clear();
        printf("bloque%d\n ", abc);
        abc++;
        


    }
    file.close();
   

    return compressedResult;
    }

    string descomprimir(const vector<int>& compressedResult){

        string originalString;
        string currentblock;
        for(int i=0;i<compressedResult.size();i=i+2){

            if(compressedResult[i]==0 && compressedResult[i+1]==0){
                originalString += currentblock;
                currentblock.clear();

            }else{
                if(compressedResult[i + 1]==0){
                char character = static_cast<char>(compressedResult[i]);
                currentblock += character;
            

                }else{
                     for(int j=0;j<compressedResult[i + 1];j++){
                        char character = currentblock[compressedResult[i]+j];
                        currentblock += character;

                     }
                }

            }


            
        }

        return originalString;

        }

};
