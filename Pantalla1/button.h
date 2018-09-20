#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED



#endif // BUTTON_H_INCLUDED

void oprimeBoton(int iCx, int iCy)
{
    setcolor(0);
    setfillstyle(1, 0);
    rectangle(100,100, 250, 125);
    if ((iCx > 100 )&&(iCy >= 100)&&(iCx <= 250)&&(iCy <= 125))
    {
        MovePacman();
        printf("se ha oprimido el menu");
    }
}
