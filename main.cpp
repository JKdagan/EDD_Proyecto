
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

void medirHuffman(const std::string& str) {

	std::ofstream outfile("tiempo_huffman_english5MB");
	if (!outfile.is_open()) {
		std::cerr << "Error al abrir el archivo para guardar los tiempos" << std::endl;
	}

	std::string nombre_archivo = str;
	std::string input = leerArchivo(nombre_archivo);

	std::vector<double> codificacion_tiempos;
	std::vector<double> decodificacion_tiempos;

	for (int i = 0; i < 20; i++) {
		Huffman huffman;
		std::cout << "Iteracion " << i + 1 << std::endl;


		auto start_codificacion = std::chrono::high_resolution_clock::now();
		std::vector<unsigned char> contenido = huffman.codificar(input);
		auto end_codificacion = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t_codificacion = end_codificacion - start_codificacion;
		codificacion_tiempos.push_back(t_codificacion.count());

		std::cout << "Codificado" << std::endl;

		auto start_decodificacion = std::chrono::high_resolution_clock::now();
		std::string decodificado = huffman.decodificar(contenido);
		auto end_decodificacion = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t_decodificacion = end_decodificacion - start_decodificacion;
		decodificacion_tiempos.push_back(t_decodificacion.count());

		std::cout << "Decodificado" << std::endl;

	}

	// Guardar los tiempos en un archivo
	for (int i = 0; i < 20; ++i) {
		outfile << codificacion_tiempos[i] << "," << decodificacion_tiempos[i] << std::endl;
	}

	outfile.close();
}
void medirLZ(const std::string& str) {

	std::ofstream outfile("tiempo_lz_english5MB");
	if (!outfile.is_open()) {
		std::cerr << "Error al abrir el archivo para guardar los tiempos" << std::endl;
	}

	std::string nombre_archivo = str;

	std::vector<double> compresion_tiempos;
	std::vector<double> descompresion_tiempos;

	for (int i = 0; i < 20; i++) {
		compresion lz;
		std::cout << "Iteracion " << i + 1 << std::endl;

		auto start_compresion = std::chrono::high_resolution_clock::now();
		std::vector<int> contenido = lz.comprimir(nombre_archivo);
		auto end_compresion = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t_compresion = end_compresion - start_compresion;
		compresion_tiempos.push_back(t_compresion.count());

		std::cout << "Comprimido" << std::endl;

		auto start_descompresion = std::chrono::high_resolution_clock::now();
		std::string decodificado = lz.descomprimir(contenido);
		auto end_descompresion = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> t_descompresion = end_descompresion - start_descompresion;
		descompresion_tiempos.push_back(t_descompresion.count());

		std::cout << "Descomprimido" << std::endl;

	}

	// Guardar los tiempos en un archivo
	for (int i = 0; i < 20; ++i) {
		outfile << compresion_tiempos[i] << "," << descompresion_tiempos[i] << std::endl;
	}

	outfile.close();
}

int main(int argc, char *argv[]) {


	medirHuffman("Dataset/english.5MB");


	return 0;

}
