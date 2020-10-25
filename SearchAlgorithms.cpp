#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;

template <class T>
class Busqueda{
public:
    vector<T>t;
    int numElementos;
    Busqueda(int numElementos){
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1,100000);
        for(int i=0; i<numElementos; i++){
            //t.push_back(i);
            t.push_back(distribution(generator));
            //cout<<t[i]<<"\n";
        }
        sort(t.begin(), t.end());
        /*for(int i=0; i<numElementos;i++){
            cout<<t[i]<<"\n";
        }*/
    }
    
    int busquedaSecuencial(vector<T> elVector, T buscado){
        for(int i=0; i<elVector.size(); i++){
            if(elVector[i]==buscado){
                return i;
            }
        }
        return -1;
    }
    int busquedaOrdenada1(vector<T> elVector, T buscado){
        for(int i=0; i<elVector.size(); i++){
            if(elVector[i]>buscado){
                return -1;
            }
            if(elVector[i]==buscado){
                return i;
            }
        }
        return -1;
    }
    
    int busquedaOrdenada2Aux(vector<T> elVector, T buscado, int inicio, int fin, int paso){
        cout<<inicio<<","<<fin<<"\n";
        if(fin>elVector.size()){
            fin=elVector.size();
        }
        if(elVector[fin-1]>=buscado){
            for(int i=inicio; i<fin; i++){
                if(elVector[i]==buscado){
                    return i;
                }
            }
            return -1;
        }else{
            return busquedaOrdenada2Aux(elVector, buscado, fin, fin+paso, paso);
        }
    }
    
    int busquedaBinariaAux(vector<T> elVector, T buscado, int inicio, int fin){
        if(fin<inicio){
            return -1;
        }
        int medio=(inicio+fin)/2;
        if(elVector[medio]==buscado){
            return medio;
        }else if(buscado>elVector[medio]){
            return busquedaBinariaAux(elVector, buscado, medio+1, fin);
        }else{
            return busquedaBinariaAux(elVector, buscado, inicio, medio-1);
        }
    }
    
    int busquedaBinariaRecursiva(vector<T> elVector, T buscado){
        if(buscado>elVector[elVector.size()-1]|| buscado<elVector[0]){
            return -1;
        }else{
            return busquedaBinariaAux(elVector, buscado, 0, elVector.size()-1);
        }
    }
    
    int busquedaOrdenada2Recursiva(vector<T> elVector, T buscado){
        int paso=10000;
        return busquedaOrdenada2Aux(elVector, buscado, 0, paso, paso);
    }
    
    int busquedaOrdenada2(vector<T> elVector, T buscado){
        int paso=2;
        int inicio=0;
        int fin;
        while(inicio<elVector.size()){
            fin=inicio+paso;
            if(fin>elVector.size()){
                fin=elVector.size();
            }
            if(elVector[fin-1]>=buscado){
                for(int i=inicio; i<fin; i++){
                    if(elVector[i]==buscado){
                        return i;
                    }
                }
                return -1;
            }
            inicio=fin;
        }
        return -1;
    }
    
    int busquedaBinaria(vector<T> elVector, T buscado){
        int inicio=0;
        int fin=elVector.size()-1;
        if(buscado>elVector[fin] || buscado<elVector[inicio]){
            return -1;
        }
        while(fin>=inicio){
            int medio=(inicio+fin)/2;
            if(elVector[medio]==buscado){
                return medio;
            }else if(buscado>elVector[medio]){
                inicio=medio+1;
            }else{
                fin=medio-1;
            }
        }
        return -1;
    }
    
};

int main(){
    int numElementos=100000;
    Busqueda<int>elVector(numElementos);
    int buscado=elVector.t[990000];
    int x;
    //Busqueda secuencial
    cout<<"Secuencial ";
    auto inicio=high_resolution_clock::now();
    x=elVector.busquedaSecuencial(elVector.t, buscado);
    //x=busquedaSecuencial(elVector.t ,buscado);
    auto fin=high_resolution_clock::now();
    auto tiempo=duration_cast<microseconds>(fin - inicio).count();
    cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<"\n";
    //Busqueda Ordenada 1
    cout<<"Ordenada 1 ";
    inicio=high_resolution_clock::now();
    x=elVector.busquedaOrdenada1(elVector.t, buscado);
    fin=high_resolution_clock::now();
    tiempo=duration_cast<microseconds>(fin - inicio).count();
    cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<"\n";
    //Busqueda Ordenada 2
    cout<<"Ordenada 2 ";
    inicio=high_resolution_clock::now();
    x=elVector.busquedaOrdenada2(elVector.t, buscado);
    fin=high_resolution_clock::now();
    tiempo=duration_cast<microseconds>(fin - inicio).count();
    cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<"\n";
    //Busqueda binaria
    cout<<"Binaria ";
    inicio=high_resolution_clock::now();
    x=elVector.busquedaBinaria(elVector.t, buscado);
    fin=high_resolution_clock::now();
    tiempo=duration_cast<microseconds>(fin - inicio).count();
    cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<"\n";
    return 0;
}
