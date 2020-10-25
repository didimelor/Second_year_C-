/*
 * Miguel Medina Ruperto A01023656
 * Diana Melo A01023785
 * Tarea Métodos de listas ligadas
 * Fecha: 6 de octubre de 2020
 */
#include <iostream>

using namespace std;

template <class T>
class Nodo
{
public:
    T value;
    Nodo<T> *next;

    Nodo(T val)
    {
        // a node has a value and a pointer to the following node.
        value = val;
        next = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    Nodo<T> *root;

    LinkedList()
    {
        root = NULL; // the pointer root starts pointing to nothing.
    }

    void append(Nodo<T> *nuevo)
    {
        // case 1 there are no nodes.
        if (root == NULL)
        {
            root = nuevo; // root points to the new node.
        }
        // case 2 there are other nodes already.
        else
        {
            Nodo<T> *temp = root; // temporal pointer points to root, it's useful to avoid having to move root.
            while (temp->next != NULL)
            {
                temp = temp->next; // temp moves to the next node.
            }
            temp->next = nuevo; // when the last node is reached, instead of pointing to NULL, it now points to new, the new last node.
        }
    }

    // another method. If the function's firm does not match, it's a different method, even if its name is shared.
    void append(T value)
    {
        auto *nuevo = new Nodo<T>(value);
        append(nuevo);
    }

    T getElementAt(int pos){
        Nodo<T> *temp=root;
        int i=0;
        while(temp!=NULL && i<pos){
            temp=temp->next;
            i++;
        }
        if (i == pos && temp != NULL)
        {
            return temp->value;
        }
        else
        {
            return NULL;
        }
    }

    void setElementAt(int pos, T value){
        Nodo<T> *temp=root;
        int i=0;
        while(temp!=NULL && i<pos){
            temp=temp->next;
            i++;
        }
        if(i==pos && temp!=NULL){
            temp->value=value;
        }
    }


    void insert (Nodo<T> *nuevo, int pos)
    {
        if (root == NULL)
        {
            root = nuevo;
        }
        else if (pos == 0)
        {
            nuevo->next = root;
            root = nuevo;
        }
        else
        {
            Nodo<T> *temp = root;
            int i = 0;
            while (temp->next != NULL && i < pos-1)
            {
                temp = temp->next;
                i++;
            }
            nuevo->next = temp->next;
            temp->next = nuevo;
        }
    }

    void insert (T value, int pos)
    {
        auto *nuevo = new Nodo<T>(value);
        insert(nuevo, pos);
    }

    void remove(T value)
    {
        if (root == NULL)
        {
            return;
        }
        else if (root->value == value)
        {
            Nodo<T> *aBorrar = root;
            root=root->next;
            delete aBorrar;
        }
        else
        {
            Nodo<T> *temp = root;
            while (temp->next != NULL)
            {
                //cout<<temp->value<<endl;
                if (temp->next->value == value)
                {
                    Nodo<T> *aBorrar = temp->next;
                    //temp->next=temp->next->next
                    temp->next = aBorrar->next;
                    delete aBorrar;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    void duplicar ()
    {
        Nodo<T> *temp = root;
        Nodo<T> *next;
        while (temp != NULL)
        {
            auto *nuevo = new Nodo<T>(temp->value); //nuevo nodo con el valor al que apunta temp.
            temp = nuevo; //temp apunta a nuevo
            nuevo->next = temp->next; //nuevo apunta al next de temp

        }
        //temp = temp->next;
    }

    int Count(T searchFor) // complejidad 12n+15 = O(n)
    {
        int counter = 0;
        Nodo<T> *temp = root;

        // Case 1 the value searched is in root.
        if (temp->value == searchFor)
        {
            counter++;
            temp = temp->next;
        }

        // Case 2 the value is searched through the nodes.
        while (temp->next != NULL)
        {
            if (temp->value == searchFor)
            {
                counter++;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }

        // Case 3 the searched value is in the last node.
        if (temp->next == NULL)
        {
            if (temp->value == searchFor)
            {
                counter++;
            }
        }
        return counter;
    }

    void deleteList() // 7n+7 = O(n)
    {
        Nodo<T> *temp = root;

        // case 1 the list is already empty.
        if (root == NULL)
        {
            return;
        }
        // case 2 the list is not empty.
        else
        {
            while (temp->next != NULL)
            {
                Nodo<T> *del = temp;
                temp = del->next;
                root = temp;
                delete del;
            }

            Nodo<T> *del = root;
            root = NULL;
            temp = NULL;
            delete del;
        }
    }

    void SortedInsert (T value) // 15n**2 + 2n + 8 = O(n)
    {
        auto *nuevo = new Nodo<T>(value);
        append(nuevo); // nuevo node is enlisted.
        Nodo<T> *temp = root;
        Nodo<T> *tprime = temp->next;

        while (temp != NULL)
        {
            temp = root;
            while (temp != tprime)
            {
                if (temp->value > tprime->value)
                {
                    int tempVal = tprime->value;
                    tprime->value = temp -> value;
                    temp->value = tempVal;
                }
                else
                {
                    temp = temp -> next;
                }
            }
            if (tprime->next != NULL)
            {
                tprime = tprime->next;
            }
            else
            {
                break;
            }
        }
    }

    void removeDuplicates() // 14n + 7 = O(n)
    {
        Nodo<T> *temp = root;
        Nodo<T> *tprime = root;
        Nodo<T> *aBorrar = root;
        if (temp == NULL)
        {
            return;
        }
        while (temp->next != NULL)
        {
            if (temp->value == temp->next->value)
            {
                tprime = temp->next->next;
                aBorrar = temp->next;
                temp->next = tprime;
                delete aBorrar;
            }
            else
            {
                temp = temp-> next;
            }
        }
    }

    void reverse() // 7n + 4 = O(n)
    {
        Nodo<T> *prev = NULL;
        Nodo<T> *temp = root;
        Nodo<T> *sig;
        while (temp != NULL)
        {
            sig = temp->next;
            temp->next = prev;
            prev = temp;
            temp = sig;
        }
        root = prev;
    }

    void print()
    {
        Nodo<T> *temp = root;
        while (temp != NULL)
        {
            cout << temp->value << ",";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList<int> list;
    auto *nuevo = new Nodo<int>(3);
    list.append(nuevo);

    list.append(3);
    list.append(5);
    list.append(4);
    list.append(7);
    list.append(20);
    list.append(7);
    list.append(1);
    list.append(5);
    list.append(3);
    list.insert(7, 0);
    list.insert(10, 3);
    list.insert(30, 5);
    list.remove(4);
    list.remove(30);
    list.remove(7);
    list.print();
    cout << "Llamada a Count(): " << endl;
    cout << "Las veces que aparece el número buscado son: " << list.Count(7) << endl;
    cout << "Llamada a SortedInsert(): " << endl;
    list.SortedInsert(2);
    list.print();
    cout << "Llamada a removeDuplicates: " << endl;
    list.removeDuplicates();
    list.print();
    cout << "Llamada a reverse(): " << endl;
    list.reverse();
    list.print();
    cout << "Llamada a deleteList(): " << endl;
    list.deleteList();
    list.print();

    return 0;
}
