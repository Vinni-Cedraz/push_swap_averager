NAME = lib.a
AR = ar
ARFLAGS = -rcs
CFLAGS = -w -O3
INC = ../include/
OBJS_DIR = objs/

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
