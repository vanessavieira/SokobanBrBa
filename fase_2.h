FASE_2()
{
    fase_atual = 2;
    /*
        1 = MURO
        2 = CHAO
        3 = BONECO
        5 = BURACO
        7 = PEDRA
    */
    ///VARIAVEIS
    int posicoesAtuais[7][7] =
    {
        {1, 1  , 1  , 1   , 1  , 1, 1},
        {1, 2*5, 2  , 2   , 2*3, 2, 1},
        {1, 2  , 1  , 2*5 , 1  , 2, 1},
        {1, 2  , 2  , 2   , 2*7, 2, 1},
        {1, 2*5, 2*7, 2*7 , 2  , 1, 1},
        {1, 2  , 2  , 1   , 1, 1  , 1},
        {1, 1  , 1  , 1   , 1  , 1, 1}
    };
    int inicio[7][7] =
    {
        {1, 1  , 1  , 1   , 1  , 1, 1},
        {1, 2*5, 2  , 2   , 2*3, 2, 1},
        {1, 2  , 1  , 2*5 , 1  , 2, 1},
        {1, 2  , 2  , 2   , 2*7, 2, 1},
        {1, 2*5, 2*7, 2*7 , 2  , 1, 1},
        {1, 2  , 2  , 1   , 1, 1  , 1},
        {1, 1  , 1  , 1   , 1  , 1, 1}
    };
    int i, k;
    int soma_linha = 0;
    int soma_coluna = 0;
    int stop = FALSE;
    int mapaValido;
    int back_up[7][7];
    int contador_movimento_2 = 0;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* boneco = load_bitmap("sprites/Personagens/jesse.bmp", NULL);
    BITMAP* fase_2 = load_bitmap("sprites/Fases/fase-2-facil.bmp", NULL);
    BITMAP* meta = load_bitmap("sprites/Fases/meta.bmp", NULL);
    BITMAP* background = load_bitmap("sprites/Fundos/FUNDO_2.bmp", NULL);

    /// GAME LOOP
    while(!exit_program || !key[KEY_ESC])
    {
        int mapaAcabou = TRUE;

        //DRAW
        draw_sprite(buffer, background, 0, 0);
        draw_sprite(buffer, fase_2, 30, 70);
        textprintf_ex(buffer, font, 540, 108.5, makecol(51, 51, 51), -1, "%d", contador_movimento_2);

        //verifica se as pedras estao nos buracos (se o mapa acabou)
        for (i = 0; i < 7; i++)
        {
            for (k = 0; k < 7; k++)
            {
                if (posicoesAtuais[i][k] % 5 == 0 && posicoesAtuais[i][k] % 7 != 0)
                {
                    mapaAcabou = FALSE;
                }
            }
        }

        if (mapaAcabou)
        {
            contador_movimento_total += contador_movimento_2;
            passou_fase();
        }

        //INPUT
        keyboard_input();

        if(key[KEY_ESC])
        {
            fecha_programa();
        }
        else if (key[KEY_SPACE])
        {
            menu();
        }

        //backup do estado do array
        for (i = 0; i < 7; i++)
        {
            for (k = 0; k < 7; k++)
            {
                back_up[i][k] = posicoesAtuais[i][k];
            }
        }

        //UPDATE
        soma_linha = 0;
        soma_coluna = 0;

        if(apertou(KEY_UP))
        {
            soma_linha = -1;
            contador_movimento_2++;

        } else if(apertou(KEY_DOWN))
        {
            soma_linha = 1;
            contador_movimento_2++;

        } else if(apertou(KEY_LEFT))
        {
            soma_coluna = -1;
            contador_movimento_2++;

        } else if(apertou(KEY_RIGHT))
        {
            soma_coluna = 1;
            contador_movimento_2++;

        } else if(apertou(KEY_R))
        {
            for (i = 0; i < 7; i++)
            {
                for (k = 0; k < 7; k++)
                {
                    posicoesAtuais[i][k] = inicio[i][k];
                    contador_movimento_2 = 0;
                }
            }
        }

        //andar do boneco
        for (i = 0; i < 7 && !stop; i++)
        {
            for (k = 0; k < 7 && !stop; k++)
            {
                if (posicoesAtuais[i][k] % 3 == 0) //boneco no chao
                {
                    posicoesAtuais[i][k] = posicoesAtuais[i][k]/3;
                    posicoesAtuais[i+soma_linha][k+soma_coluna] = posicoesAtuais[i+soma_linha][k+soma_coluna]*3;
                    stop = TRUE;
                }
            }
        }

        //andar da pedra
        stop = FALSE;
        for (i = 0; i < 7 && !stop; i++)
        {
            for (k = 0; k < 7 && !stop; k++) //pedra em cima do boneco
            {
                if (posicoesAtuais[i][k] % 42 == 0)
                {
                    posicoesAtuais[i][k] = posicoesAtuais[i][k]/7;
                    posicoesAtuais[i+soma_linha][k+soma_coluna] = posicoesAtuais[i+soma_linha][k+soma_coluna]*7;
                    stop = TRUE;
                }
            }
        }

        stop = FALSE;

        //verificar se as pedras (7) e o boneco (3) nao estao em cima de um lugar que nao podem ficar (!= %2)
        mapaValido = 1;

        for (i = 0; i < 7 && !stop; i++)
        {
            for (k = 0; k < 7 && !stop; k++)
            {
                //se uma pedra ou boneco ficou em cima do muro
                if ((posicoesAtuais[i][k] % 3 == 0 || posicoesAtuais[i][k] % 7 == 0) && posicoesAtuais[i][k] % 2 != 0)
                {
                    mapaValido = 0;
                    stop = TRUE;
                }
                //pedra em cima de outra
                if (posicoesAtuais[i][k] % 49 == 0)
                {
                    mapaValido = 0;
                    stop = TRUE;
                }
            }
        }

        if (!mapaValido)
        {
            for (i = 0; i < 7; i++)
            {
                for (k = 0; k < 7; k++)
                {
                    posicoesAtuais[i][k] = back_up[i][k];
                }
            }
        }

        //se todas posicoes estao validas
        for (i = 0; i < 7; i++)
        {
            for (k = 0; k < 7; k++)
            {
                if (posicoesAtuais[i][k] % 7 == 0) // chao = pedra
                {
                    draw_sprite(buffer, meta, k*50+30, i*50+70);
                }
                if (posicoesAtuais[i][k] % 3 == 0) // chao = boneco
                {
                    draw_sprite(buffer, boneco, k*50+30, i*50+70);
                }
            }
        }
        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));
    }
    ///FINALIZACAO
    destroy_bitmap(background);
    destroy_bitmap(fase_2);
    destroy_bitmap(boneco);
    destroy_bitmap(meta);
    destroy_bitmap(buffer);

} END_OF_FUNCTION(FASE_2);
