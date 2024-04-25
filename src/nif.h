/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 4: Tablas hash
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 13/03/2024
/// Archivo: nif.h

#ifndef NIF_H
#define NIF_H

#include <iostream>
#include <random>

class Nif {
 public:
  // Constructores
  Nif();
  Nif(const long nif);

  // Sobrecarga de operadores
  bool operator==(const Nif& nif1) const; 
  bool operator==(const long nif1) const;
  bool operator==(const int nif1) const;
  operator long() const;
 private:
  int number_;
};

// Constructor por defecto
Nif::Nif() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(10000000, 99999999);
  number_ = dis(gen);
}

// Constructor de cambio de tipo
Nif::Nif(const long nif) {
  number_ = nif;
}

// Sobrecarga de operador de comparación
bool Nif::operator==(const Nif& nif1) const {
  return number_ == nif1.number_;
}

// Sobrecarga de operador de comparación
bool Nif::operator==(const long nif1) const {
  return number_ == nif1;
}

// Sobrecarga de operador de comparación
bool Nif::operator==(const int nif1) const {
  return number_ == nif1;
}

// Sobrecarga de operador de cambio de tipo
Nif::operator long() const {
  return number_;
}

#endif