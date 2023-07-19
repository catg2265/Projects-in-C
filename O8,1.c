#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    for (int i = 0; i >= 25; i++)
    {
        maaltid(i);
    }
}
void maaltid(int i)
{
    srand(time(NULL));
    enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};
    enum hovedret {gyldenkaal, hakkeboef, gullash, foloren_hare};
    enum dessert {pandekager_med_is, gulerodskage, chokolademousse, citronfromage};
    switch (rand() % 4)
    {
        case 0:
        
    }
}