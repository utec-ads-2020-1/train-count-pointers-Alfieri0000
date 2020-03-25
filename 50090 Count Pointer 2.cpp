#include <stdio.h>
 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
#include <bits/stdc++.h>

using namespace std;

struct asociacion{
    int *Direccion;
    int cuenta;
};

bool acompare(asociacion lhs, asociacion rhs) {
    int contador = 0;
    if ((lhs.cuenta != rhs.cuenta) && ((lhs.cuenta && rhs.cuenta) != 0)){
        return lhs.cuenta < rhs.cuenta;
    }
    else{
        return lhs.Direccion < rhs.Direccion;
    }
}


void count(int **p[]){
    
    int fallo = 0;
    int CA = 0;
    
    struct asociacion Contador[MAX_SIZE_PTRARRAY]{
    };
    
    for (int i = 0;i < MAX_SIZE_PTRARRAY;i++){
        if (p[i] == NULL){
            
        }
        else{
            for (int x = 0;x <MAX_SIZE_PTRARRAY;x++){
                if(Contador[x].Direccion == *p[i]){
                    Contador[x].cuenta++;
                    fallo = 1;
                }
            }
            if (fallo == 0){
                Contador[CA].Direccion = *p[i];
                Contador[CA].cuenta = 1;
                CA++;
            }
            fallo = 0;
            
        //cout << &p[i] << " " << p[i] << " " << *p[i] << " " << **p[i] <<endl;
        // (Direccion de mi puntero),(valor del puntero),(valor de la Direccion a donde apunto),(valor de la direccion de la dirección a donde apunto)
        }
    }
    
    sort(Contador,Contador+MAX_SIZE_PTRARRAY,acompare);
    for (int x = 0;x <MAX_SIZE_PTRARRAY;x++){
        if (Contador[x].Direccion != 0){
            cout << *(Contador[x].Direccion) << " " << Contador[x].cuenta << endl;
        }
    }
}
 
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];
 
  count(ptrArray);
 
  return 0;
}