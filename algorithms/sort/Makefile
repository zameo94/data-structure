# Compiler and Flags
CC = gcc
# -I. include la cartella corrente
# -I./merge_sort, -I./quick_sort e -I./bubble_sort permettono di includere gli header senza percorsi lunghi
CFLAGS = -Wall -Wextra -g -I. -I./merge_sort -I./quick_sort -I./bubble_sort

# Relative paths to source files
MERGE_DIR = ./merge_sort
BUBBLE_DIR = ./bubble_sort
QUICK_DIR = ./quick_sort
TEST_DIR = .

# Source files
# Elenchiamo i file .c necessari
SRCS = $(TEST_DIR)/test_sort.c \
       $(MERGE_DIR)/merge_sort.c \
	   $(QUICK_DIR)/quick_sort.c \
       $(BUBBLE_DIR)/bubble_sort.c

# Trasforma i file .c in .o mantenendo i percorsi
OBJS = $(SRCS:.c=.o)

# Name of the executable
TARGET = test_sort

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation step (converts .c to .o)
# Questa regola gestisce automaticamente i file in qualsiasi sottocartella
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup: Removes object files and the test executable
.PHONY: clean
clean:
	rm -f $(TEST_DIR)/*.o $(MERGE_DIR)/*.o $(QUICK_DIR)/*.o $(BUBBLE_DIR)/*.o

.PHONY: clean_bin
clean_bin:
	rm -f $(TARGET)

.PHONY: clean_all
clean_all: clean clean_bin