void insereInicio(No **lista, int id){
    No *novo;

    novo = (No *) malloc(sizeof(No));
    novo->dado = id;

    if(listaEstaVazia(*lista) == 1){
        novo->proximo = NULL;
    }else{
        novo->proximo = *lista;
    }

    //o novo noh
    *lista = novo;

    return;
}

void insereFinal(No **lista, int id){
    No *novo;
    No *aux = *lista;

    novo = (No *) malloc(sizeof(No));
    novo->dado = id;
    novo->proximo = NULL;

    if(listaEstaVazia(*lista) == 1){
        *lista = novo;
        return;
    }

    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = novo;

    return;
}