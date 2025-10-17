define LOGO
\033[1;31m
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
# ... (seu logo aqui - mantido igual)
\033[0m
endef
export LOGO

# Compilador e flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iinclude -Ilibft -Ilibft/ft_printf

# Diretórios
SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

# Nome do binário
NAME        := push_swap

# Arquivos fonte do projeto principal
SRC_FILES   := \
	main.c \
	validation/validator.c \
	stacks/stack_a.c stacks/stack_b.c stacks/stacks.c stacks/utils.c \
	sorting/small_sort.c sorting/medium_sort.c sorting/big_sort.c \
	sorting/chunk_calculations.c sorting/push_chunk.c sorting/push_chunks.c sorting/find_min_max.c \
	finder/find_next_init.c finder/find_next_in_range.c finder/find_next_utils.c \
	communication/receiver.c

SRCS        := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN   := \033[1;32m
YELLOW  := \033[1;33m
RED     := \033[1;31m
BLUE    := \033[1;34m
RESET   := \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$$LOGO"
	@echo "$(BLUE)🔧 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✅ Build complete: $(NAME)$(RESET)"

# Compilação dos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled:$(RESET) $<"

# Diretório de objetos
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(RED)🧹 Removing object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)🗑️  Removing executables and libraries...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

## Exemplo simples de execução
test: $(NAME)
	@echo "$(BLUE)🚀 Testando push_swap...$(RESET)"
	@./$(NAME) 2 1 3 5 8
	@echo
	@echo "$(BLUE)🚫 Testando entrada inválida...$(RESET)"
	@./$(NAME) 0 one 2 3 || true

check: $(NAME)
	@echo "$(BLUE)🧠 Rodando testes automatizados...$(RESET)"
	@chmod +x test/push_swap_tests.sh
	@./test/push_swap_tests.sh

# Verificação de leaks
valgrind: $(NAME)
	@valgrind --leak-check=full ./$(NAME) 3 2 1

# Norminette
norm:
	@echo "$(BLUE)📜 Checking Norminette...$(RESET)"
	@norminette $(SRC_DIR) $(INC_DIR)

# Ajuda
help:
	@echo "$(YELLOW)Available targets:$(RESET)"
	@echo "  all       – Compila o projeto principal ($(NAME))"
	@echo "  clean     – Remove arquivos objeto"
	@echo "  fclean    – Remove objetos e executáveis"
	@echo "  re        – Reconstrói tudo"
	@echo "  test      – Executa teste básico (com exemplo do PDF)"
	@echo "  check     – Testa com checker_OS (mostra número de operações e OK/KO)"
	@echo "  valgrind  – Verifica vazamentos de memória"
	@echo "  norm      – Executa Norminette"
	@echo "  help      – Mostra este menu"

.PHONY: all clean fclean re test valgrind norm help
.SILENT: