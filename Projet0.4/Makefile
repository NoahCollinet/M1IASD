########################################
#~ définitions
########################################

BIN=bin/sous-anneau  bin/serveur

SRCS0=sous-anneau.c
SRCS1=serveur.c
SRCS2=tcp-utils.c
SRCS3=parser.c

default: $(BIN)

########################################
#~ regles pour l'executable
########################################

obj/%.o: %.c
	gcc -g -Wall -Iinclude -c $< -o $@

bin/sous-anneau: $(SRCS0:%.c=obj/%.o)
	gcc -g -o $@ $+

bin/serveur: $(SRCS1:%.c=obj/%.o) $(SRCS3:%.c=obj/%.o)
	gcc -g -o $@ $+

clean:
	rm -f $(BIN) obj/*.o *~
