/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 4: Tablas hash
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 13/03/2024
/// Archivo: hash.h

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>

#include "dispersion.h"
#include "exploration.h"
#include "sequence.h"

// Clase que implementa una tabla hash con contenedor estático
template<class Key, class Container = staticSequence<Key>>
class HashTable {
 public:
  // Constructores
  HashTable(unsigned, DispersionFunction<Key>&, ExplorationFunction<Key>&, unsigned);

  // Métodos
  bool search(const Key& k) const;
  bool insert(const Key& k);
  unsigned getSize() const { return tableSize_; }
  void print() const;
 private:
  unsigned tableSize_;
  unsigned blockSize_;
  DispersionFunction<Key>* dispersion_;
  ExplorationFunction<Key>* exploration_;
  std::vector<Container*> tabla_;
};

// Clase que implementa una tabla hash con contenedor dinámico
template<class Key>
class HashTable<Key, dynamicSequence<Key>> {
 public:
  // Constructores
  HashTable(unsigned, DispersionFunction<Key>&);

  // Métodos
  bool search(const Key& k) const;
  bool insert(const Key& k);
  unsigned getSize() const { return tableSize_; }
  void print() const;
 private:
  unsigned tableSize_;
  DispersionFunction<Key>* dispersion_;
  std::vector<dynamicSequence<Key>*> tabla_;
};

// Constructor de la tabla hash con contenedor estático
template<class Key, class Container>
HashTable<Key, Container>::HashTable(unsigned tableSize, DispersionFunction<Key>& dispersion, ExplorationFunction<Key>& exploration, unsigned blockSize) : tableSize_(tableSize), blockSize_(blockSize), dispersion_(&dispersion), exploration_(&exploration) {
  tabla_.resize(tableSize_);
  for (int iterador = 0; iterador < tableSize_; iterador++) {
    tabla_[iterador] = new Container(blockSize_);
  }
}

// Constructor de la tabla hash con contenedor dinámico
template<class Key>
HashTable<Key, dynamicSequence<Key>>::HashTable(unsigned tableSize, DispersionFunction<Key>& dispersion) : tableSize_(tableSize), dispersion_(&dispersion) {
  tabla_.resize(tableSize_);
  for (int iterador = 0; iterador < tableSize_; iterador++) {
    tabla_[iterador] = new dynamicSequence<Key>;
  }
}

// Método que busca un elemento en la tabla hash con contenedor estático
template<class Key, class Container>
bool HashTable<Key, Container>::search(const Key& k) const {
  unsigned posicion = (*dispersion_)(k);
  unsigned i = 0;
  while (i < tableSize_) {
    if (tabla_[posicion]->search(k)) {
      return true;
    }
    posicion = ((*dispersion_)(k) + (*exploration_)(k, i)) % tableSize_;
    i++;
  }
  return false;
}

// Método que busca un elemento en la tabla hash con contenedor dinámico
template<class Key>
bool HashTable<Key, dynamicSequence<Key>>::search(const Key& k) const {
  unsigned posicion = (*dispersion_)(k);
  if (tabla_[posicion]->search(k)) {
    return true;
  }
  return false;
}

// Método que inserta un elemento en la tabla hash con contenedor estático
template<class Key, class Container>
bool HashTable<Key, Container>::insert(const Key& k) {
  unsigned posicion = (*dispersion_)(k);
  unsigned i = 0;
  while (i < tableSize_) {
    if (!tabla_[posicion]->isFull()) {
      tabla_[posicion]->insert(k);
      return true;
    }
    posicion = ((*dispersion_)(k) + (*exploration_)(k, i)) % tableSize_;
    i++;
  }
  return false;
}

// Método que inserta un elemento en la tabla hash con contenedor dinámico
template<class Key>
bool HashTable<Key, dynamicSequence<Key>>::insert(const Key& k) {  
  unsigned posicion = (*dispersion_)(k);
  tabla_[posicion]->insert(k);
  return false;
}

// Método que imprime la tabla hash con contenedor estático
template<class Key, class Container>
void HashTable<Key, Container>::print() const {
  for (int iterador = 0; iterador < tableSize_; iterador++) {
    std::cout << "Posición " << iterador << ": ";
    tabla_[iterador]->print();
  }
}

// Método que imprime la tabla hash con contenedor dinámico
template<class Key>
void HashTable<Key, dynamicSequence<Key>>::print() const {
  for (int iterador = 0; iterador < tableSize_; iterador++) {
    std::cout << "Posición " << iterador << ": ";
    tabla_[iterador]->print();
  }
}

#endif