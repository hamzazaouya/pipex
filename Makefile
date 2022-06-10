NAME = pipex
BONUS = pipex_bonus
MIN_PATH = mindatory/
BNS_PATH = bonus/
.PHONY:	all clean fclean re bonus

all : $(NAME)

bonus : $(BONUS)

$(NAME) : 
	@cd $(MIN_PATH) && make && mv pipex ../

$(BONUS) : 
	@cd $(BNS_PATH) && make && mv pipex ../

clean :
	@cd $(MIN_PATH) && make clean
	@cd $(BNS_PATH) && make clean

fclean : clean
	@rm -fr pipex
	@cd $(MIN_PATH) && make fclean
	@cd $(BNS_PATH) && make fclean

re : fclean all