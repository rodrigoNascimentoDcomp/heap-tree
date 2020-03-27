#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *array;
    int n;
} heap;

// Cria heap.
heap* criar(int *a, int n) {
    heap* h = (heap*) malloc(sizeof(heap));
    h->array = a;
    h->n = n;
    return h;
}

// Troca dois elementos.
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Imprime array a de tamanho n.
void print(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

// Retorna o indice do no raiz de i.
int raiz(int i) {
    return (i - 1) / 2;
}

// Retorna o indice do no da esquerda de i.
int esquerda(int i) {
    return 2 * i + 1;
}

// Retorna o indice do no da direita de i.
int direita(int i) {
    return 2 * i + 2;
}

// Retorna o indice do ultimo no raiz do
// array de tamanho n.
int ultima_raiz(int n) {
    return ((n - 1) - 1) / 2;
}

// Gera heap maximo a partir da raiz i
// do array a de tamanho n.
void heapify_max(int *a, int i, int n) {
    int max = i;
    int left = esquerda(i);
    int right = direita(i);

    // Verifica se o indice da esquerda
    // esta dentro do intervalo de tamanho
    // do array
    if (left < n)
        // Compara o no raiz com a esquerda e,
        // caso o segundo seja maior, salva
        // seu indice
        if (a[left] > a[max])
            max = left;

    // Repete a operacao anterior comparando
    // o maior elemento com o elemento da direita.
    if (right < n)
        if (a[right] > a[max])
            max = right;

    // Se o indice do elemento de maior valor
    // for diferente da raiz, troca os dois
    if (max != i) {
        trocar(&a[max], &a[i]);
        heapify_max(a, max, n);
    }
}

// Gera heap minimo a partir da raiz i
// do array a de tamanho n.
void heapify_min(int *a, int i, int n) {
    int min = i;
    int left = esquerda(i);
    int right = direita(i);

    // Verifica se o indice da esquerda
    // esta dentro do intervalo de tamanho
    // do array
    if (left < n)
        // Compara o no raiz com a esquerda e,
        // caso o segundo seja menor, salva
        // seu indice
        if (a[left] < a[min])
            min = left;

    // Repete a operacao anterior comparando
    // o menor elemento com o elemento da direita.
    if (right < n)
        if (a[right] < a[min])
            min = right;

    // Se o indice do elemento de menor valor
    // for diferente da raiz, troca os dois
    if (min != i) {
        trocar(&a[min], &a[i]);
        heapify_min(a, min, n);
    }
}

// Substitui o no na primeira posicao pelo ultimo
// e remove o ultimo de heap maximo.
int remover_max(heap *h) {
    int aux = h->array[0];
    h->array[0] = h->array[h->n-1];
    if (h->n > 0)
        h->n--;
    
    // Pega indice da ultima raiz
    int lr = ultima_raiz(h->n);
    // Aplica heapify em todas as raizes
    // a partir da ultima
    for (int i = lr; i >= 0; i--)
        heapify_max(h->array, i, h->n);
    
    return aux;
}

// Substitui o no na primeira posicao pelo ultimo
// e remove o ultimo de heap minimo.
int remover_min(heap *h) {
    int aux = h->array[0];
    h->array[0] = h->array[h->n-1];
    if (h->n > 0)
        h->n--;
    
    // Pega indice da ultima raiz
    int lr = ultima_raiz(h->n);
    // Aplica heapify em todas as raizes
    // a partir da ultima
    for (int i = lr; i >= 0; i--)
        heapify_min(h->array, i, h->n);
    
    return aux;
}

// Insere elemento em heap maximo.
void inserir_max(heap *h, int i) {
    h->array[h->n] = i;
    h->n++;
    
    // Pega indice da ultima raiz
    int lr = ultima_raiz(h->n);
    // Aplica heapify em todas as raizes
    // a partir da ultima
    for (int i = lr; i >= 0; i--)
        heapify_max(h->array, i, h->n);
}

// Insere elemento em heap minimo.
void inserir_min(heap *h, int i) {
    h->array[h->n] = i;
    h->n++;
    
    // Pega indice da ultima raiz
    int lr = ultima_raiz(h->n);
    // Aplica heapify em todas as raizes
    // a partir da ultima
    for (int i = lr; i >= 0; i--)
        heapify_min(h->array, i, h->n);
}

int main()
{
    // Cria array
    int a[] = { 3, 2, 1, 0 };
    // Cria heap
    heap *h;
    h = criar(a, sizeof(a) / sizeof(a[0]));
    // Pega indice da ultima raiz
    int lr = ultima_raiz(h->n);
    // Aplica heapify em todas as raizes
    // a partir da ultima
    for (int i = lr; i >= 0; i--)
        heapify_min(h->array, i, h->n);
    
    print(h->array, h->n);
    printf("\n");
    
    // Remove raiz do heap
    int u = remover_min(h);
        
    print(h->array, h->n);
    printf("\n");
    
    // Insere no heap
    inserir_min(h, -1);
    print(h->array, h->n);

    return 0;
}
