void insereOrdenado (No **lista, int id){
    No *novo;
    No *aux = *lista;
    No *anterior = *lista;


   //aloca ponteiro novo 
    novo = (No*) malloc(sizeof(No));
    novo->dado = id;
    novo->proximo = NULL;

    //verifica lista vazia, caso esteja 
    if (listaVazia(*lista)){
        *lista=novo;
        return;
}
    
    //caminhar na lista                                  
    while (aux != NULL && aux->dado < id) {
        anterior = aux;
        aux = aux->proximo;    
    }

    if(aux == *lista){
        insereInicio(lista, id);
        return;
    }

    if(aux == NULL){
        insereFinal(lista, id);
        return;
    }

    anterior->proximo = novo;
    novo->proximo = aux;
    return;
}

void removeEspecifico(No **lista, int id){
    No *aux = *lista;
    No *anterior = *lista;

    if (listaVazia(*lista)){
        printf("Lista está vazia!\n");
        return;
    }

    printf("Removendo o nó de id %d\n", id);

    while (aux != NULL && aux->dado !=id) {
        anterior = aux;
        aux = aux->proximo;    
    }

    if(aux == NULL){
        printf("%d não foi encontrado na lista!!\n");
        return;
    }

    if(aux == *lista){
        removeInicio(lista);
        return;
    }

    if(aux->proximo == NULL){
        removeFinal(lista);
        return;
    }

    anterior->proximo = aux->proximo;
    free(aux);

}