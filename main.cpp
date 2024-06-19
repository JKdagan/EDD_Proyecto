#include "Trie.h"
#include "compresion.h"
#include "Huffman.h"
#include "medir_compresion.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdio.h>

int main(void) {
	Huffman huffman;
	compresion compresor;
	std::string str = "alabar_a_la_alabarda";
	std::string str_cod = huffman.codificar(str);
	std::cout << "Codificado: " << str_cod << std::endl;
	std::cout << "Decodificado: " << huffman.decodificar(str_cod) << std::endl;

	std::vector<int> result = compresor.comprimir(str);

	for (size_t i = 0; i < result.size(); i += 2) {
            if (result[i + 1] == 0) {
                char character = static_cast<char>(result[i]);
                std::cout << "(" << character << ", " << 0 << ") ";
            } else {
                std::cout << "(" << result[i] << ", " << result[i + 1] << ") ";
            }
        }
        std::cout << std::endl;

	std::string original = compresor.descomprimir(result);
        std::cout << "Cadena original descomprimida: " << original << std::endl;

	print_size_bits(str);
	print_size_bits(str_cod);

}
