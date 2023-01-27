compiler        = g++
files       = date.cpp client.cpp room.cpp reservation.cpp hotel.cpp esiremhotel.cpp main.cpp

all: compile

compile: $(files)
	$(compiler) $(files) 

clean:
	rm -f a.out

exe:
	./a.out

