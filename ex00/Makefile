NAME := megaphone

### SRCS #######################################################################

SRCS += megaphone.cpp

### OBJS #######################################################################

PATH_OBJS = objs/

OBJS := $(patsubst %.cpp, $(PATH_OBJS)%.o, $(SRCS))

### COMPILATION ################################################################

COMPILATION := c++
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -std=c++98

## RULES #######################################################################

all: $(NAME)

$(OBJS): $(PATH_OBJS)%.o: %.cpp
		mkdir -p $(PATH_OBJS)
		$(COMPILATION) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(COMPILATION) $(CFLAGS) $< -o $(NAME)

clean:
		$(RM) -r $(PATH_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
