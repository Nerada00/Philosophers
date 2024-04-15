SRCS = 	src/code.c\
		src/utils.c\
		src/parsing.c\
		src/init.c\
		src/protection.c\
		src/dinner.c\
		src/monitoring.c\
		src/display.c\
		src/synchro_utils.c\
		src/getters_setters.c\

OBJS = $(SRCS:.c=.o)

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -fsanitize=thread -g
RM = rm -f

all: $(NAME)

##############   barre de chargement    ##############

	@echo -n "\033[33m [EXECUTION] : \e[38;5;221m Compiling philo... "
	@total_iterations=60; \
	i=0; \
	while [ $$i -lt $$total_iterations ]; do \
		sleep 0.01; \
		printf "\e[38;5;212m▇\033[0m"; \
		i=$$((i + 1)); \
	done

#header nom du programme
	
	@echo
	@echo
	@echo "\e[38;5;219m   ======================== Compilation completed successfully. =========================== \033[0m"
	@echo 
	@echo "\e[38;5;214m ██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗ \033[0m"
	@echo "\e[38;5;215m ██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝ \033[0m"
	@echo "\e[38;5;216m ██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗ \033[0m"
	@echo "\e[38;5;217m ██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║ \033[0m"
	@echo "\e[38;5;218m ██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║ \033[0m"
	@echo "\e[38;5;219m ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝ \033[0m"
	@echo
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(RM) $(OBJS)

#header du clean
	@echo
	@echo "\033[33;5m	  =========== OBJ was removed.=========== \033[0m"
	@echo
	@echo "\e[38;5;220m ██████╗ ███████╗███╗   ███╗ ██████╗ ██╗   ██╗███████╗██████╗ \033[0m"
	@echo "\e[38;5;221m ██╔══██╗██╔════╝████╗ ████║██╔═══██╗██║   ██║██╔════╝██╔══██╗ \033[0m"
	@echo "\e[38;5;222m ██████╔╝█████╗  ██╔████╔██║██║   ██║██║   ██║█████╗  ██║  ██║ \033[0m"
	@echo "\e[38;5;223m ██╔══██╗██╔══╝  ██║╚██╔╝██║██║   ██║╚██╗ ██╔╝██╔══╝  ██║  ██║ \033[0m"
	@echo "\e[38;5;224m ██║  ██║███████╗██║ ╚═╝ ██║╚██████╔╝ ╚████╔╝ ███████╗██████╔╝ \033[0m"
	@echo "\e[38;5;225m ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝   ╚═══╝  ╚══════╝╚═════╝  \033[0m"
	@echo

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

#header du fclean
	@echo
	@echo "\033[32;5m 	  =========== All was removed.=========== \033[0m"
	@echo
	@echo "\e[38;5;410m ██████╗ ███████╗███╗   ███╗ ██████╗ ██╗   ██╗███████╗██████╗ \033[0m"
	@echo "\e[38;5;411m ██╔══██╗██╔════╝████╗ ████║██╔═══██╗██║   ██║██╔════╝██╔══██╗ \033[0m"
	@echo "\e[38;5;412m ██████╔╝█████╗  ██╔████╔██║██║   ██║██║   ██║█████╗  ██║  ██║ \033[0m"
	@echo "\e[38;5;413m ██╔══██╗██╔══╝  ██║╚██╔╝██║██║   ██║╚██╗ ██╔╝██╔══╝  ██║  ██║ \033[0m"
	@echo "\e[38;5;414m ██║  ██║███████╗██║ ╚═╝ ██║╚██████╔╝ ╚████╔╝ ███████╗██████╔╝ \033[0m"
	@echo "\e[38;5;415m ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝   ╚═══╝  ╚══════╝╚═════╝  \033[0m"
	@echo

re: fclean all

.PHONY: clean fclean all re