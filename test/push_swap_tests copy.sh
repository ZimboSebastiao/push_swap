#!/bin/bash

# =============================================================================
#                            Push Swap Test Suite
# =============================================================================
# Executa uma bateria de testes automáticos no binário push_swap
# usando o checker_linux para verificar correção e número de operações.
# =============================================================================

NAME=push_swap
CHECKER=./checker_linux
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
RESET="\033[0m"

# -----------------------------------------------------------------------------
# Função auxiliar para testar e validar saída
# -----------------------------------------------------------------------------
run_test() {
	local description=$1
	shift
	local args=("$@")

	echo -e "${BLUE}🔹 Teste:${RESET} $description"
	echo -e "${YELLOW}Args:${RESET} ${args[*]}"

	# Executa push_swap e checker
	local output
	output=$("./$NAME" "${args[@]}")
	local ops_count
	ops_count=$(echo "$output" | wc -l)
	local checker_result
	checker_result=$(echo "$output" | $CHECKER "${args[@]}")

	# Exibe resultados
	if [ "$checker_result" == "OK" ]; then
		echo -e "${GREEN}✅ OK${RESET} - Operações: ${ops_count}"
	else
		echo -e "${RED}❌ KO${RESET} - Operações: ${ops_count}"
	fi
	echo "----------------------------------------"
}

# -----------------------------------------------------------------------------
# Testes determinísticos (simples e previsíveis)
# -----------------------------------------------------------------------------
echo -e "${BLUE}🚀 Iniciando testes determinísticos...${RESET}\n"

run_test "Lista já ordenada" 1 2 3 4 5
run_test "Lista reversa" 5 4 3 2 1
run_test "Lista mista pequena" 3 2 1
run_test "Lista com negativos" -3 -1 -2
run_test "Lista média" 2 1 3 6 5 8
run_test "Apenas um elemento" 42

# -----------------------------------------------------------------------------
# Testes de erro e entrada inválida
# -----------------------------------------------------------------------------
echo -e "\n${BLUE}⚠️  Testando entradas inválidas...${RESET}\n"

run_test "Entrada vazia" ""
run_test "Entrada com duplicados" 2 1 2
run_test "Entrada não numérica" 1 a 3
run_test "Entrada com limite superior" 2147483648

# -----------------------------------------------------------------------------
# Testes randômicos com tamanhos progressivos
# -----------------------------------------------------------------------------
echo -e "\n${BLUE}🎲 Testando listas randômicas...${RESET}\n"

test_random() {
	local n=$1
	local arr=($(shuf -i 1-1000 -n $n))
	echo -e "${YELLOW}🔸 Teste com $n elementos${RESET}"
	local output
	output=$("./$NAME" "${arr[@]}")
	local ops_count
	ops_count=$(echo "$output" | wc -l)
	local checker_result
	checker_result=$(echo "$output" | $CHECKER "${arr[@]}")
	if [ "$checker_result" == "OK" ]; then
		echo -e "${GREEN}✅ OK${RESET} - ${ops_count} operações"
	else
		echo -e "${RED}❌ KO${RESET}"
	fi
	echo
}

test_random 5
test_random 50
test_random 100

# -----------------------------------------------------------------------------
# Benchmarks básicos (comparando limites do subject)
# -----------------------------------------------------------------------------
echo -e "\n${BLUE}📊 Benchmark básico conforme subject...${RESET}\n"
benchmark_random() {
	local n=$1
	local max_ops=$2
	local arr=($(shuf -i 1-5000 -n $n))
	local output
	output=$("./$NAME" "${arr[@]}")
	local ops_count
	ops_count=$(echo "$output" | wc -l)
	local checker_result
	checker_result=$(echo "$output" | $CHECKER "${arr[@]}")
	if [ "$checker_result" == "OK" ]; then
		if [ "$ops_count" -le "$max_ops" ]; then
			echo -e "${GREEN}✅ $n OK (${ops_count} <= ${max_ops})${RESET}"
		else
			echo -e "${YELLOW}⚠️ $n OK, mas acima do limite (${ops_count}/${max_ops})${RESET}"
		fi
	else
		echo -e "${RED}❌ $n KO${RESET}"
	fi
}

benchmark_random 3 3
benchmark_random 5 12
benchmark_random 100 700
benchmark_random 500 5500

echo -e "\n${BLUE}✅ Todos os testes finalizados.${RESET}"
