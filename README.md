# Projeto **Push Swap**

O projeto **Push Swap** consiste na implementação de um programa capaz de ordenar uma sequência de números inteiros contidos na pilha **A**, de forma crescente, utilizando um conjunto limitado de operações pré-definidas.

## Fluxo Padrão do Programa

Quando criamos um novo arquivo ou pasta no computador, eles são armazenados de forma permanente no disco rígido (**Hard Disk**).
Da mesma forma, ao compilarmos um programa escrito em **C**, o compilador gera um **arquivo binário executável**. O nome e a extensão desse arquivo variam conforme o sistema operacional utilizado:

* No **Linux**, o nome padrão costuma ser **a.out**;
* No **Windows**, o executável é gerado com a extensão **.exe**.

Ao executarmos esse binário, o sistema operacional **carrega uma cópia do programa na memória RAM**, onde ele será executado.
A RAM, então, **estabelece uma comunicação direta com o processador (CPU)**, enviando instruções uma por vez para o **cache da CPU**, de modo que o processamento ocorra com **maior eficiência**.
Esse processo permite que as instruções sejam executadas rapidamente, aproveitando o acesso de alta velocidade entre CPU e memória.

![diagrama 1](/imgs/flow1.svg)

## Armazenamento e Alocação de Memória

A **memória RAM** (memória primária) é dividida em quatro regiões principais, cada uma com uma função específica na execução de programas:

### 1. **Heap**

A **Heap** é a região da memória utilizada para **alocação dinâmica**.
Em **C**, essa alocação é realizada por meio das funções `malloc()`, `calloc()` e `realloc()`.

Sempre que alocamos memória dinamicamente, **somos responsáveis por liberá-la manualmente**, a fim de evitar **vazamento de memória (memory leak)**.
A liberação é feita com a função `free()`.


### 2. **Stack**

A **Stack** (pilha) é a região onde são armazenadas as **funções, variáveis locais e parâmetros** enquanto o programa está sendo executado.

Quando o programa é iniciado, a função `main()` é colocada na stack.
Sempre que ocorre uma **chamada de função**, é criado um **quadro de ativação (stack frame)** sobre o anterior, contendo as variáveis e dados locais da nova função.

Por exemplo:

* Quando a `main()` chama a função **A**, um novo *frame* é criado sobre a `main`.
* Se **A** chamar a função **B**, a execução de **A** é temporariamente pausada, e um novo *frame* é adicionado no topo da stack para **B**.
* Ao término de **B**, seu *frame* é removido, liberando todos os dados ali armazenados, e a execução de **A** é retomada.
* Esse processo continua de forma hierárquica e controlada.

![diagrama 4](/imgs/flow4.svg)

> ⚠️ Mesmo quando há **alocação dinâmica** (na *heap*), o **ponteiro que referencia** a área alocada **é armazenado na stack**, junto com as demais variáveis da função.


### 3. **Data Segment (Segmento de Dados)**

Essa região é responsável por armazenar **variáveis globais e estáticas**.
Ela é dividida em duas partes:

* **Data Segment Inicializado:** contém variáveis globais e estáticas com valores inicializados explicitamente no código.
* **BSS (Block Started by Symbol):** armazena variáveis globais e estáticas **não inicializadas** (que recebem zero por padrão).


### 4. **Text Segment (Segmento de Código)**

O **Text Segment** é onde fica armazenado o **código executável do programa**, ou seja, as **instruções compiladas em linguagem de máquina**.
Essa região geralmente é marcada como **somente leitura**, para impedir modificações acidentais do código durante a execução.

![diagrama 2](/imgs/flow2.svg)


## Operações Disponíveis

O programa pode manipular as pilhas **A** e **B** através das seguintes operações:

1. **sa (swap a):** troca os dois primeiros elementos no topo da pilha **A**.
2. **sb (swap b):** troca os dois primeiros elementos no topo da pilha **B**.
3. **ss (sa + sb):** executa **sa** e **sb** simultaneamente.
4. **pa (push a):** move o primeiro elemento do topo da pilha **B** para o topo da pilha **A**.
5. **pb (push b):** move o primeiro elemento do topo da pilha **A** para o topo da pilha **B**.
6. **ra (rotate a):** desloca todos os elementos da pilha **A** uma posição para cima — o primeiro elemento vai para o final.
7. **rb (rotate b):** desloca todos os elementos da pilha **B** uma posição para cima — o primeiro elemento vai para o final.
8. **rr (ra + rb):** executa **ra** e **rb** simultaneamente.
9. **rra (reverse rotate a):** desloca todos os elementos da pilha **A** uma posição para baixo — o último elemento vai para o topo.
10. **rrb (reverse rotate b):** desloca todos os elementos da pilha **B** uma posição para baixo — o último elemento vai para o topo.
11. **rrr (rra + rrb):** executa **rra** e **rrb** simultaneamente.


## Função `validator.c`

O arquivo **`validator.c`** é responsável por **validar as entradas fornecidas pelo usuário**, assegurando que apenas dados corretos e coerentes sejam processados pelo programa.
Essa etapa é essencial para evitar comportamentos inesperados, *segmentation faults* e resultados incorretos durante a ordenação.

A função impede o processamento de:

* Entradas **vazias** (menos de dois argumentos na linha de comando);
* Valores **não inteiros** ou **inválidos**;
* Números **fora do intervalo permitido para o tipo `int`** (menores que `-2147483648` ou maiores que `2147483647`);
* **Valores duplicados** entre os argumentos fornecidos.


### Estrutura do Arquivo

Dentro do arquivo `validator.c`, foram implementadas **cinco funções auxiliares**, que correspondem ao limite permitido pela *Norma da 42*.
Cada uma delas desempenha uma etapa específica do processo de validação:

```c
int	ft_is_overflow(int argc, char **argv);
int	ft_duplicate(int argc, char **argv);
int	ft_check_int(int argc, char **argv);
int	ft_empty(int argc);
int	ft_overflow_str(const char *num, const char *max);
```

![diagrama 3](/imgs/flow3.svg)