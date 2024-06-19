#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class compresion {

public:
	vector<int> comprimir(const string& input) {
    vector<int> compressedResult;
    Trie trie;
    int inputSize = input.size();
    string aux = input;


    int j=0;

    for(int i= 0;i< inputSize;i++){
        if(aux.size()<1){
            break;
            }
        
        string aux2=aux.substr(0, 1);
        while( trie.startsWith(aux2)){

            j++;
            if(aux.size()==1){
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
            size_t position = input.find(aux[0], 0);
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


    return compressedResult;
    }

    string descomprimir(const vector<int>& compressedResult){

        string originalString;
        for(int i=0;i<compressedResult.size();i=i+2){
            if(compressedResult[i + 1]==0){
                char character = static_cast<char>(compressedResult[i]);
                originalString += character;
            

            }else{
                for(int j=0;j<compressedResult[i + 1];j++){
                    char character = originalString[compressedResult[i]+j];
                    originalString += character;

                }
            }
        }

        return originalString;

        }

};