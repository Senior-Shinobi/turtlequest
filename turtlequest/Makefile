Final:	main.o Control.o List.o Dragon.o Porc.o Dorc.o Borc.o Tortoise.o Hare.o Hero.o random.o View.o
	g++ -o Final main.o Control.o List.o Dragon.o Porc.o Dorc.o Borc.o Tortoise.o Hare.o Hero.o random.o View.o

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h List.h Dragon.h Porc.h Dorc.h Borc.h Tortoise.h Hare.h Hero.h View.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

List.o: List.cc List.h Hero.h
	g++ -c List.cc

Dragon.o: Dragon.cc Dragon.h Hero.h
	g++ -c Dragon.cc

Porc.o: Porc.cc Porc.h Hero.h
	g++ -c Porc.cc

Dorc.o: Dorc.cc Dorc.h Hero.h
	g++ -c Dorc.cc

Borc.o: Borc.cc Borc.h Hero.h
	g++ -c Borc.cc

Tortoise.o: Tortoise.cc Tortoise.h Hero.h
	g++ -c Tortoise.cc

Hare.o: Hare.cc Hare.h Hero.h
	g++ -c Hare.cc

Hero.o: Hero.cc Hero.h
	g++ -c Hero.cc

random.o: random.cc
	g++ -c random.cc

clean:
	rm -f *.o Final
