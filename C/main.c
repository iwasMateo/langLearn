#include <gtk/gtk.h>

void on_button_clicked(GtkButton *button, gpointer user_data) {
  g_print("Button clicked\n");
}

void on_active(GtkApplication *app, gpointer user_data) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "GTK test");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
  GtkWidget *box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
  gtk_window_set_child(GTK_WINDOW(window), box);
  GtkWidget *button = gtk_button_new_with_label("Click here bitch");
  g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
  GtkWidget *label = gtk_label_new("Hi");
  gtk_window_set_child(GTK_WINDOW(box), label);
  gtk_window_set_child(GTK_WINDOW(box), button);
  gtk_window_present(GTK_WINDOW(window));
}

int main(int arg1, char *arg2[]) {
  GtkApplication *app;
  int status;
    //stop when i tell you to
  app = gtk_application_new("io.github.iwasmateo", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(on_active), NULL);
  status = g_application_run(G_APPLICATION(app), arg1, arg2);
  g_object_unref(app);
  return status;
}
