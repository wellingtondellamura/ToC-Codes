#ifndef CFG_LOADER_H
#define CFG_LOADER_H
/*****************/
#include "cfg_types.h"

grammar load_grammar(char *__filename){
	grammar _g;
	FILE *_file = fopen(dfa_filename,"r");
	
	fclose(_file);
	return _g;
}


#endif /*CFG_LOADER_H*/