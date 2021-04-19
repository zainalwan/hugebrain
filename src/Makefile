CC = g++
OBJECT_FILES = main.o App.o Help.o Argument.o Person.o Database.o View.o
BOOST_FLAGS = -lboost_filesystem
BINARY_DIRECTORY = ../bin
EXECUTABLE = hugebrain

all: help

help:
	@echo "Usage: make <command>"
	@echo ""
	@echo "List of available commands:"
	@echo "    install                     Install to this project's bin directory."
	@echo "    install-globally            Install to /usr/bin dirrectory."
	@echo "    clean                       Clean compiled object files."
	@echo "    uninstall                   Uninstall Bhess local and globally."

install-globally: ${BINARY_DIRECTORY}/${EXECUTABLE}
	mv ${BINARY_DIRECTORY}/${EXECUTABLE} /usr/bin/

${BINARY_DIRECTORY}/${EXECUTABLE}: install

install: ${OBJECT_FILES}
	mkdir -p ${BINARY_DIRECTORY}
	${CC} -o ${BINARY_DIRECTORY}/${EXECUTABLE} ${OBJECT_FILES} ${BOOST_FLAGS}

main.o: main.cpp
	${CC} -c -o main.o main.cpp

App.o: App.cpp ../headers/App.h
	${CC} -c -o App.o App.cpp

Help.o: Help.cpp ../headers/Help.h
	${CC} -c -o Help.o Help.cpp

Argument.o: Argument.cpp ../headers/Argument.h
	${CC} -c -o Argument.o Argument.cpp

Person.o: Person.cpp ../headers/Person.h
	${CC} -c -o Person.o Person.cpp

Database.o: Database.cpp ../headers/Database.h
	${CC} -c -o Database.o Database.cpp

View.o: View.cpp ../headers/View.h
	${CC} -c -o View.o View.cpp

clean:
	rm -f *.o

uninstall:
	rm -rf ${BINARY_DIRECTORY}
	rm -rf /usr/bin/hugebrain