#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include "Aprendizagem.h"
#include "MetodosOrdenacao.h"
#include "Escrita.h"

GtkBuilder      *builder; 
GtkWidget       *window;
GtkStack        *stack;
GtkEntry        *metodo_aprende;
GtkEntry        *tamanho_aprende;
GtkEntry        *qtd_aprende;
GtkTextView     *display_aprende;
GtkTextBuffer   *buffer_escrita;

char metodo[46];
int qtd = 0;
int tamanho = 0;
int ordem_aprende = 1;
char texto[1000000];


void on_button_voltar_aprende_clicked(GtkWidget *widget, gpointer data){

    gtk_stack_set_visible_child_name(stack, "view_modulos");
}



//---------------------------------------------------saidas display ( V )-----------------------------------------------//

void on_button_pseudo_clicked(GtkWidget *widget, gpointer data){
    
    buffer_escrita = gtk_text_view_get_buffer(display_aprende);
    strcpy(texto, "");
    
    if(metodo[0] == 'B'){
        informacao(texto, 3, 28);

    } 

    else if(metodo[0] == 'I'){
        informacao(texto, 65, 88);

    }

    else if(metodo[0] == 'S'){
        informacao(texto, 133, 160);

    }

    else if(metodo[0] == 'Q'){
        informacao(texto, 192, 238);

    } else {
        strcpy(texto, "insira um metodo");
    }

    gtk_text_buffer_set_text(buffer_escrita, (const char *) texto, (gint) -1);
    
}

void on_button_falar_sobre_clicked(GtkWidget *widget, gpointer data){

    buffer_escrita = gtk_text_view_get_buffer(display_aprende);
    strcpy(texto, "");
    if(metodo[0] == 'B'){
        informacao(texto, 31, 62);

    } 

    else if(metodo[0] == 'I'){
        informacao(texto, 89, 130);

    }

    else if(metodo[0] == 'S'){
        informacao(texto, 163, 188);

    }

    else if(metodo[0] == 'Q'){
        informacao(texto, 241, 282);

    } else {
        strcpy(texto, "insira um metodo");
    }

    gtk_text_buffer_set_text(buffer_escrita, (const char *) texto, (gint) -1);
}

void on_button_run_aprende_clicked(GtkWidget *widget, gpointer data){
    buffer_escrita = gtk_text_view_get_buffer(display_aprende);
    int i, V[tamanho];
    char tmp[100000];
    float aux, media;
    strcpy(texto, "");

    if(tamanho == 0){
        strcpy(texto, "Informe Tamanho");

    }

    else if(qtd == 0){
        strcpy(texto, "Informe Quantidade");

    }

    else if(metodo[0] == 'B'){

        for(i=0; i<qtd; i++){
            
            ordenacao(V, tamanho, ordem_aprende);
            clock_t tempo;

            tempo = clock();
            bubbleSort(V, tamanho);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;
            media = (media + aux/qtd);

            sprintf(tmp, "tempo %d: %.5f ms\n", i, aux);
            strcat(texto, tmp);
        }
        sprintf(tmp,"\ntempo médio: %.5f ms", aux);
        strcat(texto, tmp);
    } 

    else if(metodo[0] == 'I'){

        for(i=0; i<qtd; i++){
            
            ordenacao(V, tamanho, ordem_aprende);
            clock_t tempo;

            tempo = clock();
            insertionSort(V, tamanho);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;
            media = (media + aux/qtd);

            sprintf(tmp, "tempo %d: %.5f ms\n", i, aux);
            strcat(texto, tmp);
        }
        sprintf(tmp,"\ntempo médio: %.5f ms", aux);
        strcat(texto, tmp);
    }

    else if(metodo[0] == 'S'){
        
        for(i=0; i<qtd; i++){
            
            ordenacao(V, tamanho, ordem_aprende);
            clock_t tempo;

            tempo = clock();
            selectionSort(V, tamanho);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;
            media = (media + aux/qtd);

            sprintf(tmp, "tempo %d: %.5f ms\n", i, aux);
            strcat(texto, tmp);
        }
        sprintf(tmp,"\ntempo médio: %.5f ms", aux);
        strcat(texto, tmp);

    }

    else if(metodo[0] == 'Q'){
        
        for(i=0; i<qtd; i++){
            
            ordenacao(V, tamanho, ordem_aprende);
            clock_t tempo;

            tempo = clock();
            quickSort(V, 0,tamanho-1);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;
            media = (media + aux/qtd);

            sprintf(tmp, "tempo %d: %.5f ms\n", i, aux);
            strcat(texto, tmp);
        }
        sprintf(tmp,"\ntempo médio: %.5f ms", aux);
        strcat(texto, tmp);

    } else {
        strcpy(texto, "Informe Método");
    }

    gtk_text_buffer_set_text(buffer_escrita, (const char *) texto, (gint) -1);
}

//-------------------------------------------------entrada de tam e qtd ( V )-------------------------------------------//

void on_entry_tamanho_vetor_changed(GtkWidget *widget, gpointer data){
    char temp[46];
    sprintf(temp, "%s", gtk_entry_get_text(tamanho_aprende));
    tamanho = atoi(temp);
}

void on_entry_quantidade_vetor_changed(GtkWidget *widget, gpointer data){
    char temp[46];
    sprintf(temp, "%s", gtk_entry_get_text(qtd_aprende));
    qtd = atoi(temp);
}

//-------------------------------------------------selecionar metodo ( V )----------------------------------------------//

void on_entry_metodos_aprende_changed(GtkWidget *widget, gpointer data){
    sprintf(metodo, "%s", gtk_entry_get_text(metodo_aprende));
    
}

void on_box_metodos_aprende_changed(GtkWidget *widget, gpointer data){
    
    
}

 
//----------------------------------------------------odernação ( V )---------------------------------------------------//

void on_radio_crescente_aprende_toggled(GtkWidget *widget, gpointer data){
    gboolean A = 
    ordem_aprende = 1;
}

void on_radio_decrescente_aprende_toggled(GtkWidget *widget, gpointer data){
    ordem_aprende = 0;
}

void on_radio_aleatorio_aprende_toggled(GtkWidget *widget, gpointer data){
    ordem_aprende = 2;
}