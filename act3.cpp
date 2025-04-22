#include <iostream>
#include <string>
//Autor: Josetrini Anaya Alvarado
//Lenguaje de programacion 1
//Programa para calcular el RFC de una persona
//Fecha: 2025-04-21
//Descripcion: Este programa solicita el nombre, apellido paterno, apellido materno y fecha de nacimiento de una persona y calcula su RFC.//
//Funcion para obtner la primera vocal interna de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) {
    for(size_t i=1; i < str.length(); ++i) {
        char c = str [i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
        return c;

        }
        return 'X';// SI NO SE ENCUNETRA NINGUNA VOCAL INTERNA, SE USA UNA X
    }
    
    //funcion principal para calcular RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento) {
std::string rfc; // Variable para almacenar el RFC
    // Se obtiene la letra inicial y la primera vocal interna del apellido paterno
    char letraIncial = apellidoPaterno[0];
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);

    //Se obtiene la inicial del apellido materno o se usa una 'X' si no hay
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';

    //se obtiene la inical del primer nombre o se usa una 'X' si no hay
char inicialNombre = nombre[0];

// se obtiene los 2 ultimos digitos del año de nacimiento
std::string anio = fechaNacimiento.substr(2, 2);

//se obtiene el mes y el dia de nacimiento
std::string mes= fechaNacimiento.substr(5, 2);
std::string dia = fechaNacimiento.substr(8, 2);

// Se construye el RFC
rfc = letraIncial;
rfc += primeraVocalInterna;
rfc += inicialApellidoMaterno;
rfc += inicialNombre;
rfc += anio;
rfc += mes;
rfc += dia;

return rfc;
    }
    int main() {
        std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

        std::cout << "Ingrese su nombre: ";
        std::getline(std::cin, nombre);

        std::cout << "Ingrese su apellido paterno: ";
        std::getline(std::cin, apellidoPaterno);

        std::cout << "Ingrese su apellido materno: ";
        std::getline(std::cin, apellidoMaterno);

        std::cout << "Ingrese su fecha de nacimiento (YYYY-MM-DD): ";
        std::getline(std::cin, fechaNacimiento);
    
        std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
        std::cout <<" RFC: " << rfc << std::endl;

        return 0;
    }





