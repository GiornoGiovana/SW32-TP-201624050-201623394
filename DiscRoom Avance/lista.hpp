#ifndef __LISTAS_H__
#define __LISTAS_H__

template <class T>
struct Nodo {
	T elemento;
	Nodo<T>* next;

	Nodo(T elemento = 0, Nodo<T> * next = nullptr) : elemento(elemento), next(next) {}
};

template <class T>
class Lista {
public:
	class Iterador {
		Nodo<T>* nodo;
	public:
		Iterador(Nodo<T>* nodo) : nodo(nodo) {}
		void operator ++() {
			nodo = nodo->next;
		}
		T operator *() {
			return nodo->elemento;
		}
		bool operator != (Iterador it) {
			return nodo != it.nodo;
		}
	};
private:
	int ne;
	Nodo<T>* inicio;
public:
	Lista() {
		ne = 0;
		inicio = nullptr;
	}
	~Lista() {
		while (eliminarInicio());
	}
	Iterador itInico() {
		return Iterador(inicio);
	}
	Iterador itFin() {
		return Iterador(nullptr);
	}
	int getNe() {
		return ne;
	}
	bool agregarInicio(T elemento) {
		Nodo<T>* nuevo = new Nodo<T>(elemento, inicio);
		if (nuevo == nullptr) return false;
		inicio = nuevo;
		++ne;
		return true;
	}
	bool eliminarInicio() {
		Nodo<T>* aux;
		if (inicio != nullptr) {
			aux = inicio;
			inicio = inicio->next;
			delete aux;
			--ne;
			return true;
		}
		return false;
	}
	T buscar(T elemento) {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < ne; ++i) {
			if (aux->elemento == elemento) {
				return aux->elemento;
			}
			aux = aux->next;
		}
		return 0;
	}
	int buscarPos(T elemento) {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < ne; ++i) {
			if (aux->elemento == elemento) {
				return i;
			}
			aux = aux->next;
		}
		return -1;
	}
	T elementoEnPosicion(int pos) {
		// if (pos < 0 || pos >= ne) return nullptr;
		Nodo<T>* aux = inicio;
		for (int i = 0; i < pos; ++i) {
			aux = aux->next;
		}
		return aux->elemento;
	}
	bool insertar(T elemento, int pos) {
		if (pos < 0 || pos > ne) return false;
		if (pos == 0) return agregarInicio(elemento);
		Nodo<T>* aux = inicio;
		for (int i = 1; i < pos; ++i) {
			aux = aux->next;
		}
		Nodo<T>* nuevo = new Nodo<T>(elemento, aux->next);
		if (nuevo == nullptr) return false;
		aux->next = nuevo;
		++ne;
		return true;
	}
	bool eliminar(int pos) {
		if (pos < 0 || pos >= ne) return false;
		if (pos == 0) {
			return eliminarInicio();
		}
		Nodo<T>* aux = inicio;
		for (int i = 1; i < pos; ++i) {
			aux = aux->next;
		}
		Nodo<T>* aux2 = aux->next;
		aux->next = aux2->next;
		delete aux2;
		--ne;
		return true;
	}
};

#endif