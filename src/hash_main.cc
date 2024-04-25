/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: AyEDA
/// Curso: 2º
/// Práctica 4: Tablas hash
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 13/03/2024
/// Archivo: hash_main.cc

#include <iostream>

#include "hash.h"
#include "nif.h"

// Función que muestra un menú de funcionamiento para la tabla hash
template<typename T, typename Container>
void MenuDeFuncionamiento(HashTable<T, Container>& tabla) {
  while (true) {
    std::cout << "Elija una opción:" << std::endl;
    std::cout << "[1] Insertar" << std::endl;
    std::cout << "[2] Buscar" << std::endl;
    std::cout << "[3] Finalizar programa" << std::endl;
    std::cout << "[4] Mostrar tabla" << std::endl;
    int opcion_escogida{0};
    std::cin >> opcion_escogida;
    switch (opcion_escogida) {
      case 1: {
        std::cout << "Introduzca el elemento a insertar (si desea introducir un elemento aleatorio en la tabla, introduzca un 0):";
        long elemento{0};
        std::cin >> elemento;
        if (elemento == 0) {
          tabla.insert(Nif());
        } else {
          tabla.insert(elemento);
        }
        std::cout << std::endl;
        break;
      }
      case 2: {
        std::cout << "Introduzca el elemento a buscar:";
        long elemento{0};
        std::cin >> elemento;
        if (tabla.search(elemento)) {
          std::cout << "El elemento se encuentra en la tabla." << std::endl << std::endl;
        } else {
          std::cout << "El elemento no se encuentra en la tabla." << std::endl << std::endl;
        }
        break;
      }
      case 3: {
        std::cout << "Finalizando programa..." << std::endl;
        exit(EXIT_SUCCESS);
      }
      case 4: {
        tabla.print();
        std::cout << std::endl;
        break;
      }
      default: {
        std::cout << "Opción seleccionada no válida. Finalizando programa..." << std::endl;
        exit(EXIT_SUCCESS);
      }
    }
  }
}

// Función que comprueba que el número de parámetros de entrada es correcto y proporciona ayuda al usuario
void Usage(int argc, char *argv[]) {
  if (argc != 7 && argc != 11) {
    std::cout << "--Hash" << std::endl;
    std::cout << "Modo de uso: ./hash_main -ts <s> -fd <f> -hash <open|close> -bs <s> -fe <f>" << std::endl << "Pruebe ./hash_main --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }  
  if (argv[1] == "--help") {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Hash" << std::endl;
      std::cout << "Modo de uso: ./hash_main -ts <s> -fd <f> -hash <open|close> -bs <s> -fe <f>" << std::endl;
      std::cout << "-ts <s>: indica el tamaño de la tabla" << std::endl;
      std::cout << "-fd <f>: es el código que identifica a la función de dispersión. Puede ser: suma, modulo o pseudoaleatorio" << std::endl;
      std::cout << "-hash <open|close>: indica la técnica de dispersión a usar. Puede ser open o close" << std::endl;
      std::cout << "-bs <s>: indica el tamaño del bloque (este parámetro no se introduce en caso de dispersión abierta)" << std::endl;
      std::cout << "-fe <f>: es el código que identifica a la función de exploración. Puede ser: lineal, cuadratica, dispersiondoble o redispersion (este parámetro no se introduce en caso de dispersión abierta)" << std::endl;
      exit(EXIT_SUCCESS);
    } 
  }
}

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  std::string tamanio_tabla_str = argv[2];
  int tamanio_tabla = atoi(tamanio_tabla_str.c_str());
  std::string funcion_dispersion = argv[4];
  DispersionFunction<Nif>* dispersion;
  if (funcion_dispersion == "modulo") {
    dispersion = new fdModulo<Nif>(tamanio_tabla);
  } else if (funcion_dispersion == "suma") {
    dispersion = new fdSuma<Nif>(tamanio_tabla);
  } else if (funcion_dispersion == "pseudoaleatorio") {
    dispersion = new fdPseudoAleatorio<Nif>(tamanio_tabla);
    }
  std::string tecnica_dispersion = argv[6];
  if (tecnica_dispersion == "close") {
    std::string tamano_bloque_str = argv[8];
    unsigned tamanio_bloque = atoi(tamano_bloque_str.c_str());
    std::string funcion_exploracion = argv[10];
    ExplorationFunction<Nif>* exploracion;
    if (funcion_exploracion == "lineal") {
      exploracion = new feLineal<Nif>();
    } else if (funcion_exploracion == "cuadratica") {
      exploracion = new feCuadratica<Nif>();
    } else if (funcion_exploracion == "dispersiondoble") {
      exploracion = new feDobleDispersion<Nif>(dispersion);
    } else if (funcion_exploracion == "redispersion") {
      exploracion = new feRedispersion<Nif>();
    }
    HashTable<Nif> tabla(tamanio_tabla, *dispersion, *exploracion, tamanio_bloque);
    MenuDeFuncionamiento(tabla);
  } else {
    HashTable<Nif, dynamicSequence<Nif>> tabla(tamanio_tabla, *dispersion);
    MenuDeFuncionamiento(tabla);
  }
  return 0;
}