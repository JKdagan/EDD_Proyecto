
#include "Trie.h"
#include "compresion.h"
#include "Huffman.h"
#include "InputOutput.h"

#include <iostream>
#include <string>
#include <vector>


int main(void) {
    std::string nombre_archivo = "Dataset/sources50MB_158065";
    std::string input = leerArchivo(nombre_archivo);
	std::string output1 = nombre_archivo + "_comprimido";

    Huffman huffman;
	std::vector<unsigned char> contenido = huffman.codificar(input);
	escribirArchivoBinario(output1, contenido);
    
	std::string output2 = nombre_archivo + "_descomprimido.txt";
	std::string descomprimido = huffman.decodificar(leerArchivoBinario(output1));
	escribirArchivo(output2, descomprimido);

	return 0;

}
