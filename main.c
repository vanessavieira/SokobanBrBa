#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "teclado.h"
#include "menu.h"
#include "inicializacao.h"
#include "fase_1.h"
#include "fase_2.h"
#include "fase_3.h"
#include "instrucao.h"
#include "parabens.h"
#include "ranking.h"

int main()
{

    while(!exit_program)
    {
        inicializacao();
    }

    return 0;

} END_OF_MAIN();
