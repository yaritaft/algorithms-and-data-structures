const insertInTheMiddle = (lista: number[], valueToInsert: number, index: number)=>{
    const n = lista.length;
    for (let i=index; i< n-1; i++ ){
        const tmp = lista[i+1];
        lista[i+1] = lista[i];
        lista[i+2] = tmp;

    }
    lista[index]=valueToInsert;
    return lista
}

const insertionSortIn= (lista: number[])=>{
    let newList:number[] = [];
    for (let i=0;i<lista.length;i++){
        
        for (let j=0; j<newList.length;j++){
            if(lista[i]>newList[j]){
                newList = insertInTheMiddle(newList, lista[i], j+1);
            }

        }
    }
    return newList;
}


// console.log(insertInTheMiddle([1,4,5], 3, 1))
console.log(insertionSortIn([7,1,4,5]))