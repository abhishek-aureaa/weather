#include <stdio.h>
#include <gtk/gtk.h>
#include<X11/Xlib.h>

void show_info(GtkWidget *widget, gpointer window) {
//void show_info(GtkWidget *widget, gpointer window, char* msg) {

    char buffer[5000];
    memset(buffer, '\0', 5000);
    char temp[300];
        memset(temp, '\0', 300);
        int ret = 0;
        //FILE* fp = fopen("/root/Weather/weather-1.2.0/_builds/weather.log", "r");
        FILE* fp = fopen("./weather.log", "r");
        while(ret != EOF)
        {
                memset(temp, '\0', 300);
            ret = fscanf(fp, "%s", temp);
                strcat(buffer, temp);
                strcat(buffer, "\n");
        }

    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK,
            buffer);
            //"Download Completed\npppppp\nmmmmmm");
           // "Download Completed");
  gtk_window_set_title(GTK_WINDOW(dialog), "Information");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void show_error(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Error loading file");
  gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void show_question(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "Are you sure to quit?");
  gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void show_warning(GtkWidget *widget, gpointer window) {
    
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_WARNING,
            GTK_BUTTONS_OK,
            "Unallowed operation");
  gtk_window_set_title(GTK_WINDOW(dialog), "Warning");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

//int main(int argc, char *argv[]) {
int main1(int argc, char *argv[]) {
//int main1() {

  XInitThreads();

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *info;
  GtkWidget *warn;
  GtkWidget *que;
  GtkWidget *err;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 220, 150);
  gtk_window_set_title(GTK_WINDOW(window), "Message dialogs");

  table = gtk_table_new(2, 2, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  info = gtk_button_new_with_label("Info");

  gtk_table_attach(GTK_TABLE(table), info, 0, 1, 0, 1, 
      GTK_FILL, GTK_FILL, 3, 3);

  gtk_container_add(GTK_CONTAINER(window), table);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);


  g_signal_connect(G_OBJECT(info), "clicked", 
        //G_CALLBACK(show_info), (gpointer) window, "hellooo"); 
        G_CALLBACK(show_info), (gpointer) window); 

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}


/*
 * callback event function for the gtk delete event. invoked
 * when the application is closed using the window manager.
 */
int
delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    /* If you return FALSE in the "delete_event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs.
     */
 
    return(FALSE);
}


/* exit the application. */
void
exit_cb(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

//void execute();
void  execute(char* city);

/* "print text" button "clicked" callback function. */
void
on_button1_clicked(GtkButton* button, gpointer data)
{
    /* cast the data back to a GtkEntry*  */
    GtkEntry* entry = (GtkEntry*)data;

    execute(gtk_entry_get_text(entry));
    //printf("on_button_clicked - entry = '%s'\n", gtk_entry_get_text(entry));
    fflush(stdout);
}

/* "toggle editability" button "clicked" callback function. */
void
on_button2_clicked(GtkButton* button, gpointer data)
{
    static gboolean is_editable = TRUE;
    /* cast the data back to a GtkEntry*  */
    GtkEntry* entry = (GtkEntry*)data;

    if (is_editable) {
	gtk_entry_set_editable(entry, FALSE);
        is_editable = FALSE;
    }
    else {
	gtk_entry_set_editable(entry, TRUE);
        is_editable = TRUE;
    }
}


//void  execute(char **argv)
//void  execute()
void  execute(char* city)
{
     pid_t  pid;
     pid_t  pid1;
     int    status;

#if 0
     if ((pid = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          /* for the child process:         */
#endif 
          //if (execvp(*argv, argv) < 0) {     /* execute the command  */
	  /*
          if (execl("./lm", "lm", "clearactivation", 0);
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
	*/
          //execl("./lm", "lm", "clearactivation", 0);
          //execl("/usr/local/lm/bin/lm", "lm", "clearactivation", 0);
          //execl("lm", "lm", "clearactivation", 0);
          //execl("/root/Weather/weather-1.2.0/_builds/weather-cli", "/root/Weather/weather-1.2.0/_builds/weather-cli", "Munich", 0);
	  
	  //working
          //execl("/root/Weather/weather-1.2.0/_builds/weather-cli", "/root/Weather/weather-1.2.0/_builds/weather-cli", city, 0);
	  //
          //execl("/root/Weather/weather-1.2.0/_builds/weather-cli", "/root/Weather/weather-1.2.0/_builds/weather-cli", "Munich" , "> /root/Weather/weather-1.2.0/_builds/weather.log", 0);
          //execl("/root/Weather/weather-1.2.0/_builds/weather-cli",  "Munich", " > /root/Weather/weather-1.2.0/_builds/weather.log", 0);
	  
          //execl("/root/Weather/weather-1.2.0/_builds/weather.sh", "/root/Weather/weather-1.2.0/_builds/weather.sh", city, 0);
          //execl("/root/Weather/weather-1.2.0/_builds/weather.sh", city, city, 0);
          //execl("/bin/ls", "/bin/ls", city, 0);
          //execl("/root/a.sh", "/root/a.sh", city, 0);
          //execl("/root/defaultbutton", "/root/defaultbutton", city, 0);
	  
          //system("/root/a.sh");
          //system("/root/Weather/weather-1.2.0/_builds/weather.sh");
	  

           char ch[1000] = "";	  
	   strcat(ch,"./weather.sh ");
	   strcat(ch,city);
           system(ch);
	  //working
          //system("/root/Weather/weather-1.2.0/_builds/weather.sh Berlin");
          //system("/root/Weather/weather-1.2.0/_builds/weather.sh Berlin");
          //system("/root/defaultbutton");
          //system("/root/gtk-dlg");
          //system("./gtk-dlg");
	  main1(1,"weather");

#if 0
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid)       /* wait for completion  */
               ;
     }
#endif

#if 0
     if ((pid1 = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid1 == 0) {          /* for the child process:         */
          //if (execvp(*argv, argv) < 0) {     /* execute the command  */
	  /*
          if execl("./lm", "lm", "getactivation", 0);
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
	  */
          //execl("./lm", "lm", "getactivation", 0);
          //execl("/usr/local/lm/bin/lm", "lm", "getactivation", 0);
          execl("lm", "lm", "getactivation", 0);

     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid1)       /* wait for completion  */
               ;
     }
#endif
}

int
main(int argc, char* argv[])
{
    XInitThreads();
    /* this variable will store a pointer to the window object. */
    GtkWidget* main_window;
    /* this will store a horizontal box. */
    GtkWidget* hbox;
    /* these will store push buttons. */
    GtkWidget* button1;
    GtkWidget* button2;
    /* this will store a text entry. */
    GtkWidget* entry;


    /* This is called in all GTK applications. Arguments */
    /* are parsed from the command line and are returned */
    /* to the application.                               */
    gtk_init(&argc, &argv);

    /* create a new top-level window. */
    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* define some of the window's attributes. */
    //gtk_window_set_title(GTK_WINDOW (main_window),
    //                    "A Top Window For The Rest Of Us...");
    gtk_window_set_title(GTK_WINDOW (main_window),
                         "Weather App");
    gtk_container_set_border_width(GTK_CONTAINER (main_window), 5);

    /* make the window visible. */
    gtk_widget_show(main_window);

    /* When the window is given the "delete_event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event() function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function.
     */
    gtk_signal_connect(GTK_OBJECT (main_window), "delete_event",
                       GTK_SIGNAL_FUNC (delete_event), NULL);

    /* Here we connect the "destroy" event to a signal handler.
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete_event" callback.
     */
    gtk_signal_connect(GTK_OBJECT (main_window), "destroy",
                       GTK_SIGNAL_FUNC (exit_cb), NULL);

    /* create a new horizontal box, and add to top-level window. */
    hbox = gtk_hbox_new(TRUE, 20);
    gtk_container_add(GTK_CONTAINER(main_window), hbox);
    gtk_widget_show(hbox);

    /* create a text entry. */
    entry = gtk_entry_new_with_max_length(20);

    /* insert the following text into the text entry, as its initial value. */
    //gtk_entry_set_text(GTK_ENTRY(entry), "hello there");
    gtk_entry_set_text(GTK_ENTRY(entry), "Enter City Name");

    /* make the text entry visible. */
    gtk_widget_show(entry);

    /* add the text entry to the hbox. */
    gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, TRUE, 1);

    /* create a button, place in hbox, attach callback.   */
    /* note: button is created second, cause it needs the */
    /* entry's pointer as a parameter to its callback.    */
    //button1 = gtk_button_new_with_label("Print Text");
    button1 = gtk_button_new_with_label("Get Weather Details");
    gtk_widget_show(button1);
    gtk_box_pack_start(GTK_BOX(hbox), button1, FALSE, TRUE, 1);
    gtk_signal_connect(GTK_OBJECT(button1), "clicked",
                       GTK_SIGNAL_FUNC(on_button1_clicked),
                       (gpointer)entry);

#if 0
    /* create a 2nd button, place in hbox, attach callback. */
    button2 = gtk_button_new_with_label("Toggle Editablibity");
    gtk_widget_show(button2);
    gtk_box_pack_start(GTK_BOX(hbox), button2, FALSE, TRUE, 1);
    gtk_signal_connect(GTK_OBJECT(button2), "clicked",
                       GTK_SIGNAL_FUNC(on_button2_clicked),
                       (gpointer)entry);
#endif


    /* All GTK applications must have a gtk_main(). Control
     * ends here and waits for an event to occur (like a
     * key press or mouse event).
     */
    gtk_main();

    exit(0);
}
