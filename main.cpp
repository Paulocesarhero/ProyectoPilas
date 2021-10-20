#include <iostream>
using namespace std;
class Nodo {// un nodo se conforma un dato y una apuntador de tipo nodo
    char dato;
    Nodo *sig;
public:
    Nodo();

    void setDato(char x);

    void setSig(Nodo *Sig);

    char getDato();

    Nodo *getSig();

};

Nodo::Nodo() { //Inicializar los datos
    dato = '\0';
    sig = NULL;
}

void Nodo::setDato(char x) {
    this->dato = x;
}

void Nodo::setSig(Nodo *sig) {
    this->sig = sig;
}

char Nodo::getDato() {
    return dato;
}

Nodo *Nodo::getSig() {
    return sig;
}
class Pila{
    Nodo *tope;
public:
    Pila();
    ~Pila();
    int estaVacia();
    char getDato();
    void push(char x);
    void pop();
    //complementarios
    void mostrar();
    //...
    void signosDeAgrupacion();

    void signosDeAgrupacion(string cadena);
};
Pila::Pila() {
    this->tope = NULL;
}
int Pila::estaVacia() {
    return tope == NULL;
}
char Pila::getDato() {
    if (estaVacia()){
        cout<<"Error pila vacia get dato";
        return -1;
    }
    return tope->getDato();

}
void Pila::push(char x) {
    Nodo * p = new Nodo();
    p->setDato(x);
    p->setSig(tope);
    tope = p;
}
void Pila::pop() {
    if (tope != NULL){
        Nodo *p;
        p = tope;
        tope = p->getSig();
        delete p;
    }
}
Pila::~Pila() {
    while (!estaVacia()){
        pop();
    }
}
void Pila::mostrar() {
    cout<<"Tope->";
    Pila paux;
    while (!estaVacia()){
        paux.push(getDato());
        cout<<getDato()<<"->";
        pop();
    }
    while (!paux.estaVacia()){
        push(paux.getDato());
        paux.pop();
    }
    cout<<"NULL";
}
void Pila::signosDeAgrupacion(string cadena){

    for (int i = 0; cadena[i] != '\0' ; ++i) {
        if (cadena[i] == '(' || cadena[i] == '[' || cadena [i] == '{'){
            push(cadena[i]);
        }
        else if (cadena[i] == ')' || cadena [i] == '}' || cadena[i] == ']'){
            if (!estaVacia()){
                if (cadena [i] == ')' && getDato() == '('){
                    pop();
                } else if (cadena [i] == '}' && getDato() == '{'){
                    pop();
                } else if (cadena [i] == ']' && getDato() == '['){
                    pop();
                }
            } else push(cadena[i]);
        }
    }
    if (!estaVacia()){
        cout<<"Falto cerrar el "<<getDato();
    } else
        cout<<"Todo correcto";

}

int main() {
    string cadena;
    Pila MainPila;
    cout<<"Inserte una cadena de caracteres\n";
    cin>>cadena;

//    MainPila.mostrar();
    MainPila.signosDeAgrupacion(cadena);

    return 0;
}
