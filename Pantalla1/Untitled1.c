
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LIB01.h"

#define TAMC 30

typedef struct
{
    int iCoorx;
    int iCoory;
    int iColor;
}PIX;


void generaMalla();
void colores();
int ObtenerColor();
void PonerColor(int color);
void llenaBarra();
int pideNum();
int asignaMem(PIX ***ptrArr, int n, int m);
void creaMalla(PIX **ptrArr, int n, int m);
void guardarColor(PIX **ptrArr, int n, int m);
void liberaMem(PIX **ptrArr, int n, int m);
void imprimirCor(PIX **ptrArr, int n, int m);
void iniStru(PIX **ptrArr, int n, int m);
int impStruc(PIX **ptrArr, int n, int m);

int main()
{
    initwindow(800, 600, "HOLA");
    int selcol = 0;
    PIX **ptrArr;
    int res, ren, col;
    ren = pideNum();
    col = pideNum();
    res = asignaMem(&ptrArr, ren, col);
    iniStru(ptrArr, ren, col);
    if (res == 1)
    {
        creaMalla(ptrArr, ren, col);
        colores();
        selcol = ObtenerColor();
        if (selcol==1){
            guardarColor(ptrArr, ren, col);
            printf("Color Guardado\n");
            imprimirCor(ptrArr, ren, col);
            impStruc(ptrArr, ren, col);
            liberaMem(ptrArr, ren, col);
        }
    }
    //getch();
    return 0;
}

/*
void generaMalla()
{
    setcolor(15);
    int x1, x2, y1, y2;
    x1 = 20, y1 = 20, x2 = 30, y2 = 30;
    for (int i = 0; i < 50; i++)
    {
        y1 += 10;
        x1 = 20;
        for (int i = 0; i < 50; i++)
        {
         rectangle(x1, y1, x2+x1, y2+y1);
         x1 += 10;
        }
    }
}*/

void colores()
{
    setcolor(15);
    int x1, x2, y1, y2;
    x1 = 550, y1 = 20, x2 = 580, y2 = 50;

    int col = 0;
    for (int i = 0; i < 2; i++)
    {
        x1 += TAMC;
        x2 += TAMC;
        y1 = 20;
        y2 = 50;
        for (int i = 0; i < 8; i++)
        {
            exterior(x1, y1, x2, y2, col);
            y1+= TAMC;
            y2+= TAMC;
            col++;
        }
    }
}

int ObtenerColor()
{
    int iXraton, iYraton, color = 0, band = 0;
        char cCualTecla;
        do{
            fflush(stdin);
        if(kbhit()){
            cCualTecla=getch();
            //opcion(cCualTecla);
            switch(cCualTecla){
                 case 32: band = 1;
                          break;
            }
        }
        if(ismouseclick(WM_RBUTTONDOWN)){
            getmouseclick(WM_RBUTTONDOWN,iXraton,iYraton);
            color = getpixel(iXraton, iYraton);
            printf("Color: %d", color);
            }
        if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN,iXraton,iYraton);
            if (iXraton < 520 && iYraton > 20 && iYraton < 520 && iXraton > 20){
            //setcolor(color);
            //bar(iXraton, iYraton, iXraton+10, iYraton+10);
            setfillstyle(1,color);
            floodfill(iXraton+1, iYraton+1, 15);
            //FillRect(iXraton, iYraton, )
            printf("Color: %d", color);
            }
        }
    } while(band != 1 && cCualTecla != 32);
    return(band);
}


int pideNum()
{
    int num;
    printf("Ingrese el numero de renglones y/o columnas\n");
    scanf("%d", &num);
    return (num);
}

int asignaMem(PIX ***ptrArr, int n, int m)
{
    int res = 0, i;

    *ptrArr = (PIX**)malloc(sizeof(PIX*)*n);

    if (*ptrArr != NULL)
    {
        res = 1;

        for (i = 0; i < m && res == 1; i++)
        {
            *(*ptrArr+i) = (PIX*)malloc(sizeof(PIX));

            if (*(*ptrArr+i) == NULL)
            {
                while (--i > 0)
                {
                    free(*(*ptrArr+i));
                }
                free(*ptrArr);
                res = 0;
            }
        }
    }
    return(res);
}


void creaMalla(PIX **ptrArr, int n, int m)
{
    int tamDispx = 500;
    int tamDispy = 500;
    int x1, x2, y1, y2;
    x1 = 20, y1 = 20, x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            setcolor(15);
            rectangle(x1, y1, x2, y2);
            y1 = y2;
            y2 = y1+(tamDispy/m);
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 20;
        y2 = y1 + (tamDispy/m);
    }

}

void guardarColor(PIX **ptrArr, int n, int m)
{
    int tamDispx = 500;
    int tamDispy = 500;
    int x1, x2, y1, y2, iCordx = 0, iCordy = 0;
    x1 = 20, y1 = 20, x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (int i = 0; i < n; i++)
    {
        iCordx = 0;
        for (int j = 0; j < m; j++)
        {
            (*(ptrArr+i)+j)->iColor = getpixel(x1+3, y1+3);
            (*(ptrArr+i)+j)->iCoorx = j;
            (*(ptrArr+i)+j)->iCoory = i;
            y1 = y2;
            y2 = y1+(tamDispy/m);
            iCordx++;
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 20;
        y2 = y1 + (tamDispy/m);
        iCordy++;
    }

}

void liberaMem(PIX **ptrArr, int n, int m)
{
    for(int i = m; i > m; i--)
    {
        free((*ptrArr+i));
    }
    free(*ptrArr);
}

void imprimirCor(PIX **ptrArr, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("X = %d ", (*(ptrArr+i)+j)->iCoorx);
            printf("Y = %d ", (*(ptrArr+i)+j)->iCoory);
            printf("Color = %d ", (*(ptrArr+i)+j)->iColor);
            printf("\n");
        }
    }
}

void iniStru(PIX **ptrArr, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            (*(ptrArr+i)+j)->iColor = 0;
            (*(ptrArr+i)+j)->iCoorx = 0;
            (*(ptrArr+i)+j)->iCoory = 0;
        }
    }
}

int impStruc(PIX **ptrArr, int n, int m)
{
    initwindow(800, 600, " ");
    int tamDispx = 500;
    int tamDispy = 500;
    int x1, x2, y1, y2;
    x1 = 20, y1 = 20, x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            setfillstyle(1,(*(ptrArr+i)+j)->iColor);
            setcolor(15);
            rectangle(x1, y1, x2, y2);
            floodfill(x1+3, x2+3, 15);
            y1 = y2;
            y2 = y1+(tamDispy/m);
        }
        x1 = x2;
        x2 = x1+(tamDispx/n);
        y1 = 20;
        y2 = y1 + (tamDispy/m);
    }

}

/*void PonerColor( int color)
{
    int iXraton, iYraton, buff = 0;
    if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN,iXraton,iYraton);
            setcolor(color);
            floodfill(iXraton, iYraton, 1);
            printf("Color: %d", color);
            }
}

void llenaBarra()
{
    setcolor(15);
    //setfillstyle(1, 6);
    rectangle(700, 500, 750, 550);
    //bar(700, 500, 750, 550);
    setfillstyle(1, 6);
    //setcolor(0);
    floodfill(730, 530, 15);
}
*/
