#ifndef Comparacao
#define Comparacao



void on_button_voltar_compara_clicked(GtkWidget *widget, gpointer data);
void on_button_run_compara_clicked(GtkWidget *widget, gpointer data);

void on_radio_crescente_compara_toggled(GtkWidget *widget, gpointer data);
void on_radio_decrescente_compara_toggled(GtkWidget *widget, gpointer data);
void on_radio_aleatorio_compara_toggled(GtkWidget *widget, gpointer data);
void on_check_box_bubble_sort_toggled(GtkCheckButton *b);
void on_check_box_selection_sort_toggled(GtkCheckButton *b);
void on_check_box_insertion_sort_toggled(GtkCheckButton *b);
void on_check_box_quick_sort_toggled(GtkCheckButton *b);



#endif