#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include "Comparacao.h"
#include "MetodosOrdenacao.h"

GtkBuilder      *builder; 
GtkWidget       *window;
GtkStack        *stack;
GtkListStore    *lista;
GtkTreeIter     iter;

int cont = 0, ver = 0, metodos[4] = {0, 0, 0, 0}, V[30000];
int ordem_compara = 1, tamanhos[5] = {1000, 5000, 10000, 20000, 30000};
float aux;
char texto[10000];

void on_button_voltar_compara_clicked(GtkWidget *widget, gpointer data){

    gtk_stack_set_visible_child_name(stack, "view_modulos");
}

void on_button_run_compara_clicked(GtkWidget *widget, gpointer data){
    
    gtk_list_store_clear(lista);
    
    if(ver < 2){
        gtk_list_store_append(lista, &iter);
        gtk_list_store_set(lista, &iter, 0, "Informe dois",-1);
        gtk_list_store_append(lista, &iter);
        gtk_list_store_set(lista, &iter, 0,"ou mais métodos",-1);
    }

    if(metodos[0] && ver >1){
        gtk_list_store_append(lista, &iter);
        gtk_list_store_set(lista, &iter, 0, "Bubble Sort",-1);

        for(cont=0; cont<5; cont++){
            ordenacao(V, tamanhos[cont], ordem_compara);
            clock_t tempo;

            tempo = clock();
            bubbleSort(V, tamanhos[cont]);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;

            sprintf(texto, "%.5f ms", aux);   
            gtk_list_store_set(lista, &iter, cont+1, texto,-1);  
        }
    }

    if(metodos[1] && ver >1){
        gtk_list_store_append(lista, &iter);
        gtk_list_store_set(lista, &iter, 0, "Selection Sort",-1);

        for(cont=0; cont<5; cont++){
            ordenacao(V, tamanhos[cont], ordem_compara);
            clock_t tempo;

            tempo = clock();
            selectionSort(V, tamanhos[cont]);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;

            sprintf(texto, "%.5f ms", aux);   
            gtk_list_store_set(lista, &iter, cont+1, texto,-1);  
        }

    } 
    
    if(metodos[2] && ver >1){
        gtk_list_store_append(lista, &iter);
        gtk_list_store_set(lista, &iter, 0, "Insertion Sort",-1);

        for(cont=0; cont<5; cont++){
            ordenacao(V, tamanhos[cont], ordem_compara);
            clock_t tempo;

            tempo = clock();
            insertionSort(V, tamanhos[cont]);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;

            sprintf(texto, "%.5f ms", aux);   
            gtk_list_store_set(lista, &iter, cont+1, texto,-1);  
        }

    } 
    
    if(metodos[3] && ver >1){
        gtk_list_store_append(lista, &iter);
        gtk_list_store_set(lista, &iter, 0, "Quick Sort",-1);

        for(cont=0; cont<5; cont++){
            ordenacao(V, tamanhos[cont], ordem_compara);
            clock_t tempo;

            tempo = clock();
            quickSort(V, 0, tamanhos[cont]);
            tempo = clock() - tempo;

            aux = ((float)tempo/CLOCKS_PER_SEC);
            aux = aux*1000;

            sprintf(texto, "%.5f ms", aux);   
            gtk_list_store_set(lista, &iter, cont+1, texto,-1);  
        }

    } 
    
}

//--------------------------------------------------odernação ( V )----------------------------------------------------//

void on_radio_crescente_compara_toggled(GtkWidget *widget, gpointer data){
    ordem_compara = 1;
}

void on_radio_decrescente_compara_toggled(GtkWidget *widget, gpointer data){
    ordem_compara = 0;
}

void on_radio_aleatorio_compara_toggled(GtkWidget *widget, gpointer data){
    ordem_compara = 2;
}

//---------------------------------------------metodos para comparação ( V )-------------------------------------------//

void on_check_box_bubble_sort_toggled(GtkCheckButton *b){
    gboolean ativo = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

    if(ativo){
        metodos[0] = 1;
        ver++;
    } else {
        metodos[0] = 0;
        ver--;
    }
}

void on_check_box_selection_sort_toggled(GtkCheckButton *b){
    gboolean ativo = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

    if(ativo){
        metodos[1] = 1;
        ver++;
    } else {
        metodos[1] = 0;
        ver--;
    }

}

void on_check_box_insertion_sort_toggled(GtkCheckButton *b){
    gboolean ativo = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

    if(ativo){
        metodos[2] = 1;
        ver++;
    } else {
        metodos[2] = 0;
        ver--;
    }

}

void on_check_box_quick_sort_toggled(GtkCheckButton *b){
    gboolean ativo = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

    if(ativo){
        metodos[3] = 1;
        ver++;
    } else {
        metodos[3] = 0;
        ver--;
    }
}