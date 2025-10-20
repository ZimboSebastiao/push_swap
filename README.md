# Push Swap

<div align="center">

![Push Swap](https://img.shields.io/badge/42-São_Paulo-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/C-100%25-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

**Um algoritmo eficiente para ordenação usando duas pilhas**

[Instalação](#instalação) • [Uso](#uso) • [Benchmark](#benchmark) • [Testes](#testes)

</div>

## Sobre o Projeto

O **Push Swap** é um projeto da 42 São Paulo que desafia os estudantes a implementar um algoritmo de ordenação altamente eficiente utilizando apenas duas pilhas e um conjunto limitado de operações.

### Objetivo
Ordenar uma sequência de números inteiros distintos na pilha **A** em ordem crescente, utilizando o menor número possível de operações pré-definidas.

## Estrutura do Projeto

```
push_swap/
├── src/           # Código fonte
├── includes/      # Headers
├── test/  		   # Testes
├── libft1/        # Biblioteca personalizada
├── Makefile       # Sistema de build
└── checker_linux  # Validador externo
```

## Operações Disponíveis

### 🔄 Operações de Swap
| Operação | Descrição |
|----------|-----------|
| `sa` | Swap A - Troca os dois primeiros elementos da pilha A |
| `sb` | Swap B - Troca os dois primeiros elementos da pilha B |
| `ss` | Executa `sa` e `sb` simultaneamente |

### 📤 Operações de Push
| Operação | Descrição |
|----------|-----------|
| `pa` | Push A - Move o topo da pilha B para o topo da pilha A |
| `pb` | Push B - Move o topo da pilha A para o topo da pilha B |

### 🔄 Operações de Rotação
| Operação | Descrição |
|----------|-----------|
| `ra` | Rotate A - Todos os elementos da pilha A sobem uma posição |
| `rb` | Rotate B - Todos os elementos da pilha B sobem uma posição |
| `rr` | Executa `ra` e `rb` simultaneamente |

### 🔁 Operações de Rotação Reversa
| Operação | Descrição |
|----------|-----------|
| `rra` | Reverse Rotate A - Todos os elementos da pilha A descem uma posição |
| `rrb` | Reverse Rotate B - Todos os elementos da pilha B descem uma posição |
| `rrr` | Executa `rra` e `rrb` simultaneamente |

## Instalação

### Pré-requisitos
```bash
sudo apt update
sudo apt install gcc make ruby
```

### Clone e Compilação
```bash
# Clonar o repositório
git clone https://github.com/ZimboSebastiao/push_swap.git
cd push_swap

# Compilar o projeto
make

# Dar permissão ao validador
chmod +x checker_linux
```

## Comandos Make

| Comando | Descrição |
|---------|-----------|
| `make` | Compila o projeto |
| `make clean` | Remove arquivos objeto |
| `make fclean` | Remove arquivos objeto e executáveis |
| `make re` | Recompila o projeto |
| `make check` | Executa suite de testes automatizados |
| `make help` | Exibe ajuda dos comandos disponíveis |

## Uso

### Execução Básica
```bash
./push_swap [números]
```

### Exemplos
```bash
# Ordenar números específicos
./push_swap 3 1 4 2 5

# Ordenar com números negativos
./push_swap -5 10 -2 7 0
```

## Testes

### Testes Automatizados
```bash
# Executar suite completa de testes
make check
```

### Validação da Ordenação
```bash
# Gerar sequência aleatória e validar
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
./push_swap $ARG | ./checker_linux $ARG
```

### Teste de Performance
```bash
# Teste com 100 números
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
./push_swap $ARG | wc -l

# Teste com 500 números
ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
./push_swap $ARG | wc -l
```

## 📊 Benchmark

### Teste Específico de Performance
```bash
# Teste com sequência específica de 100 números
arg="795810 464593 787015 7024 623056 734594 -66964 877081 -52513 563151 408854 440758 939138 928252 968216 196709 321579 479839 376620 136893 318513 327838 648853 554227 583602 891314 871381 171491 861292 862744 111576 480571 6125 786428 194231 842440 302939 916945 164091 735976 752345 411248 187116 -72660 347651 129000 610282 684675 540462 729646 578480 524229 367109 278296 178265 758555 685876 996129 428943 917055 717675 -19224 579050 243554 98384 963965 -61309 445438 604516 -71206 600418 51272 701015 923294 505644 -92226 477967 869059 444070 694427 658307 145844 71750 732166 925113 617861 940631 906268 709493 570693 263993 573317 863239 556088 326095 612973 346345 955583 205672 -25421";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

# Teste com sequência específica de 500 números
arg="496284 550907 359740 487595 965200 776929 -61518 172851 753920 696601 68987 912798 425872 605030 193176 551941 78259 104789 603498 202197 989458 765277 756603 408217 167687 953098 571835 622038 707304 -75679 473630 461265 979236 325122 149570 468276 271723 571385 -1078 689959 -81940 941711 301867 929620 216640 -52797 961411 32959 -21602 631722 709067 157371 985122 313761 386385 858705 883251 120125 740664 499262 983493 790136 91357 353691 -11140 670972 853183 179855 -31999 18633 737082 94339 449087 -87119 577472 838399 464454 396155 -86178 780758 496376 357015 986062 807346 5040 742581 897355 12824 34052 657118 980650 657145 435166 594259 792418 972013 602419 494548 341365 803924 811457 27914 816101 600463 287425 589831 433898 865248 606341 443197 118484 217895 570262 768037 971230 694940 633127 27083 75158 27124 645039 994872 361497 6997 80593 645898 407000 958362 59034 919876 383709 113339 901595 361739 687053 35881 40315 939097 324262 80790 550783 951605 737924 903217 -50063 515747 517579 116492 687682 357079 658130 39967 -8498 161101 -70071 319968 25729 16377 611340 160790 908754 584973 557042 57820 428484 662899 599760 361918 952427 88773 367355 251317 527181 371058 401901 494002 382724 -55331 -52689 888733 325157 522446 -31588 949809 232117 356258 887875 901653 494665 679838 894341 255387 703208 35138 336812 741163 -83423 653517 836767 478328 290079 392042 968196 657253 501619 711833 247431 896320 288347 320975 230356 563032 610113 513588 451110 -66054 429645 739836 -36619 98075 570586 684861 -24947 977017 923800 889144 480762 120913 209636 836371 475563 374742 304162 483363 812291 144591 835418 -5393 227977 -57290 334221 554122 412147 -15979 884808 963701 158972 561353 268295 327084 951021 814685 857614 37466 619794 483016 639218 782757 233803 663181 666377 364194 362508 938833 237140 694479 742859 762165 433009 416627 301199 -98527 994105 860677 68448 562263 510798 474071 640061 529383 236411 221429 74548 760026 719059 822945 614493 497990 964979 655846 -54835 723165 448472 228766 817749 469287 577282 786440 917310 852269 908528 904969 830526 548897 171775 756538 376236 527279 667020 590398 68898 657546 81365 453421 400189 845349 219270 659027 252649 431535 -86370 528243 703464 471923 227410 615089 203269 967954 278143 -79428 675406 63923 152753 24757 454161 30730 548158 728289 773350 480809 80969 791854 117312 487290 256025 882450 608441 968936 282847 767606 -98707 222870 420981 595691 -55747 552249 161664 160660 726450 660358 375607 -4570 76883 102235 -39966 729536 968921 552551 496434 104536 202567 67492 759589 260665 966561 590218 615664 399344 688405 736692 373388 -91382 708649 753605 887375 788476 640290 740496 555182 978779 315526 756985 747919 477825 92297 -56585 472381 602673 48382 99403 364018 251146 158126 69426 500711 334569 189064 289793 14444 97477 499121 892238 628984 571176 577156 690692 124773 691597 724038 -40715 725700 178992 449794 277614 737336 668731 480240 977693 960486 2378 349832 687554 880541 562279 481085 579032 -48027 -17686 742248 459974 -43929 545280 892470 -31242 877019 494154 771569 332582 838133 923970 610754 -57434 589126 241592 928310 156653 680713 668193 916147 170975 769985 902997 305575 541603 668281 82015 820137 863686 502457 169353 515023 889358 785742 788602 763099 721142 691712 674251 340208 179006 -81990 462561 447108 559948 763353 644352 604106 928173 88110 524383 933626 419652 695232 433821 -68404 97387 790996 873411 -65542 505268";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

```

### Métricas de Referência
| Quantidade | Operações Máximas | Status |
|------------|-------------------|---------|
| 3 números | 3 operações | ✅ |
| 5 números | 12 operações | ✅ |
| 100 números | ~700 operações | ✅ |
| 500 números | ~5500 operações | ✅ |

## 🔍 Verificação de Qualidade

### Teste com Valgrind
```bash
# Verificar memory leaks
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
valgrind --leak-check=full ./push_swap $ARG
```

### Validação de Entrada
```bash
# Verificar números duplicados
./push_swap 1 2 3 2  # ❌ Erro: números duplicados

# Verificar entradas inválidas  
./push_swap 1 2 "abc"  # ❌ Erro: entrada inválida
```

## Fluxo do Algoritmo

![Diagrama do Fluxo](/imgs/Fluxo%20principal.svg)

###  Estratégia Medium Sort (Chunking)

![Diagrama do Fluxo](/imgs/Medium%20Sort(Chunking).svg)



## Solução de Problemas

### Problemas Comuns

**Checker não executa:**
```bash
chmod +x checker_linux
```

**Erro de números duplicados:**
```bash
# ❌ Incorreto
./push_swap 1 2 3 2

# ✅ Correto  
./push_swap 1 2 3 4
```

**Erro de entrada inválida:**
```bash
# ❌ Incorreto
./push_swap 1 2 "abc"

# ✅ Correto
./push_swap 1 2 3
```

### Debug
```bash
# Compilar com flags de debug
make DEBUG=1

# Executar com output detalhado
./push_swap 3 2 1
```

## 🤝 Contribuindo

1. Fork o projeto
2. Crie uma branch para sua feature (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

## Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para detalhes.

## Autora

**Zimbo Sebastião** - 42 São Paulo

<div align="center">

**⭐️ Não esqueça de dar uma estrela se este projeto te ajudou!**

</div>