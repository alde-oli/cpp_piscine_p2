NAME = TemplatesAreGreat

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = ./
INCDIR = ./
OBJDIR = obj

GREEN = \033[0;32m
BLUE = \033[0;34m
VIOLET = \033[0;35m
BOLD = \033[1m
NC = \033[0m

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJECTS)
	@echo -e "$(GREEN)$(BOLD)[ ok ] files compiled$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS) -I$(INCDIR) -g
	@echo -e "$(BLUE)$(BOLD)[ ok ] $(NAME) created$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo -e "$(VIOLET)$(BOLD)obj files deleted$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(VIOLET)$(BOLD)program deleted$(NC)"

re: fclean all

run: re
	@./$(NAME)

.PHONY: all clean fclean re run