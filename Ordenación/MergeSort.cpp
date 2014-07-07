mergeSort: divide el arreglo a la mitad
Orden (nLog(n))
void mergesort(Array<nat> a, Array<nat> b, nat izq, nat der)
{
    if(izq<der){
        nat pivot=(izq+der)/2;
        mergesort(a,b,izq,pivot);
        mergesort(a,b,pivot+1,der);
        merge(a,b,izq,pivot,der);
    }
}

void merge(Array<nat>a, Array<nat>b, nat izq, nat pivot, nat der)
{
    nat h,i,j,k;
    h=izq;
    i=izq;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=der)){
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;
        }else{
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot){
        for(k=j; k<=der; k++){
            b[i]=a[k];
            i++;
        }
    }else{
        for(k=h; k<=pivot; k++){
            b[i]=a[k];
            i++;
        }
    }
    for(k=izq; k<=der; k++) a[k]=b[k];
}
Cáculo de orden en página 79.

//O(nLogn):

T(1) = 1
T(n) = 2T(n/2) + n
						-->  T(n) = 4T(n/4) + 2n --> T(i) = 2^iT(n/2^i) + in --> n = 2^i --> i = nLogn --> T(n) = nLogn + n --> O(nLogn)
T(n/2) = 2T(n/4) + n/2

