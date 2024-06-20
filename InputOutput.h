#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


std::string leerArchivo(const std::string& nombreArchivo) {
	std::ifstream t(nombreArchivo);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

void escribirArchivo(const std::string& nombreArchivo, const std::string& contenido) {
	std::ofstream out(nombreArchivo);
	out << contenido;
	out.close();
}

void escribirArchivoBinario(const std::string& nombreArchivo, const std::vector<unsigned char>& contenido) {
	std::ofstream out(nombreArchivo, std::ios::binary);
	out.write(reinterpret_cast<const char*>(contenido.data()), contenido.size());
	out.close();
}

std::vector<unsigned char> leerArchivoBinario(const std::string& nombreArchivo) {
	std::ifstream input(nombreArchivo, std::ios::binary);
	return std::vector<unsigned char>((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
}