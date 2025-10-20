# Projeto **Push Swap** 42 São Paulo

## Descrição

O projeto **Push Swap** consiste na implementação de um algoritmo eficiente para ordenar uma sequência de números inteiros distintos utilizando duas pilhas (**A** e **B**) e um conjunto limitado de operações.

**Objetivo**: Ordenar os números da pilha **A** em ordem crescente (do menor para o maior) utilizando o menor número possível de operações.

---

## Operações Disponíveis

### Operações Básicas
- **`sa`** (swap a): Troca os dois primeiros elementos do topo da pilha **A**
- **`sb`** (swap b): Troca os dois primeiros elementos do topo da pilha **B**
- **`ss`**: Executa `sa` e `sb` simultaneamente

### Operações de Transferência
- **`pa`** (push a): Move o elemento do topo da pilha **B** para o topo da pilha **A**
- **`pb`** (push b): Move o elemento do topo da pilha **A** para o topo da pilha **B**

### Operações de Rotação
- **`ra`** (rotate a): Desloca todos os elementos da pilha **A** para cima (o primeiro vai para o final)
- **`rb`** (rotate b): Desloca todos os elementos da pilha **B** para cima (o primeiro vai para o final)
- **`rr`**: Executa `ra` e `rb` simultaneamente

### Operações de Rotação Reversa
- **`rra`** (reverse rotate a): Desloca todos os elementos da pilha **A** para baixo (o último vai para o topo)
- **`rrb`** (reverse rotate b): Desloca todos os elementos da pilha **B** para baixo (o último vai para o topo)
- **`rrr`**: Executa `rra` e `rrb` simultaneamente

---

## Instalação e Execução

### 1. Clonar o Repositório
```bash
git clone https://github.com/ZimboSebastiao/push_swap.git
cd push_swap
```

### 2. Compilar o Projeto
```bash
make
```

### 3. Opções de Compilação
```bash
make help    # Exibe todas as opções disponíveis
make clean   # Remove arquivos objetos
make fclean  # Remove arquivos objetos e executáveis
make re      # Recompila o projeto
make check   # Executa testes automatizados (requer checker_linux)
```

### 4. Executar o Programa
```bash
./push_swap [sequência de números]
```

**Exemplo:**
```bash
./push_swap 3 1 4 2 5
```

---

## 📊 Benchmark - Medindo Desempenho

### Pré-requisitos
```bash
sudo apt install ruby
```

### Preparar o Checker
```bash
# Autorizar o executável do checker
chmod +x checker_linux
```

### Testar com Sequência Aleatória
```bash
# Para 100 números
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

# Para 500 números  
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
```

### Testes de Benchmark Específicos
```bash
# Teste com sequência específica de 100 números
arg="795810 464593 787015 7024 623056 734594 -66964 877081 -52513 563151 408854 440758 939138 928252 968216 196709 321579 479839 376620 136893 318513 327838 648853 554227 583602 891314 871381 171491 861292 862744 111576 480571 6125 786428 194231 842440 302939 916945 164091 735976 752345 411248 187116 -72660 347651 129000 610282 684675 540462 729646 578480 524229 367109 278296 178265 758555 685876 996129 428943 917055 717675 -19224 579050 243554 98384 963965 -61309 445438 604516 -71206 600418 51272 701015 923294 505644 -92226 477967 869059 444070 694427 658307 145844 71750 732166 925113 617861 940631 906268 709493 570693 263993 573317 863239 556088 326095 612973 346345 955583 205672 -25421";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

# Teste com sequência específica de 500 números
arg="496284 550907 359740 487595 965200 776929 -61518 172851 753920 696601 68987 912798 425872 605030 193176 551941 78259 104789 603498 202197 989458 765277 756603 408217 167687 953098 571835 622038 707304 -75679 473630 461265 979236 325122 149570 468276 271723 571385 -1078 689959 -81940 941711 301867 929620 216640 -52797 961411 32959 -21602 631722 709067 157371 985122 313761 386385 858705 883251 120125 740664 499262 983493 790136 91357 353691 -11140 670972 853183 179855 -31999 18633 737082 94339 449087 -87119 577472 838399 464454 396155 -86178 780758 496376 357015 986062 807346 5040 742581 897355 12824 34052 657118 980650 657145 435166 594259 792418 972013 602419 494548 341365 803924 811457 27914 816101 600463 287425 589831 433898 865248 606341 443197 118484 217895 570262 768037 971230 694940 633127 27083 75158 27124 645039 994872 361497 6997 80593 645898 407000 958362 59034 919876 383709 113339 901595 361739 687053 35881 40315 939097 324262 80790 550783 951605 737924 903217 -50063 515747 517579 116492 687682 357079 658130 39967 -8498 161101 -70071 319968 25729 16377 611340 160790 908754 584973 557042 57820 428484 662899 599760 361918 952427 88773 367355 251317 527181 371058 401901 494002 382724 -55331 -52689 888733 325157 522446 -31588 949809 232117 356258 887875 901653 494665 679838 894341 255387 703208 35138 336812 741163 -83423 653517 836767 478328 290079 392042 968196 657253 501619 711833 247431 896320 288347 320975 230356 563032 610113 513588 451110 -66054 429645 739836 -36619 98075 570586 684861 -24947 977017 923800 889144 480762 120913 209636 836371 475563 374742 304162 483363 812291 144591 835418 -5393 227977 -57290 334221 554122 412147 -15979 884808 963701 158972 561353 268295 327084 951021 814685 857614 37466 619794 483016 639218 782757 233803 663181 666377 364194 362508 938833 237140 694479 742859 762165 433009 416627 301199 -98527 994105 860677 68448 562263 510798 474071 640061 529383 236411 221429 74548 760026 719059 822945 614493 497990 964979 655846 -54835 723165 448472 228766 817749 469287 577282 786440 917310 852269 908528 904969 830526 548897 171775 756538 376236 527279 667020 590398 68898 657546 81365 453421 400189 845349 219270 659027 252649 431535 -86370 528243 703464 471923 227410 615089 203269 967954 278143 -79428 675406 63923 152753 24757 454161 30730 548158 728289 773350 480809 80969 791854 117312 487290 256025 882450 608441 968936 282847 767606 -98707 222870 420981 595691 -55747 552249 161664 160660 726450 660358 375607 -4570 76883 102235 -39966 729536 968921 552551 496434 104536 202567 67492 759589 260665 966561 590218 615664 399344 688405 736692 373388 -91382 708649 753605 887375 788476 640290 740496 555182 978779 315526 756985 747919 477825 92297 -56585 472381 602673 48382 99403 364018 251146 158126 69426 500711 334569 189064 289793 14444 97477 499121 892238 628984 571176 577156 690692 124773 691597 724038 -40715 725700 178992 449794 277614 737336 668731 480240 977693 960486 2378 349832 687554 880541 562279 481085 579032 -48027 -17686 742248 459974 -43929 545280 892470 -31242 877019 494154 771569 332582 838133 923970 610754 -57434 589126 241592 928310 156653 680713 668193 916147 170975 769985 902997 305575 541603 668281 82015 820137 863686 502457 169353 515023 889358 785742 788602 763099 721142 691712 674251 340208 179006 -81990 462561 447108 559948 763353 644352 604106 928173 88110 524383 933626 419652 695232 433821 -68404 97387 790996 873411 -65542 505268";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

```

### Testes de Validação
```bash
# Validar se a ordenação está correta
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG

# Contar operações e validar
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l && ./push_swap $ARG | ./checker_linux $ARG
```

---

## 📈 Fluxo de Checagem de Erros

![Diagrama do Fluxo](/imgs/flow3.svg)

---

## Critérios de Avaliação

- **Eficiência**: Número de operações executadas
- **Corretude**: Sequência final ordenada corretamente
- **Performance**: Tempo de execução para diferentes tamanhos de entrada

### Limites de Referência
- **100 números**: Idealmente menos de 700 operações
- **500 números**: Idealmente menos de 5500 operações

---

## Testes Automatizados

### Usando make check
```bash
make check  # Executa uma série de testes pré-definidos
```

### Teste Manual Completo
```bash
# Teste com contagem de operações e validação
echo "=== TESTE DE PERFORMANCE ==="
arg="703122 594407 690128 454899 221321 77718 568728 -52969 215758 121011 169575 975364 823381 594008 871717 620108 380708 159117 394600 468189 -59365 263780 259748 250560 511019 -1433 988325 861914 -19340 369794 698469 328899 140665 192324 175807 388755 41978 826985 255648 813683 609988 389558 648920 693754 153814 972589 -85892 675751 492600 993905 728008 69817 370298 739001 657262 203961 957431 637499 518108 646538 87397 184901 454455 128332 961975 15286 197215 923901 577458 -55634 637771 96538 445042 584511 62723 847202 38790 265402 -54565 182725 195091 416408 695351 383933 496941 983289 34632 987038 738894 158850 925320 317534 998659 481781 904108 241958 202258 598966 216396 2855"

echo "Resultado:"
./push_swap $arg | ./checker_linux $arg
echo "Número de operações:"
./push_swap $arg | wc -l
```

---

## Solução de Problemas

### Erro Comuns
- **Números duplicados**: Certifique-se que todos os números são distintos
- **Valores fora do range**: Verifique se todos os números são inteiros válidos
- **Memory leaks**: Use `valgrind` para verificar vazamentos de memória

### Verificação com Valgrind
```bash
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG
```

### Problemas com o Checker
```bash
# Se o checker_linux não executar:
chmod +x checker_linux

# Verificar se é executável:
ls -la checker_linux
```

---

## Notas

- O programa deve lidar com qualquer sequência de números inteiros distintos
- A pilha **A** é inicializada com os números fornecidos como argumento
- A pilha **B** inicia vazia
- O resultado é uma sequência de operações que ordena a pilha **A**
- Use `make check` para testes rápidos e automatizados
- O teste de benchmark específico ajuda a comparar performance entre diferentes implementações

---

**Dica**: Para desenvolvimento, use frequentemente `make check` e os testes de benchmark para garantir que otimizações não quebrem a funcionalidade existente.