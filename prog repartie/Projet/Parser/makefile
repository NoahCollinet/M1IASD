# définition de la cible et des dépendances  

serverTCP: serveurTCP.o parser.o
	gcc -o $@ $^

serveurTCP.o: serveurTCP.c parser.h
	gcc -Include -Wall -c $<

parser.o: parser.c parser.h
	gcc -Include -Wall -c $<

TCP.pdf: serveurTCP.c parser.c parser.h Makefile
	a2ps -o - $^ | ps2pdf - $@

# on clean

clean :
	rm -f *~ *.o

mrproper : clean
	rm -f serverTCP