# Projeto **Push Swap**

O projeto **Push Swap** consiste na implementação de um programa capaz de ordenar uma sequência de números inteiros contidos na pilha **A**, de forma crescente, utilizando um conjunto limitado de operações pré-definidas.



## Fluxo Padrão do Programa

Quando criamos um novo arquivo ou pasta no computador, eles são armazenados de forma permanente no disco rígido (**Hard Disk**).
Da mesma forma, ao compilarmos um programa escrito em **C**, o compilador gera um **arquivo binário executável**. O nome e a extensão desse arquivo variam conforme o sistema operacional utilizado:

* No **Linux**, o nome padrão costuma ser **a.out**;
* No **Windows**, o executável é gerado com a extensão **.exe**.

Ao executarmos esse binário, o sistema operacional **carrega uma cópia do programa na memória RAM**, onde ele será executado.
A RAM, então, **estabelece uma comunicação direta com o processador (CPU)**, enviando instruções — uma por vez — para o **cache da CPU**, de modo que o processamento ocorra com **maior eficiência**.
Esse processo permite que as instruções sejam executadas rapidamente, aproveitando o acesso de alta velocidade entre CPU e memória.

![diagrama 1](/imgs/flow1.svg)


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


