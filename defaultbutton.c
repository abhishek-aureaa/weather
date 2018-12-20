#include <gtk/gtk.h>

/* Uncomment the below macro to see the default focus */
//#define DEFAULT_FOCUS 

int main(void)
{
    gtk_init (NULL, NULL);
#ifdef DIALOG_WITH_BUTTONS
    GtkWidget * dialog = gtk_dialog_new_with_buttons ("Dialog",
                    NULL,
                    GTK_DIALOG_MODAL,
                    GTK_STOCK_CANCEL,
                    GTK_RESPONSE_CANCEL,
                    GTK_STOCK_OK,
                    GTK_RESPONSE_OK,
                    NULL);
#ifndef DEFAULT_FOCUS
    gtk_widget_grab_focus(gtk_dialog_get_widget_for_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK));
#endif

#else

    char buffer[5000];
    memset(buffer, '\0', 5000);
    char temp[300];
	memset(temp, '\0', 300);
	int ret = 0;
	//FILE* fp = fopen("a.txt", "r");
	FILE* fp = fopen("/root/Weather/weather-1.2.0/_builds/weather.log", "r");
	while(ret != EOF)
	{
		memset(temp, '\0', 300);
  	    ret = fscanf(fp, "%s", temp);
		strcat(buffer, temp);
		strcat(buffer, "\n");
		//printf(buffer);
	}
	printf("whole file\n");
	printf(buffer);


    GtkWidget *dialog = gtk_dialog_new();
    //gtk_window_set_title(GTK_WINDOW(dialog), "Dialog");
    gtk_window_set_title(GTK_WINDOW(dialog), buffer);
    GtkWidget *action_area = gtk_dialog_get_action_area(GTK_DIALOG(dialog));
    GtkWidget *ok_button = gtk_button_new_with_label("OK");
    //GtkWidget *cancel_button = gtk_button_new_with_label("Cancel");
    //gtk_container_add(GTK_CONTAINER(action_area), cancel_button);
    gtk_container_add(GTK_CONTAINER(action_area), ok_button);
    gtk_widget_show_all(dialog);
#ifndef DEFAULT_FOCUS
    gtk_widget_grab_focus(ok_button);
#endif

#endif
    g_signal_connect(dialog, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_main();
    return 0;
}
