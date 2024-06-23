
#include "Trie.h"
#include "compresion.h"
#include "Huffman.h"
#include "InputOutput.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>

//Esta funcion comprime, escribe y descomprime un archivo de texto
void usoHuffman(const std::string& str) {
	Huffman huffman;

	std::string nombre_archivo = str;
	std::string input = leerArchivo(nombre_archivo);
	std::string output1 = nombre_archivo + "_comprimido";
	std::string output2 = nombre_archivo + "_descomprimido.txt";

	std::vector<unsigned char> contenido = huffman.codificar(input);
	escribirArchivoBinario(output1, contenido);

	std::vector<unsigned char> contenido2 = leerArchivoBinario(output1);
	std::string descomprimido = huffman.decodificar(contenido2);
	escribirArchivo(output2, descomprimido);
}

void medirHuffman(const std::string& str, std::ofstream& outfile) {
	Huffman huffman;
	std::string nombre_archivo = str;
	std::string input = leerArchivo(nombre_archivo);

	std::vector<double> codificacion_tiempos;
	std::vector<double> decodificacion_tiempos;

	for (int i = 0; i < 20; i++) {
		auto start_codificacion = std::chrono::high_resolution_clock::now();
		std::vector<unsigned char> contenido = huffman.codificar(input);
		auto end_codificacion = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t_codificacion = end_codificacion - start_codificacion;
		codificacion_tiempos.push_back(t_codificacion.count());

		auto start_decodificacion = std::chrono::high_resolution_clock::now();
		std::string descomprimido = huffman.decodificar(contenido);
		auto end_decodificacion = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t_decodificacion = end_decodificacion - start_decodificacion;
		decodificacion_tiempos.push_back(t_decodificacion.count());

	}

	// Guardar los tiempos en un archivo
	for (int i = 0; i < 20; ++i) {
		outfile << codificacion_tiempos[i] << "," << decodificacion_tiempos[i] << std::endl;
	}
}

void usoLZ(const std::string& str) {

}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << "Ingrese la ubicacion del archivo a comprimir" << std::endl;
		return 1;
	}

	std::string str(argv[1]);

	std::ofstream outfile("tiempo_huffman_english50MB");
	if (!outfile.is_open()) {
		std::cerr << "Error al abrir el archivo para guardar los tiempos" << std::endl;
		return 1;
	}

	medirHuffman(argv[1], outfile);

	outfile.close();
	return 0;

	return 0;

}
