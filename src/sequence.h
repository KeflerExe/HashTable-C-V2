/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 4: Tablas hash
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 13/03/2024
/// Archivo: sequence.h

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>

template<class Key>
class Sequence {
 public:
  virtual bool search(const Key& k) const = 0;
  virtual bool insert(const Key& k) = 0;
  virtual void print() const = 0;
};

// Clase que implementa una secuencia dinámica
template<class Key>
class dynamicSequence : public Sequence<Key> {
 public:
  // Constructores
  dynamicSequence() {}
  dynamicSequence(unsigned size) {
    sequencia_.resize(size, 0);
  }

  // Destructor
  virtual ~dynamicSequence();

  // Métodos
  virtual bool search(const Key& k) const;
  virtual bool insert(const Key& k);
  virtual void print() const;
 private:
  std::vector<Key> sequencia_; 
};

// Clase que implementa una secuencia estática
template<class Key>
class staticSequence : public Sequence<Key> {
 public:
  // Constructores
  staticSequence() {}
  staticSequence(unsigned size) {
    sequencia_.resize(size, 0);
  }

  // Destructor
  virtual ~staticSequence();

  // Métodos
  virtual bool search(const Key& k) const;
  virtual bool insert(const Key& k);
  virtual bool isFull() const;
  virtual void print() const;
 private:
  std::vector<Key> sequencia_;
};

// Método que busca un elemento en la secuencia estática
template<class Key>
bool staticSequence<Key>::search(const Key& k) const {
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    if (sequencia_[iterador] == k) {
      return true;
    }
  }
  return false;
}

// Método que busca un elemento en la secuencia dinámica
template<class Key>
bool dynamicSequence<Key>::search(const Key& k) const {
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    if (sequencia_[iterador] == k) {
      return true;
    }
  }
  return false;
}

// Método que inserta un elemento en la secuencia estática
template<class Key>
bool staticSequence<Key>::insert(const Key& k) {
  if (isFull()) {
    return false;
  }
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    if (sequencia_[iterador] == k) {
      return false;
    }
  }
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    if (sequencia_[iterador] == 0) {
      sequencia_[iterador] = k;
      return true;
    }
  }
  return false;
}

// Método que inserta un elemento en la secuencia dinámica
template<class Key>
bool dynamicSequence<Key>::insert(const Key& k) {
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    if (sequencia_[iterador] == k) {
      return false;
    }
  }
  sequencia_.push_back(k);
  return true;
}

// Método que comprueba si la secuencia está llena
template<class Key>
bool staticSequence<Key>::isFull() const {
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    if (sequencia_[iterador] == 0) {
      return false;
    }
  }
  return true;
}

// Destructor de la secuencia estática
template<class Key>
staticSequence<Key>::~staticSequence() {
  sequencia_.clear();
}

// Destructor de la secuencia dinámica
template<class Key>
dynamicSequence<Key>::~dynamicSequence() {
  sequencia_.clear();
}

// Método que imprime la secuencia dinámica
template<class Key>
void dynamicSequence<Key>::print() const {
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    std::cout << sequencia_[iterador] << " ";
  }
  std::cout << std::endl;
}

// Método que imprime la secuencia estática
template<class Key>
void staticSequence<Key>::print() const {
  for (int iterador = 0; iterador < sequencia_.size(); iterador++) {
    std::cout << sequencia_[iterador] << " ";
  }
  std::cout << std::endl;
}

#endif