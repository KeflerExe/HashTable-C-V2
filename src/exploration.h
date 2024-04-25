/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 4: Tablas hash
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 13/03/2024
/// Archivo: exploration.h

#include <iostream>

#include "dispersion.h"

#ifndef EXPLORATION_H
#define EXPLORATION_H

template<class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

// Clase que implementa una función de exploración lineal
template<class Key>
class feLineal: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const {
    return i;
  }
};

// Clase que implementa una función de exploración cuadrática
template<class Key>
class feCuadratica : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const {
    return i * i;
  }
};

// Clase que implementa una función de exploración redispersión
template<class Key>
class feRedispersion : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const {
    srand(k);
    for (int iterador = 0; iterador < i; iterador++) {
      rand();
    }
    return rand();
  }
};

// Clase que implementa una función de exploración doble dispersión
template<class Key>
class feDobleDispersion : public ExplorationFunction<Key> {
 public:
  feDobleDispersion(DispersionFunction<Key> *funcion1) : fd1_(funcion1) {}
  unsigned operator()(const Key &k, unsigned i) const {
    unsigned funcion_disp1 = (*fd1_)(k);
    return funcion_disp1 * i;
  }
 private:
  DispersionFunction<Key> *fd1_;
};

#endif