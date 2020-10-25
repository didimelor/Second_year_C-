/*
 * Miguel Angel Medina Ruperto & Diana Melo Reyes
 * A01023656 - A01023785
 * Fecha: 17/08/2020
 * Ejercicios de calentamiento
 */

#include <iostream>
#include <string>

// Ejercicio Uno

void anioBisiesto(int numero)
{
    if (numero % 4 == 0 && numero % 100 == 0 && numero % 400 == 0)
    {
        std::cout << "El año es Bisiesto!" << std::endl;
    }
    else if (numero % 4 == 0 && numero % 100 != 0)
    {
        std::cout << "El año es Bisiesto!" << std::endl;
    }
    else
    {
        std::cout << "El año No es Bisiesto." << std::endl;
    }
}

// Ejercicio Dos

int sumaNumeros(int max)
{
    int suma;
    int contador;
    int numero;
    suma = 0;
    contador = 0;

    while (contador < max)
    {
        std::cout << "Ingresa un numero: " << std::endl;
        std::cin >> numero;

        suma += numero;

        contador ++;
    }
    std::cout << "La suma de tus números es = " << suma << std::endl;
    return suma;
}


// Ejercicio Tres

void encontrarPalabra(std::string oracion, std::string palabra)
{
    int contador = 0;
    std::size_t encontrado = oracion.find(palabra); // posición de dónde halló la palabra

    while (encontrado != std::string::npos) // línea obtenida: http://www.cplusplus.com/reference/string/string/find_first_of/
    {
        contador++;
        encontrado = oracion.find(palabra, encontrado + palabra.size());
    }
    std::cout << "El numero de veces que aparece tu palabra es: " << contador << std::endl;
}

// Ejercicio Cuatro

template <class N>
class Calculadora
{
    public:
        std::string nombre;
        N resultado;

        N sumar(N numeroUno, N numeroDos)
        {
            nombre = "suma";
            return resultado = numeroUno + numeroDos;
        }

        N restar(N numeroUno, N numeroDos)
        {
            nombre = "resta";
            return resultado = numeroUno - numeroDos;
        }

        N multiplicar(N numeroUno, N numeroDos)
        {
            nombre = "multiplicación";
            return resultado = numeroUno * numeroDos;
        }

        N dividir(N numeroUno, N numeroDos)
        {
            nombre = "división";
            return resultado = numeroUno / numeroDos;
        }

        void mostrarRespuesta()
        {
            std::cout << "El resultado de la " << nombre << " es: " << resultado << std::endl;
        }
};

// Ejercicio Cinco

class Animal
{
    public:
        bool pico;
        bool cola;
        bool alas;
        std::string nombre;
        std::string especie;
        std::string color;
        std::string sonido;
        int patas;
        float peso;

        void hacerSonido()
        {
            std::cout << sonido << std::endl;
        }

        void volar()
        {
            if (alas)
            {
                std::cout << "El " << nombre << " está volando!" << std::endl;
            }
            else
            {
                std::cout << "El " << nombre << " no tiene alas, por lo tanto no puede volar" << std::endl;
            }
        }

        void caminar()
        {
            if (0 < patas && cola)
            {
                if (250.75 < peso)
                {
                    std::cout << "El animal camina lentamente" << std::endl;
                }
                else if (125.34 <= peso <= 250.75)
                {
                    std::cout << "El animal camina modestamente" << std::endl;
                }
                else
                {
                    std::cout << "El animal camina rápidamente!" << std::endl;
                }
            }
            else
            {
                std::cout << "El animal no está en condiciones para caminar" << std::endl;
            }
        }

        void imprimirFichaTecnica()
        {
            std::string tienePico;

            if (pico)
            {
                tienePico = "Este animal tiene pico";
            }

            else{
                tienePico = "Este animal no tiene pico";
            }

            std::string tieneCola;

            if (cola)
            {
                tieneCola = "Este animal tiene cola";
            }
            else{
                tieneCola = "Este animal no tiene cola";
            }
            std::cout << "Nombre: " << nombre << "\nEspecie: " << especie << "\nSonido: " << sonido << "\n" << tienePico << "\n" << tieneCola << "\nTiene: " << patas << " patas" << std::endl;
        }
};

class Perro : public Animal
{
    public:
        Perro() // Constructor vacío
        {
            pico = false;
            cola = true;
            alas = false;
            nombre = "perro";
            especie = "Canis lupus";
            color = "blanco";
            sonido = "woof";
            patas = 4;
            peso = 45.88;
        }
};

class Gato : public Animal
{
    public:
        Gato()
        {
            pico = false;
            cola = true;
            alas = false;
            nombre = "gato";
            especie = "Felis silvestris";
            color = "naranja";
            sonido = "meow";
            patas = 4;
            peso = 10.15;
        }
};

class Cuervo : public Animal
{
    public:
        Cuervo()
        {
            pico = true;
            cola = true;
            alas = true;
            nombre = "cuervo";
            especie = "Corvus corax";
            color = "negro";
            sonido = "sqwok";
            patas = 2;
            peso = 2.24;
        }
};

class Vaca : public Animal
{
    public:
        Vaca()
        {
            pico = false;
            cola = true;
            alas = false;
            nombre = "vaca";
            especie = "Bos Taurus";
            color = "café";
            sonido = "mooo";
            patas = 4;
            peso = 711.21;
        }
};

template <class T>
class Veterinario
{
    public:
        void inyectar(T mascota)
        {
            mascota.hacerSonido();
        }
        void obtenerMovimiento(T mascota)
        {
            mascota.caminar();
        }
        void obtenerVuelo(T mascota)
        {
            mascota.volar();
        }
        void obtenerFicha(T mascota)
        {
            mascota.imprimirFichaTecnica();
        }
};

int main()
{
    // 1
    int anio;
    std::cout << "¿Qué año te gustaría probar? ";
    std::cin >> anio;
    anioBisiesto(anio);

    // 2
    int limite;
    std::cout << "¿Cuántos números te gustaría sumar? ";
    std::cin >> limite;
    sumaNumeros(limite);

    // 3
    std::string suFrase;
    std::string suPalabra;

    std::cout << "Escriba una frase: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, suFrase);
    std::cout << "Escriba una palabra: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, suPalabra);
    encontrarPalabra(suFrase, suPalabra);

    // 4
    Calculadora <int> casio1;
    int numero1, numero2;
    std::cout << "Dame un entero " << std::endl;
    std::cin >> numero1;
    std::cout << "Dame otro entero " << std::endl;
    std::cin >> numero2;
    casio1.sumar(numero1, numero2);
    casio1.mostrarRespuesta();

    Calculadora <float> casio2;
    float numeroU, numeroD;
    std::cout << "Dame un decimal " << std::endl;
    std::cin >> numeroU;
    std::cout << "Dame otro decimal " << std::endl;
    std::cin >> numeroD;
    casio2.dividir(numeroU, numeroD);
    casio2.mostrarRespuesta();

    Calculadora <double> casio3;
    double numerou, numerod;
    std::cout << "Dame un decimal, doble " << std::endl;
    std::cin >> numerou;
    std::cout << "Dame otro decimal, doble " << std::endl;
    std::cin >> numerod;
    casio3.multiplicar(numerou, numerod);
    casio3.mostrarRespuesta();

    Calculadora <long> casio4;
    long numero_1, numero_2;
    std::cout << "Dame un número muy largo " << std::endl;
    std::cin >> numero_1;
    std::cout << "Dame otro número muy largo " << std::endl;
    std::cin >> numero_2;
    casio4.restar(numero_1, numero_2);
    casio4.mostrarRespuesta();

    // 5
    Perro firulais;
    firulais.caminar();
    firulais.volar();
    Veterinario<Perro> Ale;
    Ale.inyectar(firulais);

    Gato michi;
    michi.caminar();
    Veterinario<Gato> Bernardo;
    Bernardo.inyectar(michi);

    Cuervo kross;
    kross.volar();
    Veterinario<Cuervo> Mitch;
    Mitch.inyectar(kross);

    Vaca bessie;
    bessie.caminar();
    Veterinario<Vaca> Austin;
    Austin.inyectar(bessie);
    Austin.obtenerFicha(bessie);

    return 0;
}