#!/bin/bash

# =============================================================================
#                            Push Swap Test Suite
# =============================================================================
# Executa uma bateria de testes automáticos no binário push_swap
# usando o checker_linux para verificar correção e número de operações.
# =============================================================================

# Configurações
NAME=push_swap
CHECKER=./checker_linux
LOG_FILE="push_swap_test.log"
TEMP_FILE="temp_output.txt"
TIMEOUT_DURATION=5  # segundos

# Cores e formatação
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
BOLD="\033[1m"
RESET="\033[0m"

# Estatísticas
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# -----------------------------------------------------------------------------
# Funções auxiliares
# -----------------------------------------------------------------------------

# Inicializar arquivo de log
init_log() {
    echo "=== Push Swap Test Suite - $(date) ===" > "$LOG_FILE"
    echo "======================================" >> "$LOG_FILE"
}

# Log para arquivo
log_test() {
    local test_type=$1
    local description=$2
    local result=$3
    local ops_count=$4
    echo "[$(date '+%H:%M:%S')] $test_type: $description - $result - $ops_count ops" >> "$LOG_FILE"
}

# Verificar se binários existem
check_binaries() {
    if [ ! -f "$NAME" ]; then
        echo -e "${RED}❌ Erro: $NAME não encontrado${RESET}"
        echo -e "${YELLOW}Dica: Compile com 'make' antes de executar os testes${RESET}"
        exit 1
    fi
    
    if [ ! -x "$NAME" ]; then
        chmod +x "$NAME"
    fi
    
    if [ ! -f "$CHECKER" ]; then
        echo -e "${RED}❌ Erro: $CHECKER não encontrado${RESET}"
        echo -e "${YELLOW}Dica: Baixe o checker_linux e coloque no diretório atual${RESET}"
        exit 1
    fi
    
    if [ ! -x "$CHECKER" ]; then
        chmod +x "$CHECKER"
    fi
    
    echo -e "${GREEN}✅ Binários verificados com sucesso${RESET}"
}

# Header de seção
print_section() {
    echo -e "\n${PURPLE}╔════════════════════════════════════════════════════════════╗${RESET}"
    echo -e "${PURPLE}║${BOLD} $1${RESET}"
    echo -e "${PURPLE}╚════════════════════════════════════════════════════════════╝${RESET}"
}

# Footer de teste
print_test_footer() {
    echo -e "${CYAN}┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄${RESET}"
}

# Função com timeout para evitar travamentos
run_with_timeout() {
    local timeout_duration=$1
    shift
    local command=("$@")
    
    timeout "$timeout_duration" "${command[@]}" 2>/dev/null
    local exit_code=$?
    
    if [ $exit_code -eq 124 ]; then
        echo "TIMEOUT"
        return 1
    elif [ $exit_code -ne 0 ]; then
        return 1
    fi
    return 0
}

# -----------------------------------------------------------------------------
# Função principal de teste
# -----------------------------------------------------------------------------
run_test() {
    local description=$1
    shift
    local args=("$@")
    
    ((TOTAL_TESTS++))
    
    echo -e "${BLUE}🔹 Teste:${RESET} ${BOLD}$description${RESET}"
    echo -e "${YELLOW}📋 Args:${RESET} ${args[*]:-(vazio)}"
    
    # Verifica se é lista vazia
    if [ ${#args[@]} -eq 1 ] && [ -z "${args[0]}" ]; then
        echo -e "${YELLOW}⚠️  Teste de lista vazia - verificando comportamento...${RESET}"
        local output
        output=$("./$NAME" "${args[@]}" 2>&1)
        if [ -z "$output" ]; then
            echo -e "${GREEN}✅ OK - Nenhuma operação (comportamento esperado para lista vazia)${RESET}"
            ((PASSED_TESTS++))
            log_test "SUCESSO" "$description" "OK" "0"
        else
            echo -e "${YELLOW}⚠️  Comportamento inesperado para lista vazia${RESET}"
            ((FAILED_TESTS++))
            log_test "FALHA" "$description" "COMPORTAMENTO_INESPERADO" "?"
        fi
        print_test_footer
        return 0
    fi
    
    # Executa push_swap com timeout
    local start_time
    start_time=$(date +%s%N)
    
    local output
    output=$(run_with_timeout $TIMEOUT_DURATION "./$NAME" "${args[@]}")
    local push_swap_exit_code=$?
    
    local end_time
    end_time=$(date +%s%N)
    local duration=$(( (end_time - start_time) / 1000000 ))
    
    # Verifica timeout
    if [ "$output" == "TIMEOUT" ]; then
        echo -e "${RED}❌ TIMEOUT - Programa travou ou demorou muito${RESET}"
        ((FAILED_TESTS++))
        log_test "FALHA" "$description" "TIMEOUT" "?"
        print_test_footer
        return 1
    fi
    
    # Verifica erro na execução
    if [ $push_swap_exit_code -ne 0 ]; then
        echo -e "${RED}❌ ERRO NA EXECUÇÃO (código: $push_swap_exit_code)${RESET}"
        ((FAILED_TESTS++))
        log_test "FALHA" "$description" "ERRO_EXECUCAO" "?"
        print_test_footer
        return 1
    fi
    
    # Conta operações
    local ops_count=0
    if [ -n "$output" ]; then
        ops_count=$(echo "$output" | grep -v "^$" | wc -l | tr -d ' ')
    fi
    
    # Verifica com checker (também com timeout)
    local checker_result
    checker_result=$(echo "$output" | run_with_timeout $TIMEOUT_DURATION $CHECKER "${args[@]}")
    local checker_exit_code=$?
    
    # Exibe resultados
    if [ $checker_exit_code -eq 0 ] && [ "$checker_result" == "OK" ]; then
        echo -e "${GREEN}✅ OK${RESET} - ${CYAN}${ops_count}${RESET} operações - ${YELLOW}${duration}ms${RESET}"
        ((PASSED_TESTS++))
        log_test "SUCESSO" "$description" "OK" "$ops_count"
    elif [ $checker_exit_code -eq 0 ] && [ "$checker_result" == "KO" ]; then
        echo -e "${RED}❌ KO${RESET} - ${CYAN}${ops_count}${RESET} operações"
        ((FAILED_TESTS++))
        log_test "FALHA" "$description" "KO" "$ops_count"
    else
        echo -e "${RED}❌ ERRO NO CHECKER${RESET}"
        ((FAILED_TESTS++))
        log_test "FALHA" "$description" "ERRO_CHECKER" "$ops_count"
    fi
    
    print_test_footer
}

# -----------------------------------------------------------------------------
# Teste de performance
# -----------------------------------------------------------------------------
performance_test() {
    local size=$1
    local iterations=$2
    local max_acceptable=$3
    
    echo -e "${BLUE}📊 Performance Test - $size elementos ($iterations iterações)${RESET}"
    
    local total_ops=0
    local max_ops=0
    local min_ops=999999
    local passed=0
    
    for ((i=1; i<=iterations; i++)); do
        # Gera números únicos
        local arr=($(shuf -i 1-$((size * 10)) -n $size | tr '\n' ' '))
        
        echo -e "${CYAN}Iteração $i/$iterations...${RESET}"
        
        local output
        output=$(run_with_timeout $TIMEOUT_DURATION "./$NAME" "${arr[@]}")
        
        if [ "$output" == "TIMEOUT" ]; then
            echo -e "${RED}❌ Timeout na iteração $i${RESET}"
            continue
        fi
        
        local ops_count
        ops_count=$(echo "$output" | grep -v "^$" | wc -l | tr -d ' ')
        local checker_result
        checker_result=$(echo "$output" | run_with_timeout $TIMEOUT_DURATION $CHECKER "${arr[@]}")
        
        # Atualiza estatísticas apenas se não houve timeout
        if [ "$output" != "TIMEOUT" ] && [ "$checker_result" != "TIMEOUT" ]; then
            total_ops=$((total_ops + ops_count))
            [ $ops_count -gt $max_ops ] && max_ops=$ops_count
            [ $ops_count -lt $min_ops ] && min_ops=$ops_count
            
            if [ "$checker_result" == "OK" ]; then
                ((passed++))
            fi
        fi
    done
    
    if [ $iterations -gt 0 ] && [ $passed -gt 0 ]; then
        local avg_ops=$((total_ops / passed))
        local pass_rate=$((passed * 100 / iterations))
        
        echo -e "${YELLOW}📈 Estatísticas:${RESET}"
        echo -e "  Mínimo: ${min_ops} ops"
        echo -e "  Máximo: ${max_ops} ops" 
        echo -e "  Média:  ${avg_ops} ops"
        echo -e "  Taxa de acerto: ${pass_rate}%"
        
        if [ $avg_ops -le $max_acceptable ]; then
            echo -e "${GREEN}✅ Performance dentro do esperado (<= ${max_acceptable})${RESET}"
        else
            echo -e "${YELLOW}⚠️  Performance acima do esperado (${avg_ops} > ${max_acceptable})${RESET}"
        fi
    else
        echo -e "${RED}❌ Não foi possível calcular estatísticas${RESET}"
    fi
    
    echo "performance,$size,$iterations,$min_ops,$max_ops,$avg_ops,$pass_rate" >> "$LOG_FILE"
    print_test_footer
}

# -----------------------------------------------------------------------------
# Testes específicos para casos edge
# -----------------------------------------------------------------------------
run_edge_tests() {
    print_section "TESTES ESPECIAIS"
    
    # Teste com lista já ordenada (deve gerar 0 operações)
    echo -e "${BLUE}🔹 Teste Especial: Lista já ordenada${RESET}"
    echo -e "${YELLOW}📋 Args: 1 2 3 4 5${RESET}"
    local output
    output=$(run_with_timeout $TIMEOUT_DURATION "./$NAME" 1 2 3 4 5)
    local ops_count
    ops_count=$(echo "$output" | grep -v "^$" | wc -l | tr -d ' ')
    
    if [ $ops_count -eq 0 ]; then
        echo -e "${GREEN}✅ PERFEITO - Nenhuma operação para lista ordenada${RESET}"
    else
        echo -e "${YELLOW}⚠️  Gerou $ops_count operações para lista já ordenada${RESET}"
    fi
    print_test_footer
    
    # Teste com um único elemento
    echo -e "${BLUE}🔹 Teste Especial: Um elemento${RESET}"
    echo -e "${YELLOW}📋 Args: 42${RESET}"
    output=$(run_with_timeout $TIMEOUT_DURATION "./$NAME" 42)
    ops_count=$(echo "$output" | grep -v "^$" | wc -l | tr -d ' ')
    
    if [ $ops_count -eq 0 ]; then
        echo -e "${GREEN}✅ PERFEITO - Nenhuma operação para um elemento${RESET}"
    else
        echo -e "${YELLOW}⚠️  Gerou $ops_count operações para um único elemento${RESET}"
    fi
    print_test_footer
}

# -----------------------------------------------------------------------------
# Relatório final
# -----------------------------------------------------------------------------
print_summary() {
    print_section "RELATÓRIO FINAL"
    
    local success_rate=0
    if [ $TOTAL_TESTS -gt 0 ]; then
        success_rate=$((PASSED_TESTS * 100 / TOTAL_TESTS))
    fi
    
    echo -e "${BOLD}📊 Estatísticas dos Testes:${RESET}"
    echo -e "  Total de testes:   ${TOTAL_TESTS}"
    echo -e "  ${GREEN}Testes aprovados: ${PASSED_TESTS}${RESET}"
    echo -e "  ${RED}Testes reprovados: ${FAILED_TESTS}${RESET}"
    echo -e "  ${CYAN}Taxa de sucesso:   ${success_rate}%${RESET}"
    
    if [ $FAILED_TESTS -eq 0 ] && [ $TOTAL_TESTS -gt 0 ]; then
        echo -e "\n${GREEN}🎉 Todos os testes passaram!${RESET}"
    elif [ $success_rate -ge 80 ]; then
        echo -e "\n${YELLOW}⚠️  A maioria dos testes passou.${RESET}"
    else
        echo -e "\n${RED}❌ Muitos testes falharam. Verifique sua implementação.${RESET}"
    fi
    
    echo -e "\n${CYAN}📄 Log completo salvo em: $LOG_FILE${RESET}"
}

# -----------------------------------------------------------------------------
# Limpeza
# -----------------------------------------------------------------------------
cleanup() {
    [ -f "$TEMP_FILE" ] && rm -f "$TEMP_FILE"
}

# Trap para garantir limpeza
trap cleanup EXIT

# -----------------------------------------------------------------------------
# Execução dos testes
# -----------------------------------------------------------------------------

main() {
    init_log
    check_binaries
    
    print_section "PUSH SWAP TEST SUITE"
    echo -e "${CYAN}Iniciando testes em: $(date)${RESET}\n"
    
    # Testes edge primeiro
    run_edge_tests
    
    # Testes determinísticos
    print_section "TESTES DETERMINÍSTICOS"
    run_test "Lista ordenada" 1 2 3 4 5
    run_test "Lista reversa" 5 4 3 2 1
    run_test "Lista mista pequena" 3 2 1
    run_test "Lista com negativos" -3 -1 -2
    run_test "Lista média" 2 1 3 6 5 8
    run_test "Apenas um elemento" 42
    run_test "Dois elementos ordenados" 1 2
    run_test "Dois elementos reversos" 2 1
    
    # Testes de erro
    print_section "TESTES DE ERRO"
    run_test "Entrada vazia" ""
    run_test "Entrada com duplicados" 2 1 2
    run_test "Entrada não numérica" 1 a 3
    run_test "Número além do limite INT_MAX" 2147483648
    run_test "Número além do limite INT_MIN" -2147483649
    
    # Testes de performance (reduzidos para evitar travamentos)
    print_section "TESTES DE PERFORMANCE"
    performance_test 5 5 12
    performance_test 100 3 700
    
    # Relatório final
    print_summary
}

# Executar main
main "$@"