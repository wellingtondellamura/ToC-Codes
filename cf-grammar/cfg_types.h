#ifndef CFG_TYPES_H
#define CFG_TYPES_H
/*****************/
#define EPSILON '&' 

typedef _derivation{
  char lhs;
  char* rhs;
} derivation;

typedef _grammar{
  char S;
  derivation* derivations;
} grammar;  

#endif /*CFG_TYPES_H*/