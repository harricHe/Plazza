##
## Makefile for plazza in /home/nlequain/projets/tek2/cpp/cpp_plazza
##
## Made by nlequain
## Login   <nlequain@epitech.net>
##
## Started on  Sun Apr 19 15:09:57 2015 nlequain
## Last update Sun Apr 26 22:42:15 2015 nlequain
##

CC			=	g++

RM			=	rm -f

NAME		=	plazza

CXXFLAGS	+=	-I./headers -W -Wall -Wextra

LDFLAGS		=	-lpthread -lncurses -lncursesw

SRCS		=	sources/AIngredient.cpp \
				sources/Americana.cpp \
				sources/ARecipe.cpp \
				sources/AThreadable.cpp \
				sources/ConditionalVariable.cpp \
				sources/Doe.cpp \
				sources/Eggplant.cpp \
				sources/Fantasia.cpp \
				sources/Freezer.cpp \
				sources/GoatCheese.cpp \
				sources/Gruyere.cpp \
				sources/Ham.cpp \
				sources/IngredientFactory.cpp \
				sources/main.cpp \
				sources/Margarita.cpp \
				sources/Mushroom.cpp \
				sources/Mutex.cpp \
				sources/MutexScopedLock.cpp \
				sources/RecipeFactory.cpp \
				sources/Regina.cpp \
				sources/Steak.cpp \
				sources/Tomato.cpp \
				sources/Kitchen.cpp \
				sources/Cook.cpp \
				sources/KitchenManager.cpp \
				sources/KitchenTracker.cpp \
				sources/Reception.cpp \
				sources/AForkable.cpp \
				sources/ANamedPipe.cpp \
				sources/InputNamedPipe.cpp \
				sources/OutputNamedPipe.cpp \
				sources/Parser.cpp \
				sources/NCursesIOManager.cpp \
				sources/ASerializable.cpp \
				sources/Royal.cpp \
				sources/Gourmand.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CXXFLAGS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
