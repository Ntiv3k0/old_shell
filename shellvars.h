#ifndef SHELLVAR
#define SHELLVARH

/**
 * struct Shellvar - 
 * @name:
 * @val:
 * @next:
 * */

typedef struct Shellvar
{
	char *name;
	char *val;
	struct Shellvar *next;
}
shellvar;

#endif
