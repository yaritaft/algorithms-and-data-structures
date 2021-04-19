const lista = [5,2,11,3,1,51]

const swap = (i:number, j: number, lista: number[]): number[]=>{
    const temp = lista[i];
    lista[i] = lista[j]
    lista[j] = temp;
    return lista;
}

const bubbleSort = (lista: number[]): number[] =>{
    const n = lista.length;
    for (let i = 0;i < n ;i++){
        for(let j=0;j< n + i - 1;j++){
            if (lista[i]<lista[j]){
                lista = swap(i,j,lista)
            }
        }
    }
    return lista;
}
console.log(bubbleSort(lista))