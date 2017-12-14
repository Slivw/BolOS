CC	:= i686-elf-gcc

ASM	:= nasm

RM	:= rm -rf

LDFLAGS	+= -lgcc -ffreestanding -O2 -nostdlib

CFLAGS	+= -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iincludes

CSRCS	:= $(shell find srcs -type f -name "*.c")

CTEMPSRCS	:= $(shell find srcs -type f -name "*~")

ASRCS	:= $(shell find srcs -type f -name "*.asm")

COBJS	:= $(CSRCS:.c=.o)

AOBJS	:= $(ASRCS:.asm=.o)

NAME	:= kernel.bin

all: $(NAME)

$(AOBJS):
	for src in $(ASRCS); do \
		$(ASM) -felf32 $$src; \
	done

$(NAME): $(COBJS) $(AOBJS)
	$(CC) -T linker.ld -o $(NAME) $(COBJS) $(AOBJS) $(LDFLAGS)

clean:
	$(RM) $(COBJS) $(AOBJS)
	$(RM) $(CTEMPSRCS)

fclean: clean
	$(RM) $(NAME)

indent: 
	indent $(CSRCS) -nbad -bap -bbo -nbc -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -cp33 -cs -d0 -di1 -nfc1 -nfca -hnl -i4 -ip0 -l75 -lp -npcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss -bli0

run:
	/mnt/c/"Program Files"/qemu/qemu-system-i386.exe -kernel kernel.bin

re: fclean all

rerun: re run

.PHONY: all re clean fclean indent
