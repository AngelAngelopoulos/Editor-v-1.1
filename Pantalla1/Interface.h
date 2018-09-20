#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

int menu();

#endif // INTERFACE_H_INCLUDED

int menu(){
    //initwindow(800, 600, "Raton"); //Inicializacion de la pantalla
    char cCualTecla;
    int iXraton, iYraton, res = 0;
    setcolor(15);
    rectangle(100,100, 250, 125);
    //exterior(100, 100, 250, 125, 15);
    floodfill(120, 120, 15);
    setfillstyle(1, 15);
    do {
        fflush(stdin); //Instruccion que libera el buffer de las variabless

        if(kbhit())
            {
                cCualTecla=getch(); //Instruccion que lee la tecla que fue presionada
            }
            if(ismouseclick(WM_LBUTTONDOWN))
                { //instruccion que detecta si el raton fue presionado
                    /*floodfill(120, 120, 9);
                    exterior(100, 100, 250, 125, 15);
                    interior(110, 110, 240, 115, 8);
                    exterior(110, 110, 240, 115, 0);
                    exterior(100, 100, 250, 125, 15);
                    floodfill(120, 120, 15);*/
                    getmouseclick(WM_LBUTTONDOWN, iXraton, iYraton); //Instruccion  que regresa las coordendass
                                                                //En donde se hizo click con el raton
                    if ((iXraton > 100 )&&(iYraton >= 100)&&(iXraton <= 250)&&(iYraton <= 125))
                        {
                            res = 1;
                        }
                }
        } while(cCualTecla!=27 || res == 1); //fin de DO esperrando que no se presione la tecla esc cuando es
        return (res);                        //Presionada la tecla ESC el ciclo termina
}

