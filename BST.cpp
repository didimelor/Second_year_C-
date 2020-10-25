//
//  main.cpp
//  BST
//
//  Created by Diana Melo on 22/10/20.
//  Copyright © 2020 Diana Melo. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class Nodo{
    public:
    T value;
    Nodo<T> *izq;
    Nodo<T> *der;
    
    Nodo(){
        value=NULL;
        izq=NULL;
        der=NULL;
    }
    
    Nodo(T val){
        value=val;
        izq=NULL;
        der=NULL;
    }
};

template <class T>
class BST{
    public:
    Nodo<T> *root;
    
    BST(){
        root=NULL;
    }
    
    void insertar(T value){
        Nodo<T> *nuevo=new Nodo<T>(value);
        if(root==NULL){
            root=nuevo;
        }else{
            insertar(nuevo, root);
        }
    }
    
    void insertar(Nodo<T> *nuevo, Nodo<T> *temp){
        if(nuevo->value==temp->value){    //si el valor es igual, terminamos
            return;
        }else if(nuevo->value<temp->value){//si el valor es menor que el valor de temp
            if(temp->izq==NULL){//si el izquierdo es nulo, ahi agregamos
                temp->izq=nuevo;
            }else{
                insertar(nuevo, temp->izq);//sino, temp=temp->izq
            }
        }else{//si el valor es mayor que el valor de temp
            if(temp->der==NULL){    //si el derecho es nulo, ahi agregamos
                temp->der=nuevo;
            }else{
                insertar(nuevo, temp->der);//sino, temp=temp->der
            }
        }
    }
    
    void inorder(){
        inorder(root);
        cout<<endl;
    }

    
    void inorder(Nodo<T> *temp){
        if(temp!=NULL){
            inorder(temp->izq);
            cout<<temp->value<<" ";
            inorder(temp->der);
        }
    }
    
    
    bool buscarIterativo(T value){
        Nodo<T> *temp=root;
        while(temp!=NULL){
            if(temp->value==value){
                return true;
            }else if(value<temp->value){
                temp=temp->izq;
            }else{
                temp=temp->der;
            }
        }
        return false;
    }
    
    bool buscarRecursivo(T value){
        if(root==NULL){
            return false;
        }else{
            return buscarRecursivo(value, root);
        }
    }
    
    bool buscarRecursivo(T value, Nodo<T> *temp){
        if(temp==NULL){
            return false;
        }else if(temp->value==value){
            return true;
        }else if(value<temp->value){
            return buscarRecursivo(value, temp->izq);
        }else{
            return buscarRecursivo(value, temp->der);
        }
    }
    
    void eliminar (T value){
        if(root==NULL){
            return;
        }
        else{
            root=eliminar(value, root);
        }
    }
    
    Nodo<T> *eliminar(T value, Nodo<T> *temp){
        if(temp == NULL){
            return NULL;
        }
        else if(value<temp->value){
            temp->izq = eliminar(value, temp->izq);
        }
        else if(value>temp->value){
            temp->der = eliminar(value, temp->der);
        }
        else{//Aqui temp es igual al value, lo encontramos
            if(temp->izq==NULL && temp->der==NULL){//Es el nodo hoja
                delete temp;
                return NULL;
            }
        }
        return temp;
    }

};

int main(){
    BST<int> tree;
    tree.insertar(10);
    tree.insertar(35);
    tree.insertar(15);
    tree.insertar(100);
    tree.insertar(30);
    tree.insertar(20);
    cout<<tree.buscarRecursivo(10)<<endl;
    cout<<tree.buscarRecursivo(12)<<endl;
    return 0;
}
