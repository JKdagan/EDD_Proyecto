#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdio.h>
#include <memory>


class TrieNode {
public:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};


class Trie {
private:
    std::unique_ptr<TrieNode> root;

public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    // Función para insertar una palabra en el Trie
    void insert(const std::string& word) {
        TrieNode* current = root.get();
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = std::make_unique<TrieNode>();
            }
            current = current->children[c].get();
        }
        current->isEndOfWord = true;
    }

    // Función para buscar una palabra en el Trie
    bool search(const std::string& word) const {
        const TrieNode* node = findNode(word);
        return node && node->isEndOfWord;
    }

    // Función para verificar si existe alguna palabra que empiece con el prefijo dado
    bool startsWith(const std::string& prefix) const {
        const TrieNode* node = findNode(prefix);
        return node != nullptr;
    }

    // Función para eliminar todas las palabras del Trie
    void clear() {
        clearRecursive(root);
    }

private:
    // Función privada para encontrar un nodo en el Trie
    const TrieNode* findNode(const std::string& word) const {
        const TrieNode* current = root.get();
        for (char c : word) {
            auto it = current->children.find(c);
            if (it == current->children.end()) {
                return nullptr;
            }
            current = it->second.get();
        }
        return current;
    }

    // Función recursiva para eliminar nodos del Trie
    void clearRecursive(std::unique_ptr<TrieNode>& node) {
        for (auto& child : node->children) {
            clearRecursive(child.second);
        }
        node.reset();  // Libera la memoria del nodo actual
    }
};
