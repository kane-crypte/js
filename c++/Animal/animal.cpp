#include "animal.h"

Animal::Animal(char * n){
 nom = new char(strlen(n)+1);
 strcpy(nom,n);
}
