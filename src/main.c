#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "MetodosOrdenacao.h"
#include "Aprendizagem.h"
#include "Comparacao.h"

//SortNoResort//

GtkBuilder      *builder; 
GtkWidget       *window;
GtkStack        *stack;
GtkEntry        *metodo_aprende;
GtkEntry        *tamanho_aprende;
GtkEntry        *qtd_aprende;
GtkTextView     *display_aprende;
GtkListStore    *lista;


void on_main_window_destroy(){
    gtk_main_quit();
}

//Modulos

void on_button_aprende_clicked(GtkWidget *widget, gpointer data){

    gtk_stack_set_visible_child_name(stack, "view_aprendizagem");
}

void on_button_compara_clicked(GtkWidget *widget, gpointer data){

    gtk_stack_set_visible_child_name(stack, "view_comparacao");
}


int main(int argc, char* argv[]){

    gtk_init(&argc, &argv);
    
    //construtor
    
    builder = gtk_builder_new_from_file("glade/Sort.glade");

    //conecta os sinais
    
    gtk_builder_add_callback_symbol(builder, "on_main_window_destroy", G_CALLBACK(on_main_window_destroy));
    gtk_builder_add_callback_symbol(builder, "on_button_aprende_clicked", G_CALLBACK(on_button_aprende_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_compara_clicked", G_CALLBACK(on_button_compara_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_voltar_aprende_clicked", G_CALLBACK(on_button_voltar_aprende_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_voltar_compara_clicked", G_CALLBACK(on_button_voltar_compara_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_pseudo_clicked", G_CALLBACK(on_button_pseudo_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_falar_sobre_clicked", G_CALLBACK(on_button_falar_sobre_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_run_aprende_clicked", G_CALLBACK(on_button_run_aprende_clicked));
    gtk_builder_add_callback_symbol(builder, "on_button_run_compara_clicked", G_CALLBACK(on_button_run_compara_clicked));
    gtk_builder_add_callback_symbol(builder, "on_entry_metodos_aprende_changed", G_CALLBACK(on_entry_metodos_aprende_changed));
    gtk_builder_add_callback_symbol(builder, "on_box_metodos_aprende_changed", G_CALLBACK(on_box_metodos_aprende_changed));
    gtk_builder_add_callback_symbol(builder, "on_entry_quantidade_vetor_changed", G_CALLBACK(on_entry_quantidade_vetor_changed));
    gtk_builder_add_callback_symbol(builder, "on_entry_tamanho_vetor_changed", G_CALLBACK(on_entry_tamanho_vetor_changed));
    
    gtk_builder_add_callback_symbol(builder, "on_radio_crescente_aprende_toggled", G_CALLBACK(on_radio_crescente_aprende_toggled));
    gtk_builder_add_callback_symbol(builder, "on_radio_decrescente_aprende_toggled", G_CALLBACK(on_radio_decrescente_aprende_toggled));
    gtk_builder_add_callback_symbol(builder, "on_radio_aleatorio_aprende_toggled", G_CALLBACK(on_radio_aleatorio_aprende_toggled));
    
    gtk_builder_add_callback_symbol(builder, "on_radio_crescente_compara_toggled", G_CALLBACK(on_radio_crescente_compara_toggled));
    gtk_builder_add_callback_symbol(builder, "on_radio_decrescente_compara_toggled", G_CALLBACK(on_radio_decrescente_compara_toggled));
    gtk_builder_add_callback_symbol(builder, "on_radio_aleatorio_compara_toggled", G_CALLBACK(on_radio_aleatorio_compara_toggled));
    
    gtk_builder_add_callback_symbol(builder, "on_check_box_bubble_sort_toggled", G_CALLBACK(on_check_box_bubble_sort_toggled));
    gtk_builder_add_callback_symbol(builder, "on_check_box_selection_sort_toggled", G_CALLBACK(on_check_box_selection_sort_toggled));
    gtk_builder_add_callback_symbol(builder, "on_check_box_insertion_sort_toggled", G_CALLBACK(on_check_box_insertion_sort_toggled));
    gtk_builder_add_callback_symbol(builder, "on_check_box_quick_sort_toggled", G_CALLBACK(on_check_box_quick_sort_toggled));


    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, NULL);

    stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    metodo_aprende = GTK_ENTRY(gtk_builder_get_object(builder, "entry_metodos_aprende"));
    tamanho_aprende = GTK_ENTRY(gtk_builder_get_object(builder, "entry_tamanho_vetor"));
    qtd_aprende = GTK_ENTRY(gtk_builder_get_object(builder, "entry_quantidade_vetor"));
    display_aprende = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "display_aprende"));
    lista = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore2"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();
    
    return 0;
}
