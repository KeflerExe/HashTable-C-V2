/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 4: Tablas hash
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 13/03/2024
/// Archivo: dispersion.h

#include <iostream>

#ifndef DISPERSION_H
#define DISPERSION_H

template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key& k) const = 0;
  virtual ~DispersionFunction() {}
};

// Clase que implementa una función de dispersión modular
template<class Key>
class fdModulo: public DispersionFunction<Key> {
 public:
  fdModulo(const unsigned n): tableSize(n){}
  unsigned operator()(const Key& k) const {
    return k % tableSize;
  }
 private:
  unsigned tableSize;
};

// Clase que implementa una función de dispersión por suma de dígitos
template<class Key>
class fdSuma: public DispersionFunction<Key> {
 public:
  fdSuma(const unsigned n): tableSize(n){}
  unsigned operator()(const Key& k) const {
    long suma = 0; 
    long valor = k;
    while (valor > 0) {
      int digito = valor % 10;
      suma = suma + digito;
      valor = valor / 10;
    }
    return (suma % tableSize);
  }
 private:
  unsigned tableSize;
};

// Clase que implementa una función de dispersión pseudoaleatoria
template<class Key>
class fdPseudoAleatorio: public DispersionFunction<Key> {
 public:
  fdPseudoAleatorio(const unsigned n): tableSize(n){}
  unsigned operator()(const Key& k) const {
    srand(k);
    return rand() % tableSize;
  }
 private:
  unsigned tableSize;
};

#endif