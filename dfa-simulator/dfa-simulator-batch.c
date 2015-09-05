#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 


FILE *dfa_file;
char *dfa_filename;
int current;
int retract = 0;

int verbose_test = 0;

typedef struct {
	int from;
	char symbol;
	int to;
} transition;

typedef struct {
	int initial;
	int* final;
	transition* transitions;
	int finalc;
	int transitionsc;
}automaton;

int next_char();
int read_int();
void usage(char*);
automaton load_dfa();

void print_automaton(const automaton);
int test(const automaton, const char*); 
int delta(const automaton, int, char);
int test_final(const automaton, int);

int main(int argc, char* argv[]){
	size_t tsize = 1024*2014*1024;
	char *tape;
	if (argc < 2){
		usage(argv[0]);
		return 0;
	}
	if (argc >=3){
		verbose_test = (strcmp(argv[2],"-v")) == 0; 
	}
	dfa_filename = argv[1];
	//printf("Opening file %s\n", dfa_filename);
	automaton dfa = load_dfa();
	//print_automaton(dfa);
	//printf("\n\n*** DFA Test (Ctrl+C to Terminate) ***\n\n");
	int read = EOF;
	do{
		//printf("Tape: ");
		tape = (char *) malloc (tsize + 1);
		read = getline(&tape, &tsize, stdin);
		if (read != -1){
			if (test(dfa, tape)){
				printf("%s;1\n",tape);
			}else{
				printf("%s;0\n",tape);
			}
		}
		free(tape);
	}while (read != EOF);
	return 0;
}

void usage(char* prog_name){
	printf("Usage: %s [FILE] -v\n", prog_name);
	printf("A very simple Deterministic Finite Automata simulator\n\n");
	printf("ARGS:\n");
	printf("\t[FILE] \t\t dfa file: a file with specifications of the automaton to simulate.\n");
	printf("\t-v \t\t verbose mode: show all transitions iterations.\n");
}

void print_automaton(const automaton dfa){
	int i;
	printf("Initial state: %d\n", dfa.initial);
	printf("Final states: {");
	for (i = 0; i<dfa.finalc; i++){
	 	printf("%d", dfa.final[i]);
		if (i<dfa.finalc-1)
			printf(",");
	}
	printf("}\n");
	printf("Transitions: {");
	for (i = 0; i<dfa.transitionsc; i++){
	 	printf("(%d,%c,%d)",  dfa.transitions[i].from, dfa.transitions[i].symbol, dfa.transitions[i].to);
		if (i<dfa.transitionsc-1)
			printf(",");
	}
	printf("}\n");
}

int test(const automaton dfa, const char* tape){
	int i = 0;
	int current_state = dfa.initial;
	while (tape[i] != '\n'){
		if (verbose_test){
			printf("(%d, %c", current_state, tape[i]);
		}
		current_state = delta(dfa, current_state, tape[i]);
		i++;
		if (verbose_test){
			printf(",%d)\n", current_state);
		}
		if (current_state == -1)
			return 0;
	}
	return (test_final(dfa, current_state));
}

int delta(const automaton dfa, int state, char symbol){
	int i;
	for (i = 0; i < dfa.transitionsc; i++){
		if (dfa.transitions[i].from == state && dfa.transitions[i].symbol == symbol){
			return dfa.transitions[i].to;
		}
	}
	return -1;
}

int test_final(const automaton dfa, int state){
	int i;
	for (i = 0; i < dfa.finalc; i++){
		if (dfa.final[i] == state){
			return 1;
		}
	}
	return 0;
}

int next_char(){
	if (dfa_file == NULL){
		dfa_file = fopen(dfa_filename,"r");
	}	
	if (!retract){
		int r = getc(dfa_file);	
		while (r == '\n' || r == '\t' || r == ' '){
			r = getc(dfa_file);
		}
		current = r;
		if (current == EOF){
			fclose(dfa_file);	
		}
	}
	retract = 0;
	return current;
}

int read_int(){
	char c = next_char();
	int v = 0;
	int f = 1;
	while (isdigit(c)){
		v = v + f * atoi(&c); 
		f = f *10;
		c = next_char();
	}
	retract = 1;
	return v;
}

automaton load_dfa(){
	char c;
	automaton dfa;
	dfa.finalc = dfa.transitionsc = 0;
	dfa.final = NULL;
	dfa.transitions = NULL;
	while ((c = next_char()) != EOF){		
		switch(c){			
			case 'i':
				if (next_char()==':'){
					dfa.initial = read_int();
				}
				break;
			case 'f':
		   		if (next_char()==':'){
						int f = read_int();
						dfa.finalc++;
						if (dfa.final == NULL){
							dfa.final = malloc(sizeof(int));
						}else{
							int *temp = realloc(dfa.final,dfa.finalc*sizeof(int));
							dfa.final = temp;
						}
						dfa.final[dfa.finalc-1] = f;
					}	
				break;
			case 't':				
				if (next_char()==':'){
					transition t;
					t.from = read_int();
					if(next_char()!='-')
						break;
					t.symbol = next_char();
					if(next_char()!='-')
						break;
					t.to = read_int();
					dfa.transitionsc++;
					if (dfa.transitions == NULL){
						dfa.transitions = malloc(sizeof(transition));
					}else{
						transition *temp = realloc(dfa.transitions,dfa.transitionsc*sizeof(transition));
						dfa.transitions = temp;
					}
					dfa.transitions[dfa.transitionsc-1] = t;
				}
				break;
			default:
				printf("Unexpected character '%c'\n", c);
				abort();
	   }
    }	
    return dfa;
}

