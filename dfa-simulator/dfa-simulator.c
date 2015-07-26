#include <stdio.h>

typedef struct {
	int from;
	char symbol;
	int to;
} transition;

typedef struct {
	int initial;
	int* final;
	transition* transitions;
}automaton;

void usage(char*);

int main(int argc, char* argv[]){
	if (argc < 2){
		usage(argv[0]);
		return 0;
	}
	char* filename = argv[1];
	printf("Opening file %s\n", filename);
	return 0;
}

void usage(char* prog_name){
	printf("Usage: %s [FILE] \n", prog_name);
	printf("A very simple Deterministic Finite Automata simulator\n\n");
	printf("ARGS:\n");
	printf("[FILE] \t\t a file with specifications of the automaton to simulate.\n");
}