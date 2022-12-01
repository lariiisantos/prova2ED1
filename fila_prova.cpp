#include <stdio.h>

typedef int dado;

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

/*
        empty = testa se a lista está vazia ou não
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

struct Fila {

    Node *cabeca, *cauda;
    int size;

    Fila() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* enqueue(dado valor) { //O(1) - push back
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* dequeue() { //O(1) -- pop front
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    dado front() {
        if (!empty()) {
            return cabeca->valor;
        } else {
            return NULL;
        }
    }
};

struct Pilha {

    int j;

    Pilha() {
    j = 0;
    }

    bool empty() {
    return (j == 0);
    }

    int size() {
    return j;
    }

    void pop() {
        if (j <= 0) {
            printf("Pilha vazia\n");
        } else {
       j--;
        }
    }

    dado top() {
        if (j <= 0) {
            printf("Pilha vazia\n");
            return NULL;
        } else {
            return j;
        }
    }
};

    void ReverseQueue() {
        for (int i = 1; i < size; i++) {
            pop_front();
            push_back();
            cauda->prox = cabeca;
            cabeca->prox = cauda;
        }
        return size;
    }

int main() {

    Fila f;
    Pilha p;

    f.enqueue(2);
    f.enqueue(8);
    f.enqueue(7);

    printf("%d\n", f.front());

    f.dequeue();

    printf("%d\n", f.front());

    f.dequeue();

    printf("%d\n", f.front());

    f.popFront();
    f.pushBack();

    return 0;
}
