#mkdir gtk
#cd gtk
#vi base.c // here add command to download the gtk program from  github
sudo apt-get update
sudo apt-get install pkg-config -y
sudo apt-get update
sudo apt-get install pkg-config -y
export PKG_CONFIG_PATH=/usr/bin:$PKG_CONFIG_PATH
sudo apt-get update
sudo apt-get install gtk+2.0 -y
sudo apt-get update
sudo apt-get install gtk+2.0 -y
#gcc base.c -o base `pkg-config --cflags --libs gtk+-2.0`
#gcc haifux.c -o base `pkg-config --cflags --libs gtk+-2.0`
#gcc haifux.c -o weather `pkg-config --cflags --libs gtk+-2.0`

#write here the commands to download from git
gcc haifux.c -o WeatherApp `pkg-config --cflags --libs gtk+-2.0`
chmod 777 WeatherApp
gcc gtk-dlg.c -o gtk-dlg `pkg-config --cflags --libs gtk+-2.0`
chmod 777 gtk-dlg 
gcc defaultbutton.c -o defaultbutton `pkg-config --cflags --libs gtk+-2.0`
chmod 777 defaultbutton 

#if desktop version on ubuntu 18 is not installed then this step would be needed
sudo apt install ubuntu-desktop -y

#https://askubuntu.com/questions/765526/how-to-install-gtk2-0
#https://stackoverflow.com/questions/3834166/textbox-with-a-label-in-a-gtk-program
#http://haifux.org/lectures/34+35/examples/gtk-entry.c
#https://www.cc.gatech.edu/data_files/public/doc/gtk/tutorial/gtk_tut-3.html
#https://stackoverflow.com/questions/33247405/gtk-displaying-a-dialog-from-within-a-dialog
#https://github.com/steshaw/gtk-examples/blob/master/ch11.color.font/dialog.c
#http://zetcode.com/gui/gtk2/gtkdialogs/
